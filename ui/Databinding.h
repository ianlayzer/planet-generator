#ifndef DATABINDING_H
#define DATABINDING_H

#include <QObject>
#include <QVariant>
#include <QSlider>
#include <QLineEdit>
#include <QCheckBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QDockWidget>
#include <QTabWidget>
#include <QDial>
#include <QPushButton>

/**
 * @class DataBinding
 *
 * This class binds a slider and a textbox to an int, so when either the slider or the textbox
 * is changed, the other is also changed and the int is updated with the new value.  This does
 * not update either the slider or the textbox when the int is set to a new value.
 */
class DataBinding : public QObject {
    Q_OBJECT

public:
    DataBinding(QObject *parent = 0) : QObject(parent) {}
    virtual ~DataBinding() {}

signals:
    void dataChanged();

};

/**
 * @class IntBinding
 *
 * This class binds a slider and a textbox to an int, so when either the slider or the textbox
 * is changed, the other is also changed and the int is updated with the new value.  This does
 * not update either the slider or the textbox when the int is set to a new value.
 */
class IntBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~IntBinding() {}

    static IntBinding* bindSliderAndTextbox(
        QSlider *slider, QLineEdit *textbox, int &value, int minValue, int maxValue);

    static IntBinding* bindTextbox(QLineEdit *textbox, int &value);

private slots:
    void intChanged(int newValue);
    void stringChanged(QString newValue);

signals:
    void updateInt(int newValue);
    void updateString(QString newValue);

private:
    IntBinding(int &value) : DataBinding(), m_value(value) {}

    static void connectToSliders(IntBinding* binding, QSlider *slider, QLineEdit *textbox);
    static void setWidgetValues(QSlider *slider, QLineEdit *textbox, int value, int minValue, int maxValue);
    int &m_value;
};



/**
 * @class UCharBinding
 *
 * This class binds a slider and a textbox to an int, so when either the slider or the textbox
 * is changed, the other is also changed and the int is updated with the new value.  This does
 * not update either the slider or the textbox when the int is set to a new value.
 */
class UCharBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~UCharBinding() {}

    static UCharBinding* bindSliderAndTextbox(
        QSlider *slider, QLineEdit *textbox, unsigned char &value, int minValue, int maxValue);

    static UCharBinding* bindTextbox(QLineEdit *textbox, unsigned char &value);

private slots:
    void ucharChanged(int newValue);
    void stringChanged(QString newValue);

signals:
    void updateInt(int newValue);
    void updateString(QString newValue);

private:
    UCharBinding(unsigned char &value) : DataBinding(), m_value(value) {}

    static void connectToSliders(IntBinding* binding, QSlider *slider, QLineEdit *textbox);
    static void setWidgetValues(QSlider *slider, QLineEdit *textbox, unsigned char value, unsigned char minValue, unsigned char maxValue);
    unsigned char &m_value;
};


/**
 *
 * @class FloatBinding
 *
 * This class binds a slider and a textbox to a REAL, so when either the slider or the textbox
 * is changed, the other is also changed and the REAL is updated with the new value.  This does
 * not update either the slider or the textbox when the REAL is set to a new value.
 */
class FloatBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~FloatBinding() {}

    static FloatBinding* bindSliderAndTextbox(
         QSlider *slider, QLineEdit *textbox, float &value, float minValue, float maxValue);
    static FloatBinding* bindDial(
         QDial *dial, float &value, float minValue, float maxValue, bool wrappingExtendsRange);

private slots:
    void intChanged(int newValue);
    void stringChanged(QString newValue);

signals:
    void updateInt(int newValue);
    void updateString(QString newValue);

private:
    FloatBinding(float &value) :
        DataBinding(),
        m_value(value),
        m_maxValue(0),
        m_minValue(0),
        m_offset(0),
        m_wrappingExtendsRange(false) {}

    float &m_value, m_maxValue, m_minValue, m_offset;
    bool m_wrappingExtendsRange;
};

/**
 * @class BoolBinding
 *
 * This class binds a checkbox to a bool, so when the checkbox is changed the bool is updated
 * with the new value.  This does not update the checkbox when the bool is set to a new value.
 */
class BoolBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~BoolBinding() {}

    static BoolBinding* bindCheckbox(QCheckBox *checkbox, bool &value);
    static BoolBinding* bindDock(QDockWidget *dock, bool &value);

private slots:
    void boolChanged(bool newValue);

private:
    BoolBinding(bool &value) : DataBinding(), m_value(value) {}

    bool &m_value;
};

/**
 * @class ChoiceBinding
 *
 * This class binds a group of radio buttons to an int, so when a radio button is clicked the
 * int is updated with the index of the currently checked button in the group.  This does not
 * update the radio buttons when the int is set to a new value.
 */
class ChoiceBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~ChoiceBinding() {}

    static ChoiceBinding* bindRadioButtons(
            QButtonGroup *buttonGroup, int numRadioButtons, int &value, ...);
    static ChoiceBinding* bindTabs(QTabWidget *tabs, int &value);

private slots:
    void intChanged(int newValue);

private:
    ChoiceBinding(int &value) : DataBinding(), m_value(value) {}

    int &m_value;
};

/**
 * @class ColorBinding
 * @brief Binds a button and three textboxes to a QColor.
**/
class ColorBinding : public DataBinding {
    Q_OBJECT
public:
    virtual ~ColorBinding() {}

    static ColorBinding* bindButtonAndTextboxes(
            QPushButton *button, QLineEdit *rTextbox, QLineEdit *gTextbox, QLineEdit *bTextbox,
            QColor &value);

private slots:
    void buttonPushed();
    void rStringChanged(QString newValue);
    void gStringChanged(QString newValue);
    void bStringChanged(QString newValue);

signals:
    void updateRString(QString newValue);
    void updateGString(QString newValue);
    void updateBString(QString newValue);

private:
    void updateButtonColor();

    ColorBinding(QColor &value, QPushButton *button) :
        DataBinding(), m_value(value), m_button(button) {}
    QColor &m_value;
    QPushButton *m_button;
};

#endif // DATABINDING_H
