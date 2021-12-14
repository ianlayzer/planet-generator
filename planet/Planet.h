#ifndef PLANET_H
#define PLANET_H

#include "TerrainFace.h"
#include "Noise.h"
#include "PlanetSettings.h"

class Planet {
public:
    Planet(PlanetSettings planetSettings);
    ~Planet();
    void generate();
    void draw();
private:
    int m_resolution;
    std::vector<std::unique_ptr<TerrainFace>> m_faces;
    std::unique_ptr<Noise> m_continentNoise;
    std::unique_ptr<Noise> m_mountainNoise;
    bool m_onlyShowOneFace;
};

#endif // PLANET_H
