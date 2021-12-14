#ifndef PLANETSETTINGS_H
#define PLANETSETTINGS_H

#include "glm/common.hpp"
#include <QColor>

struct NoiseLayerSettings {
    NoiseLayerSettings(float roughness, float baseRoughness, float persistence, int numLayers,
            float strength, float minValue, float centerX, float centerY, float centerZ, bool isEnabled):
        roughness(roughness), baseRoughness(baseRoughness), persistence(persistence), numLayers(numLayers),
        strength(strength), minValue(minValue), center(glm::vec3(centerX, centerY, centerZ)), isEnabled(isEnabled) {}

    float roughness;
    float baseRoughness;
    float persistence;
    int numLayers;
    float strength;
    float minValue;
    glm::vec3 center;
    bool isEnabled;
};

struct NoiseSettings {
    NoiseSettings(NoiseLayerSettings continentSettings, NoiseLayerSettings mountainSettings, bool useContinentsAsMask):
        continentSettings(continentSettings), mountainSettings(mountainSettings), useContinentsAsMask(useContinentsAsMask) {}
    NoiseLayerSettings continentSettings;
    NoiseLayerSettings mountainSettings;
    bool useContinentsAsMask;
};

struct ColorSettings {
    ColorSettings(QColor oceanColor, QColor landColor, QColor mountainColor):
        oceanColor(oceanColor), landColor(landColor), mountainColor(mountainColor) {}
    QColor oceanColor;
    QColor landColor;
    QColor mountainColor;
};

struct PlanetSettings {
    PlanetSettings(int resolution, NoiseSettings noiseSettings, ColorSettings colorSettings):
        resolution(resolution), noiseSettings(noiseSettings), colorSettings(colorSettings) {}
    int resolution;
    NoiseSettings noiseSettings;
    ColorSettings colorSettings;
};

#endif // PLANETSETTINGS_H
