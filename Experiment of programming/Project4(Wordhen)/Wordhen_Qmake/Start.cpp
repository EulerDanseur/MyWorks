#include "Start.h"
#include "./ui_Start.h"
#include "animationeffect.h"
#include <QDate>
#include <QPainter>
#include <QThread>
#include "learn.h"
#include <QStandardItemModel>
#include <QRandomGenerator>

int wallpaperorder = 0;

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
    modellearnt = new QStandardItemModel();
    modelunlearnt = new QStandardItemModel();

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

    //设置图标
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
    
    //设置只能输入数字
    QRegularExpression rx("[0-9]*");
    QRegularExpressionValidator *pReg = new QRegularExpressionValidator(rx, this);
    ui->wordAmountline->setValidator(pReg);

    //设置随机壁纸
    wallpaperorder = QRandomGenerator::global()->bounded(0,10);
    QImage img;
    img.load(QString(":/new/picture/pic/%1.png").arg(wallpaperorder));
    ui->startBG_2->setPixmap(QPixmap::fromImage(img));

    //设置模式
    QFile file(QString(":/book/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Debug/mode.txt"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);
    QString bookname;
    int ordered;
    while (!in.atEnd())
    {
        in >> bookname >> w_learn->wordsPerGroup >> ordered >> w_learn->mode;
    }
    ui->wordAmountline->setText(QString("%1").arg(w_learn->wordsPerGroup));
    delete w_learn->book;
    w_learn->book = new Book(bookname);
    if(!w_learn->mode)
    {
        ui->cnToEn->setChecked(1);
        on_cnToEn_clicked();
    }
    if(!ordered)
        ui->randomButton->setChecked(1);
    w_learn->setQuiz();

}

Widget::~Widget()
{
    delete ui;

    delete w_learn;
}

void Widget::on_Learn_clicked()
{
    //更改图标
    ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_pencil));
    setWindowIcon(QIcon(":/icon/pic/book-open-cover.png"));

    ui->startBG_2->graphicsEffect()->setEnabled(1);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");

    //切换界面
    animate(this);

    int index = ui->stackedWidget->addWidget(w_learn);
    ui->stackedWidget->setCurrentIndex(index);

}

void Widget::on_startButton_clicked()
{
     // QGraphicsBlurEffect blureffect;
     // blureffect.setBlurRadius(5); //数值越大，越模糊
     // ui->startButton->setGraphicsEffect(&blureffect);//设置模糊特效

    //开始动画
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
    connect(expand, &QPropertyAnimation::finished, this, [=] {/*delete blureffect;*/ delete animation; delete OpacityStartButton; delete expand; ui->startButton->hide();});

}


void Widget::on_shiftWallpaperButton_clicked()
{
    animate(this);
    wallpaperorder = (wallpaperorder + 1) % 10;
    QImage img;
    img.load(QString(":/new/picture/pic/%1.png").arg(wallpaperorder));
    ui->startBG_2->setPixmap(QPixmap::fromImage(img));

}



void Widget::createTable(QStandardItemModel *model, QTableView *table, char name)
{
    //清空表格
    model->clear();
    QString state;
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal, "单词");
    model->setHeaderData(1,Qt::Horizontal, "状态");
    model->setHeaderData(2,Qt::Horizontal, "音标");
    model->setHeaderData(3,Qt::Horizontal, "释义");

    //填充表格
    switch(name)
    {
    case 'w':
        for(auto i : w_learn->book->wordList)
        {
            QList<QStandardItem *> item;
            i.learnt ? state = "已学习" : state = "未学习";
            item << new QStandardItem(i.word) << new QStandardItem(state) <<  new QStandardItem(i.pronunciation) <<  new QStandardItem(i.meaning.join(" "));
            model->appendRow(item);
        }
        break;
    case 's':
        for(auto i : w_learn->book->starList)
        {
            QList<QStandardItem *> item;
            i.learnt ? state = "已学习" : state = "未学习";
            item << new QStandardItem(i.word) << new QStandardItem(state) <<  new QStandardItem(i.pronunciation) <<  new QStandardItem(i.meaning.join(" "));
            model->appendRow(item);
        }
        break;
    case 'l':
        for(auto i : w_learn->book->learntList)
        {
            QList<QStandardItem *> item;
            state = "已学习";
            item << new QStandardItem(i->word) << new QStandardItem(state) <<  new QStandardItem(i->pronunciation) <<  new QStandardItem(i->meaning.join(" "));
            model->appendRow(item);
        }
        break;
    case 'u':
        for(auto i : w_learn->book->unlearntList)
        {
            QList<QStandardItem *> item;
            state = "未学习";
            item << new QStandardItem(i->word) << new QStandardItem(state) <<  new QStandardItem(i->pronunciation) <<  new QStandardItem(i->meaning.join(" "));
            model->appendRow(item);
        }
        break;
    }
    table->setModel(model);
    table->verticalHeader()->hide();
    table->setColumnWidth(3, 200);
}

void Widget::on_bookButton_clicked()
{
    animate(this);
    ui->startBG_2->graphicsEffect()->setEnabled(1);
    ui->startBG->setStyleSheet("background-color: rgba(0,0,0,200); border-radius:0");

    //更新数据
    ui->bookListButton->setText(w_learn->book->name);
    int learned = w_learn->book->learntList.size();
    int unlearned = w_learn->book->unlearntList.size();
    ui->learnt->setText(QString("已学习 %1").arg(learned));
    ui->unlearnt->setText(QString("已学习 %1").arg(unlearned));
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(learned + unlearned);
    ui->progressBar->setValue(learned);
    ui->stackedWidget->setCurrentWidget(ui->book);

    createTable(modelword, ui->bookWordTable, 'w');
    createTable(modelstar, ui->starTable, 's');
    createTable(modellearnt, ui->learntTable, 'l');
    createTable(modelunlearnt, ui->unlearntTable, 'u');
}


void Widget::on_returnButton_clicked()
{
    animate(this);

    //更改图标
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
    QVector<Word> stared;
    stared = w_learn->book->starList;
    delete w_learn->book;
    w_learn->book = new Book(bookindex);
    w_learn->book->starList = stared;
    w_learn->setQuiz();
    on_bookButton_clicked();
}


void Widget::on_nextbook_clicked()
{
    bookindex++;
    bookindex %= 3;
    QVector<Word> stared;
    stared = w_learn->book->starList;
    delete w_learn->book;
    w_learn->book = new Book(bookindex);
    w_learn->book->starList = stared;
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
    if(!w_learn->ordered)
    {
        unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
        std::shuffle(w_learn->book->unlearntList.begin(),w_learn->book->unlearntList.end(),std::default_random_engine(seed));
    }
    else
    {
        sort(w_learn->book->unlearntList.begin(),w_learn->book->unlearntList.end(),[=](Word *a, Word *b){return a->word < b->word;});
    }
    w_learn->setQuiz();
}


void Widget::on_enToCn_clicked()
{
    w_learn->mode = 1;
    w_learn->setQuiz();
}


void Widget::on_cnToEn_clicked()
{
    w_learn->mode = 0;
    w_learn->setQuiz();
}


void Widget::on_wordAmountline_textChanged(const QString &amt)
{
    //排除非法输入
    if(amt == "0" )
    {
        ui->wordAmountline->setText("1");
        w_learn->wordsPerGroup = 1;
    }
    if(amt == "")
    {
        w_learn->wordsPerGroup = 1;
    }
    w_learn->wordsPerGroup = amt.toInt();
}

