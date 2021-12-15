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
    NoiseSettings(NoiseLayerSettings continentSettings, NoiseLayerSettings mountainSettings, NoiseLayerSettings oceanSettings, bool useContinentsAsMask):
        continentSettings(continentSettings), mountainSettings(mountainSettings), oceanSettings(oceanSettings), useContinentsAsMask(useContinentsAsMask) {}
    NoiseLayerSettings continentSettings;
    NoiseLayerSettings mountainSettings;
    NoiseLayerSettings oceanSettings;
    bool useContinentsAsMask;
};

struct ColorSettings {
    ColorSettings(QColor oceanColor, QColor landColor, QColor mountainColor, bool smoothColors):
        oceanColor(oceanColor), landColor(landColor), mountainColor(mountainColor), smoothColors(smoothColors) {}
    QColor oceanColor;
    QColor landColor;
    QColor mountainColor;
    bool smoothColors;
};

struct PlanetSettings {
    PlanetSettings(int resolution, NoiseSettings noiseSettings, ColorSettings colorSettings, bool onlyShowOneFace):
        resolution(resolution), noiseSettings(noiseSettings), colorSettings(colorSettings), onlyShowOneFace(onlyShowOneFace) {}
    int resolution;
    NoiseSettings noiseSettings;
    ColorSettings colorSettings;
    bool onlyShowOneFace;
};

#endif // PLANETSETTINGS_H
