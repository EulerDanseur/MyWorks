#include "learn.h"
#include "ui_learn.h"
#include "icon.h"
#include <QThread>
#include <QParallelAnimationGroup>
#include <random>
#include <algorithm>
#include <QRandomGenerator>
#include <QRegularExpression>
#include "animationeffect.h"

bool stared = 0;

Learn::Learn(Widget *parent)
    : QWidget(parent), ui(new Ui::Learn)
{
    ui->setupUi(this);
    setWindowTitle(QString("Learning"));
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/icon/pic/book-open-cover.png"));

    Vater = parent;
    book = new Book;
    // 排序
    if (!ordered)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(book->unlearntList.begin(), book->unlearntList.end(), std::default_random_engine(seed));
    }
    else
    {
        sort(book->unlearntList.begin(), book->unlearntList.end(), [=](Word *a, Word *b)
             { return a->word.compare(b->word, Qt::CaseInsensitive) >= 0 ? 0 : 1; });
    }
     // sort(book->learntList.begin(), book->learntList.end(), [=](Word *a, Word *b)
     //     { return a < b;});

    sort(book->learntList.begin(), book->learntList.end(), [=](Word *a, Word *b)
     { return a->word.compare(b->word, Qt::CaseInsensitive) >= 0 ? 0 : 1; });

    // 设置图标
    ui->returnButton->setFont(FontAwesomeIcons::Instance().getFont());
    ui->returnButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_sign_out));
    ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
    ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star));

    // 设置网页
    viewLexipidia = new QWebEngineView();
    auto webEnginePageLex = viewLexipidia->page();
    webEnginePageLex->setBackgroundColor(QColor(0, 0, 0, 0));
    viewLexipidia->setZoomFactor(0.75);
    viewLexipidia->resize(ui->webPage->size());

    viewEtym = new QWebEngineView();
    auto webEnginePageEtym = viewEtym->page();
    webEnginePageEtym->setBackgroundColor(QColor(0, 0, 0, 0));
    viewEtym->setZoomFactor(0.75);
    viewEtym->resize(ui->webPage->size());

    ui->tabLexLayer->addWidget(viewLexipidia);
    ui->tabEtymLayer->addWidget(viewEtym);

    // 设置背词循环
    setQuiz();
}

Learn::~Learn()
{
    QFile file(QString("mode.txt"));
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out << book->name <<' '<< wordsPerGroup<<' ' << ordered<<' '<< mode;
        file.close();
    }

    delete ui;
    delete book;
}

bool wronged = 0;

void Learn::setQuiz()
{
    // 结束一组单词
    if (quizLoop == wordsPerGroup)
    {
        quizLoop = 0;
        animate(this);
        ui->stackedWidget->setCurrentWidget(ui->endpage);
        return;
    }

    // 设置选项
    animate(this);

    QPushButton *selection[4] = {ui->selection_1, ui->selection_9, ui->selection_3, ui->selection_4};
    for (int i = 0; i < 4; i++)
        selection[i]->disconnect();

    // 设置单词收藏
    stared = false;
    if (stared == false)
    {
        ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
        ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star_o));
        ui->starWord->setStyleSheet("color: rgb(78,78,78); background-color: rgba(255, 255, 255, 0); font-size:16px;");
    }

    // 设置选项
    selectionList.clear();
    selectionList.append(book->unlearntList);
    selectionList.append(book->learntList);
    selectionList.erase(selectionList.begin());

    // 随机抽取无关选项
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(selectionList.begin(), selectionList.end(), std::default_random_engine(seed));

    //插入ui
    ui->stackedWidget->setCurrentWidget(ui->quizpage);
    ui->wordstack->setCurrentWidget(ui->select);

    // 随机抽取答案序号
    int answerNum = QRandomGenerator::global()->bounded(0, 4);
    Word *answerWord = book->unlearntList[0];
    wronged = 0;
    QString shortedMeaning;

    // 设置答案
    if (mode)
    {
        ui->wordLabel->setText(answerWord->word);
        ui->pronunciation->setText(answerWord->pronunciation);
    }
    else
    {
        if (answerWord->meaning[0].length() <= 15)
            shortedMeaning = answerWord->meaning[0];
        else
        {
            QStringList temp = answerWord->meaning[0].split(",");
            temp.pop_back();
            shortedMeaning = temp.join(",");
        }
        ui->wordLabel->setText(shortedMeaning);
        ui->pronunciation->setText("");
    }

    for (int i = 0; i < 4; i++)
    {
        // 设置选项
        selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(78, 78, 78, 120);border-radius: 10;font-size:16px;");

        if (i == answerNum)
        {
            if (mode)
            {
                // 设置答案, 去长串
                if (answerWord->meaning[0].length() <= 15)
                    shortedMeaning = answerWord->meaning[0];
                else
                {
                    QStringList temp = answerWord->meaning[0].split(",");
                    if (temp.size() > 1)
                        temp.pop_back();
                    shortedMeaning = temp.join(",");
                }

                selection[i]->setText("   " + shortedMeaning);
            }
            else
                selection[i]->setText("   " + answerWord->word);
        }
        else
        {
            if (mode)
            {
                // 设置选项, 去长串
                if (answerWord->meaning[0].length() <= 15)
                    shortedMeaning = selectionList[i]->meaning[0];
                else
                {
                    QStringList temp = selectionList[i]->meaning[0].split(",");
                    if (temp.size() > 1)
                        temp.pop_back();
                    shortedMeaning = temp.join(",");
                }

                // 设置选项
                selection[i]->setText("   " + shortedMeaning);
            }
            else
                selection[i]->setText("   " + selectionList[i]->word);

            // 设置错误选项选项点击
            connect(selection[i], &QPushButton::clicked, this, [=]
                    {
                selection[i]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(255, 0, 0, 120);border-radius: 10;font-size:16px;");
                wronged = true; });
        }
    }

    // 设置答案选项
    connect(selection[answerNum], &QPushButton::clicked, this, [=]
            {
                selection[answerNum]->setStyleSheet("text-align : left;color: rgb(255,255,255); background-color:rgba(0, 170, 127, 120);border-radius: 10;font-size:16px;");

                // 断开信号
                for (int i = 0; i < 4; i++)
                    selection[i]->disconnect();

                animate(this);
                ui->wordstack->setCurrentWidget(ui->wordinfo);
                ui->wordMeaning->setText(book->unlearntList[0]->meaning.join("\n"));
                ui->wordLabel->setText(book->unlearntList[0]->word);

                // 错误过则需要重新选择
                if (wronged)
                {
                    book->unlearntList.insert(wordsPerGroup - quizLoop, answerWord);
                    book->unlearntList.erase(book->unlearntList.begin());
                }
                else
                {
                    book->learntList.append(answerWord);
                    quizLoop++;
                    book->unlearntList[0]->learnt = true;
                    book->unlearntList.erase(book->unlearntList.begin());
                }
            });
}
void Learn::on_returnButton_clicked()
{
    // 退出学习
    Vater->setWindowIcon(QIcon(":/icon/pic/book1.png"));
    QLabel *label = new QLabel(Vater);
    label->resize(this->size());
    label->setPixmap(Vater->grab());
    label->show();

    // 设置icon
    Vater->ui->stackedWidget->setCurrentIndex(0);
    Vater->ui->startBG->setStyleSheet("background-color: rgba(0,0,0,0); border-radius:0");
    Vater->ui->titleBarIcon->setFont(FontAwesomeIcons::Instance().getFont());
    Vater->ui->titleBarIcon->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_book));

    Vater->ui->startBG_2->graphicsEffect()->setEnabled(0); // 设置模糊特效

    QGraphicsOpacityEffect *OpacityImage = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(OpacityImage);
    QPropertyAnimation *animation = new QPropertyAnimation(OpacityImage, "opacity", Vater);
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0.0);
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=]
            {delete animation; delete OpacityImage; delete label; });
}

void Learn::on_starWord_clicked()
{
    // 点击收藏
    stared = !stared;
    QString thisword = ui->wordLabel->text();
    Word wordToStar;
    if (book->wordList.find(thisword) != book->wordList.end())
        wordToStar = book->wordList[thisword];
    auto key = std::find(book->starList.begin(), book->starList.end(), wordToStar);

    // 收藏
    if (stared == false)
    {
        ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
        ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star_o));
        ui->starWord->setStyleSheet("color: rgb(78,78,78); background-color: rgba(255, 255, 255, 0); font-size:16px;");
        if (key != book->starList.end())
            book->starList.erase(key);
    }
    else
    {
        ui->starWord->setFont(FontAwesomeIcons::Instance().getFont());
        ui->starWord->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_star));
        ui->starWord->setStyleSheet("color:rgb(255, 170, 0); background-color: rgba(255, 255, 255, 0); font-size:16px;");
        if (key == book->starList.end())
            book->starList.append(wordToStar);
    }
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
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->webPage);
    ui->tabWidget->setCurrentWidget(ui->tabLex);
    viewLexipidia->setStyleSheet("background:transparent");
    QString address = QString("https://www.lexipedia.com/english/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    viewLexipidia->load(address);
    viewEtym->setStyleSheet("background:transparent");
    address = QString("https://www.etymonline.com/word/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    viewEtym->load(address);
}

void Learn::on_etym_clicked()
{
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->webPage);
    ui->tabWidget->setCurrentWidget(ui->tabEtym);
    viewEtym->setStyleSheet("background:transparent");
    QString address = QString("https://www.etymonline.com/word/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    viewEtym->load(address);
    viewLexipidia->setStyleSheet("background:transparent");
    address = QString("https://www.lexipedia.com/english/%1").arg(ui->wordLabel->text());
    qDebug() << address;
    viewLexipidia->load(address);
}

void Learn::on_backButton_clicked()
{
    animate(this);
    ui->stackedWidget->setCurrentWidget(ui->quizpage);
}
