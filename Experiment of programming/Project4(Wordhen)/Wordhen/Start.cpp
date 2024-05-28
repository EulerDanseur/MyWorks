#include "Start.h"
#include "./ui_Start.h"
#include <QDate>
#include <QPainter>
#include <QThread>
#include "learn.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Wordhen");

    //setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::FramelessWindowHint);

    QDate today = QDate::currentDate();

    QGraphicsDropShadowEffect * dse = new QGraphicsDropShadowEffect();
    dse->setBlurRadius(20);
    dse->setOffset(0);
    dse->setColor(QColor(0x7E8EF1));
    ui->startTitle->setGraphicsEffect(dse);

    ui->date->setAlignment(Qt::AlignHCenter);
    ui->date->setText(QString(
                              "<font style = 'font-size:20px; color:#028391 ; font-weight:900'> %1 </font> <br>"
                              "<font style = 'font-size:20px; color:#01204E ; font-weight:700'> %2 </font>").arg(today.toString("MMM dd")).arg(today.toString("ddd.")));

    ui->bookButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->bookButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));
    ui->settingButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->settingButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_gear));
    ui->statisticButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->statisticButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_bar_chart));

    ui->closeButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->closeButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_times));
    ui->hideButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->hideButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_minus));
    ui->moveButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->moveButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chain_broken ));
    ui->shiftWallpaperButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->shiftWallpaperButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_file_image_o));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    ui->startBG->resize(this->size());
}

void Widget::on_Learn_clicked()
{
    w_learn.show();
}

void Widget::on_startButton_clicked()
{
    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(5); //数值越大，越模糊
    ui->startButton->setGraphicsEffect(blureffect);//设置模糊特效

    QGraphicsOpacityEffect  *OpacityStartButton = new QGraphicsOpacityEffect(ui->startButton);
    ui->startButton->setGraphicsEffect(OpacityStartButton);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityStartButton, "opacity", this);
    animation->setDuration(1200);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();

    QPropertyAnimation *shrink = new QPropertyAnimation(ui->startButton, "geometry");
    shrink->setDuration(2000);
    shrink->setStartValue(QRect(0, 0, 401, 621));
    shrink->setEndValue(QRect(0, 0, 1000, 1000));
    shrink->start();

    // QGraphicsOpacityEffect  *OpacityTitle = new QGraphicsOpacityEffect(ui->startTitle);
    // ui->startTitle->setGraphicsEffect(OpacityTitle);
    // QPropertyAnimation *comeout = new QPropertyAnimation(OpacityTitle, "opacity", this);
    // comeout->setDuration(2000);
    // comeout->setStartValue(0);
    // comeout->setEndValue(1);
    // comeout->start();

    QPropertyAnimation *expand = new QPropertyAnimation(ui->startTitle, "geometry");
    expand->setDuration(1200);
    expand->setStartValue(QRect(63,170,0,0));
    expand->setEndValue(QRect(63,170,252,52));
    expand->start();

    connect(animation, &QPropertyAnimation::finished, [=] {ui->startButton->hide();});

}

int wallpaperorder = 0;

void Widget::on_shiftWallpaperButton_clicked()
{
    wallpaperorder = (wallpaperorder + 1) % 10;
    QImage img;
    img.load(QString(":/new/picture/pic/%1.png").arg(wallpaperorder));
    ui->startBG->setPixmap(QPixmap::fromImage(img));
}

