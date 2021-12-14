#ifndef NOISE_H
#define NOISE_H

#include <cstddef>
#include <stdint.h>
#include <glm/glm.hpp>
#include <vector>
#include "PlanetSettings.h"

class Noise
{
public:
    Noise(NoiseLayerSettings noiseSettings);
    float getNoise(glm::vec3 point);
    float evaluate(glm::vec3 point);
    bool isEnabled();
private:
    float m_strength;
    float m_roughness;
    glm::vec3 m_center;
    float m_baseRoughness;
    float m_persistence;
    int m_numLayers;;
    float m_minValue;
    bool m_isEnabled;
};

#endif // NOISE_H
