#include "Planet.h"

Planet::Planet(int resolution):
    m_resolution(resolution),
    m_noise(std::make_unique<Noise>())
{
    m_faces = std::vector<std::unique_ptr<TerrainFace>>(6);
    m_faces[0] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(1.f, 0.f, 0.f), std::move(m_noise));
    m_faces[1] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(-1.f, 0.f, 0.f), std::move(m_noise));
    m_faces[2] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 1.f, 0.f), std::move(m_noise));
    m_faces[3] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, -1.f, 0.f), std::move(m_noise));
    m_faces[4] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, 1.f), std::move(m_noise));
    m_faces[5] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, -1.f), std::move(m_noise));
}

Planet::~Planet() {
}

void Planet::generate() {
    for (int i = 0; i < m_faces.size(); i++) {
        m_faces[i]->generate();
    }
}

void Planet::draw() {
    for (int i = 0; i < m_faces.size(); i++) {
        m_faces[i]->draw();
    }
}
