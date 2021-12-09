#include "Planet.h"

Planet::Planet(int resolution, float noiseStrength, float noiseRoughness, glm::vec3 noiseCenter,
               float noiseBaseRoughness, int noiseNumLayers, float noisePersistence, float noiseMinValue,
               float noiseStrengthMount, float noiseRoughnessMount, glm::vec3 noiseCenterMount,
               float noiseBaseRoughnessMount, int noiseNumLayersMount, float noisePersistenceMount, float noiseMinValueMount,
               bool continentsEnabled, bool mountainsEnabled, bool useContinentsAsMask):
    m_resolution(resolution),
    m_noise(std::make_unique<Noise>(noiseStrength, noiseRoughness, noiseCenter, noiseBaseRoughness,
                                    noiseNumLayers, noisePersistence, noiseMinValue, noiseStrengthMount,
                                    noiseRoughnessMount, noiseCenterMount, noiseBaseRoughnessMount, noiseNumLayersMount,
                                    noisePersistenceMount, noiseMinValueMount, continentsEnabled, mountainsEnabled, useContinentsAsMask))
{
    m_faces = std::vector<std::unique_ptr<TerrainFace>>(6);
    m_faces[0] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(1.f, 0.f, 0.f), *m_noise.get());
    m_faces[1] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(-1.f, 0.f, 0.f), *m_noise.get());
    m_faces[2] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 1.f, 0.f), *m_noise.get());
    m_faces[3] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, -1.f, 0.f), *m_noise.get());
    m_faces[4] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, 1.f), *m_noise.get());
    m_faces[5] = std::make_unique<TerrainFace>(m_resolution, glm::vec3(0.f, 0.f, -1.f), *m_noise.get());
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
