#ifndef ANIMATIONEFFECT_H
#define ANIMATIONEFFECT_H
#include <QWidget>
#include <QLabel>
#include <QGraphicsEffect>
#include <QPropertyAnimation>

//淡出动画
inline void animate(QWidget * w)
{
    QLabel *label = new QLabel(w);
    label->resize(w->size());
    label->setPixmap(w->grab());
    label->show();
    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", w);
    animation->setDuration(200);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    QAbstractAnimation::connect(animation, &QPropertyAnimation::finished, w, [=] {delete animation; delete OpacityImage; delete label;});
}

inline void animate(QWidget * w, int time)
{
    QLabel *label = new QLabel(w);
    label->resize(w->size());
    label->setPixmap(w->grab());
    label->show();
    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", w);
    animation->setDuration(time);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    QAbstractAnimation::connect(animation, &QPropertyAnimation::finished, w, [=] {delete animation; delete label;});
}
#endif // ANIMATIONEFFECT_H
