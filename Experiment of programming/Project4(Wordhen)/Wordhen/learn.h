#ifndef LEARN_H
#define LEARN_H

#include <QWidget>
#include <QMouseEvent>
#include "Start.h"
#include "ui_Start.h"
namespace Ui {
class Learn;
}

class Learn : public QWidget
{
    Q_OBJECT

public:
    explicit Learn(QWidget *parent = nullptr);
    ~Learn();
    Widget *Vater;

private slots:
    void on_closeButton_clicked();

private:
    Ui::Learn *ui;

private slots:
    //由于去掉显示界面的菜单栏和标题栏，无法拖动窗口，重写关于窗口拖动用的几个函数
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void on_hideButton_clicked();

    void on_moveButton_stateChanged(int arg1);

private:
    QPoint last;//窗口拖动用变量
    bool movable = false;
};

#endif // LEARN_H
