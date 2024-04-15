#include "My2048.h"
#include "move.h"
#include "number.h"

My2048::My2048(QWidget *parent)
    : QWidget(parent)
{

    // set default size
    resize(860, 900);

    // initialize the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // initialize the board layout
    boardLayout = new QGridLayout();
    setStyleSheet("My2048 { background-color: rgb(187,173,160) }");

    //initialize the squares widgets
    for (int i = 0; i < 16; i++)
    {
        square[i] = new Square();
    }

    //initialize score widgets
    point = new QLabel();

    bottomLayout = new QHBoxLayout();

    bonusButton = new QPushButton();

    bonustext = new QLabel("Remove one square! (score -100)");

    menuButton = new QPushButton();

    bonusback = new QPushButton("<- Back");

    StartBoard();
}

My2048::~My2048()
{

}

void My2048::StartBoard()
{
    gamestart = 0;
    
    //the realise of starttext
    starttext = new QLabel(" 2 0 4 8");
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

    sttext = new QLabel("Welcome to the captivating world of 2048 \n a mesmerizing puzzle experience\nyour mission is to slide, merge, \nand strategize your way to \nthe elusive tile with the number 2048.");
    sttext->setAlignment(Qt::AlignCenter);
    sttext->setObjectName(QString::fromUtf8("label"));
    sttext->setGeometry(QRect(230, 110, 151, 61));
    sttext->setStyleSheet(QString::fromUtf8("		\n"
        "		color: rgb(245,95,60);\n"
        "	 	\n"
        "		font: 18pt \"Code new roman\";\n"
        "		border-radius: 10px; \n"
        "		"));
    mainLayout->insertWidget(2, sttext);


    //the realise of startbutton
    startButton = new QPushButton("  Start!  ");
    startButton->setObjectName(QString::fromUtf8("pushButton"));
    startButton->setGeometry(QRect(210, 240, 171, 61));
    startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        //"       background:  rgb(187,173,160); \n"
        "		background: rgb(238,228,218); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 40pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));

   
    //insert the components into the mainlayout
    mainLayout->insertWidget(0, startButton, 0, Qt::AlignCenter);

    connect(startButton, SIGNAL(clicked()), this, SLOT(StartClicked()));

}

void My2048::StartClicked()
{
    //remove start interface
    mainLayout->removeWidget(starttext);
    mainLayout->removeWidget(startButton);
    delete sttext;
    delete starttext;
    delete startButton;

    GameStart();

    Board();
}

void My2048::Board()
{
    ClearBoard();

    PrintBoard();

    PrintScore();

    PrintBottom();
}

void My2048::ClearBoard()
{
    //clean the point
    boardLayout->removeWidget(point);
    delete point;

    //clean the bottom
    if(!bottomLayoutcleared)
    {
        delete bonusButton;
        delete menuButton;
        delete bottomLayout;
        bottomLayoutcleared = 1;
    }

    //clean the board
    for (int i = 0; i < 16; i++)
    {
        boardLayout->removeWidget(square[i]);
        delete square[i];
    }
    delete boardLayout;
    
    
}

void My2048::PrintBoard()
{
    //reset boardlayout and square
    boardLayout = new QGridLayout();
    for (int i = 0; i < 16; i++)
    {
        square[i] = new Square();
    }
    
    //plug in the squares
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            square[PlaceToOrder(i, j)]->Style(&board[i][j]);
            boardLayout->addWidget(square[PlaceToOrder(i, j)], i, j);
        }
    }


    mainLayout->insertLayout(1, boardLayout, 0);

}

void My2048::PrintScore()
{
    point = new QLabel(QString("score: %1").arg(QString::number(score)));
    point->setStyleSheet("QLabel { color: rgb(235,224,214); font: 30pt \"Agency FB\";}");
    point->setFixedHeight(50);

    mainLayout->insertWidget(0, point, 0, Qt::AlignLeft);
}

void My2048::PrintBottom()
{
    //create a horizontal layout to create a place to the bonusbutton and menubutton
    bottomLayout = new QHBoxLayout();
    bottomLayoutcleared = 0;

    //create bonus button
    bonusButton = new QPushButton("Bonus");
    bonusButton->setObjectName(QString::fromUtf8("pushButton"));
    bonusButton->setGeometry(QRect(210, 240, 171, 61));
    bonusButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    bottomLayout->insertWidget(0, bonusButton, 0);
    connect(bonusButton, SIGNAL(clicked()), this, SLOT(PrintBonus()));

    //crate the menu button
    menuButton = new QPushButton("Menu");
    menuButton->setObjectName(QString::fromUtf8("pushButton"));
    menuButton->setGeometry(QRect(210, 240, 171, 61));
    menuButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    bottomLayout->insertWidget(1, menuButton, 0);
    connect(menuButton, SIGNAL(clicked()), this, SLOT(PrintMenu()));

    //insert the bottom into the mainlayout
    mainLayout->insertLayout(2, bottomLayout, 0);
}

void My2048::keyPressEvent(QKeyEvent* event)
{
    //ban the keypress when some circumstances
    if (!gamestart || bonusActive || menuActive) return;
    
    int vacantRange = 14;
    int vacantOrder[16] = { 0 };

    auto flag = event->key();

    switch (flag)
    {

    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Right:
    case Qt::Key_Left:
    case Qt::Key_W:
    case Qt::Key_S:
    case Qt::Key_A:
    case Qt::Key_D:
    {


        //move by the direction
        Move(flag);

        //generate new num
        vacantRange = VacantAmount(vacantOrder, vacantRange);

        if (movable)
        {  
            GenerateNum(vacantOrder, vacantRange);
        }
        else
            score++;

        movable = 0;

        break;
    }
    }


    if ((vacantRange > 0 || IfCombinable()) && !If2048())
    {
        Board();
    }
    else
    {
        GameEnd();
    }


}

void My2048::PrintBonus()
{
    
    ClearBoard();
    bonusActive = 1;

    PrintBoard();
    
    PrintScore();
    
    //realise back button
    bonusback = new QPushButton("<- Back");
    bonusback->setObjectName(QString::fromUtf8("pushButton"));
    bonusback->setGeometry(QRect(210, 240, 171, 61));
    bonusback->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    bonusbackcleared = 0;
    mainLayout->insertWidget(3, bonusback);
    
    //realise the back operation with lambda sentences
    connect(bonusback, &QPushButton::clicked, this, [&] {
            if (!bonustextcleared)
            {
                mainLayout->removeWidget(bonustext);
                delete bonustext;
                bonustextcleared = 1;
            }
            if (!bonusbackcleared)
            {
                mainLayout->removeWidget(bonusback);
                delete bonusback;
                bonusbackcleared = 1;
            }
            
            bonusActive = 0;

            Board();
        });

    //realise the explaination of the bonus effect
    bonustext = new QLabel("Remove one square! (score -100)");
    bonustext->setAlignment(Qt::AlignCenter);
    bonustext->setObjectName(QString::fromUtf8("label"));
    bonustext->setFixedHeight(70);
    bonustext->setStyleSheet(QString::fromUtf8("QLabel{\n"
        "	\n"
       // "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    bonustextcleared = 0;
    mainLayout->insertWidget(0, bonustext);
   
        for (int i = 0; i < 16; i++)
        {
            if (board[i / 4][i % 4] != 0)
            {
                connect(square[i], &QPushButton::clicked, this, [=] {
                    if (score < 100)
                    {
                        bonustext->setText("Your score is NOT enough!");
                        bonustext->setStyleSheet(QString::fromUtf8("QLabel{\n"
                            "	\n"
                            //"		background: rgb(204, 192, 179); \n"
                            //"		background: rgb(187, 173, 160); \n"
                            //"		color: rgb(119,110,101);\n"
                            "color: rgb(237, 207, 114); "
                            "	 	font: 25pt \"Agency FB\";\n"
                            "		border-radius: 10px; \n"
                            "		\n"
                            "\n"
                            "\n"
                            "		\n"
                            "}"));
                        return;
                    }
                    else
                        Bonus(i);
                    });

            }
        }
    
}

void My2048::Bonus(int i)
{
    score -= 100;
    board[i / 4][i % 4] = 0;

    if (!bonustextcleared) 
    {
        mainLayout->removeWidget(bonustext);
        delete bonustext;
        bonustextcleared = 1;
    }
    if (!bonusbackcleared)
    {
        mainLayout->removeWidget(bonusback);
        delete bonusback;
        bonusbackcleared = 1;
    }
    
    bonusActive = 0;

    Board();

    
}

void My2048::PrintMenu()
{
    ClearBoard();
    menuActive = 1;

    //realise menu title
    menutext = new QLabel();
    menutext->setText("M E N U");
    menutext->setAlignment(Qt::AlignCenter);
    menutext->setObjectName(QString::fromUtf8("label"));
    menutext->setFixedHeight(70);
    menutext->setStyleSheet(QString::fromUtf8("QLabel{\n"
        "	\n"
         //"		background: rgb(204,192,179); \n"
         "		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 40pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    mainLayout->insertWidget(0, menutext);


    //backbutton    
    back = new QPushButton("<- Back");
    back->setObjectName(QString::fromUtf8("pushButton"));
    back->setGeometry(QRect(210, 240, 171, 61));
    back->setFixedWidth(270);
    back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));
    
    mainLayout->insertWidget(1, back, 0, Qt::AlignHCenter);
    
   
    //restart button
    restart = new QPushButton("Restart");
    restart->setObjectName(QString::fromUtf8("pushButton"));
    restart->setGeometry(QRect(210, 240, 171, 61));
    restart->setFixedWidth(270);
    restart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));

    mainLayout->insertWidget(2, restart, 0, Qt::AlignHCenter);

    
    //exit button
    Exit = new QPushButton("Exit");
    Exit->setObjectName(QString::fromUtf8("pushButton"));
    Exit->setGeometry(QRect(210, 240, 171, 61));
    Exit->setFixedWidth(270);
    Exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
        "	\n"
        "		background: rgb(204,192,179); \n"
        //"		background: rgb(187, 173, 160); \n"
        "		color: rgb(119,110,101);\n"
        "	 	font: 25pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		\n"
        "\n"
        "\n"
        "		\n"
        "}"));

    mainLayout->insertWidget(3, Exit, 0, Qt::AlignHCenter);
    

    connect(back, &QPushButton::clicked, this, [&] {
        menuActive = 0;
        delete Exit;
        delete restart;
        delete back;
        delete menutext;
        PrintBoard();
        PrintScore();
        PrintBottom();
        });

    connect(restart, &QPushButton::clicked, this, [&] {
        menuActive = 0;
        delete Exit;
        delete restart;
        delete back;
        delete menutext;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                board[i][j] = 0;
        
        GameStart();
        PrintBoard();
        PrintScore();
        PrintBottom();

        });

    connect(Exit, &QPushButton::clicked, this, [&] {
        menuActive = 0;
        exit(0);
        });

    
}

void My2048::GameStart()
{
    gamestart = 1;
    score = 0;
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

void My2048::GameEnd()
{
    gamestart = 0;

    
    //end title
    endtext = new QLabel();
    if (If2048())
    {
        ClearBoard();
        PrintBoard();
        endtext->setText("You win!");
    }
    else
    {
        ClearBoard();
        endtext->setText("What a pity!");
    }
    endtext->setAlignment(Qt::AlignCenter);
    endtext->setObjectName(QString::fromUtf8("label"));
    endtext->setGeometry(QRect(230, 110, 151, 61));
    endtext->setStyleSheet(QString::fromUtf8("		\n"
        "		color: rgb(255, 191, 102);\n"
        "	 	\n"
        "		font: 60pt \"Agency FB\";\n"
        "		border-radius: 10px; \n"
        "		"));

    mainLayout->insertWidget(0, endtext);

    //end button
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


    
    PrintScore();
    
    //restart button
    restart = new QPushButton("Restart");
    restart->setObjectName(QString::fromUtf8("pushButton"));
    restart->setGeometry(QRect(210, 240, 171, 61));
    restart->setFixedWidth(270);
    restart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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


    mainLayout->insertWidget(2, restart, 0, Qt::AlignHCenter);

    mainLayout->insertWidget(3, endButton, 0, Qt::AlignCenter);

    connect(endButton, &QPushButton::clicked, this, [&]{ exit(0); });

    connect(restart, &QPushButton::clicked, this, [&] {
        //menuActive = 0;
        
        delete restart;
        delete endButton;
        delete endtext;
        delete point;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                board[i][j] = 0;
        GameStart();
        PrintBoard();
        PrintScore();
        PrintBottom();

        });

}

void Square::Style(int* value)
{
    setFixedHeight(200);
    
    setText(QString::number(*value));
    
    if (*value > 4096)
    {
        *value %= 4096;
        setText(QString::number(*value));
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(QColor(0, 245, 150, 100));
        shadow->setBlurRadius(70);
        shadow->setOffset(1);
        setGraphicsEffect(shadow);
    }

    switch (*value)
    {
    case 2:
    {
        setStyleSheet("Square { background: rgb(238,228,218); color: rgb(119,110,101); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 4:
    {
        setStyleSheet("Square { background: rgb(237,224,200); color: rgb(119,110,101); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 8:
    {
        setStyleSheet("Square { background: rgb(242,177,121); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 16:
    {
        setStyleSheet("Square { background: rgb(245,150,100); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 32:
    {
        setStyleSheet("Square { background: rgb(245,125,95); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 64:
    {
        setStyleSheet("Square { background: rgb(245,95,60); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 128:
    {
        setStyleSheet("Square { background: rgb(237,207,114); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 256:
    {

        setStyleSheet("Square { background: rgb(237,204,97); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 512:
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(30);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet("Square { background: rgb(237,204,97); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 1024:
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(40);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet("Square { background: rgb(237,204,97); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    case 2048:
    {
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
        shadow->setColor(Qt::yellow);
        shadow->setBlurRadius(50);
        shadow->setOffset(-1);
        setGraphicsEffect(shadow);
        setStyleSheet("Square { background: rgb(237,204,97); color: rgb(255,255,255); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
        break;
    }
    default: 
    {
        if (*value < 0)
        {
            *value *= -1;
            setText(QString::number(*value));
            QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();

            if (*value == 2)
            {
                setStyleSheet("Square { background: rgb(238,228,218); color: rgb(119,110,101); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
                shadow->setColor(Qt::yellow);
            }
            else
            {
                setStyleSheet("Square { background: rgb(237,224,200); color: rgb(119,110,101); font: 40pt \"JetBrains mono\"; border-radius: 10px; }");
                shadow->setColor(Qt::yellow);
            }
            
            shadow->setBlurRadius(30);
            shadow->setOffset(-1);
            setGraphicsEffect(shadow);
        }
        else
        {
            setText("");
            setStyleSheet("Square{ background: rgb(204,192,179); border-radius: 10px; }");
        }
    }
    }

}



