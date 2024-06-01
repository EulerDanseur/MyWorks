#include "learn.h"
#include "ui_learn.h"
#include "icon.h"
#include <QThread>
#include <QParallelAnimationGroup>
#include <random>
#include <algorithm>
#include <QRandomGenerator>
#include "animationeffect.h"

bool stared = 0;

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
    //book->writeFile();
    view = new QWebEngineView();
    ui->webLayer->addWidget(view);
    if(!ordered)
    {
        unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
        std::shuffle(book->unlearntList.begin(),book->unlearntList.end(),std::default_random_engine(seed));
    }
    else
    {
        sort(book->unlearntList.begin(),book->unlearntList.end(),[=](Word *a, Word *b){return a->word < b->word;});
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
    delete book;
}

bool wronged = 0;
void Learn::setQuiz()
{
    if(quizLoop == 0)
    {
        quizLoop = wordsPerGroup;
        animate(this);
        ui->stackedWidget->setCurrentWidget(ui->endpage);
        return;
    }

    animate(this);


    stared = true;
    on_starWord_clicked();

    selectionList.clear();
    selectionList.append(book->unlearntList);
    selectionList.append(book->learntList);
    selectionList.erase(selectionList.begin());
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    std::shuffle(selectionList.begin(),selectionList.end(),std::default_random_engine(seed));
    if(!ordered)
    {
        unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
        std::shuffle(book->unlearntList.begin(),book->unlearntList.end(),std::default_random_engine(seed));
    }
    else
    {
        sort(book->unlearntList.begin(),book->unlearntList.end(),[=](Word *a, Word *b){return a->word < b->word;});
    }
    ui->wordLabel->setText(book->unlearntList[0]->word);
    ui->pronunciation->setText(book->unlearntList[0]->pronunciation);
    ui->stackedWidget->setCurrentWidget(ui->quizpage);
    ui->wordstack->setCurrentWidget(ui->select);
    QPushButton * selection[4] = {ui->selection_1, ui->selection_9, ui->selection_3, ui->selection_4};
    int answerNum = QRandomGenerator::global()->bounded(0, 3);
    Word * answerWord = book->unlearntList[0];
    wronged = 0;
    for(int i = 0; i < 4; i++)
    {
        if(i == answerNum)
        {
            selection[i]->setText("   "+answerWord->meaning[0]);
            selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(78, 78, 78, 120);border-radius: 10;font-size:16px;");

        }
        else
        {
            selection[i]->setText("   "+selectionList[i]->meaning[0]);
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

        animate(this);
        ui->wordstack->setCurrentWidget(ui->wordinfo);
        ui->wordMeaning->setText(book->unlearntList[0]->meaning.join("\n"));


            if(wronged)
            {
                book->unlearntList.insert(quizLoop, answerWord);
                book->unlearntList.erase(book->unlearntList.begin());
            }
            else
            {
                book->learntList.append(answerWord);
                quizLoop--;
                book->unlearntList.erase(book->unlearntList.begin());
                answerWord->learnt = true;
            }

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

    Vater->ui->startBG_2->graphicsEffect()->setEnabled(0);//设置模糊特效

    QGraphicsOpacityEffect  *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", Vater);
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=] {delete OpacityImage; delete label;});

}


void Learn::on_starWord_clicked()
{
    stared = !stared;
    QString thisword = ui->wordLabel->text();
    Word wordToStar;
    if(book->wordList.find(thisword)!=book->wordList.end())
        wordToStar = book->wordList[thisword];
    auto key = std::find(book->starList.begin(), book->starList.end(), wordToStar);

    //bug might happen when quitting with a star event and then reload the program

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
    //book->writeFile();
}


void Learn::on_continueButton_clicked()
{
    setQuiz();
}


void Learn::on_nextLoopButton_clicked()
{
    setQuiz();
}


void Learn::on_lexipidia_clicked()
{
    QString address = QString("https://www.lexipedia.com/english/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    view->setStyleSheet("background:transparent");
    auto webEnginePage = view->page();
    webEnginePage->setBackgroundColor(QColor(0,0,0,0));
    view->setZoomFactor(0.75);
    view->load(address);
    view->resize(ui->webPage->size());

    animate(this);

    ui->stackedWidget->setCurrentWidget(ui->webPage);
}


void Learn::on_etym_clicked()
{
    QString address = QString("https://www.etymonline.com/word/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    view->setStyleSheet("background:transparent");
    auto webEnginePage = view->page();
    webEnginePage->setBackgroundColor(QColor(0,0,0,0));
    view->setZoomFactor(0.75);
    view->load(address);
    view->resize(ui->webPage->size());

    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->webPage);
}


void Learn::on_backButton_clicked()
{
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->quizpage);
}

