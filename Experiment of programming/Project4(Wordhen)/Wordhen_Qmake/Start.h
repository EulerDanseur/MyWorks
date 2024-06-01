#ifndef START_H
#define START_H
#include <QWidget>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <Windows.h>
#include "icon.h"
#include "qheaderview.h"
#include "qstandarditemmodel.h"

class Learn;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void resizeEvent(QResizeEvent *event);
    friend class Learn;
private slots:

    void on_Learn_clicked();

    void on_closeButton_clicked();

    void on_startButton_clicked();

    void on_hideButton_clicked();

    void on_moveButton_stateChanged(int arg1);
    void on_bookButton_clicked();

private:
    Ui::Widget *ui;
    Learn *w_learn;
    QStandardItemModel* modelstar;
    QStandardItemModel* modelword;

    //QGraphicsOpacityEffect  *Opacity;

    //在头文件中重写鼠标事件
private slots:
    //由于去掉显示界面的菜单栏和标题栏，无法拖动窗口，重写关于窗口拖动用的几个函数
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void PopOut();
    void on_shiftWallpaperButton_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_returnButton_clicked();

    void on_lastbook_clicked();

    void on_nextbook_clicked();

    void on_returnButton_2_clicked();

    void on_settingButton_clicked();

    void on_randomButton_stateChanged(int arg1);

private:
    QPoint last;//窗口拖动用变量
    bool movable = false;

    int xPosition;
    int yPosition;
};

#include <QTableView>
#include <QStandardItemModel>


#endif // START_H
