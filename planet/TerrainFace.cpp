#include "TerrainFace.h"

TerrainFace::TerrainFace(int resolution, glm::vec3 up):
    m_resolution(resolution), m_up(up)
{
    m_axisA = glm::vec3(m_up.y, m_up.z, m_up.x);
    m_axisB = glm::cross(m_up, m_axisA);
    m_vertices = std::vector<glm::vec3>(resolution * resolution);
    generate();
}

void TerrainFace::generate() {
    float width = m_resolution - 1;
    for (int y = 0; y < m_resolution; y++) {
        for (int x = 0; x < m_resolution; x++) {
            int index = getIndex(x, y, m_resolution);
            glm::vec2 percent = glm::vec2(x, y) / width;
            glm::vec3 position = m_up + (percent.x - 0.5f) * 2 * m_axisA + (percent.y - 0.5f) * 2 * m_axisB;
            position = glm::normalize(position);
            float offset = getHeight(y, x) / 10;
            position += offset * position;
            m_vertices[index] = position;
        }
    }

    for (int y = 0; y < m_resolution - 1; y++) {
        for (int x = 0; x < m_resolution - 1; x++) {
            glm::vec3 current = m_vertices[getIndex(x, y, m_resolution)];
            glm::vec3 right = m_vertices[getIndex(x + 1, y, m_resolution)];
            glm::vec3 below = m_vertices[getIndex(x, y + 1, m_resolution)];
            glm::vec3 rightBelow = m_vertices[getIndex(x + 1, y + 1, m_resolution)];
            makeTriangle(current, rightBelow, below);
            makeTriangle(current, right, rightBelow);
        }
    }
    initializeOpenGLShapeProperties();
}

// pointA, pointB, pointC listed in counter-clockwise order
void TerrainFace::makeTriangle(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC) {
    glm::vec3 faceNormal = getFaceNormal(pointA, pointB, pointC);
    insertVec3(m_vertexData, pointA);
    insertVec3(m_vertexData, faceNormal);
    insertVec3(m_vertexData, pointB);
    insertVec3(m_vertexData, faceNormal);
    insertVec3(m_vertexData, pointC);
    insertVec3(m_vertexData, faceNormal);
}

// pointA, pointB, pointC listed in counter-clockwise order
glm::vec3 TerrainFace::getFaceNormal(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC) {
    return glm::normalize(glm::cross(pointB - pointA, pointC - pointA));
}

// FEEL FREE TO DO WHATEVER / DELETE THE NOISE STUFF
float TerrainFace::getHeight(int row, int col) {
    float height = 0;
    int frequency = 5;
    int gridRow = glm::floor(row / static_cast<float>(frequency));
    int gridCol = glm::floor(col / static_cast<float>(frequency));
    float verticalPos = glm::fract(row / static_cast<float>(frequency));
    float horizPos = glm::fract(col / static_cast<float>(frequency));
    float verticalAdjusted = 3 * pow(verticalPos, 2) - 2 * pow(verticalPos, 3);
    float horizAdjusted = 3 * pow(horizPos, 2) - 2* pow(horizPos, 3);
    float gridValue = randValue(gridRow, gridCol);
    float rightNeighbor = randValue(gridRow, gridCol + 1);
    float belowNeighbor = randValue(gridRow + 1, gridCol);
    float rightBelowNeighbor = randValue(gridRow + 1, gridCol + 1);
    height += glm::mix(
                glm::mix(gridValue, rightNeighbor, horizAdjusted),
                glm::mix(belowNeighbor, rightBelowNeighbor, horizAdjusted),
                verticalAdjusted);
    return height;
}


float TerrainFace::randValue(int row, int col) {
    return -1.0 + 2.0 * glm::fract(std::sin(row * 127.1f + col * 311.7f) * 43758.5453123f);
}



