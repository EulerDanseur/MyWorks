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
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    friend class Learn;
    void createTable(QStandardItemModel *model, QTableView *table, char name);

private:
    Ui::Widget *ui;
    QGraphicsOpacityEffect *Opacity;

    // 学习窗口
    Learn *w_learn;

    // 列表模型
    QStandardItemModel *modelstar;
    QStandardItemModel *modelword;
    QStandardItemModel *modellearnt;
    QStandardItemModel *modelunlearnt;

private slots:
    // 学习窗口的槽函数
    void on_Learn_clicked();

    // 开始动画
    void on_startButton_clicked();

    // 标题栏的槽函数
    void on_closeButton_clicked();

    void on_hideButton_clicked();

    void on_moveButton_stateChanged(int arg1);

    void on_shiftWallpaperButton_clicked();

    // 菜单栏的槽函数
    void on_returnButton_2_clicked();

    void on_returnButton_clicked();
    // 书本按钮
    void on_bookButton_clicked();
    // 设置按钮
    void on_settingButton_clicked();

    // 学习模式转换
    void on_enToCn_clicked();

    void on_cnToEn_clicked();

    void on_randomButton_stateChanged(int arg1);

    void on_wordAmountline_textChanged(const QString &arg1);

    // 书本切换
    void on_lastbook_clicked();

    void on_nextbook_clicked();


    // 在头文件中重写鼠标事件
private slots:
    // 由于去掉显示界面的菜单栏和标题栏，无法拖动窗口，重写关于窗口拖动用的几个函数
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void PopOut();

private:
    QPoint last; // 窗口拖动用变量
    bool movable = false;

    int xPosition;
    int yPosition;
};

#include <QTableView>
#include <QStandardItemModel>

#endif // START_H
