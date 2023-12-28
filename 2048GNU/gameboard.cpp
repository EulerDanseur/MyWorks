#include "gameboard.h"
#include "number.h"
#include "move.h"
//#include "bonus.h"
//#include "startandend.h"
//#include "startFace.h"
#include <QGraphicsDropShadowEffect>

extern int board[4][4];
extern int score;

GameBoard::GameBoard(QWidget* parent) :
    QWidget(parent)
{
    // set default size
    resize(900, 650);

    // initialize the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // initialize the board layout
    boardLayout = new QGridLayout();
    setStyleSheet("GameBoard { background-color: rgb(187,173,160) }");
    
    //initialize the squares widgets
    for (int i = 0; i < 16; i++)
    {
        square[i] = new Square();
    }

    //initialize score widgets
    point = new QLabel();

    StartBoard();

}

void GameBoard::StartBoard()
{
    starttext = new QLabel(" 2 0 4 8 ");
    starttext->setAlignment(Qt::AlignCenter);
    starttext->setObjectName(QString::fromUtf8("label"));
    starttext->setGeometry(QRect(230, 110, 151, 61));
    starttext->setStyleSheet(QString::fromUtf8("		\n"
        "		color: rgb(255, 191, 102);\n"
        "	 	\n"
        "		font: 80pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		"));
    mainLayout->insertWidget(0, starttext);
    
        startButton = new QPushButton("  Start!  ");
        startButton->setObjectName(QString::fromUtf8("pushButton"));
        startButton->setGeometry(QRect(210, 240, 171, 61));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
            "	\n"
            "		background: rgb(238,228,218); \n"
            "		color: rgb(119,110,101);\n"
            "	 	font: 40pt \"Agency FB\";\n"
            "		border-radius: 10px; \n"
            "		\n"
            "\n"
            "\n"
            "		\n"
            "}"));
        

        mainLayout->insertWidget(1, startButton, 0, Qt::AlignCenter);

        connect(startButton, SIGNAL(clicked()), this, SLOT(StartClicked()));

}

void GameBoard::StartClicked()
{
    mainLayout->removeWidget(starttext);
    mainLayout->removeWidget(startButton);
    delete starttext;
    delete startButton;

    GameStart();

    Board();
}

void GameBoard::Board()
 {
     ClearBoard();

     PrintBoard();
  
     PrintScore();

 }

void GameBoard::ClearBoard()
{
    boardLayout->removeWidget(point);
    //delete point;
    for (int i = 0; i < 16; i++)
    {
        boardLayout->removeWidget(square[i]);
        delete square[i];
    }
    delete boardLayout;
}

void GameBoard::PrintBoard()
{
    boardLayout = new QGridLayout();
    for (int i = 0; i < 16; i++)
    {
        square[i] = new Square();
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int value = board[i][j];
            square[PlaceToOrder(i, j)]->Style(value);
            boardLayout->addWidget(square[PlaceToOrder(i, j)], i, j);
        }
    }
    mainLayout->insertLayout(0, boardLayout);

}

void GameBoard::PrintScore()
{
    delete point;
    point = new QLabel(QString("score: %1").arg(QString::number(score)));
    point->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    point->setFixedHeight(50);
    mainLayout->insertWidget(1, point, 0, Qt::AlignLeft);
}

void GameBoard::keyPressEvent(QKeyEvent* event) 
{
    if (!gamestart) return;
    int vacantRange = 14;
    int vacantOrder[16] = { 0 };

    auto flag = event->key();

    switch (flag)
    {
    

        case Qt::Key_W: 
        case Qt::Key_S:
        case Qt::Key_A:
        case Qt::Key_D:
        {
            //move by the direction
            Move(flag);

            //generate new num
            vacantRange = VacantAmount(vacantOrder, vacantRange);
            GenerateNum(vacantOrder, vacantRange);

            break;
        }
    }


    if ( (vacantRange > 0 || IfCombinable() ) && !If2048() )
    {
        Board();
    }
    else 
    {
        GameEnd();
    }
     

 }

void GameBoard::GameStart()
{
    gamestart = 1;

    rand();

    int corner[4] = { 0, 3, 12, 15 };

    int first = 3 * rand() / RAND_MAX;
    board[OrderToRow(corner[first])][OrderToCol(corner[first])] = 2;

    int second = 0;
    do
    {
        second = 15 * rand() / RAND_MAX;

    } while (second == corner[first]);

    board[OrderToRow(second)][OrderToCol(second)] = 2;

}

void GameBoard::GameEnd()
{
    gamestart = 0;
    
    ClearBoard();

    if (If2048())
        endtext.setText("You win!");
    else
        endtext.setText("What a pity!");
        endtext.setAlignment(Qt::AlignCenter);
        endtext.setObjectName(QString::fromUtf8("label"));
        endtext.setGeometry(QRect(230, 110, 151, 61));
        endtext.setStyleSheet(QString::fromUtf8("		\n"
        "		color: rgb(255, 191, 102);\n"
        "	 	\n"
        "		font: 60pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		"));

    mainLayout->insertWidget(0, &endtext);

    endButton = new QPushButton("  Bye!  ");
    endButton->setObjectName(QString::fromUtf8("pushButton"));
    endButton->setGeometry(QRect(210, 240, 171, 61));
    endButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(238,228,218); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 40pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));


    mainLayout->insertWidget(1, endButton, 0, Qt::AlignCenter);

    connect(endButton, SIGNAL(clicked()), this, SLOT(EndClicked()));
}

void GameBoard::EndClicked()
{
    exit(0);
}

void Square::Style(int value)
{
    setAlignment(Qt::AlignCenter);
    setText(QString::number(value));
    auto style = QString("Square { background: %1; color: %2; font: bold; border-radius: 10px; font: 40pt; }");
    switch (value) 
    {
    case 2: 
    {
        setStyleSheet(style.arg("rgb(238,228,218)").arg("rgb(119,110,101)"));
        break;
    }
    case 4: 
    {
        setStyleSheet(style.arg("rgb(237,224,200)").arg("rgb(119,110,101)"));
        break;
    }
    case 8: 
    {
        setStyleSheet(style.arg("rgb(242,177,121)").arg("rgb(255,255,255)"));
        break;
    }
    case 16: 
    {
        setStyleSheet(style.arg("rgb(245,150,100)").arg("rgb(255,255,255)"));
        break;
    }
    case 32: 
    {
        setStyleSheet(style.arg("rgb(245,125,95)").arg("rgb(255,255,255)"));
        break;
    }
    case 64: 
    {
        setStyleSheet(style.arg("rgb(245,95,60)").arg("rgb(255,255,255)"));
        break;
    }
    case 128: 
    {
        setStyleSheet(style.arg("rgb(237,207,114)").arg("rgb(255,255,255)"));
        break;
    }
    case 256: 
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(20);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 512: 
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(30);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 1024: 
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(40);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 2048: 
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(50);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    default: {
        setText("");
        setStyleSheet("Square{ background: rgb(204,192,179); border-radius: 10px; }");
    }
    }

}
