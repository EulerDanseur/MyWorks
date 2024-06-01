#ifndef LEARN_H
#define LEARN_H

#include <QWidget>
#include <QMouseEvent>
#include "Start.h"
#include "ui_Start.h"
#include "book.h"
#include <QWebEngineView>

namespace Ui {
class Learn;
}

class Learn : public QWidget
{
    Q_OBJECT

public:
    explicit Learn(Widget *parent = nullptr);
    ~Learn();
    Widget *Vater;
    Book *book;

    int wordsPerGroup = 4;
    bool ordered = 1;
    int quizLoop = 1;
    QVector<Word *> selectionList;
    QWebEngineView *view;

    void setQuiz();
private slots:
    void on_returnButton_clicked();

    void on_starWord_clicked();

    void on_continueButton_clicked();

    void on_nextLoopButton_clicked();

    void on_lexipidia_clicked();

    void on_etym_clicked();

    void on_backButton_clicked();

private:
    Ui::Learn *ui;

};

#endif // LEARN_H
