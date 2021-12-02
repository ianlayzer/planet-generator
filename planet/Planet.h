#ifndef PLANET_H
#define PLANET_H

#include "TerrainFace.h"

class Planet {
public:
    Planet();
    void generate();
private:
    std::vector<std::unique_ptr<TerrainFace>> m_faces;
};

#endif // PLANET_H
