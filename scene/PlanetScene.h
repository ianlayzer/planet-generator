#ifndef PLANETSCENE_H
#define PLANETSCENE_H

#include "OpenGLScene.h"

#include <memory>

#include <GL/glew.h>

#include "gl/datatype/FBO.h"
#include "Settings.h"
#include "planet/Planet.h"

namespace CS123 { namespace GL {

    class Shader;
    class CS123Shader;
    class FullScreenQuad;

}}

class OpenGLShape;

/**
 *
 * @class ShapesScene
 *
 * A scene that is used to render a single shape.
 *
 * This scene has no notion of the scene graph, so it will not be useful to you in
 * assignments requiring the display of multiple shapes. Luckily, the first time you
 * will need that kind of functionality is in the Sceneview assignment... and we've
 * left that task up to you in the SceneviewScene class.
 *
 * By default, the ShapesScene displays only a single triangle. You'll need to do
 * a little work here to render your shapes. You could render the shapes directly
 * in this class, or you could pass the work on to one or more subclasses. Think
 * carefully about your design here - you'll be reusing your shapes multiple times
 * during this course!
 */
class PlanetScene : public OpenGLScene {
public:
    PlanetScene(int width, int height);
    virtual ~PlanetScene();

    virtual void render(Canvas3D *context) override;
    virtual void settingsChanged() override;
    void rotateModel(float angleInDegrees);

protected:
    // Set the light uniforms for the lights in the scene. (The view matrix is used so that the
    // light can follows the camera.)
    virtual void setLights(CS123::GL::CS123Shader *shader, const glm::mat4 viewMatrix);

    // Render geometry for Shapes and Sceneview.
    virtual void renderGeometry();

private:
    // Storage for private copies of the scene's light and material data. Note that these don't
    // need to be freed because they are VALUE types (not pointers) and the memory for them is
    // freed when the class itself is freed.
    std::unique_ptr<CS123::GL::CS123Shader> m_phongShader;
    std::unique_ptr<CS123::GL::CS123Shader> m_planetShader;
    std::unique_ptr<CS123::GL::Shader> m_wireframeShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsArrowShader;
    std::unique_ptr<CS123::GL::Shader> m_fsqShader;
    CS123SceneLightData  m_light;
    CS123SceneMaterial   m_material;

    glm::vec4 m_lightDirection = glm::normalize(glm::vec4(1.f, -1.f, -1.f, 0.f));

    std::unique_ptr<Planet> m_planet;

    int m_width;
    int m_height;

    glm::mat4 m_model;

    void clearLights(CS123::GL::CS123Shader *shader);
    void loadPhongShader();
    void loadPlanetShader();
    void loadWireframeShader();
    void loadNormalsShader();
    void loadNormalsArrowShader();
    void renderPhongPass(Canvas3D *context);
    void renderPlanetPass(Canvas3D *context);
    void renderGeometryAsFilledPolygons();
    void renderWireframePass(Canvas3D *context);
    void renderGeometryAsWireframe();
    void renderNormalsPass(Canvas3D *context);
    void initializeSceneMaterial();
    void initializeSceneLight();
    void setPhongSceneUniforms();
    void setMatrixUniforms(CS123::GL::Shader *shader, Canvas3D *context);
    void renderFilledPolygons();
    void renderNormals();
    void renderWireframe();
    void setSceneUniforms(Canvas3D *context);
};

#endif // PLANETSCENE_H
