#include "learn.h"
#include "ui_learn.h"
#include "icon.h"
#include <QThread>
#include <QParallelAnimationGroup>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <QRandomGenerator>

Learn::Learn(Widget *parent)
    : QWidget(parent)
    , ui(new Ui::Learn)
{
    ui->setupUi(this);
    setWindowTitle(QString("Learning"));
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/icon/pic/book-open-cover.png"));

    Vater = parent;
    book = new Book();
    book->writeFile();

    if(!ordered)
    {
        unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
        std::shuffle(book->unlearnList.begin(),book->unlearnList.end(),std::default_random_engine(seed));
    }
    else
    {
        sort(book->unlearnList.begin(),book->unlearnList.end(),[=](Word *a, Word *b){return a->word < b->word;});
    }

    quizLoop = wordsPerGroup;

    ui->returnButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->returnButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_sign_out));
    ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
    ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star));
    ui->deleteWord->setFont(FontAwesomeIcons::Instance().getFont());
    ui->deleteWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_trash));

    setQuiz();
}

Learn::~Learn()
{
    delete ui;
}

bool wronged = 0;
void Learn::setQuiz()
{
    if(quizLoop == 0)
    {
        quizLoop = wordsPerGroup;
        return;
    }
    selectionList.clear();
    selectionList.append(book->unlearnList);
    selectionList.append(book->learntList);
    selectionList.erase(selectionList.begin());
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    std::shuffle(selectionList.begin(),selectionList.end(),std::default_random_engine(seed));

    ui->wordLabel->setText(book->unlearnList[0]->word);
    QPushButton * selection[4] = {ui->selection_1, ui->selection_2, ui->selection_3, ui->selection_4};
    int answerNum = QRandomGenerator::global()->bounded(0, 3);
    Word * answerWord = book->unlearnList[0];
    wronged = 0;
    for(int i = 0; i < 4; i++)
    {
        if(i == answerNum)
        {
            selection[i]->setText("   "+answerWord->meaning);
            selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(78, 78, 78, 120);border-radius: 10;font-size:16px;");

        }
        else
        {
            selection[i]->setText("   "+selectionList[i]->meaning);
            selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(78, 78, 78, 120);border-radius: 10;font-size:16px;");
            connect(selection[i], &QPushButton::clicked, this, [=]{
                selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(255, 0, 0, 120);border-radius: 10;font-size:16px;");
                wronged = true;
            });
        }
    }
    connect(selection[answerNum], &QPushButton::clicked, this, [=]{
        selection[answerNum]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(0, 170, 127, 120);border-radius: 10;font-size:16px;");


        for(int i = 0; i < 4 ;i++)
            selection[i]->disconnect();
        connect(selection[answerNum], &QPushButton::clicked, this, [=]{
            if(wronged)
            {
                book->unlearnList.insert(quizLoop, answerWord);
                book->unlearnList.erase(book->unlearnList.begin());
                selection[answerNum]->disconnect();
                setQuiz();
            }
            else
            {
                book->learntList.append(answerWord);
                quizLoop--;
                book->unlearnList.erase(book->unlearnList.begin());
                selection[answerNum]->disconnect();
                setQuiz();
            }
        });

    });
}

void Learn::on_returnButton_clicked()
{

    Vater->setWindowIcon(QIcon(":/icon/pic/book1.png"));
    QLabel *label = new QLabel(Vater);
    label->resize(this->size());
    label->setPixmap(Vater->grab());
    label->show();

    Vater->ui->stackedWidget->setCurrentIndex(0);
    Vater->ui->startBG->setStyleSheet("background-color: rgba(0,0,0,0); border-radius:0");
    Vater->ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    Vater->ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));

    QGraphicsBlurEffect *blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(0); //数值越大，越模糊
    Vater->ui->startBG_2->setGraphicsEffect(blureffect);//设置模糊特效

    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", Vater);
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=] {delete label;});

}

bool stared = 0;

void Learn::on_starWord_clicked()
{
    stared = !stared;
    QString wordToStar = ui->wordLabel->text();
    auto key = std::find(book->starList.begin(), book->starList.end(), wordToStar);
    if(stared == false)
    {
        ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
        ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star_o));
        ui->starWord->setStyleSheet("color: rgb(78,78,78); background-color: rgba(255, 255, 255, 0); font-size:16px;")    ;
        if(key != book->starList.end())
            book->starList.erase(key);
    }
    else
    {
        ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
        ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star));
        ui->starWord->setStyleSheet("color:rgb(255, 170, 0); background-color: rgba(255, 255, 255, 0); font-size:16px;")    ;
        if(key == book->starList.end())
            book->starList.append(wordToStar);

    }
}

