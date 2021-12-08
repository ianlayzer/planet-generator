#ifndef CS123SHADER_H
#define CS123SHADER_H

#include "Shader.h"
#include <QColor>

class CS123SceneMaterial;
class CS123SceneLightData;

namespace CS123 { namespace GL {

class CS123Shader : public Shader {
public:
    CS123Shader(const std::string &vertexSource, const std::string &fragmentSource);
    CS123Shader(const std::string &vertexSource, const std::string &geometrySource, const std::string &fragmentSource);

    void applyMaterial(const CS123SceneMaterial &material);
    void setColor(const QColor &color);
    void setLight(const CS123SceneLightData &light);
};

}}

#endif // CS123SHADER_H
