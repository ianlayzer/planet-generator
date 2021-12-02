#ifndef TERRAINFACE_H
#define TERRAINFACE_H

#include <vector>
#include "glm/glm.hpp"
#include "gl/OpenGLShape.h"

class TerrainFace : OpenGLShape {
public:
    TerrainFace(int resolution, glm::vec3 up);
    void generate();
private:
    void makeTriangle(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC);
    glm::vec3 getFaceNormal(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC);
    int m_resolution;
    glm::vec3 m_up;
    glm::vec3 m_axisA;
    glm::vec3 m_axisB;
    std::vector<glm::vec3> m_vertices;
};

inline int getIndex(int x, int y, int width) {
    return y * width + x;
}

#endif // TERRAINFACE_H
