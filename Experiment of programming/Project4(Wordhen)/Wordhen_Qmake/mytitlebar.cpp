#include "Start.h"
#include "./ui_Start.h"
#include <QScreen>
#include <QParallelAnimationGroup>
void Widget::on_closeButton_clicked()
{
    // 隐藏窗口
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(200);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, &QWidget::close);

}

void Widget::on_hideButton_clicked()
{
    // 最小化窗口
    const QRect &currRect = this->geometry();
    QPropertyAnimation *pAnim1 = new QPropertyAnimation(this, "geometry");
    pAnim1->setStartValue(currRect);
    pAnim1->setEndValue(QRect(x(), 1000, currRect.x(), currRect.y()));
    pAnim1->setEasingCurve(QEasingCurve::Linear);
    pAnim1->setDuration(300);

    QPropertyAnimation *pAnim2 = new QPropertyAnimation(this, "windowOpacity");
    pAnim2->setStartValue(1);
    pAnim2->setEndValue(0.5);
    pAnim2->setDuration(300);

    QParallelAnimationGroup *animGrp = new QParallelAnimationGroup(this);
    animGrp->addAnimation(pAnim1);
    animGrp->addAnimation(pAnim2);
    animGrp->start(QAbstractAnimation::DeleteWhenStopped);

    connect(animGrp, &QParallelAnimationGroup::finished, this, [=]{
        setWindowState(windowState()^Qt::WindowMinimized);
        move(xPosition, yPosition);

        QPropertyAnimation *pAnim2 = new QPropertyAnimation(this, "windowOpacity");
        pAnim2->setStartValue(0);
        pAnim2->setEndValue(1);
        pAnim2->setDuration(600);
        pAnim2->start();
    });
}

void Widget::PopOut()
{
    // 弹出窗口
    const QRect &currRect = this->geometry();
    QPropertyAnimation *pAnim1 = new QPropertyAnimation(this, "geometry");
    pAnim1->setEndValue(currRect);
    pAnim1->setStartValue(QRect(-currRect.x(), -currRect.y(), currRect.x(), currRect.y()));
    pAnim1->setEasingCurve(QEasingCurve::Linear);
    pAnim1->setDuration(100);

    QPropertyAnimation *pAnim2 = new QPropertyAnimation(this, "windowOpacity");
    pAnim2->setStartValue(0);
    pAnim2->setEndValue(1);
    pAnim2->setDuration(100);

    QParallelAnimationGroup *animGrp = new QParallelAnimationGroup(this);
    animGrp->addAnimation(pAnim1);
    animGrp->addAnimation(pAnim2);
    animGrp->start(QAbstractAnimation::DeleteWhenStopped);
}


void Widget::on_moveButton_stateChanged(int checked)
{
    if(checked == Qt::Checked)
    {
        movable = true;
        ui->moveButton->setFont(FontAwesomeIcons::Instance().getFont());
        ui->moveButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chain_broken ));
    }
    else
    {
        movable = false;
        ui->moveButton->setFont(FontAwesomeIcons::Instance().getFont());
        ui->moveButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chain));
    }
}
//三个鼠标事件的重写
//鼠标释放
void Widget::mousePressEvent(QMouseEvent *e)
{
    if(movable)
    if(e->button()== Qt::LeftButton)	//鼠标左键释放
        last = e->globalPosition().toPoint();;
}
//鼠标移动
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(movable)
    if(e->buttons()==Qt::LeftButton)	//坐标左键按下并移动
    {
        int dx = e->globalPosition().x() - last.x();
        int dy = e->globalPosition().y() - last.y();
        last = e->globalPosition().toPoint();;
        move(x()+dx, y()+dy);
        xPosition = x();
        yPosition = y();
    }

}
//鼠标按下
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(movable)
    if(e->button()==Qt::LeftButton)	//鼠标左键按下
    {
        int dx = e->globalPosition().x() - last.x();
        int dy = e->globalPosition().y() - last.y();
        move(x()+dx, y()+dy);
        xPosition = x();
        yPosition = y();
    }

}



