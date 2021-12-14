#include "Planet.h"

Planet::Planet(PlanetSettings planetSettings):
    m_resolution(std::max(2, planetSettings.resolution))
{
    m_continentNoise = std::make_unique<Noise>(planetSettings.noiseSettings.continentSettings);
    m_mountainNoise = std::make_unique<Noise>(planetSettings.noiseSettings.mountainSettings);

    m_faces = std::vector<std::unique_ptr<TerrainFace>>(6);
    m_faces[0] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(1.f, 0.f, 0.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
    m_faces[1] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(-1.f, 0.f, 0.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
    m_faces[2] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 1.f, 0.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
    m_faces[3] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, -1.f, 0.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
    m_faces[4] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, 1.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
    m_faces[5] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, -1.f), m_continentNoise.get(), m_mountainNoise.get(), planetSettings.noiseSettings.useContinentsAsMask);
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
