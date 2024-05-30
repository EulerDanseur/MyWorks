#ifndef LEARN_H
#define LEARN_H

#include <QWidget>
#include <QMouseEvent>
#include "Start.h"
#include "ui_Start.h"
#include "book.h"
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

    int wordsPerGroup = 3;
    bool ordered = 1;
    int quizLoop = 1;
    QVector<Word *> selectionList;
    void setQuiz();
private slots:
    void on_returnButton_clicked();

    void on_starWord_clicked();

private:
    Ui::Learn *ui;

};

#endif // LEARN_H
