#include "TerrainFace.h"

TerrainFace::TerrainFace(int resolution, glm::vec3 up, std::unique_ptr<Noise> noise):
    m_resolution(resolution), m_noise(std::move(noise)), m_up(up)
{
    m_axisA = glm::vec3(m_up.y, m_up.z, m_up.x);
    m_axisB = glm::cross(m_up, m_axisA);
    m_vertices = std::vector<Vertex>(m_resolution * m_resolution);
    m_triangles = std::vector<int>((m_resolution - 1) * (m_resolution - 1) * 2 * 3);
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
            float elevation = m_noise-> Evaluate(position);
            position *= (elevation + 1);
            m_vertices[index] = Vertex(position, glm::vec3(), 0);
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
        Vertex pointA = m_vertices[m_triangles[i]];
        Vertex pointB = m_vertices[m_triangles[i + 1]];
        Vertex pointC = m_vertices[m_triangles[i + 2]];
        makeTriangle(pointA, pointB, pointC);
    }
}
// pointA, pointB, pointC listed in counter-clockwise order
void TerrainFace::makeTriangle(const Vertex &pointA, const Vertex &pointB, const Vertex &pointC) {
    insertVec3(m_vertexData, pointA.position);
    insertVec3(m_vertexData, pointA.normal);
    insertVec3(m_vertexData, pointB.position);
    insertVec3(m_vertexData, pointB.normal);
    insertVec3(m_vertexData, pointC.position);
    insertVec3(m_vertexData, pointC.normal);
}

// pointA, pointB, pointC listed in counter-clockwise order
glm::vec3 TerrainFace::getFaceNormal(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC) {
    return glm::normalize(glm::cross(pointB - pointA, pointC - pointA));
}

float TerrainFace::getNoise(glm::vec3 position) {
    return (-1.0 + 2.0 * glm::fract(std::sin(position.x * 127.1f + position.y * 311.7f + position.z * 219.4f) * 43758.5453123f)) * 0.02;
}



