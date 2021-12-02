#ifndef PLANET_H
#define PLANET_H

#include "TerrainFace.h"

class Planet {
public:
    Planet(int resolution);
    void generate();
    void draw();
private:
    int m_resolution;
    std::vector<std::unique_ptr<TerrainFace>> m_faces;
};

#endif // PLANET_H
