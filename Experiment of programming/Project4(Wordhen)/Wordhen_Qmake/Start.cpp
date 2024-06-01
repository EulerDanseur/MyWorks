#include "Start.h"
#include "./ui_Start.h"
#include "animationeffect.h"
#include <QDate>
#include <QPainter>
#include <QThread>
#include "learn.h"
#include <QStandardItemModel>



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

    modelword = new QStandardItemModel();
    modelstar = new QStandardItemModel();

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
    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(20); //数值越大，越模糊
    ui->startBG_2->setGraphicsEffect(blureffect);//设置模糊特效
    ui->startBG_2->graphicsEffect()->setEnabled(0);//设置模糊特效

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

    ui->returnButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->returnButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_sign_out));

    ui->returnButton_2->setFont(FontAwesomeIcons::Instance().getFont());
    ui->returnButton_2->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_sign_out));

    ui->lastbook->setFont(FontAwesomeIcons::Instance().getFont());
    ui->lastbook->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chevron_left));
    ui->nextbook->setFont(FontAwesomeIcons::Instance().getFont());
    ui->nextbook->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chevron_right));

}

Widget::~Widget()
{
    delete ui;

    delete w_learn;
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

    ui->startBG_2->graphicsEffect()->setEnabled(1);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");

    animate(this);

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
    connect(animation, &QPropertyAnimation::finished, this, [=] {delete blureffect; delete OpacityStartButton;delete expand;ui->startButton->hide();});

}

int wallpaperorder = 0;

void Widget::on_shiftWallpaperButton_clicked()
{
    animate(this);
    wallpaperorder = (wallpaperorder + 1) % 10;
    QImage img;
    img.load(QString(":/new/picture/pic/%1.png").arg(wallpaperorder));

    ui->startBG_2->setPixmap(QPixmap::fromImage(img));

}


void Widget::on_stackedWidget_currentChanged(int index)
{

}


void Widget::on_bookButton_clicked()
{
    animate(this);
    ui->startBG_2->graphicsEffect()->setEnabled(1);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");

    ui->bookListButton->setText(w_learn->book->name);
    int learned = w_learn->book->learntList.size();
    int unlearned = w_learn->book->unlearntList.size();
    ui->learnt->setText(QString("已学习 %1").arg(learned));
    ui->unlearnt->setText(QString("已学习 %1").arg(unlearned));
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(learned + unlearned);
    ui->progressBar->setValue(learned);
    ui->stackedWidget->setCurrentWidget(ui->book);

    delete modelword;
    delete modelstar;

    QString state;
    modelword = new QStandardItemModel(ui->bookWordTable);
    modelstar = new QStandardItemModel(ui->starTable);
    modelword->setColumnCount(4);
    modelword->setHeaderData(0,Qt::Horizontal, "单词");
    modelword->setHeaderData(1,Qt::Horizontal, "状态");
    modelword->setHeaderData(2,Qt::Horizontal, "音标");
    modelword->setHeaderData(3,Qt::Horizontal, "释义");
    modelstar->setColumnCount(4);
    modelstar->setHeaderData(0,Qt::Horizontal, "单词");
    modelstar->setHeaderData(1,Qt::Horizontal, "状态");
    modelstar->setHeaderData(2,Qt::Horizontal, "音标");
    modelstar->setHeaderData(3,Qt::Horizontal, "释义");
    for(auto i : w_learn->book->starList)
    {
        QList<QStandardItem *> item;
        i.learnt ? state = "已学习" : state = "未学习";
        item << new QStandardItem(i.word) << new QStandardItem(state) <<  new QStandardItem(i.pronunciation) <<  new QStandardItem(i.meaning.join(" "));
        modelstar->appendRow(item);
    }
    for(auto i : w_learn->book->wordList)
    {
        QList<QStandardItem *> item;
        i.learnt ? state = "已学习" : state = "未学习";
        item << new QStandardItem(i.word) << new QStandardItem(state) <<  new QStandardItem(i.pronunciation) <<  new QStandardItem(i.meaning.join(" "));
        modelword->appendRow(item);
    }
    ui->bookWordTable->setModel(modelword);
    ui->starTable->setModel(modelstar);
    ui->bookWordTable->verticalHeader()->hide();
    ui->starTable->verticalHeader()->hide();
    ui->bookWordTable->setColumnWidth(3, 200);
    ui->starTable->setColumnWidth(3, 200);
}


void Widget::on_returnButton_clicked()
{
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->start);

    ui->stackedWidget->setCurrentIndex(0);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,0); border-radius:0");
    ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));

    ui->startBG_2->graphicsEffect()->setEnabled(0);
}

int bookindex = 0;

void Widget::on_lastbook_clicked()
{
    bookindex += 2;
    bookindex %= 3;
    delete w_learn->book;
    w_learn->book = new Book(bookindex);
    w_learn->setQuiz();
    on_bookButton_clicked();
}


void Widget::on_nextbook_clicked()
{
    bookindex++;
    bookindex %= 3;
    delete w_learn->book;
    w_learn->book = new Book(bookindex);
    w_learn->setQuiz();
    on_bookButton_clicked();
}


void Widget::on_returnButton_2_clicked()
{
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->start);

    ui->stackedWidget->setCurrentIndex(0);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,0); border-radius:0");
    ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));

    ui->startBG_2->graphicsEffect()->setEnabled(0);
}


void Widget::on_settingButton_clicked()
{
    animate(this);
    ui->startBG_2->graphicsEffect()->setEnabled(1);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");

    ui->stackedWidget->setCurrentWidget(ui->setting);

}


void Widget::on_randomButton_stateChanged(int arg1)
{
    w_learn->ordered =! w_learn->ordered;
    w_learn->setQuiz();
}

