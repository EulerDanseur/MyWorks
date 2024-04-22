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

    //创建输入框
    void createInputBox();
    //创建结果框
    void createResultBox();
    //创建警告框
    void createWarnBox();
    //创建明暗按钮
    void createswitchButton();

    // 重画界面
    void showscreen();

    // 重画按钮
    void showsbutton();

    // 创建操作按钮
    void createOptButtons(tstring name, int x, int y);

    // 创建数字按钮
    void createNumButtons(TCHAR num, int x, int y);

    // 显示输入
    void showinput(TCHAR key = 0);

    // 显示结果
    void showresult(TCHAR key = 0);

    // 显示警告，或结果
    void showwarningbar(QString warn, TCHAR key = 0);

    // 按键响应
    bool buttonsPressed(TCHAR key);

    // 插入数字或算符
    void inputInsert(TCHAR ch);

    // 退格
    void backSpace();

    // 等号出结果
    void equalPress();

    // 清空
    void Clear();

private:
    //Ui::Window ui;

    // 主要界面布局
    QVBoxLayout *mainLayout;

    // 按钮布局
    QGridLayout *buttonLayout;

    // 输入框
    QLineEdit *inputBox;

    // 结果框
    QLineEdit *resultBox;

    // 警告框
    QLineEdit *warnBox;

    // 按钮
    map<TCHAR, Buttons *> buttons;

    // 是否已按键
    bool buttonPressflag;

    // 切换按钮
    SwitchButton *switchButton;

    // 表达式求值
    Expression expn;
private slots:
};

class Buttons : public QPushButton
{
    Q_OBJECT

public:

    //数字的样式
    void styleNum(int num);

    //操作符的样式
    void styleOpt(tstring opt);
};
