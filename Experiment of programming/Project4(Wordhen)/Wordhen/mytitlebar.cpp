#include "Start.h"
#include "./ui_Start.h"

void Widget::on_closeButton_clicked()
{
    this->close();
}

void Widget::on_hideButton_clicked()
{
    //HWND hw1 = FindWindowA(NULL, "Wordhen");//获取程序句柄
    //ShowWindow(hw1, SW_MINIMIZE);//程序最小化到任务栏
    //ShowWindow(hw1, SW_RESTORE);//程序恢复到主界面
    setWindowState(windowState()^Qt::WindowMinimized);
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
    }

}



