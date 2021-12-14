#include "TerrainFace.h"
#include <iostream>

TerrainFace::TerrainFace(int resolution, glm::vec3 up, Noise *continentNoise, Noise *mountainNoise, Noise *oceanNoise, bool useContinentsAsMask):
    m_resolution(resolution), m_continentNoise(continentNoise), m_mountainNoise(mountainNoise), m_oceanNoise(oceanNoise), m_up(up),
    m_useContinentsAsMask(useContinentsAsMask)
{
    m_axisA = glm::vec3(m_up.y, m_up.z, m_up.x);
    m_axisB = glm::cross(m_up, m_axisA);
    int numVertices = m_resolution * m_resolution;
    int numTriangles = (m_resolution - 1) * (m_resolution - 1) * 2 * 3;
    m_vertices = std::vector<PlanetVertex>(numVertices);
    m_triangles = std::vector<int>(numTriangles);
    m_vertexData.reserve(numTriangles * 6);
    generate();
}

TerrainFace::~TerrainFace() {
}

void TerrainFace::generate() {
    float width = m_resolution - 1;
    for (int y = 0; y < m_resolution; y++) {
        for (int x = 0; x < m_resolution; x++) {
            int index = getIndex(x, y, m_resolution);
            glm::vec2 percent = glm::vec2(x, y) / width;
            glm::vec3 position = m_up + (percent.x - 0.5f) * 2 * m_axisA + (percent.y - 0.5f) * 2 * m_axisB;
            position = glm::normalize(position);
            float elevation = evaluateNoise(position);
            if (elevation > 1.f) {
                position *= elevation;
            }
            m_vertices[index] = PlanetVertex(position, elevation, glm::vec3(), 0);
        }
    }
    // record triangles
    int triangleCounter = 0;
    for (int y = 0; y < m_resolution - 1; y++) {
        for (int x = 0; x < m_resolution - 1; x++) {

            int currentIndex = getIndex(x, y, m_resolution);
            int rightNeighborIndex = getIndex(x + 1, y, m_resolution);
            int belowNeighborIndex = getIndex(x, y + 1, m_resolution);
            int rightBelowNeighborIndex = getIndex(x + 1, y + 1, m_resolution);
            // record triangle between current vertex, rightBelow neighbor, and below neighbor
            m_triangles[triangleCounter++] = currentIndex;
            m_triangles[triangleCounter++] = rightBelowNeighborIndex;
            m_triangles[triangleCounter++] = belowNeighborIndex;
            // record triangle between current vertex, right neighbor, and rightBelow neighbor
            m_triangles[triangleCounter++] = currentIndex;
            m_triangles[triangleCounter++] = rightNeighborIndex;
            m_triangles[triangleCounter++] = rightBelowNeighborIndex;
        }
    }
    processTriangles();
    initializeOpenGLShapeProperties();
}

void TerrainFace::processTriangles() {
    for (int i = 0; i < m_triangles.size(); i += 3) {
        Vertex *pointA = &m_vertices[m_triangles[i]];
        Vertex *pointB = &m_vertices[m_triangles[i + 1]];
        Vertex *pointC = &m_vertices[m_triangles[i + 2]];
        glm::vec3 faceNormal = getFaceNormal(pointA->position, pointB->position, pointC->position);
        // add face normals to vertex normals accumulator and increment num faces
        pointA->normal += faceNormal;
        pointB->normal += faceNormal;
        pointC->normal += faceNormal;
        pointA->numFaces += 1;
        pointB->numFaces += 1;
        pointC->numFaces += 1;
    }
    // set vertex normal to be the average of all face normals
    for (int i = 0; i < m_vertices.size(); i++) {
        m_vertices[i].normal = glm::normalize(m_vertices[i].normal / static_cast<float>(m_vertices[i].numFaces));
    }
    for (int i = 0; i < m_triangles.size(); i += 3) {
        PlanetVertex pointA = m_vertices[m_triangles[i]];
        PlanetVertex pointB = m_vertices[m_triangles[i + 1]];
        PlanetVertex pointC = m_vertices[m_triangles[i + 2]];
        makeTriangle(pointA, pointB, pointC);
    }
}
// pointA, pointB, pointC listed in counter-clockwise order
void TerrainFace::makeTriangle(const PlanetVertex &pointA, const PlanetVertex &pointB, const PlanetVertex &pointC) {
    insertVec3(m_vertexData, pointA.position);
    insertVec3(m_vertexData, pointA.normal);
    m_vertexData.push_back(pointA.elevation);

    insertVec3(m_vertexData, pointB.position);
    insertVec3(m_vertexData, pointB.normal);
    m_vertexData.push_back(pointB.elevation);

    insertVec3(m_vertexData, pointC.position);
    insertVec3(m_vertexData, pointC.normal);
    m_vertexData.push_back(pointC.elevation);
}

// pointA, pointB, pointC listed in counter-clockwise order
glm::vec3 TerrainFace::getFaceNormal(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC) {
    return glm::normalize(glm::cross(pointB - pointA, pointC - pointA));
}

float TerrainFace::evaluateNoise(glm::vec3 point) {
    float firstLayerNoise = m_continentNoise->evaluate(point);
    float continentNoise = m_continentNoise->isEnabled() ? firstLayerNoise : 0.f;
    float mountainNoise = m_mountainNoise->isEnabled() ? m_mountainNoise->evaluate(point) : 0.f;
    float mask = m_useContinentsAsMask ? firstLayerNoise : 1.f;
    float ocean = 0.f;
    float elevation = continentNoise + mountainNoise * mask;
    if (elevation < 0.001f) {
        ocean = m_oceanNoise->isEnabled() ? - m_oceanNoise->evaluate(point) : 0.f;
    }
    return (elevation + ocean + 1);
}
