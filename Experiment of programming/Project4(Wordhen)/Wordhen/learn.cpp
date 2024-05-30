#include "learn.h"
#include "ui_learn.h"
#include "icon.h"
#include <QThread>
Learn::Learn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Learn)
{
    ui->setupUi(this);
    setWindowTitle(QString("Learning"));
    setWindowFlags(Qt::FramelessWindowHint);

    ui->closeButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->closeButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_times));
    ui->hideButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->hideButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_minus));
    ui->moveButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->moveButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chain_broken ));

}

Learn::~Learn()
{
    delete ui;
}

void Learn::on_closeButton_clicked()
{

    Vater->show();
    QPropertyAnimation *animation = new QPropertyAnimation(Vater,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    connect(animation, &QPropertyAnimation::finished, this, &QWidget::close);

}

void Learn::on_hideButton_clicked()
{
    //HWND hw1 = FindWindowA(NULL, "Wordhen");//获取程序句柄
    //ShowWindow(hw1, SW_MINIMIZE);//程序最小化到任务栏
    //ShowWindow(hw1, SW_RESTORE);//程序恢复到主界面
    setWindowState(windowState()^Qt::WindowMinimized);
}


void Learn::on_moveButton_stateChanged(int checked)
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
void Learn::mousePressEvent(QMouseEvent *e)
{
    if(movable)
        if(e->button()== Qt::LeftButton)	//鼠标左键释放
            last = e->globalPosition().toPoint();;
}
//鼠标移动
void Learn::mouseMoveEvent(QMouseEvent *e)
{
    if(movable)
        if(e->buttons()==Qt::LeftButton)	//坐标左键按下并移动
        {
            int dx = e->globalPosition().x() - last.x();
            int dy = e->globalPosition().y() - last.y();
            last = e->globalPosition().toPoint();;
            move(x()+dx, y()+dy);
        }

}
//鼠标按下
void Learn::mouseReleaseEvent(QMouseEvent *e)
{
    if(movable)
        if(e->button()==Qt::LeftButton)	//鼠标左键按下
        {
            int dx = e->globalPosition().x() - last.x();
            int dy = e->globalPosition().y() - last.y();
            move(x()+dx, y()+dy);
        }

}


