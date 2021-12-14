#ifndef NOISE_H
#define NOISE_H

#include <cstddef>
#include <stdint.h>
#include <glm/glm.hpp>
#include <vector>

class Noise
{
public:
    Noise(float noiseStrength, float noiseRoughness, glm::vec3 noiseCenter,
          float noiseBaseRoughness, int noiseNumLayers, float noisePersistence, float noiseMinValue,
          float noiseStrengthMount, float noiseRoughnessMount, glm::vec3 noiseCenterMount,
          float noiseBaseRoughnessMount, int noiseNumLayersMount, float noisePersistenceMount, float noiseMinValueMount,
          bool continentsEnabled, bool mountainsEnabled, bool useContinentsAsMask);
    float getNoise(glm::vec3 point);
    float Evaluate(glm::vec3 point);
private:
    float m_strengthCont;
    float m_roughnessCont;
    glm::vec3 m_centerCont;
    float m_baseRoughnessCont;
    float m_persistenceCont;
    int m_numLayersCont;
    float m_minValueCont;
    float m_strengthMount;
    float m_roughnessMount;
    glm::vec3 m_centerMount;
    float m_baseRoughnessMount;
    float m_persistenceMount;
    int m_numLayersMount;
    float m_minValueMount;
    bool m_continentsEnabled;
    bool m_mountainsEnabled;
    bool m_useContinentsAsMask;

    float evaluateContinents(glm::vec3 point);
    float evaluateMountains(glm::vec3 point);
    float evaluateOceans(glm::vec3 point);
};

#endif // NOISE_H
