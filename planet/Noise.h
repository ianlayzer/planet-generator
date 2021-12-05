#ifndef NOISE_H
#define NOISE_H

#include <cstddef>
#include <stdint.h>
#include <glm/glm.hpp>
#include <vector>

class Noise
{
public:
    Noise();
    float getNoise(glm::vec3 point);
    float Evaluate(glm::vec3 point);
};

#endif // NOISE_H
