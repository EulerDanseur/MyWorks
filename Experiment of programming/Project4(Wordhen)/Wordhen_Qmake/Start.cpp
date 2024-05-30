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

    w_learn = new Learn(this);
    w_learn->hide();

    setWindowTitle("Wordhen");
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/icon/pic/book1.png"));

    //移动窗体到屏幕中央
    QRect rect = frameGeometry();
    QScreen* screen = QGuiApplication::primaryScreen();
    QPoint centerPoint = screen->availableGeometry().center();
    rect.moveCenter(centerPoint);
    move(rect.topLeft());

    //记录坐标
    xPosition = x();
    yPosition = y();


    QGraphicsDropShadowEffect * dse = new QGraphicsDropShadowEffect();
    dse->setBlurRadius(20);
    dse->setOffset(0);
    dse->setColor(QColor(0x7E8EF1));
    ui->startTitle->setGraphicsEffect(dse);

    QDate today = QDate::currentDate();
    ui->date->setAlignment(Qt::AlignHCenter);
    ui->date->setText(QString(
                              "<font style = 'font-size:20px; color:#028391 ; font-weight:900'> %1 </font> <br>"
                              "<font style = 'font-size:20px; color:#01204E ; font-weight:700'> %2 </font>").arg(today.toString("MMM dd")).arg(today.toString("ddd.")));

    //ui->startBG->setFixedSize(392, 615);

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
    ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    //ui->startBG->resize(this->size());
}

void Widget::on_Learn_clicked()
{
    ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_pencil));

    setWindowIcon(QIcon(":/icon/pic/book-open-cover.png"));

    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(20); //数值越大，越模糊
    ui->startBG_2->setGraphicsEffect(blureffect);//设置模糊特效

    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");
    QLabel *label = new QLabel(this);
    label->resize(this->size());
    label->setPixmap(this->grab());
    label->show();
    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", this);
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=] {delete label;});

    int index = ui->stackedWidget->addWidget(w_learn);
    ui->stackedWidget->setCurrentIndex(index);

}

void Widget::on_startButton_clicked()
{
    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(5); //数值越大，越模糊
    ui->startButton->setGraphicsEffect(blureffect);//设置模糊特效

    QGraphicsOpacityEffect  *OpacityStartButton = new QGraphicsOpacityEffect(ui->startButton);
    ui->startButton->setGraphicsEffect(OpacityStartButton);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityStartButton, "opacity", this);
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();

    QPropertyAnimation *expand = new QPropertyAnimation(ui->startTitle, "geometry");
    expand->setDuration(1200);
    expand->setStartValue(QRect(63,170,0,0));
    expand->setEndValue(QRect(63,170,252,52));
    expand->start();
    connect(animation, &QPropertyAnimation::finished, this, [=] {ui->startButton->hide();});

}

int wallpaperorder = 0;

void Widget::on_shiftWallpaperButton_clicked()
{
    QLabel *label = new QLabel(this);
    label->resize(this->size());
    label->setPixmap(this->grab());
    label->show();
    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", this);
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=] {delete label;});

    wallpaperorder = (wallpaperorder + 1) % 10;
    QImage img;
    img.load(QString(":/new/picture/pic/%1.png").arg(wallpaperorder));
    //ui->startBG->setPixmap(QPixmap::fromImage(img));
    ui->startBG_2->setPixmap(QPixmap::fromImage(img));

}


void Widget::on_stackedWidget_currentChanged(int index)
{

}


void Widget::on_bookButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Widget::on_bookListButton_clicked()
{

}

