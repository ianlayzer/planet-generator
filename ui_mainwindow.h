/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *baseRoughnessLabel;
    QSlider *baseRoughnessSlider;
    QLineEdit *baseRoughnessTextbox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *roughnessLabel;
    QSlider *roughnessSlider;
    QLineEdit *roughnessTextbox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *minValueLabel;
    QSlider *minValueSlider;
    QLineEdit *minValueTextbox;
    QLabel *noiseLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *strengthLabel;
    QSlider *strengthSlider;
    QLineEdit *strengthTextbox;
    QLabel *centerLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *resolutionLabel;
    QSlider *resolutionSlider;
    QLineEdit *resolutionTextbox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *numLayersLabel;
    QSlider *numLayersSlider;
    QLineEdit *numLayersTextbox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *xLabel;
    QDial *noiseCenterXDial;
    QLabel *yLabel;
    QDial *noiseCenterYDial;
    QLabel *zLabel;
    QDial *noiseCenterZDial;
    QHBoxLayout *horizontalLayout_7;
    QLabel *persistenceLabel;
    QSlider *persistenceSlider;
    QLineEdit *persistenceTextbox;
    QFrame *line;
    QHBoxLayout *horizontalLayout_9;
    QLabel *colorLabel;
    QPushButton *colorButton;
    QLineEdit *colorRedEdit;
    QLineEdit *colorGreenEdit;
    QLineEdit *colorBlueEdit;
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
        MainWindow->resize(600, 524);
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
        shapesDockContents = new QWidget();
        shapesDockContents->setObjectName(QString::fromUtf8("shapesDockContents"));
        verticalLayout_7 = new QVBoxLayout(shapesDockContents);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        shapeParameters = new QGroupBox(shapesDockContents);
        shapeParameters->setObjectName(QString::fromUtf8("shapeParameters"));
        gridLayout_4 = new QGridLayout(shapeParameters);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        baseRoughnessLabel = new QLabel(shapeParameters);
        baseRoughnessLabel->setObjectName(QString::fromUtf8("baseRoughnessLabel"));

        horizontalLayout_5->addWidget(baseRoughnessLabel);

        baseRoughnessSlider = new QSlider(shapeParameters);
        baseRoughnessSlider->setObjectName(QString::fromUtf8("baseRoughnessSlider"));
        baseRoughnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(baseRoughnessSlider);

        baseRoughnessTextbox = new QLineEdit(shapeParameters);
        baseRoughnessTextbox->setObjectName(QString::fromUtf8("baseRoughnessTextbox"));
        baseRoughnessTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(baseRoughnessTextbox);


        gridLayout_4->addLayout(horizontalLayout_5, 7, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        roughnessLabel = new QLabel(shapeParameters);
        roughnessLabel->setObjectName(QString::fromUtf8("roughnessLabel"));

        horizontalLayout_3->addWidget(roughnessLabel);

        roughnessSlider = new QSlider(shapeParameters);
        roughnessSlider->setObjectName(QString::fromUtf8("roughnessSlider"));
        roughnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(roughnessSlider);

        roughnessTextbox = new QLineEdit(shapeParameters);
        roughnessTextbox->setObjectName(QString::fromUtf8("roughnessTextbox"));
        roughnessTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(roughnessTextbox);


        gridLayout_4->addLayout(horizontalLayout_3, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        minValueLabel = new QLabel(shapeParameters);
        minValueLabel->setObjectName(QString::fromUtf8("minValueLabel"));

        horizontalLayout_8->addWidget(minValueLabel);

        minValueSlider = new QSlider(shapeParameters);
        minValueSlider->setObjectName(QString::fromUtf8("minValueSlider"));
        minValueSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(minValueSlider);

        minValueTextbox = new QLineEdit(shapeParameters);
        minValueTextbox->setObjectName(QString::fromUtf8("minValueTextbox"));
        minValueTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_8->addWidget(minValueTextbox);


        gridLayout_4->addLayout(horizontalLayout_8, 10, 0, 1, 1);

        noiseLabel = new QLabel(shapeParameters);
        noiseLabel->setObjectName(QString::fromUtf8("noiseLabel"));

        gridLayout_4->addWidget(noiseLabel, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        strengthLabel = new QLabel(shapeParameters);
        strengthLabel->setObjectName(QString::fromUtf8("strengthLabel"));

        horizontalLayout->addWidget(strengthLabel);

        strengthSlider = new QSlider(shapeParameters);
        strengthSlider->setObjectName(QString::fromUtf8("strengthSlider"));
        strengthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(strengthSlider);

        strengthTextbox = new QLineEdit(shapeParameters);
        strengthTextbox->setObjectName(QString::fromUtf8("strengthTextbox"));
        strengthTextbox->setMinimumSize(QSize(40, 0));
        strengthTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(strengthTextbox);


        gridLayout_4->addLayout(horizontalLayout, 4, 0, 1, 1);

        centerLabel = new QLabel(shapeParameters);
        centerLabel->setObjectName(QString::fromUtf8("centerLabel"));

        gridLayout_4->addWidget(centerLabel, 11, 0, 1, 1);

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

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        numLayersLabel = new QLabel(shapeParameters);
        numLayersLabel->setObjectName(QString::fromUtf8("numLayersLabel"));

        horizontalLayout_6->addWidget(numLayersLabel);

        numLayersSlider = new QSlider(shapeParameters);
        numLayersSlider->setObjectName(QString::fromUtf8("numLayersSlider"));
        numLayersSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(numLayersSlider);

        numLayersTextbox = new QLineEdit(shapeParameters);
        numLayersTextbox->setObjectName(QString::fromUtf8("numLayersTextbox"));
        numLayersTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(numLayersTextbox);


        gridLayout_4->addLayout(horizontalLayout_6, 8, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        xLabel = new QLabel(shapeParameters);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));

        horizontalLayout_4->addWidget(xLabel);

        noiseCenterXDial = new QDial(shapeParameters);
        noiseCenterXDial->setObjectName(QString::fromUtf8("noiseCenterXDial"));

        horizontalLayout_4->addWidget(noiseCenterXDial);

        yLabel = new QLabel(shapeParameters);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));

        horizontalLayout_4->addWidget(yLabel);

        noiseCenterYDial = new QDial(shapeParameters);
        noiseCenterYDial->setObjectName(QString::fromUtf8("noiseCenterYDial"));

        horizontalLayout_4->addWidget(noiseCenterYDial);

        zLabel = new QLabel(shapeParameters);
        zLabel->setObjectName(QString::fromUtf8("zLabel"));

        horizontalLayout_4->addWidget(zLabel);

        noiseCenterZDial = new QDial(shapeParameters);
        noiseCenterZDial->setObjectName(QString::fromUtf8("noiseCenterZDial"));

        horizontalLayout_4->addWidget(noiseCenterZDial);


        gridLayout_4->addLayout(horizontalLayout_4, 12, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        persistenceLabel = new QLabel(shapeParameters);
        persistenceLabel->setObjectName(QString::fromUtf8("persistenceLabel"));

        horizontalLayout_7->addWidget(persistenceLabel);

        persistenceSlider = new QSlider(shapeParameters);
        persistenceSlider->setObjectName(QString::fromUtf8("persistenceSlider"));
        persistenceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(persistenceSlider);

        persistenceTextbox = new QLineEdit(shapeParameters);
        persistenceTextbox->setObjectName(QString::fromUtf8("persistenceTextbox"));
        persistenceTextbox->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_7->addWidget(persistenceTextbox);


        gridLayout_4->addLayout(horizontalLayout_7, 9, 0, 1, 1);

        line = new QFrame(shapeParameters);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 2, 0, 1, 3);

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


        gridLayout_4->addLayout(horizontalLayout_9, 13, 0, 1, 1);


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
        menuBar->setGeometry(QRect(0, 0, 600, 24));
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
        baseRoughnessLabel->setText(QCoreApplication::translate("MainWindow", "Base Roughness", nullptr));
        roughnessLabel->setText(QCoreApplication::translate("MainWindow", "Roughness", nullptr));
        minValueLabel->setText(QCoreApplication::translate("MainWindow", "Min Value", nullptr));
        noiseLabel->setText(QCoreApplication::translate("MainWindow", "Noise", nullptr));
        strengthLabel->setText(QCoreApplication::translate("MainWindow", "Strength", nullptr));
        strengthTextbox->setText(QString());
        centerLabel->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        resolutionLabel->setText(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
        numLayersLabel->setText(QCoreApplication::translate("MainWindow", "Num Layers", nullptr));
        xLabel->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        yLabel->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        zLabel->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        persistenceLabel->setText(QCoreApplication::translate("MainWindow", "Persistence", nullptr));
        colorLabel->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        colorButton->setText(QString());
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
