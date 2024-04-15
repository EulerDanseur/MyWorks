// #pragma once
#include "ui_CalculatorQT.h"
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <map>
#include <string>
#include <tchar.h>
#include <iostream>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "SwitchButton.h"
#include "RPN.h"
using namespace std;

#define calw CalculatorQT


extern int cursorPosition;



class CalculatorQT : public QWidget
{
    Q_OBJECT

public:

    friend class Buttons;

    CalculatorQT(QWidget *parent = nullptr);

    ~CalculatorQT();

    void showscreen();

    void showsbutton();
    
    void createOptButtons(tstring name, int x, int y);

    void createNumButtons(TCHAR num, int x, int y);

    void showinput();

    void showresult();

    void showwarningbar(QString);

    bool buttonsPressed(TCHAR key);

    void inputInsert(TCHAR ch);

    void backSpace();

    void equalPress();

    void Clear();

    

    Expression expn;

private:
    Ui::Window ui;
    // main layout
    QVBoxLayout *mainLayout;
    // grid layout of board
    QGridLayout *buttonLayout;

    QLineEdit *inputBox;

    QLineEdit *resultBox;

    QLineEdit *warnBox;

    map<TCHAR, Buttons *> buttons;

    SwitchButton *switchButton;

    bool buttonPressflag;
private slots:
};

class Buttons : public QPushButton
{
    Q_OBJECT

public:
    void styleNum(int num);

    void styleOpt(tstring opt);
};
