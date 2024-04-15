#pragma once

#include <QtWidgets/QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

extern int board[4][4];
extern int score;
extern int movable;

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class Square : public QPushButton
{
    Q_OBJECT
public:   
    void Style(int* value);

private:

};

class My2048 : public QWidget
{
    Q_OBJECT

public:
    My2048(QWidget *parent = nullptr);
    ~My2048();

    //get the key and make reflections
    void keyPressEvent(QKeyEvent* event);

    //diaplay the general board
    void Board();

    //clear the general board
    void ClearBoard();

    //print the board body
    void PrintBoard();

    //print the score label
    void PrintScore();

    //print the bottom line
    void PrintBottom();

    
    //print the start interface
    void StartBoard();

    //initialize the game
    void GameStart();

    //print the end interface
    void GameEnd();

    

private:

    // main layout
    QVBoxLayout* mainLayout;
    // grid layout of board
    QGridLayout* boardLayout;
    //Bottom layout of Buttons
    QHBoxLayout* bottomLayout;
    bool bottomLayoutcleared = 0;

    // score widget
    QLabel* point;

    //the squares
    Square* square[16];

    //start interface components
    QPushButton* startButton;
    QLabel* starttext;
    QLabel* sttext;
    
    //end interface components
    QPushButton* endButton;
    QLabel* endtext;

    //the flag that gamestart
    bool gamestart = 0;

    //bonuses
    QPushButton* bonusButton;
    QLabel* bonustext;
    QPushButton* bonusback;
    bool bonusbackcleared = 0;
    bool bonustextcleared = 0;
    bool bonusActive = 0;

    //menu components
    QPushButton* menuButton;
    QPushButton* restart;
    QPushButton* back;
    QPushButton* Exit;
    QLabel* menutext;
    bool menuActive = 0;
    

private slots:
    void StartClicked();
    
    //connected when bonusbutton clicked
    void PrintBonus();
    //connect to each buttons
    void Bonus(int i);
    
    void PrintMenu();
};
