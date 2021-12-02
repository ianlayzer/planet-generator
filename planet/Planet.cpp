#include "Planet.h"

Planet::Planet() {
    int resolution = 10;
    m_faces = std::vector<std::unique_ptr<TerrainFace>>(6);
    m_faces[0] = std::make_unique<TerrainFace>(resolution, glm::vec3(1.f, 0.f, 0.f));
    m_faces[1] = std::make_unique<TerrainFace>(resolution, glm::vec3(-1.f, 0.f, 0.f));
    m_faces[2] = std::make_unique<TerrainFace>(resolution, glm::vec3(0.f, 1.f, 0.f));
    m_faces[3] = std::make_unique<TerrainFace>(resolution, glm::vec3(0.f, -1.f, 0.f));
    m_faces[4] = std::make_unique<TerrainFace>(resolution, glm::vec3(0.f, 0.f, 1.f));
    m_faces[5] = std::make_unique<TerrainFace>(resolution, glm::vec3(0.f, 0.f, -1.f));
}

void Planet::generate() {
    for (int i = 0; i < m_faces.size(); i++) {
        m_faces[i]->generate();
    }
}
