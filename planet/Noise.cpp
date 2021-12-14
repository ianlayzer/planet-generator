#include "Noise.h"
#include <iostream>

static inline int32_t fastfloor(float fp) {
    int32_t i = static_cast<int32_t>(fp);
    return (fp < i) ? (i - 1) : (i);
}

static const uint8_t perm[256] = {
    151, 160, 137, 91, 90, 15,
    131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
    190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
    88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
    77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
    102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
    135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
    5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
    223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
    129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
    251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
    49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
    138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180
};

static float grad(int32_t hash, float x, float y, float z) {
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}

Noise::Noise(float strengthCont, float roughnessCont, glm::vec3 centerCont,
             float baseRoughnessCont, int numLayersCont, float persistenceCont, float minValueCont,
             float strengthMount, float roughnessMount, glm::vec3 centerMount,
             float baseRoughnessMount, int numLayersMount, float persistenceMount, float minValueMount,
             bool continentsEnabled, bool mountainsEnabled, bool useContinentsAsMask) :
    m_strengthCont(strengthCont),
    m_roughnessCont(roughnessCont),
    m_centerCont(centerCont),
    m_baseRoughnessCont(baseRoughnessCont),
    m_persistenceCont(persistenceCont),
    m_numLayersCont(numLayersCont),
    m_minValueCont(minValueCont),
    m_strengthMount(strengthMount),
    m_roughnessMount(roughnessMount),
    m_centerMount(centerMount),
    m_baseRoughnessMount(baseRoughnessMount),
    m_persistenceMount(persistenceMount),
    m_numLayersMount(numLayersMount),
    m_minValueMount(minValueMount),
    m_continentsEnabled(continentsEnabled),
    m_mountainsEnabled(mountainsEnabled),
    m_useContinentsAsMask(useContinentsAsMask)
{
}

float Noise::getNoise(glm::vec3 point) {
    float x = point.x;
    float y = point.y;
    float z = point.z;
    float n0, n1, n2, n3;

    static const float F3 = 1.0f / 3.0f;
    static const float G3 = 1.0f / 6.0f;

    float s = (x + y + z) * F3;
    int i = fastfloor(x + s);
    int j = fastfloor(y + s);
    int k = fastfloor(z + s);
    float t = (i + j + k) * G3;
    // The x,y,z distances from the cell origin
    float x0 = x - (i - t);
    float y0 = y - (j - t);
    float z0 = z - (k - t);

    int i1, j1, k1; // Offsets for second corner of simplex in (i,j,k) coords
    int i2, j2, k2; // Offsets for third corner of simplex in (i,j,k) coords
    if (x0 >= y0) {
        if (y0 >= z0) {
            // X Y Z order
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        } else if (x0 >= z0) {
            // X Z Y order
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        } else {
            // Z X Y order
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        }
    } else {
        // x0<y0
        if (y0 < z0) {
            // Z Y X order
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        } else if (x0 < z0) {
            // Y Z X order
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        } else {
             // Y X Z order
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        }
    }

    // A step of (1,0,0) in (i,j,k) means a step of (1-c,-c,-c) in (x,y,z),
    // a step of (0,1,0) in (i,j,k) means a step of (-c,1-c,-c) in (x,y,z), and
    // a step of (0,0,1) in (i,j,k) means a step of (-c,-c,1-c) in (x,y,z), where
    // c = 1/6.
    float x1 = x0 - i1 + G3; // Offsets for second corner in (x,y,z) coords
    float y1 = y0 - j1 + G3;
    float z1 = z0 - k1 + G3;

    float x2 = x0 - i2 + F3; // Offsets for third corner in (x,y,z) coords
    float y2 = y0 - j2 + F3;
    float z2 = z0 - k2 + F3;

    float x3 = x0 - 0.5; // Offsets for last corner in (x,y,z) coords
    float y3 = y0 - 0.5;
    float z3 = z0 - 0.5;

    // Work out the hashed gradient indices of the four simplex corners
    int gi0 = perm[i + perm[j + perm[k]]];
    int gi1 = perm[i + i1 + perm[j + j1 + perm[k + k1]]];
    int gi2 = perm[i + i2 + perm[j + j2 + perm[k + k2]]];
    int gi3 = perm[i + 1 + perm[j + 1 + perm[k + 1]]];

    // Calculate the contribution from the four corners
    float t0 = 0.6f - x0*x0 - y0*y0 - z0*z0;
    if (t0 < 0) {
        n0 = 0.0;
    } else {
        t0 *= t0;
        n0 = t0 * t0 * grad(gi0, x0, y0, z0);
    }
    float t1 = 0.6f - x1*x1 - y1*y1 - z1*z1;
    if (t1 < 0) {
        n1 = 0.0;
    } else {
        t1 *= t1;
        n1 = t1 * t1 * grad(gi1, x1, y1, z1);
    }
    float t2 = 0.6f - x2*x2 - y2*y2 - z2*z2;
    if (t2 < 0) {
        n2 = 0.0;
    } else {
        t2 *= t2;
        n2 = t2 * t2 * grad(gi2, x2, y2, z2);
    }
    float t3 = 0.6f - x3*x3 - y3*y3 - z3*z3;
    if (t3 < 0) {
        n3 = 0.0;
    } else {
        t3 *= t3;
        n3 = t3 * t3 * grad(gi3, x3, y3, z3);
    }
    // Add contributions from each corner to get the final noise value.
    // The result is scaled to stay just inside [-1,1]
    return 32.0f*(n0 + n1 + n2 + n3);
}

float Noise::evaluateContinents(glm::vec3 point) {
    float noiseValue = 0.f;
    float frequency = m_baseRoughnessCont;
    float amplitude = 1.f;
    for (int i = 0; i < m_numLayersCont; i++) {
        float v = getNoise(point * frequency + m_centerCont);
        noiseValue += (v + 1) * 0.5f * amplitude;
        frequency *= m_roughnessCont;
        amplitude *= m_persistenceCont;
    }
    noiseValue = std::max(0.f, noiseValue - m_minValueCont);
    return noiseValue * m_strengthCont;
}

float Noise::evaluateMountains(glm::vec3 point) {
    float noiseValue = 0.f;
    float frequency = m_baseRoughnessMount;
    float amplitude = 1.f;
    for (int i = 0; i < m_numLayersMount; i++) {
        float v = getNoise(point * frequency + m_centerMount);
        noiseValue += (v + 1) * 0.5f * amplitude;
        frequency *= m_roughnessMount;
        amplitude *= m_persistenceMount;
    }
    noiseValue = std::max(0.f, noiseValue - m_minValueMount);
    return noiseValue * m_strengthMount;
}

float Noise::evaluateOceans(glm::vec3 point) {
    float noiseValue = 0.f;
    float frequency = m_baseRoughnessCont;
    float amplitude = 1.f;
    for (int i = 0; i < m_numLayersCont; i++) {
        float v = getNoise(point * frequency + m_centerCont);
        noiseValue += (v + 1) * 0.5f * amplitude;
        frequency *= m_roughnessCont;
        amplitude *= m_persistenceCont;
    }
    noiseValue = std::max(0.f, noiseValue - m_minValueCont);
    return -(noiseValue * m_strengthCont);
}

float Noise::Evaluate(glm::vec3 point) {
//    float firstLayerVal = evaluateContinents(point);
//    float continents = m_continentsEnabled ? firstLayerVal : 0.f;
//    float mask = m_useContinentsAsMask ? firstLayerVal : 1.f;
//    float mountains = m_mountainsEnabled ? evaluateMountains(point) : 0.f;
//    float elevation = continents + mountains * mask;
//    if (elevation < .001) {
        float oceans = evaluateOceans(point);
        return (oceans + 1);
//    }
//    return (elevation + 1);
}
