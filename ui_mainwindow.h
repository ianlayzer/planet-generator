/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionRevert;
    QAction *actionCopy3Dto2D;
    QAction *actionClear;
    QAction *actionUseOrbitingCamera;
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QWidget *canvas3D;
    QDockWidget *shapesDock;
    QWidget *shapesDockContents;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *shapeParameters;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *colorLabel;
    QPushButton *colorButton;
    QLineEdit *colorRedEdit;
    QLineEdit *colorGreenEdit;
    QLineEdit *colorBlueEdit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *resolutionLabel;
    QSlider *resolutionSlider;
    QLineEdit *resolutionTextbox;
    QLabel *noiseLabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_17;
    QLabel *continentNoiseLabel;
    QCheckBox *continentsEnabled;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *strengthLabel1;
    QSlider *strengthSlider1;
    QLineEdit *strengthTextbox1;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *numLayersLabel1;
    QSlider *numLayersSlider1;
    QLineEdit *numLayersTextbox1;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *baseRoughnessLabel1;
    QSlider *baseRoughnessSlider1;
    QLineEdit *baseRoughnessTextbox1;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *roughnessLabel1;
    QSlider *roughnessSlider1;
    QLineEdit *roughnessTextbox1;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *persistenceLabel1;
    QSlider *persistenceSlider1;
    QLineEdit *persistenceTextbox1;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *minValueLabel1;
    QSlider *minValueSlider1;
    QLineEdit *minValueTextbox1;
    QSpacerItem *horizontalSpacer_5;
    QLabel *centerLabel1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *xLabel1;
    QDial *noiseCenterXDial1;
    QLabel *yLabel1;
    QDial *noiseCenterYDial1;
    QLabel *zLabel1;
    QDial *noiseCenterZDial1;
    QSpacerItem *horizontalSpacer_6;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_18;
    QLabel *continentNoiseLabel_2;
    QCheckBox *mountainsEnabled;
    QCheckBox *continentMask;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *strengthLabel1_2;
    QSlider *strengthSlider1_2;
    QLineEdit *strengthTextbox1_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *numLayersLabel1_2;
    QSlider *numLayersSlider1_2;
    QLineEdit *numLayersTextbox1_2;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *baseRoughnessLabel1_2;
    QSlider *baseRoughnessSlider1_2;
    QLineEdit *baseRoughnessTextbox1_2;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *roughnessLabel1_2;
    QSlider *roughnessSlider1_2;
    QLineEdit *roughnessTextbox1_2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_13;
    QLabel *persistenceLabel1_2;
    QSlider *persistenceSlider1_2;
    QLineEdit *persistenceTextbox1_2;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *minValueLabel1_2;
    QSlider *minValueSlider1_2;
    QLineEdit *minValueTextbox1_2;
    QSpacerItem *horizontalSpacer_12;
    QLabel *centerLabel1_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *xLabel1_2;
    QDial *noiseCenterXDial1_2;
    QLabel *yLabel1_2;
    QDial *noiseCenterYDial1_2;
    QLabel *zLabel1_2;
    QDial *noiseCenterZDial1_2;
    QSpacerItem *horizontalSpacer_14;
    QCheckBox *useLightingCheckbox;
    QCheckBox *drawWireframeCheckbox;
    QCheckBox *drawNormalsCheckbox;
    QWidget *shapesDockEmptySpace;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuToolbars;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 720);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::VerticalTabs);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName(QString::fromUtf8("actionRevert"));
        actionRevert->setEnabled(true);
        actionCopy3Dto2D = new QAction(MainWindow);
        actionCopy3Dto2D->setObjectName(QString::fromUtf8("actionCopy3Dto2D"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionUseOrbitingCamera = new QAction(MainWindow);
        actionUseOrbitingCamera->setObjectName(QString::fromUtf8("actionUseOrbitingCamera"));
        actionUseOrbitingCamera->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        canvas3D = new QWidget(centralWidget);
        canvas3D->setObjectName(QString::fromUtf8("canvas3D"));

        gridLayout_10->addWidget(canvas3D, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        shapesDock = new QDockWidget(MainWindow);
        shapesDock->setObjectName(QString::fromUtf8("shapesDock"));
        shapesDock->setMinimumSize(QSize(380, 798));
        shapesDockContents = new QWidget();
        shapesDockContents->setObjectName(QString::fromUtf8("shapesDockContents"));
        verticalLayout_7 = new QVBoxLayout(shapesDockContents);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        shapeParameters = new QGroupBox(shapesDockContents);
        shapeParameters->setObjectName(QString::fromUtf8("shapeParameters"));
        shapeParameters->setEnabled(true);
        shapeParameters->setMinimumSize(QSize(250, 0));
        gridLayout_4 = new QGridLayout(shapeParameters);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        colorLabel = new QLabel(shapeParameters);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

        horizontalLayout_9->addWidget(colorLabel);

        colorButton = new QPushButton(shapeParameters);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        horizontalLayout_9->addWidget(colorButton);

        colorRedEdit = new QLineEdit(shapeParameters);
        colorRedEdit->setObjectName(QString::fromUtf8("colorRedEdit"));

        horizontalLayout_9->addWidget(colorRedEdit);

        colorGreenEdit = new QLineEdit(shapeParameters);
        colorGreenEdit->setObjectName(QString::fromUtf8("colorGreenEdit"));

        horizontalLayout_9->addWidget(colorGreenEdit);

        colorBlueEdit = new QLineEdit(shapeParameters);
        colorBlueEdit->setObjectName(QString::fromUtf8("colorBlueEdit"));

        horizontalLayout_9->addWidget(colorBlueEdit);


        gridLayout_4->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        line = new QFrame(shapeParameters);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 3, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        resolutionLabel = new QLabel(shapeParameters);
        resolutionLabel->setObjectName(QString::fromUtf8("resolutionLabel"));

        horizontalLayout_2->addWidget(resolutionLabel);

        resolutionSlider = new QSlider(shapeParameters);
        resolutionSlider->setObjectName(QString::fromUtf8("resolutionSlider"));
        resolutionSlider->setMinimumSize(QSize(100, 0));
        resolutionSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(resolutionSlider);

        resolutionTextbox = new QLineEdit(shapeParameters);
        resolutionTextbox->setObjectName(QString::fromUtf8("resolutionTextbox"));
        resolutionTextbox->setMinimumSize(QSize(40, 0));
        resolutionTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(resolutionTextbox);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        noiseLabel = new QLabel(shapeParameters);
        noiseLabel->setObjectName(QString::fromUtf8("noiseLabel"));

        gridLayout_4->addWidget(noiseLabel, 4, 0, 1, 1);

        tabWidget = new QTabWidget(shapeParameters);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(250, 500));
        tabWidget->setUsesScrollButtons(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMinimumSize(QSize(300, 0));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 503, 430));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        continentNoiseLabel = new QLabel(verticalLayoutWidget);
        continentNoiseLabel->setObjectName(QString::fromUtf8("continentNoiseLabel"));
        continentNoiseLabel->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_17->addWidget(continentNoiseLabel);

        continentsEnabled = new QCheckBox(verticalLayoutWidget);
        continentsEnabled->setObjectName(QString::fromUtf8("continentsEnabled"));

        horizontalLayout_17->addWidget(continentsEnabled);


        verticalLayout->addLayout(horizontalLayout_17);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        strengthLabel1 = new QLabel(verticalLayoutWidget);
        strengthLabel1->setObjectName(QString::fromUtf8("strengthLabel1"));
        strengthLabel1->setMinimumSize(QSize(40, 0));

        horizontalLayout->addWidget(strengthLabel1);

        strengthSlider1 = new QSlider(verticalLayoutWidget);
        strengthSlider1->setObjectName(QString::fromUtf8("strengthSlider1"));
        strengthSlider1->setMinimumSize(QSize(100, 0));
        strengthSlider1->setMaximumSize(QSize(100, 16777215));
        strengthSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(strengthSlider1);

        strengthTextbox1 = new QLineEdit(verticalLayoutWidget);
        strengthTextbox1->setObjectName(QString::fromUtf8("strengthTextbox1"));
        strengthTextbox1->setMinimumSize(QSize(40, 0));
        strengthTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(strengthTextbox1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        numLayersLabel1 = new QLabel(verticalLayoutWidget);
        numLayersLabel1->setObjectName(QString::fromUtf8("numLayersLabel1"));
        numLayersLabel1->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(numLayersLabel1);

        numLayersSlider1 = new QSlider(verticalLayoutWidget);
        numLayersSlider1->setObjectName(QString::fromUtf8("numLayersSlider1"));
        numLayersSlider1->setMaximumSize(QSize(100, 16777215));
        numLayersSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(numLayersSlider1);

        numLayersTextbox1 = new QLineEdit(verticalLayoutWidget);
        numLayersTextbox1->setObjectName(QString::fromUtf8("numLayersTextbox1"));
        numLayersTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(numLayersTextbox1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        baseRoughnessLabel1 = new QLabel(verticalLayoutWidget);
        baseRoughnessLabel1->setObjectName(QString::fromUtf8("baseRoughnessLabel1"));
        baseRoughnessLabel1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(baseRoughnessLabel1);

        baseRoughnessSlider1 = new QSlider(verticalLayoutWidget);
        baseRoughnessSlider1->setObjectName(QString::fromUtf8("baseRoughnessSlider1"));
        baseRoughnessSlider1->setMaximumSize(QSize(100, 16777215));
        baseRoughnessSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(baseRoughnessSlider1);

        baseRoughnessTextbox1 = new QLineEdit(verticalLayoutWidget);
        baseRoughnessTextbox1->setObjectName(QString::fromUtf8("baseRoughnessTextbox1"));
        baseRoughnessTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(baseRoughnessTextbox1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        roughnessLabel1 = new QLabel(verticalLayoutWidget);
        roughnessLabel1->setObjectName(QString::fromUtf8("roughnessLabel1"));

        horizontalLayout_3->addWidget(roughnessLabel1);

        roughnessSlider1 = new QSlider(verticalLayoutWidget);
        roughnessSlider1->setObjectName(QString::fromUtf8("roughnessSlider1"));
        roughnessSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(roughnessSlider1);

        roughnessTextbox1 = new QLineEdit(verticalLayoutWidget);
        roughnessTextbox1->setObjectName(QString::fromUtf8("roughnessTextbox1"));
        roughnessTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(roughnessTextbox1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        persistenceLabel1 = new QLabel(verticalLayoutWidget);
        persistenceLabel1->setObjectName(QString::fromUtf8("persistenceLabel1"));
        persistenceLabel1->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_7->addWidget(persistenceLabel1);

        persistenceSlider1 = new QSlider(verticalLayoutWidget);
        persistenceSlider1->setObjectName(QString::fromUtf8("persistenceSlider1"));
        persistenceSlider1->setMaximumSize(QSize(100, 16777215));
        persistenceSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(persistenceSlider1);

        persistenceTextbox1 = new QLineEdit(verticalLayoutWidget);
        persistenceTextbox1->setObjectName(QString::fromUtf8("persistenceTextbox1"));
        persistenceTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_7->addWidget(persistenceTextbox1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        minValueLabel1 = new QLabel(verticalLayoutWidget);
        minValueLabel1->setObjectName(QString::fromUtf8("minValueLabel1"));
        minValueLabel1->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(minValueLabel1);

        minValueSlider1 = new QSlider(verticalLayoutWidget);
        minValueSlider1->setObjectName(QString::fromUtf8("minValueSlider1"));
        minValueSlider1->setMaximumSize(QSize(100, 16777215));
        minValueSlider1->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(minValueSlider1);

        minValueTextbox1 = new QLineEdit(verticalLayoutWidget);
        minValueTextbox1->setObjectName(QString::fromUtf8("minValueTextbox1"));
        minValueTextbox1->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_8->addWidget(minValueTextbox1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_8);

        centerLabel1 = new QLabel(verticalLayoutWidget);
        centerLabel1->setObjectName(QString::fromUtf8("centerLabel1"));
        centerLabel1->setMaximumSize(QSize(16777215, 10));

        verticalLayout->addWidget(centerLabel1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        xLabel1 = new QLabel(verticalLayoutWidget);
        xLabel1->setObjectName(QString::fromUtf8("xLabel1"));
        xLabel1->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(xLabel1);

        noiseCenterXDial1 = new QDial(verticalLayoutWidget);
        noiseCenterXDial1->setObjectName(QString::fromUtf8("noiseCenterXDial1"));
        noiseCenterXDial1->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(noiseCenterXDial1);

        yLabel1 = new QLabel(verticalLayoutWidget);
        yLabel1->setObjectName(QString::fromUtf8("yLabel1"));
        yLabel1->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(yLabel1);

        noiseCenterYDial1 = new QDial(verticalLayoutWidget);
        noiseCenterYDial1->setObjectName(QString::fromUtf8("noiseCenterYDial1"));
        noiseCenterYDial1->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(noiseCenterYDial1);

        zLabel1 = new QLabel(verticalLayoutWidget);
        zLabel1->setObjectName(QString::fromUtf8("zLabel1"));
        zLabel1->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(zLabel1);

        noiseCenterZDial1 = new QDial(verticalLayoutWidget);
        noiseCenterZDial1->setObjectName(QString::fromUtf8("noiseCenterZDial1"));
        noiseCenterZDial1->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(noiseCenterZDial1);

        horizontalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 506, 430));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        continentNoiseLabel_2 = new QLabel(verticalLayoutWidget_2);
        continentNoiseLabel_2->setObjectName(QString::fromUtf8("continentNoiseLabel_2"));
        continentNoiseLabel_2->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_18->addWidget(continentNoiseLabel_2);

        mountainsEnabled = new QCheckBox(verticalLayoutWidget_2);
        mountainsEnabled->setObjectName(QString::fromUtf8("mountainsEnabled"));
        mountainsEnabled->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_18->addWidget(mountainsEnabled);


        verticalLayout_3->addLayout(horizontalLayout_18);

        continentMask = new QCheckBox(verticalLayoutWidget_2);
        continentMask->setObjectName(QString::fromUtf8("continentMask"));

        verticalLayout_3->addWidget(continentMask);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        strengthLabel1_2 = new QLabel(verticalLayoutWidget_2);
        strengthLabel1_2->setObjectName(QString::fromUtf8("strengthLabel1_2"));
        strengthLabel1_2->setMinimumSize(QSize(40, 0));

        horizontalLayout_10->addWidget(strengthLabel1_2);

        strengthSlider1_2 = new QSlider(verticalLayoutWidget_2);
        strengthSlider1_2->setObjectName(QString::fromUtf8("strengthSlider1_2"));
        strengthSlider1_2->setMinimumSize(QSize(100, 0));
        strengthSlider1_2->setMaximumSize(QSize(100, 16777215));
        strengthSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(strengthSlider1_2);

        strengthTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        strengthTextbox1_2->setObjectName(QString::fromUtf8("strengthTextbox1_2"));
        strengthTextbox1_2->setMinimumSize(QSize(40, 0));
        strengthTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_10->addWidget(strengthTextbox1_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        numLayersLabel1_2 = new QLabel(verticalLayoutWidget_2);
        numLayersLabel1_2->setObjectName(QString::fromUtf8("numLayersLabel1_2"));
        numLayersLabel1_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(numLayersLabel1_2);

        numLayersSlider1_2 = new QSlider(verticalLayoutWidget_2);
        numLayersSlider1_2->setObjectName(QString::fromUtf8("numLayersSlider1_2"));
        numLayersSlider1_2->setMaximumSize(QSize(100, 16777215));
        numLayersSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(numLayersSlider1_2);

        numLayersTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        numLayersTextbox1_2->setObjectName(QString::fromUtf8("numLayersTextbox1_2"));
        numLayersTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_12->addWidget(numLayersTextbox1_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        baseRoughnessLabel1_2 = new QLabel(verticalLayoutWidget_2);
        baseRoughnessLabel1_2->setObjectName(QString::fromUtf8("baseRoughnessLabel1_2"));
        baseRoughnessLabel1_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_11->addWidget(baseRoughnessLabel1_2);

        baseRoughnessSlider1_2 = new QSlider(verticalLayoutWidget_2);
        baseRoughnessSlider1_2->setObjectName(QString::fromUtf8("baseRoughnessSlider1_2"));
        baseRoughnessSlider1_2->setMaximumSize(QSize(100, 16777215));
        baseRoughnessSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(baseRoughnessSlider1_2);

        baseRoughnessTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        baseRoughnessTextbox1_2->setObjectName(QString::fromUtf8("baseRoughnessTextbox1_2"));
        baseRoughnessTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_11->addWidget(baseRoughnessTextbox1_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        roughnessLabel1_2 = new QLabel(verticalLayoutWidget_2);
        roughnessLabel1_2->setObjectName(QString::fromUtf8("roughnessLabel1_2"));

        horizontalLayout_15->addWidget(roughnessLabel1_2);

        roughnessSlider1_2 = new QSlider(verticalLayoutWidget_2);
        roughnessSlider1_2->setObjectName(QString::fromUtf8("roughnessSlider1_2"));
        roughnessSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_15->addWidget(roughnessSlider1_2);

        roughnessTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        roughnessTextbox1_2->setObjectName(QString::fromUtf8("roughnessTextbox1_2"));
        roughnessTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_15->addWidget(roughnessTextbox1_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        persistenceLabel1_2 = new QLabel(verticalLayoutWidget_2);
        persistenceLabel1_2->setObjectName(QString::fromUtf8("persistenceLabel1_2"));
        persistenceLabel1_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_13->addWidget(persistenceLabel1_2);

        persistenceSlider1_2 = new QSlider(verticalLayoutWidget_2);
        persistenceSlider1_2->setObjectName(QString::fromUtf8("persistenceSlider1_2"));
        persistenceSlider1_2->setMaximumSize(QSize(100, 16777215));
        persistenceSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(persistenceSlider1_2);

        persistenceTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        persistenceTextbox1_2->setObjectName(QString::fromUtf8("persistenceTextbox1_2"));
        persistenceTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_13->addWidget(persistenceTextbox1_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_11);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        minValueLabel1_2 = new QLabel(verticalLayoutWidget_2);
        minValueLabel1_2->setObjectName(QString::fromUtf8("minValueLabel1_2"));
        minValueLabel1_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_14->addWidget(minValueLabel1_2);

        minValueSlider1_2 = new QSlider(verticalLayoutWidget_2);
        minValueSlider1_2->setObjectName(QString::fromUtf8("minValueSlider1_2"));
        minValueSlider1_2->setMaximumSize(QSize(100, 16777215));
        minValueSlider1_2->setOrientation(Qt::Horizontal);

        horizontalLayout_14->addWidget(minValueSlider1_2);

        minValueTextbox1_2 = new QLineEdit(verticalLayoutWidget_2);
        minValueTextbox1_2->setObjectName(QString::fromUtf8("minValueTextbox1_2"));
        minValueTextbox1_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_14->addWidget(minValueTextbox1_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_14);

        centerLabel1_2 = new QLabel(verticalLayoutWidget_2);
        centerLabel1_2->setObjectName(QString::fromUtf8("centerLabel1_2"));
        centerLabel1_2->setMaximumSize(QSize(16777215, 10));

        verticalLayout_3->addWidget(centerLabel1_2);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, 0, -1, -1);
        xLabel1_2 = new QLabel(verticalLayoutWidget_2);
        xLabel1_2->setObjectName(QString::fromUtf8("xLabel1_2"));
        xLabel1_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_16->addWidget(xLabel1_2);

        noiseCenterXDial1_2 = new QDial(verticalLayoutWidget_2);
        noiseCenterXDial1_2->setObjectName(QString::fromUtf8("noiseCenterXDial1_2"));
        noiseCenterXDial1_2->setMaximumSize(QSize(50, 50));

        horizontalLayout_16->addWidget(noiseCenterXDial1_2);

        yLabel1_2 = new QLabel(verticalLayoutWidget_2);
        yLabel1_2->setObjectName(QString::fromUtf8("yLabel1_2"));
        yLabel1_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_16->addWidget(yLabel1_2);

        noiseCenterYDial1_2 = new QDial(verticalLayoutWidget_2);
        noiseCenterYDial1_2->setObjectName(QString::fromUtf8("noiseCenterYDial1_2"));
        noiseCenterYDial1_2->setMaximumSize(QSize(50, 50));

        horizontalLayout_16->addWidget(noiseCenterYDial1_2);

        zLabel1_2 = new QLabel(verticalLayoutWidget_2);
        zLabel1_2->setObjectName(QString::fromUtf8("zLabel1_2"));
        zLabel1_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_16->addWidget(zLabel1_2);

        noiseCenterZDial1_2 = new QDial(verticalLayoutWidget_2);
        noiseCenterZDial1_2->setObjectName(QString::fromUtf8("noiseCenterZDial1_2"));
        noiseCenterZDial1_2->setMaximumSize(QSize(50, 50));

        horizontalLayout_16->addWidget(noiseCenterZDial1_2);

        horizontalSpacer_14 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_14);


        verticalLayout_3->addLayout(horizontalLayout_16);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 7, 0, 1, 1);


        verticalLayout_7->addWidget(shapeParameters);

        useLightingCheckbox = new QCheckBox(shapesDockContents);
        useLightingCheckbox->setObjectName(QString::fromUtf8("useLightingCheckbox"));

        verticalLayout_7->addWidget(useLightingCheckbox);

        drawWireframeCheckbox = new QCheckBox(shapesDockContents);
        drawWireframeCheckbox->setObjectName(QString::fromUtf8("drawWireframeCheckbox"));

        verticalLayout_7->addWidget(drawWireframeCheckbox);

        drawNormalsCheckbox = new QCheckBox(shapesDockContents);
        drawNormalsCheckbox->setObjectName(QString::fromUtf8("drawNormalsCheckbox"));

        verticalLayout_7->addWidget(drawNormalsCheckbox);

        shapesDockEmptySpace = new QWidget(shapesDockContents);
        shapesDockEmptySpace->setObjectName(QString::fromUtf8("shapesDockEmptySpace"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shapesDockEmptySpace->sizePolicy().hasHeightForWidth());
        shapesDockEmptySpace->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(shapesDockEmptySpace);

        shapesDock->setWidget(shapesDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, shapesDock);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuToolbars = new QMenu(menuBar);
        menuToolbars->setObjectName(QString::fromUtf8("menuToolbars"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuToolbars->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(fileSave()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(fileOpen()));
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(fileNew()));
        QObject::connect(actionCopy3Dto2D, SIGNAL(triggered()), MainWindow, SLOT(fileCopy3Dto2D()));
        QObject::connect(actionClear, SIGNAL(triggered()), MainWindow, SLOT(clearImage()));
        QObject::connect(actionRevert, SIGNAL(triggered()), MainWindow, SLOT(revertImage()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Planet Generator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRevert->setText(QCoreApplication::translate("MainWindow", "&Revert Image", nullptr));
#if QT_CONFIG(shortcut)
        actionRevert->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy3Dto2D->setText(QCoreApplication::translate("MainWindow", "Copy &3D tab to 2D tab", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "&Clear Image", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear Image", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUseOrbitingCamera->setText(QCoreApplication::translate("MainWindow", "&Use Orbiting Camera", nullptr));
#if QT_CONFIG(shortcut)
        actionUseOrbitingCamera->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        shapesDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Planet Properties", nullptr));
        shapeParameters->setTitle(QCoreApplication::translate("MainWindow", "Planet Parameters", nullptr));
        colorLabel->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        colorButton->setText(QString());
        resolutionLabel->setText(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
        noiseLabel->setText(QCoreApplication::translate("MainWindow", "Noise", nullptr));
        continentNoiseLabel->setText(QCoreApplication::translate("MainWindow", "Noise Layer 1 (Continents)", nullptr));
        continentsEnabled->setText(QCoreApplication::translate("MainWindow", "Enabled", nullptr));
        strengthLabel1->setText(QCoreApplication::translate("MainWindow", "Strength", nullptr));
        strengthTextbox1->setText(QString());
        numLayersLabel1->setText(QCoreApplication::translate("MainWindow", "Num Layers", nullptr));
        baseRoughnessLabel1->setText(QCoreApplication::translate("MainWindow", "Base Roughness", nullptr));
        roughnessLabel1->setText(QCoreApplication::translate("MainWindow", "Roughness", nullptr));
        persistenceLabel1->setText(QCoreApplication::translate("MainWindow", "Persistence", nullptr));
        minValueLabel1->setText(QCoreApplication::translate("MainWindow", "Min Value", nullptr));
        centerLabel1->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        xLabel1->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        yLabel1->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        zLabel1->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Continents", nullptr));
        continentNoiseLabel_2->setText(QCoreApplication::translate("MainWindow", "Noise Layer 2 (Mountains)", nullptr));
        mountainsEnabled->setText(QCoreApplication::translate("MainWindow", "Enabled", nullptr));
        continentMask->setText(QCoreApplication::translate("MainWindow", "Use Continents as Mask", nullptr));
        strengthLabel1_2->setText(QCoreApplication::translate("MainWindow", "Strength", nullptr));
        strengthTextbox1_2->setText(QString());
        numLayersLabel1_2->setText(QCoreApplication::translate("MainWindow", "Num Layers", nullptr));
        baseRoughnessLabel1_2->setText(QCoreApplication::translate("MainWindow", "Base Roughness", nullptr));
        roughnessLabel1_2->setText(QCoreApplication::translate("MainWindow", "Roughness", nullptr));
        persistenceLabel1_2->setText(QCoreApplication::translate("MainWindow", "Persistence", nullptr));
        minValueLabel1_2->setText(QCoreApplication::translate("MainWindow", "Min Value", nullptr));
        centerLabel1_2->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        xLabel1_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        yLabel1_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        zLabel1_2->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Mountains", nullptr));
        useLightingCheckbox->setText(QCoreApplication::translate("MainWindow", "Use lighting", nullptr));
        drawWireframeCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw wireframe", nullptr));
        drawNormalsCheckbox->setText(QCoreApplication::translate("MainWindow", "Draw normals", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuToolbars->setTitle(QCoreApplication::translate("MainWindow", "&Toolbars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
