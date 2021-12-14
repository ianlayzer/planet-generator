#include "PlanetScene.h"
#include "camera/Camera.h"
#include "gl/OpenGLShape.h"
#include <Canvas3D.h>
#include <QFileDialog>

#include <sstream>
#include <iostream>
#include <chrono>

#include "planet/ExampleShape.h"

using namespace CS123::GL;
#include "gl/shaders/CS123Shader.h"
#include "gl/shaders/Shader.h"
#include "glm/ext.hpp"

#include "ResourceLoader.h"

PlanetScene::PlanetScene(int width, int height) :
    m_planet(nullptr),
    m_width(width),
    m_height(height),
    m_model(glm::mat4(1.0f))
{
    initializeSceneMaterial();
    initializeSceneLight();
    loadPhongShader();
    loadWireframeShader();
    loadNormalsShader();
    loadNormalsArrowShader();
    m_phongShader->setColor(settings.planetColor);
    //TODO: [SHAPES] Allocate any additional memory you need...

}

PlanetScene::~PlanetScene()
{
    // Pro-tip: If you use smart pointers properly, this destructor should be empty
}

void PlanetScene::initializeSceneMaterial() {
    // Use a shiny orange material
    m_material.clear();
    m_material.cAmbient.r = settings.planetColor.redF() / 5.f;
    m_material.cAmbient.g = settings.planetColor.greenF() / 5.f;
    m_material.cAmbient.b = settings.planetColor.blueF() / 5.f;
    m_material.cDiffuse.r = settings.planetColor.redF();
    m_material.cDiffuse.g = settings.planetColor.greenF();
    m_material.cDiffuse.b = settings.planetColor.blueF();
    m_material.cSpecular.r = m_material.cSpecular.g = m_material.cSpecular.b = 0.4f;
//    m_material.cSpecular.r = settings.planetColor.redF();
//    m_material.cSpecular.g = settings.planetColor.greenF();
//    m_material.cSpecular.b = settings.planetColor.blueF();
    m_material.shininess = 15;
}

void PlanetScene::initializeSceneLight() {
    // Use a white directional light from the upper left corner
    memset(&m_light, 0, sizeof(m_light));
    m_light.type = LightType::LIGHT_DIRECTIONAL;
    m_light.dir = m_lightDirection;
    m_light.color.r = m_light.color.g = m_light.color.b = 1;
    m_light.id = 0;
}

void PlanetScene::loadPhongShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/default.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/default.frag");
    m_phongShader = std::make_unique<CS123Shader>(vertexSource, fragmentSource);
}

void PlanetScene::loadWireframeShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.frag");
    m_wireframeShader = std::make_unique<Shader>(vertexSource, fragmentSource);
}

void PlanetScene::loadNormalsShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normals.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.frag");
    m_normalsShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void PlanetScene::loadNormalsArrowShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.frag");
    m_normalsArrowShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void PlanetScene::render(Canvas3D *context) {
    // Clear the screen in preparation for the next frame. (Use a gray background instead of a
    // black one for drawing wireframe or normals so they will show up against the background.)
    setClearColor();
    renderPhongPass(context);

    if (settings.drawWireframe) {
        renderWireframePass(context);
    }

    if (settings.drawNormals) {
        renderNormalsPass(context);
    }
}

void PlanetScene::renderPhongPass(Canvas3D *context) {
    m_phongShader->bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    clearLights();
    setLights(context->getCamera()->getViewMatrix());
    setPhongSceneUniforms();
    setMatrixUniforms(m_phongShader.get(), context);
    renderGeometryAsFilledPolygons();

    m_phongShader->unbind();
}

void PlanetScene::setPhongSceneUniforms() {
    m_phongShader->setUniform("useLighting", settings.useLighting);
    m_phongShader->setUniform("useArrowOffsets", false);
    m_phongShader->applyMaterial(m_material);
//    m_phongShader->setColor(settings.planetColor);
}

void PlanetScene::setMatrixUniforms(Shader *shader, Canvas3D *context) {
    shader->setUniform("p", context->getCamera()->getProjectionMatrix());
    shader->setUniform("v", context->getCamera()->getViewMatrix());
    shader->setUniform("m", m_model);
}

void PlanetScene::renderGeometryAsFilledPolygons() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    renderGeometry();
}

void PlanetScene::renderWireframePass(Canvas3D *context) {
    m_wireframeShader->bind();
    setMatrixUniforms(m_wireframeShader.get(), context);
    renderGeometryAsWireframe();
    m_wireframeShader->unbind();
}

void PlanetScene::renderGeometryAsWireframe() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    renderGeometry();
}

void PlanetScene::renderNormalsPass (Canvas3D *context) {
    // Render the lines.
    m_normalsShader->bind();
    setMatrixUniforms(m_normalsShader.get(), context);
    renderGeometryAsWireframe();
    m_normalsShader->unbind();

    // Render the arrows.
    m_normalsArrowShader->bind();
    setMatrixUniforms(m_normalsArrowShader.get(), context);
    renderGeometryAsFilledPolygons();
    m_normalsArrowShader->unbind();
}

void PlanetScene::renderGeometry() {
    // TODO: [SHAPES] Render the shape. Lab 1 seems like it'll come in handy...
    if (m_planet) {
        m_planet->draw();
    }
}

void PlanetScene::clearLights() {
    for (int i = 0; i < MAX_NUM_LIGHTS; i++) {
        std::ostringstream os;
        os << i;
        std::string indexString = "[" + os.str() + "]"; // e.g. [0], [1], etc.
        m_phongShader->setUniform("lightColors" + indexString, glm::vec3(0.0f, 0.0f, 0.0f));
    }
}

void PlanetScene::setLights(const glm::mat4 viewMatrix) {
    // YOU DON'T NEED TO TOUCH THIS METHOD, unless you want to do fancy lighting...

    m_light.dir = glm::inverse(viewMatrix) * m_lightDirection;

    clearLights();
    m_phongShader->setLight(m_light);
}

void PlanetScene::settingsChanged() {
    // TODO: [SHAPES] Fill this in, for now default to an example shape
    m_planet = std::make_unique<Planet>(std::max(settings.resolution, 2), settings.noiseStrengthCont, settings.noiseRoughnessCont,
                                        glm::vec3({settings.noiseCenterXCont, settings.noiseCenterYCont, settings.noiseCenterZCont}),
                                        settings.noiseBaseRoughnessCont, settings.noiseNumLayersCont, settings.noisePersistenceCont,
                                        settings.noiseMinValueCont, settings.noiseStrengthMount, settings.noiseRoughnessMount,
                                        glm::vec3({settings.noiseCenterXMount, settings.noiseCenterYMount, settings.noiseCenterZMount}),
                                        settings.noiseBaseRoughnessMount, settings.noiseNumLayersMount, settings.noisePersistenceMount,
                                        settings.noiseMinValueMount, settings.continentsEnabled, settings.mountainsEnabled, settings.useContinentsAsMask);
    initializeSceneMaterial();
}

void PlanetScene::rotateModel(float angleInDegrees) {
    m_model = glm::rotate(m_model, glm::radians(angleInDegrees), glm::normalize(glm::vec3(0.5f, 1.f, 0.f)));
    m_phongShader->setUniform("m", m_model);
}

