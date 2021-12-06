#ifndef PLANET_H
#define PLANET_H

#include "TerrainFace.h"
#include "Noise.h"

class Planet {
public:
    Planet(int resolution, float noiseStrength, float noiseRoughness, glm::vec3 noiseCenter);
    ~Planet();
    void generate();
    void draw();
private:
    int m_resolution;
    std::vector<std::unique_ptr<TerrainFace>> m_faces;
    std::unique_ptr<Noise> m_noise;
};

#endif // PLANET_H
