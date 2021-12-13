#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Databinding.h"
#include "Canvas3D.h"
#include "CS123XmlSceneParser.h"
#include "scene/PlanetScene.h"
#include "CS123XmlSceneParser.h"
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Make sure the settings are loaded before the UI
    settings.loadSettingsOrDefaults();

    QGLFormat qglFormat;
    qglFormat.setVersion(4, 3);
    qglFormat.setProfile(QGLFormat::CoreProfile);
    qglFormat.setSampleBuffers(true);
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(ui->canvas3D);
    m_canvas3D = new Canvas3D(qglFormat, this);
    gridLayout->addWidget(m_canvas3D, 0, 1);


    // Restore the UI settings
    QSettings qtSettings("CS123", "CS123");
    restoreGeometry(qtSettings.value("geometry").toByteArray());
    restoreState(qtSettings.value("windowState").toByteArray());

    // Resize the window because the window is huge since all docks were visible.
    resize(1000, 600);

    // Bind the UI elements to their properties in the global Settings object, using binding
    // objects to simplify the code.  Each binding object connects to its UI elements and keeps
    // the UI and its setting in sync.

    QList<QAction*> actions;

#define SETUP_ACTION(dock, key) \
    actions.push_back(ui->dock->toggleViewAction()); \
    actions.back()->setShortcut(QKeySequence(key));

    SETUP_ACTION(shapesDock,    "CTRL+3");

    ui->menuToolbars->addActions(actions);
#undef SETUP_ACTION

    dataBind();

    // Reset the contents of both canvas widgets (make a new 500x500 image for the 2D one)
    fileNew();

    // Make certain radio buttons switch to the 2D canvas when clicked.
    QList<QRadioButton*> a;
    foreach (QRadioButton *rb, a)
        connect(rb, SIGNAL(clicked()), this, SLOT(activateCanvas2D()));

    a.clear();
    foreach (QRadioButton *rb, a)
        connect(rb, SIGNAL(clicked()), this, SLOT(activateCanvas3D()));

}

MainWindow::~MainWindow()
{
    foreach (DataBinding *b, m_bindings)
        delete b;
    foreach (QButtonGroup *bg, m_buttonGroups)
        delete bg;
    delete ui;
}

void MainWindow::dataBind() {
    // Brush dock
#define BIND(b) { \
    DataBinding *_b = (b); \
    m_bindings.push_back(_b); \
    assert(connect(_b, SIGNAL(dataChanged()), this, SLOT(settingsChanged()))); \
}
    QButtonGroup *brushButtonGroup = new QButtonGroup;
    QButtonGroup *shapesButtonGroup = new QButtonGroup;
    QButtonGroup *filterButtonGroup = new QButtonGroup;
    m_buttonGroups.push_back(brushButtonGroup);
    m_buttonGroups.push_back(shapesButtonGroup);
    m_buttonGroups.push_back(filterButtonGroup);

    // Shapes dock
    BIND(IntBinding::bindSliderAndTextbox(
        ui->resolutionSlider, ui->resolutionTextbox, settings.resolution, 1.f, 200.f))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->strengthSlider1, ui->strengthTextbox1, settings.noiseStrengthCont, 0.0f, 1.0f))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->baseRoughnessSlider1, ui->baseRoughnessTextbox1, settings.noiseBaseRoughnessCont, 0.0f, 5.0f))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->roughnessSlider1, ui->roughnessTextbox1, settings.noiseRoughnessCont, 0.0f, 5.0f))
    BIND(IntBinding::bindSliderAndTextbox(
         ui->numLayersSlider1, ui->numLayersTextbox1, settings.noiseNumLayersCont, 1, 8))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->persistenceSlider1, ui->persistenceTextbox1, settings.noisePersistenceCont, 0.f, 1.f))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->minValueSlider1, ui->minValueTextbox1, settings.noiseMinValueCont, 0.f, 2.f))
    BIND(FloatBinding::bindDial(ui->noiseCenterXDial1, settings.noiseCenterXCont, -5.f, 5.f, true))
    BIND(FloatBinding::bindDial(ui->noiseCenterYDial1, settings.noiseCenterYCont, -5.f, 5.f, true))
    BIND(FloatBinding::bindDial(ui->noiseCenterZDial1, settings.noiseCenterZCont, -5.f, 5.f, true))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->strengthSlider1_2, ui->strengthTextbox1_2, settings.noiseStrengthMount, 0.0f, 15.0f))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->baseRoughnessSlider1_2, ui->baseRoughnessTextbox1_2, settings.noiseBaseRoughnessMount, 0.0f, 5.0f))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->roughnessSlider1_2, ui->roughnessTextbox1_2, settings.noiseRoughnessMount, 0.0f, 5.0f))
    BIND(IntBinding::bindSliderAndTextbox(
         ui->numLayersSlider1_2, ui->numLayersTextbox1_2, settings.noiseNumLayersMount, 1, 8))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->persistenceSlider1_2, ui->persistenceTextbox1_2, settings.noisePersistenceMount, 0.f, 1.f))
    BIND(FloatBinding::bindSliderAndTextbox(
         ui->minValueSlider1_2, ui->minValueTextbox1_2, settings.noiseMinValueMount, 0.f, 2.f))
    BIND(FloatBinding::bindDial(ui->noiseCenterXDial1_2, settings.noiseCenterXMount, -5.f, 5.f, true))
    BIND(FloatBinding::bindDial(ui->noiseCenterYDial1_2, settings.noiseCenterYMount, -5.f, 5.f, true))
    BIND(FloatBinding::bindDial(ui->noiseCenterZDial1_2, settings.noiseCenterZMount, -5.f, 5.f, true))
    BIND(BoolBinding::bindCheckbox(ui->planetRotationCheckbox, settings.enableRotation));
    BIND(BoolBinding::bindCheckbox(ui->useLightingCheckbox, settings.useLighting))
    BIND(BoolBinding::bindCheckbox(ui->drawWireframeCheckbox, settings.drawWireframe))
    BIND(BoolBinding::bindCheckbox(ui->drawNormalsCheckbox, settings.drawNormals))
    BIND(BoolBinding::bindCheckbox(ui->continentsEnabled, settings.continentsEnabled))
    BIND(BoolBinding::bindCheckbox(ui->mountainsEnabled, settings.mountainsEnabled))
    BIND(BoolBinding::bindCheckbox(ui->continentMask, settings.useContinentsAsMask))

    BIND(ColorBinding::bindButtonAndTextboxes(ui->colorButton,
                                              ui->colorRedEdit,ui->colorGreenEdit,
                                              ui->colorBlueEdit, settings.planetColor));

#undef BIND

    // make sure the aspect ratio updates when m_canvas3D changes size
    connect(m_canvas3D, SIGNAL(aspectRatioChanged()), this, SLOT(updateAspectRatio()));
}

void MainWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e); // allow the superclass to handle this for the most part...

    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Save the settings before we quit
    settings.saveSettings();
    QSettings qtSettings("CS123", "CS123");
    qtSettings.setValue("geometry", saveGeometry());
    qtSettings.setValue("windowState", saveState());

    // Stop any raytracing, otherwise the thread will hang around until done
    QMainWindow::closeEvent(event);
}

void MainWindow::updateAspectRatio() {
    // Update the aspect ratio text so the aspect ratio will be correct even if the
    // 3D canvas isn't visible (the 3D canvas isn't resized when it isn't visible)
    QSize activeTabSize = m_canvas3D->size();
    float aspectRatio = static_cast<float>(activeTabSize.width()) / static_cast<float>(activeTabSize.height());
}


void MainWindow::settingsChanged() {
    m_canvas3D->settingsChanged();
}

void MainWindow::fileCopy3Dto2D() {
}

void MainWindow::fileNew() {
}

void MainWindow::fileOpen() {
}

void MainWindow::fileSave() {
}

void MainWindow::filterImage() {
    // Disable the UI so the user can't interfere with the filtering
    setAllEnabled(false);

    // Enable the UI again
    setAllEnabled(true);
}

void MainWindow::renderImage() {
}

void MainWindow::setAllEnabled(bool enabled) {
    QList<QWidget *> widgets;
    widgets += ui->shapesDock;

    QList<QAction *> actions;
    actions += ui->actionNew;
    actions += ui->actionOpen;
    actions += ui->actionSave;
    actions += ui->actionRevert;
    actions += ui->actionCopy3Dto2D;
    actions += ui->actionClear;
    actions += ui->actionQuit;

    foreach (QWidget *widget, widgets)
        widget->setEnabled(enabled);
    foreach (QAction *action, actions)
        action->setEnabled(enabled);
}

void MainWindow::activateCanvas2D() {
}

void MainWindow::activateCanvas3D() {
}

void MainWindow::clearImage()
{
}

void MainWindow::revertImage()
{
}

void MainWindow::resetSliders() {
    QCoreApplication::processEvents();
    update();
}
