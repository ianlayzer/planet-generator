#include "Canvas3D.h"

#include <QFileDialog>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>

#include "RGBA.h"
#include "OrbitingCamera.h"
#include "Settings.h"
#include "scene/PlanetScene.h"

#include <iostream>
#include "gl/GLDebug.h"
#include "CS123XmlSceneParser.h"

Canvas3D::Canvas3D(QGLFormat format, QWidget *parent) : QGLWidget(format, parent),
    m_isDragging(false),
    m_settingsDirty(true),
    m_defaultOrbitingCamera(new OrbitingCamera()),
    m_currentScene(nullptr)
{
    m_timer = std::make_unique<QTimer>(this);
    connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(handleRotation()));
}

Canvas3D::~Canvas3D()
{
}

Camera *Canvas3D::getCamera() {
    return m_defaultOrbitingCamera.get();
}

OrbitingCamera *Canvas3D::getOrbitingCamera() {
    return m_defaultOrbitingCamera.get();
}

void Canvas3D::initializeGL() {
    // Track the camera settings so we can generate deltas
    m_oldPosX = settings.cameraPosX;
    m_oldPosY = settings.cameraPosY;
    m_oldPosZ = settings.cameraPosZ;
    m_oldRotU = settings.cameraRotU;
    m_oldRotV = settings.cameraRotV;
    m_oldRotN = settings.cameraRotN;

    initializeGlew();

    initializeOpenGLSettings();
    initializeScenes();
    setSceneFromSettings();

    settingsChanged();

}

void Canvas3D::initializeGlew() {
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    glGetError(); // Clear errors after call to glewInit
    if (GLEW_OK != err) {
      // Problem: glewInit failed, something is seriously wrong.
      fprintf(stderr, "Error initializing glew: %s\n", glewGetErrorString(err));
    }
}

void Canvas3D::initializeOpenGLSettings() {
    // Enable depth testing, so that objects are occluded based on depth instead of drawing order.
    glEnable(GL_DEPTH_TEST);

    // Move the polygons back a bit so lines are still drawn even though they are coplanar with the
    // polygons they came from, which will be drawn before them.
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1, -1);

    // Enable back-face culling, meaning only the front side of every face is rendered.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Specify that the front face is represented by vertices in counterclockwise order (this is
    // the default).
    glFrontFace(GL_CCW);

    // Calculate the orbiting camera matrices.
    getOrbitingCamera()->updateMatrices();
}

void Canvas3D::initializeScenes() {
    m_planetScene = std::make_unique<PlanetScene>(width(), height());
}

void Canvas3D::paintGL() {
    if (m_settingsDirty) {
        setSceneFromSettings();
    }
    float ratio = static_cast<QGuiApplication *>(QCoreApplication::instance())->devicePixelRatio();
    glViewport(0, 0, width() * ratio, height() * ratio);
    getCamera()->setAspectRatio(static_cast<float>(width()) / static_cast<float>(height()));
    m_currentScene->render(this);
}

void Canvas3D::settingsChanged() {
    m_settingsDirty = true;
    if (m_currentScene != nullptr) {
        // Just calling this function so that the scene is always updated.
        setSceneFromSettings();
        m_currentScene->settingsChanged();
    }
    if (m_timer->isActive() && !settings.enableRotation) {
        m_timer->stop();
    }
    if (!m_timer->isActive() && settings.enableRotation) {
        m_timer->start(1000.0f/30.0f);
    }
    update(); /* repaint the scene */
}

void Canvas3D::setSceneFromSettings() {
    switch(settings.getSceneMode()) {
        case SCENEMODE_SHAPES:
            setSceneToShapes();
            break;
        case SCENEMODE_SCENEVIEW:
            setSceneToSceneview();
            break;
    }
    m_settingsDirty = false;
}

void Canvas3D::loadSceneviewSceneFromParser(CS123XmlSceneParser &parser) {
}

void Canvas3D::setSceneToSceneview() {
}

void Canvas3D::setSceneToShapes() {
    assert(m_planetScene.get());
    m_currentScene = m_planetScene.get();
}

void Canvas3D::copyPixels(int width, int height, RGBA *data) {
    glReadPixels(0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, data);
    std::cout << "copied " << width << "x" << height << std::endl;

    // Flip the image and since OpenGL uses an origin in the lower left and we an origin in the
    // upper left.
    for (int y = 0; y < (height + 1) / 2; y++)
        for (int x = 0; x < width; x++)
            std::swap(data[x + y * width], data[x + (height - y - 1) * width]);
}

void Canvas3D::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        getCamera()->mouseDown(event->x(), event->y());
        m_isDragging = true;
        update();
    }
}

void Canvas3D::mouseMoveEvent(QMouseEvent *event) {
    if (m_isDragging) {
        getCamera()->mouseDragged(event->x(), event->y());
        update();
    }
}

void Canvas3D::mouseReleaseEvent(QMouseEvent *event) {
    if (m_isDragging && event->button() == Qt::RightButton) {
        getCamera()->mouseUp(event->x(), event->y());
        m_isDragging = false;
        update();
    }
}

void Canvas3D::wheelEvent(QWheelEvent *event) {
    getCamera()->mouseScrolled(event->delta());
    update();
}

void Canvas3D::resizeEvent(QResizeEvent *event) {
    emit aspectRatioChanged();
}

void Canvas3D::handleRotation() {
    m_planetScene->rotateModel(0.1);
    update();
}
