#ifndef TERRAINFACE_H
#define TERRAINFACE_H

#include <vector>
#include "glm/glm.hpp"
#include "gl/OpenGLShape.h"
#include "Noise.h"

struct PlanetVertex : Vertex {
    PlanetVertex() {};
    PlanetVertex(glm::vec3 position, float elevation, glm::vec3 normal, int numFaces):
        Vertex(position, normal, numFaces),
        elevation(elevation) {}
    float elevation;
};

class TerrainFace : OpenGLShape {
public:
    TerrainFace(int resolution, glm::vec3 up, Noise *continentNoise, Noise *mountainNoise, bool useContinentsAsMask);
    ~TerrainFace();
    void generate();
    using OpenGLShape::draw;
private:
    void processTriangles();
    void makeTriangle(const PlanetVertex &pointA, const PlanetVertex &pointB, const PlanetVertex &pointC);
    glm::vec3 getFaceNormal(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 pointC);
    float evaluateNoise(glm::vec3 point);

    int m_resolution;
    Noise *m_continentNoise;
    Noise *m_mountainNoise;
    bool m_useContinentsAsMask;
    glm::vec3 m_up;
    glm::vec3 m_axisA;
    glm::vec3 m_axisB;
    std::vector<PlanetVertex> m_vertices;
    std::vector<int> m_triangles;
};

inline int getIndex(int x, int y, int width) {
    return y * width + x;
}

#endif // TERRAINFACE_H
