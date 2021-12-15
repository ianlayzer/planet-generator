#include "CS123Shader.h"

#include "CS123SceneData.h"
#include "Settings.h"


#include "gl/GLDebug.h"
#include <sstream>

namespace CS123 { namespace GL {


CS123Shader::CS123Shader(const std::string &vertexSource, const std::string &fragmentSource) :
    Shader(vertexSource, fragmentSource)
{
}

CS123Shader::CS123Shader(const std::string &vertexSource, const std::string &geometrySource, const std::string &fragmentSource) :
    Shader(vertexSource, geometrySource, fragmentSource)
{
}

glm::vec3 toGLMVec3(const CS123SceneColor &c) {
    return glm::vec3(c.r, c.g, c.b);
}

void CS123Shader::applyMaterial(const CS123SceneMaterial &material) {
    setUniform("ambient_color", toGLMVec3(material.cAmbient));
    setUniform("diffuse_color", toGLMVec3(material.cDiffuse));
    setUniform("specular_color", toGLMVec3(material.cSpecular));
    setUniform("shininess", material.shininess);
}

void CS123Shader::setColor(const QColor &color) {
    glm::vec3 colorVec = glm::vec3(color.redF(), color.greenF(), color.blueF());
    setUniform("ambient_color", glm::vec3(0.2f, 0.1f, 0.f));
    setUniform("diffuse_color", colorVec);
    setUniform("specular_color", glm::vec3(0.1f, 0.1f, 0.1f));
    setUniform("shininess", 15);
}

void CS123Shader::applyColorSettings(const ColorSettings &colorSettings) {
    setUniform("ocean_color", makeColorVec(colorSettings.oceanColor));
    setUniform("shore_color", makeColorVec(colorSettings.shoreColor));
    setUniform("land_color", makeColorVec(colorSettings.landColor));
    setUniform("mountain_color", makeColorVec(colorSettings.mountainColor));
    setUniform("mountain_cap_color", makeColorVec(colorSettings.mountainCapColor));
    setUniform("smoothColors", colorSettings.smoothColors);
}

void CS123Shader::setLight(const CS123SceneLightData &light) {
    bool ignoreLight = false;

    GLint lightType;
    std::string name;
    glm::vec3 ndir;
    switch(light.type) {
        case LightType::LIGHT_POINT:
            lightType = 0;
            name = "lightPositions";
            setUniformArrayByIndex(name, light.pos.xyz(), light.id);
            break;
        case LightType::LIGHT_DIRECTIONAL:
            lightType = 1;
            ndir = glm::normalize(light.dir.xyz());
            name = "lightDirections";
            setUniformArrayByIndex(name, ndir, light.id);
            break;
        default:
            lightType = 0;
            ignoreLight = true; // Light type not supported
            break;
    }

    CS123SceneColor color = light.color;
    if (ignoreLight) color.r = color.g = color.b = 0;

    setUniformArrayByIndex("lightTypes", lightType, light.id);
    setUniformArrayByIndex("lightColors", glm::vec3(color.r, color.g, color.b), light.id);
//    setUniformArrayByIndex("lightAttenuations", light.function, light.id);
}

glm::vec3 CS123Shader::makeColorVec(QColor color) {
    return glm::vec3(color.redF(), color.greenF(), color.blueF());
}

}}
