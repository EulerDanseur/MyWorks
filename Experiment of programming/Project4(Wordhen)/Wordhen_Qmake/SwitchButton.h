#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "qlabel.h"
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <QColor>

class SwitchButton : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchButton(QWidget *parent = 0);
    ~SwitchButton() {}

signals:
    void statusChanged(bool checked);

public slots:

private slots:
    void updateValue();

private:
    void drawBackGround(QPainter *painter);
    void drawSlider(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

private:
    int m_space;  // 滑块距离边界距离
    int m_radius; // 圆角角度

    bool m_checked;    // 是否选中
    bool m_showText;   // 是否显示文字
    bool m_showCircle; // 是否显示圆圈
    bool m_animation;  // 是否使用动画

    QColor m_bgColorOn;      // 打开时候的背景色
    QColor m_bgColorOff;     // 关闭时候的背景色
    QColor m_sliderColorOn;  // 打开时候滑块颜色
    QColor m_sliderColorOff; // 关闭时候滑块颜色
    QColor m_textColorOn;    // 文字颜色
    QColor m_textColorOff;   // 文字颜色

    QString m_textOn;  // 打开时候的文字
    QString m_textOff; // 关闭时候的文字

    QTimer *m_timer; // 动画定时器
    int m_step;      // 动画步长
    int m_startX;    // 滑块开始X轴坐标
    int m_endX;      // 滑块结束X轴坐标


public:
    int space() const;       // 滑块距离边界距离
    int radius() const;      // 圆角角度
    bool checked() const;    // 是否选中
    bool showText() const;   // 是否显示文字
    bool showCircel() const; // 是否显示圆圈
    bool animation() const;  // 是否使用动画

    QColor bgColorOn() const;      // 打开时候的背景色
    QColor bgColorOff() const;     // 关闭时候的背景色
    QColor sliderColorOn() const;  // 打开时候滑块颜色
    QColor sliderColorOff() const; // 关闭时候滑块颜色
    QColor textColorOn() const;    // 文字颜色
    QColor textColorOff() const;   // 文字颜色

    QString textOn() const;  // 打开时候的文字
    QString textOff() const; // 关闭时候的文字

    int step() const;   // 动画步长
    int startX() const; // 滑块开始X轴坐标
    int endX() const;   // 滑块结束X轴坐标

public Q_SLOTS:
    void setSpace(int space);      // 滑块距离边界距离
    void setRadius(int radius);    // 圆角角度
    void setChecked(bool checked); // 是否选中
    void setShowText(bool show);   // 是否显示文字
    void setShowCircle(bool show); // 是否显示圆圈
    void setAnimation(bool ok);    // 是否使用动画

    void setBgColorOn(const QColor &color);      // 打开时候的背景色
    void setBgColorOff(const QColor &color);     // 关闭时候的背景色
    void setSliderColorOn(const QColor &color);  // 打开时候滑块颜色
    void setSliderColorOff(const QColor &color); // 关闭时候滑块颜色
    void setTextColorOn(const QColor &color);    // 文字颜色
    void setTextColorOff(const QColor &color);   // 文字颜色

    void setTextOn(const QString &text);  //  打开时候的文字
    void setTextOff(const QString &text); // 关闭时候的文字
    void setText(QString a){}
};

#endif // SWITCHBUTTON_H
