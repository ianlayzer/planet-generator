#ifndef CS123SHADER_H
#define CS123SHADER_H

#include "Shader.h"
#include <QColor>
#include "planet/PlanetSettings.h"

class CS123SceneMaterial;
class CS123SceneLightData;

namespace CS123 { namespace GL {

class CS123Shader : public Shader {
public:
    CS123Shader(const std::string &vertexSource, const std::string &fragmentSource);
    CS123Shader(const std::string &vertexSource, const std::string &geometrySource, const std::string &fragmentSource);

    void applyMaterial(const CS123SceneMaterial &material);
    void setColor(const QColor &color);
    void applyColorSettings(const ColorSettings &colorSettings);
    void setLight(const CS123SceneLightData &light);
private:
    glm::vec3 makeColorVec(QColor color);
};

}}

#endif // CS123SHADER_H
