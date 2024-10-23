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
    // 指示父节点
    Widget *Vater;
    
    // 词库
    Book *book;

    //每组词数
    int wordsPerGroup = 5;
    
    // 排序
    int ordered = 1;
    
    // 选择模式
    int mode = 1;
    
    // 选择的词
    int quizLoop = 0;
    
    // 选项
    QVector<Word *> selectionList;
    
    // 网页
    QWebEngineView *viewLexipidia;
    QWebEngineView *viewEtym;

    //设置背词
    void setQuiz();
    
private slots:
    //返回键
    void on_returnButton_clicked();

    //收藏
    void on_starWord_clicked();

    //继续
    void on_continueButton_clicked();

    //下一组
    void on_nextLoopButton_clicked();

    //lexipidia
    void on_lexipidia_clicked();

    //etymology
    void on_etym_clicked();

    //返回
    void on_backButton_clicked();


private:
    Ui::Learn *ui;

};

#endif // LEARN_H
