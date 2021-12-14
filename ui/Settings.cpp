/*!

 Settings.h
 CS123 Support Code

 @author  Evan Wallace (edwallac)
 @date    9/1/2010

 This file contains various settings and enumerations that you will need to
 use in the various assignments. The settings are bound to the GUI via static
 data bindings.

**/

#include "Settings.h"
#include <QFile>
#include <QSettings>

Settings settings;


/**
 * Loads the application settings, or, if no saved settings are available, loads default values for
 * the settings. You can change the defaults here.
 */
void Settings::loadSettingsOrDefaults() {
    // Set the default values below
    QSettings s("CS123", "CS123");

    // Brush
    brushType = s.value("brushType", BRUSH_LINEAR).toInt();
    brushRadius = s.value("brushRadius", 50).toInt();
    brushColor.r = s.value("brushRed", 127).toInt();
    brushColor.g = s.value("brushGreen", 255).toInt();
    brushColor.b = s.value("brushBlue", 0).toInt();
    brushColor.a = s.value("brushAlpha", 20).toInt();

    // Filter
    filterType = s.value("filterType", FILTER_EDGE_DETECT).toInt();
    edgeDetectSensitivity = s.value("edgeDetectSensitivity", 0.5f).toDouble();
    blurRadius = s.value("blurRadius", 10).toInt();
    scaleX = s.value("scaleX", 2).toDouble();
    scaleY = s.value("scaleY", 2).toDouble();
    rotateAngle = s.value("rotateAngle", 0).toInt();

    // Shapes
    shapeType = s.value("shapeType", SHAPE_SPHERE).toInt();
    resolution = s.value("resolution", 50).toInt();
    noiseRoughnessCont = s.value("roughnessCont", 1).toFloat();
    noiseBaseRoughnessCont = s.value("baseRoughnessCont", 1).toFloat();
    noisePersistenceCont = s.value("persistenceCont", 1).toFloat();
    noiseNumLayersCont = s.value("numLayersCont", 5).toInt();
    noiseMinValueCont = s.value("minValueCont", 0).toFloat();
    noiseStrengthCont = s.value("strengthCont", 1).toFloat();
    noiseCenterXCont = s.value("noiseCenterXCont", 0).toFloat();
    noiseCenterYCont = s.value("noiseCenterYCont", 0).toFloat();
    noiseCenterZCont = s.value("noiseCenterZCont", 0).toFloat();
    continentsEnabled = s.value("noiseContEnabled", true).toBool();
    noiseRoughnessMount = s.value("roughnessMount", 1).toFloat();
    noiseBaseRoughnessMount = s.value("baseRoughnessMount", 1).toFloat();
    noisePersistenceMount = s.value("persistenceMount", 1).toFloat();
    noiseNumLayersMount = s.value("numLayersMount", 5).toInt();
    noiseMinValueMount = s.value("minValueMount", 0).toFloat();
    noiseStrengthMount = s.value("strengthMount", 1).toFloat();
    noiseCenterXMount = s.value("noiseCenterXMount", 0).toFloat();
    noiseCenterYMount = s.value("noiseCenterYMount", 0).toFloat();
    noiseCenterZMount = s.value("noiseCenterZMount", 0).toFloat();
    mountainsEnabled = s.value("noiseMountEnabled", true).toBool();
    useContinentsAsMask = s.value("useContinentsAsMask", true).toBool();
    noiseRoughnessOcean = s.value("roughnessOcean", 1).toFloat();
    noiseBaseRoughnessOcean = s.value("baseRoughnessOcean", 1).toFloat();
    noisePersistenceOcean = s.value("persistenceOcean", 1).toFloat();
    noiseNumLayersOcean = s.value("numLayersOcean", 5).toInt();
    noiseMinValueOcean = s.value("minValueOcean", 0).toFloat();
    noiseStrengthOcean = s.value("strengthOcean", 1).toFloat();
    noiseCenterXOcean = s.value("noiseCenterXOcean", 0).toFloat();
    noiseCenterYOcean = s.value("noiseCenterYOcean", 0).toFloat();
    noiseCenterZOcean = s.value("noiseCenterZOcean", 0).toFloat();
    oceansEnabled = s.value("noiseOceanEnabled", true).toBool();
    shapeParameter3 = s.value("shapeParameter3", 15).toDouble();
    planetColor = s.value("planetColor", QColor(255, 100, 230)).value<QColor>();
    enableRotation = s.value("enableRotation", false).toBool();
    useLighting = s.value("useLighting", true).toBool();
    drawWireframe = s.value("drawWireframe", true).toBool();
    drawNormals = s.value("drawNormals", false).toBool();

    // Camtrans
    useOrbitCamera = s.value("useOrbitCamera", true).toBool();
    cameraFov = s.value("cameraFov", 55).toDouble();
    cameraNear = s.value("cameraNear", 0.1).toDouble();
    cameraFar = s.value("cameraFar", 50).toDouble();

    // Ray
    useSuperSampling = s.value("useSuperSampling", false).toBool();
    numSuperSamples = s.value("numSuperSamples", 2).toInt();
    useAntiAliasing = s.value("useAntiAliasing", true).toBool();
    useShadows = s.value("useShadows", false).toBool();
    useTextureMapping = s.value("useTextureMapping", false).toBool();
    useReflection = s.value("useReflection", false).toBool();
    useRefraction = s.value("useRefraction", false).toBool();
    useMultiThreading = s.value("useMultiThreading", true).toBool();
    usePointLights = s.value("usePointLights", true).toBool();
    useDirectionalLights = s.value("useDirectionalLights", true).toBool();
    useSpotLights = s.value("useSpotLights", true).toBool();
    useKDTree = s.value("useKDTree", true).toBool();

    currentTab = s.value("currentTab", TAB_2D).toBool();

    // These are for computing deltas and the values don't matter, so start all dials in the up
    // position
    cameraPosX = 0;
    cameraPosY = 0;
    cameraPosZ = 0;
    cameraRotU = 0;
    cameraRotV = 0;
    cameraRotN = 0;
}

void Settings::saveSettings() {
    QSettings s("CS123", "CS123");

    // Brush
    s.setValue("brushType", brushType);
    s.setValue("brushRadius", brushRadius);
    s.setValue("brushRed", brushColor.r);
    s.setValue("brushGreen", brushColor.g);
    s.setValue("brushBlue", brushColor.b);
    s.setValue("brushAlpha", brushColor.a);

    // Filter
    s.setValue("filterType", filterType);
    s.setValue("edgeDetectSensitivity", edgeDetectSensitivity);
    s.setValue("blurRadius", blurRadius);
    s.setValue("scaleX", scaleX);
    s.setValue("scaleY", scaleY);
    s.setValue("rotateAngle", rotateAngle);

    // Shapes
    s.setValue("shapeType", shapeType);
    s.setValue("resolution", resolution);
    s.setValue("roughnessCont", noiseRoughnessCont);
    s.setValue("strengthCont", noiseStrengthCont);
    s.setValue("baseRoughnessCont", noiseBaseRoughnessCont);
    s.setValue("numLayersCont", noiseNumLayersCont);
    s.setValue("persistenceCont", noisePersistenceCont);
    s.setValue("noiseCenterXCont", noiseCenterXCont);
    s.setValue("noiseCenterYCont", noiseCenterYCont);
    s.setValue("noiseCenterZCont", noiseCenterZCont);
    s.setValue("minValueCont", noiseMinValueCont);
    s.setValue("noiseContEnabled", continentsEnabled);
    s.setValue("roughnessMount", noiseRoughnessMount);
    s.setValue("strengthMount", noiseStrengthMount);
    s.setValue("baseRoughnessMount", noiseBaseRoughnessMount);
    s.setValue("numLayersMount", noiseNumLayersMount);
    s.setValue("persistenceMount", noisePersistenceMount);
    s.setValue("noiseCenterXMount", noiseCenterXMount);
    s.setValue("noiseCenterYMount", noiseCenterYMount);
    s.setValue("noiseCenterZMount", noiseCenterZMount);
    s.setValue("minValueMount", noiseMinValueMount);
    s.setValue("noiseMountEnabled", mountainsEnabled);
    s.setValue("useContinentsAsMask", useContinentsAsMask);
    s.setValue("roughnessOcean", noiseRoughnessOcean);
    s.setValue("strengthOcean", noiseStrengthOcean);
    s.setValue("baseRoughnessOcean", noiseBaseRoughnessOcean);
    s.setValue("numLayersOcean", noiseNumLayersOcean);
    s.setValue("persistenceOcean", noisePersistenceOcean);
    s.setValue("noiseCenterXOcean", noiseCenterXOcean);
    s.setValue("noiseCenterYOcean", noiseCenterYOcean);
    s.setValue("noiseCenterZOcean", noiseCenterZOcean);
    s.setValue("minValueOcean", noiseMinValueOcean);
    s.setValue("noiseOceanEnabled", oceansEnabled);
    s.setValue("shapeParameter3", shapeParameter3);
    s.setValue("enableRotation", enableRotation);
    s.setValue("useLighting", useLighting);
    s.setValue("drawWireframe", drawWireframe);
    s.setValue("drawNormals", drawNormals);

    // Camtrans
    s.setValue("useOrbitCamera", useOrbitCamera);
    s.setValue("cameraFov", cameraFov);
    s.setValue("cameraNear", cameraNear);
    s.setValue("cameraFar", cameraFar);

    // Ray
    s.setValue("useSuperSampling", useSuperSampling);
    s.setValue("numSuperSamples", numSuperSamples);
    s.setValue("useAntiAliasing", useAntiAliasing);
    s.setValue("useShadows", useShadows);
    s.setValue("useTextureMapping", useTextureMapping);
    s.setValue("useReflection", useReflection);
    s.setValue("useRefraction", useRefraction);
    s.setValue("useMultiThreading", useMultiThreading);
    s.setValue("usePointLights", usePointLights);
    s.setValue("useDirectionalLights", useDirectionalLights);
    s.setValue("useSpotLights", useSpotLights);
    s.setValue("useKDTree", useKDTree);

    s.setValue("currentTab", currentTab);
}

int Settings::getSceneMode() {
    if (this->useSceneviewScene)
        return SCENEMODE_SCENEVIEW;
    else
        return SCENEMODE_SHAPES;
}

int Settings::getCameraMode() {
    if (this->useOrbitCamera)
        return CAMERAMODE_ORBIT;
    else
        return CAMERAMODE_CAMTRANS;
}
