#ifndef NOISE_H
#define NOISE_H

#include <cstddef>
#include <stdint.h>
#include <glm/glm.hpp>
#include <vector>

class Noise
{
public:
    Noise(float strength, float roughness, glm::vec3 center);
    float getNoise(glm::vec3 point);
    float Evaluate(glm::vec3 point);
private:
    float m_strength;
    float m_roughness;
    glm::vec3 m_center;
};

#endif // NOISE_H
