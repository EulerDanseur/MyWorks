#pragma once

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include <QPushButton>


class Square : public QLabel
{
    Q_OBJECT
public:
    void Style(int value);

private:
    int value;


};

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget* parent = 0);
    
    void keyPressEvent(QKeyEvent* event);
    
    void Board();

    void ClearBoard();

    void PrintBoard();

    void PrintScore();

    void StartBoard();

    void GameStart();

    //void EndBoard();
    
    void GameEnd();

private:

    // main layout
    QVBoxLayout* mainLayout;
    // grid layout of board
    QGridLayout* boardLayout;

    
    QPushButton* startButton;
    QLabel* starttext;
    QPushButton* endButton;
    QLabel endtext;
    // score widget
    QLabel* point;

    Square* square[16];

    //Ui::StartUi* 
    bool gamestart = 0;

private slots:
    void StartClicked();
    void EndClicked();

};

