#include "CalculatorQT.h"
bool lightmode = 0;
int cursorPosition = 0;

CalculatorQT::CalculatorQT(QWidget *parent)
    : QWidget(parent)
{
    //ui.setupUi(this);

    // set default size
    resize(500, 900);

    buttonPressflag = 0;

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setStyleSheet("CalculatorQT { background-color: rgb(85, 90, 96) }");

    inputBox = new QLineEdit();
    inputBox->setStyleSheet(
        "max-height: 50px;\n"
        "min-height: 50px;\n"
        "border-radius: 50px;\n"
        "background: rgb(85, 90, 96); color: rgba(116, 119, 122, 0.5); font: 20pt \"consolas\";}\n ");

    QRegularExpression regx("[0-9\\+\\-\\*/·×)(]+$");
    QValidator* validator = new QRegularExpressionValidator(regx, inputBox);
    inputBox->setValidator(validator);
    connect(inputBox, &QLineEdit::textChanged, this, [=] {
        if (buttonPressflag == 0)
        {
            cursorPosition = inputBox->cursorPosition();
            expn.input = (inputBox->text()).toStdTString();
            buttonsPressed(0);
        }
        buttonPressflag = 0; });
    connect(inputBox, &QLineEdit::returnPressed, this, [=] { 
        equalPress(); 
        buttonPressflag = 0; });
    mainLayout->insertWidget(0, inputBox, 0);

    resultBox = new QLineEdit();
    resultBox->setStyleSheet(
        "max-height: 100px;\n"
        "min-height: 100px;\n"
        "border-radius: 60px;\n"
        "background: rgb(85, 90, 96); color: rgba(243, 170, 76, 0.5); font: 30pt \"consolas\";}\n ");
    resultBox->setReadOnly(true);
    resultBox->setText("RESULT BOX");
        
    mainLayout->insertWidget(1, resultBox, 0);

    warnBox = new QLineEdit();
    warnBox->setStyleSheet(
        "max-height: 50px;\n"
        "min-height: 50px;\n"
        "border-radius: 50px;\n"
        "background: rgb(85, 90, 96); color: rgba(255, 90, 96, 0.5); font: 30pt \"consolas\";}\n ");
    warnBox->setReadOnly(true);
    warnBox->setText("WARNING BOX");
    mainLayout->insertWidget(2, warnBox, 0);
    
    switchButton = new SwitchButton();
    switchButton->setFixedWidth(200);
    switchButton->setFixedHeight(50);
    switchButton->setSpace(40);
    switchButton->setRadius(40);
    QColor offColor(12, 23, 50), onColor(245, 170, 83);
    switchButton->setBgColorOff(offColor);
    switchButton->setBgColorOn(onColor);
    switchButton->setSliderColorOff(QColor(244, 170, 76));
    switchButton->setSliderColorOn(QColor(86, 89, 95));
    switchButton->setAnimation(true);
    switchButton->setTextOff("Moon");
    switchButton->setTextOn("Sun");
    switchButton->setTextColorOff(QColor(244, 170, 76));
    switchButton->setTextColorOn(QColor(86, 89, 95));
    connect(switchButton, &SwitchButton::statusChanged, this, [=] {lightmode = switchButton->checked(); showscreen(); });
    
    buttonLayout = new QGridLayout();
    buttonLayout->addWidget(switchButton, 0, 2, 1, 0, Qt::AlignCenter);

    showsbutton();
}

CalculatorQT::~CalculatorQT()
{
    //delete ui;
}

void CalculatorQT::showscreen()
{
    for (auto i : buttons)
    {
        i.second->setParent(0);
        delete i.second;
    }
    showsbutton();

    if(lightmode)
        setStyleSheet("CalculatorQT { background-color: rgb(255,255,255) }");
    else
        setStyleSheet("CalculatorQT { background-color: rgb(85, 90, 96) }");
    showinput();
    showresult();
    showwarningbar(QString::fromStdTString(expn.warning));


}

void CalculatorQT::showinput()
{
    if (lightmode)
        inputBox->setStyleSheet(
            "max-height: 50px;\n"
            "min-height: 50px;\n"
            "border-radius: 50px;\n"
            "background: rgb(255, 255, 255); color: rgb(133, 137 ,139); font: 25pt \"consolas\";}\n ");
    else
        inputBox->setStyleSheet(
            "max-height: 50px;\n"
            "min-height: 50px;\n"
            "border-radius: 50px;\n"
            "background: rgb(85, 90, 96); color: rgb(116, 119, 122); font: 25pt \"consolas\";}\n ");
    inputBox->setText(QString::fromStdTString(expn.input));
    inputBox->setEnabled(true);
    inputBox->setFocus();
    inputBox->setCursorPosition(cursorPosition);
    inputBox->repaint();
}

void CalculatorQT::showresult() 
{
    if (lightmode)
        resultBox->setStyleSheet(
            "max-height: 100px;\n"
            "min-height: 100px;\n"
            "border-radius: 60px;\n"
            "background: rgb(255, 255, 255); color: rgb(243, 170, 76); font: 30pt \"consolas\";}\n ");
    else
        resultBox->setStyleSheet(
            "max-height: 100px;\n"
            "min-height: 100px;\n"
            "border-radius: 60px;\n"
            "background: rgb(85, 90, 96); color: rgb(243, 170, 76); font: 30pt \"consolas\";}\n ");
    resultBox->setText(QString::fromStdTString(expn.result));
    resultBox->setReadOnly(true);
    resultBox->repaint();
}

void CalculatorQT::showwarningbar(QString warn)
{
    if (lightmode)
        warnBox->setStyleSheet(
            "max-height: 50px;\n"
            "min-height: 50px;\n"
            "border-radius: 50px;\n"
            "background: rgb(255, 255, 255); color: rgb(255, 90, 96); font: 30pt \"consolas\";}\n ");
    else
        warnBox->setStyleSheet(
            "max-height: 50px;\n"
            "min-height: 50px;\n"
            "border-radius: 50px;\n"
            "background: rgb(85, 90, 96); color: rgb(255, 90, 96); font: 30pt \"consolas\";}\n ");
    warnBox->setText(warn);
    warnBox->setReadOnly(true);
    warnBox->repaint();
}

void CalculatorQT::showsbutton()
{
    
    // 按钮们~
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // 数字按钮
            if (j >= 1 && j < 4 && i <= 2)
            {
                int num = 3 * j - 2 + i;
                createNumButtons(num + '0', 5 - j, i);
            }
            else if (j == 0 && i == 0)
            {
                /*buttons['0'] = new Buttons();
                buttons['0']->styleNum(0);
                connect(buttons['0'], &QPushButton::clicked, this, [=] {buttonsPressed('0'); });
                buttonLayout->addWidget(buttons['0'], 5 - j, i);*/

                createNumButtons('0', 5 - j, i);
            }
            else // 功能按钮
            {
                // 小数
                if (j == 0 && i == 1)
                {
                    /*buttons['.'] = new Buttons();
                    buttons['.']->styleOpt(TEXT("."));
                    connect(buttons['.'], &QPushButton::clicked, this, [=] {buttonsPressed('.'); });
                    buttonLayout->addWidget(buttons['.'], 5 - j, i);*/

                    createOptButtons(TEXT("."), 5 - j, i);
                }

                // 退格
                else if (j == 0 && i == 2)
                {
                    /*buttons['D'] = new Buttons();
                    buttons['D']->styleOpt(TEXT("Del"));
                    connect(buttons['D'], &QPushButton::clicked, this, [=] {buttonsPressed('D'); });
                    buttonLayout->addWidget(buttons['D'], 5 - j, i);*/

                    createOptButtons(TEXT("Del"), 5 - j, i);
                }

                // 等于结果
                else if (j == 0 && i == 3)
                {
                    /*buttons['='] = new Buttons();
                    buttons['=']->styleOpt(TEXT("="));
                    connect(buttons['='], &QPushButton::clicked, this, [=]{buttonsPressed('='); });
                    buttonLayout->addWidget(buttons['='], 5 - j, i);*/

                    createOptButtons(TEXT("="), 5 - j, i);
                }

                // 加减乘除
                else if (j == 1 && i == 3)
                {
                    /*buttons['+'] = new Buttons();
                    buttons['+']->styleOpt(TEXT("+"));
                    connect(buttons['+'], &QPushButton::clicked, this, [=] {buttonsPressed('+'); });
                    buttonLayout->addWidget(buttons['+'], 5 - j, i);*/

                    createOptButtons(TEXT("+"), 5 - j, i);
                }
                else if (j == 2 && i == 3)
                {
                    /*buttons['-'] = new Buttons();
                    buttons['-']->styleOpt(TEXT("-"));
                    connect(buttons['-'], &QPushButton::clicked, this, [=] {buttonsPressed('-'); });
                    buttonLayout->addWidget(buttons['-'], 5 - j, i);*/

                    createOptButtons(TEXT("-"), 5 - j, i);
                }
                else if (j == 3 && i == 3)
                {
                    /*buttons['×'] = new Buttons();
                    buttons['×']->styleOpt(TEXT("×"));
                    connect(buttons['×'], &QPushButton::clicked, this, [=] {buttonsPressed('×'); });
                    buttonLayout->addWidget(buttons['×'], 5 - j, i);*/

                    createOptButtons(TEXT("×"), 5 - j, i);
                }
                else if (j == 4 && i == 3)
                {
                    /*buttons['/'] = new Buttons();
                    buttons['/']->styleOpt(TEXT("/"));
                    connect(buttons['/'], &QPushButton::clicked, this, [=] {buttonsPressed('/'); });
                    buttonLayout->addWidget(buttons['/'], 5 - j, i);*/

                    createOptButtons(TEXT("/"), 5 - j, i);
                }

                // 括号
                else if (j == 4 && i == 2)
                {
                    /*buttons[')'] = new Buttons();
                    buttons[')']->styleOpt(TEXT(")"));
                    connect(buttons[')'], &QPushButton::clicked, this, [=] {buttonsPressed(')'); });
                    buttonLayout->addWidget(buttons[')'], 5 - j, i);*/

                    createOptButtons(TEXT(")"), 5 - j, i);
                }
                else if (j == 4 && i == 1)
                {
                    /*buttons['('] = new Buttons();
                    buttons['(']->styleOpt(TEXT("("));
                    connect(buttons['('], &QPushButton::clicked, this, [=] {buttonsPressed('('); });
                    buttonLayout->addWidget(buttons['('], 5 - j, i);*/
                
                    createOptButtons(TEXT("("), 5 - j, i);
                }

                // 清屏
                else if (j == 4 && i == 0)
                {
                    /*buttons['C'] = new Buttons();
                    buttons['C']->styleOpt(TEXT("C"));
                    connect(buttons['C'], &QPushButton::clicked, this, [=] {buttonsPressed('C'); });
                    buttonLayout->addWidget(buttons['C'], 5 - j, i);*/

                    createOptButtons(TEXT("C"), 5 - j, i);
                }
            }
        }
    }

    /*buttons['l'] = new Buttons();
    buttons['l']->styleOpt(TEXT("<-"));
    connect(buttons['l'], &QPushButton::clicked, this, [=] {buttonsPressed('l'); });
    buttonLayout->addWidget(buttons['l'], 0, 0);*/

    createOptButtons(TEXT("<"), 0, 0);

    /*buttons['r'] = new Buttons();
    buttons['r']->styleOpt(TEXT("->"));
    connect(buttons['r'], &QPushButton::clicked, this, [=] {buttonsPressed('r'); });
    buttonLayout->addWidget(buttons['r'], 0, 1);*/

    createOptButtons(TEXT(">"), 0, 1);

    mainLayout->insertLayout(3, buttonLayout, 0);
}

void CalculatorQT::createOptButtons(tstring name, int x, int y)
{
    TCHAR namec = name[0];
    buttons[namec] = new Buttons();
    buttons[namec]->styleOpt(name);
    connect(buttons[namec], &QPushButton::clicked, this, [=] {buttonsPressed(namec); });
    buttonLayout->addWidget(buttons[namec], x, y);
}

void CalculatorQT::createNumButtons(TCHAR num, int x, int y)
{
    buttons[num] = new Buttons();
    buttons[num]->styleNum(num - '0');
    connect(buttons[num], &QPushButton::clicked, this, [=] {buttonsPressed(num); });
    buttonLayout->addWidget(buttons[num], x, y);
}

void Buttons::styleNum(int num)
{
    if(lightmode)
        setStyleSheet("Buttons { \n"
            "min-width: 100px;\n"
            "max-width: 100px;\n"
            "max-height: 100px;\n"
            "min-height: 100px;\n"
            "border-radius: 50px;\n"
            "background: rgb(255, 255, 255); color: rgb(133, 137 ,139); font: 30pt \"consolas\";}\n"
            "Buttons:hover { background: rgb(225,232,237);}");
    else
        setStyleSheet("Buttons { \n"
            "min-width: 100px;\n"
            "max-width: 100px;\n"
            "max-height: 100px;\n"
            "min-height: 100px;\n"
            "border-radius: 50px;\n"
            "background: rgb(85, 90, 96); color: rgb(116, 119, 122); font: 30pt \"consolas\";}\n"
            "Buttons:hover { background: rgb(95, 100, 106);}");

    setText(QString::number(num));
}

void Buttons::styleOpt(tstring opt)
{
    setText(QString::fromStdTString(opt));

    switch (opt[0])
    {
    case 'D':
        if (lightmode)
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(255, 255, 255); color: rgb(133, 137 ,139); font: 20pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(225,232,237);}");
        else
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(85, 90, 96); color: rgb(116, 119, 122); font: 20pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(95, 100, 106);}");
        break;
    case '(':
    case ')':
    case '.': 
    case '<':
    case '>':
        if (lightmode)
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(255, 255, 255); color: rgb(133, 137 ,139); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(225,232,237);}");
        else
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(85, 90, 96); color: rgb(116, 119, 122); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(95, 100, 106);}");
        break;
    case 'C':
        if (lightmode)
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(255, 255, 255); color: rgb(133, 137 ,139); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(255, 90, 96); color:rgb(243, 170, 76)}");
        else
            setStyleSheet("Buttons { \n"
                "min-width: 100px;\n"
                "max-width: 100px;\n"
                "max-height: 100px;\n"
                "min-height: 100px;\n"
                "border-radius: 50px;\n"
                "background: rgb(85, 90, 96); color: rgb(116, 119, 122); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(255, 90, 96); color:rgb(243, 170, 76)}");
        break;
    case '=':
    case '+':
    case '-':
    case TEXT('×'):
    case '/':
    default:
        if (lightmode)
            setStyleSheet("Buttons { \n"
                "min-width: 90px;\n"
                "max-width: 90px;\n"
                "max-height: 90px;\n"
                "min-height: 90px;\n"
                "border-radius: 45px;\n"
                "background: rgb(225,232,237); color: rgb(245,169,75); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(244, 246, 247); color:rgb(243, 170, 76)}");
        else
            setStyleSheet("Buttons { \n"
                "min-width: 90px;\n"
                "max-width: 90px;\n"
                "max-height: 90px;\n"
                "min-height: 90px;\n"
                "border-radius: 45px;\n"
                "background: rgb(106, 106, 105); color: rgb(243, 170, 76); font: 30pt \"consolas\";}\n"
                "Buttons:hover { background: rgb(126, 120, 118); color:rgb(243, 170, 76)}");
        break;
    }


}

bool CalculatorQT::buttonsPressed(TCHAR key)
{

    if(key =='9')
        inputInsert(key);
    else if (isdigit(key))
        inputInsert(key);
    else 
        switch (key)
        {
        case'.':
            inputInsert(key);
            break;
        case'+':
        case'-':case TEXT('×'):case'/':case'(':case')':
            inputInsert(key);
            break;
        case'=':
            equalPress();
            break;
        case'D':
            backSpace();
            break;
        case'C':
            Clear();
            break;
        case'>':
            if (cursorPosition < expn.input.length())
            {
                cursorPosition++;
            }
            break;
        case'<':
            if (cursorPosition > 0)
            {
                cursorPosition--;
            }
            break;
        }
    expn.calculate();
    showinput();
    showresult();
    if(key != '=')
        showwarningbar(QString::fromStdTString(expn.warning));
    
    buttonPressflag = 1;
    return 1;
}

void CalculatorQT::inputInsert(TCHAR ch)
{
    if (expn.input.length() < 22)
    {
        expn.input.insert(cursorPosition, 1, ch);
        cursorPosition++;
        inputBox->setCursorPosition(cursorPosition);
    }
}

void CalculatorQT::backSpace()
{
    if (expn.input.size() && cursorPosition > 0)
    {
        if ((cursorPosition > 1) &&
            ((expn.input[cursorPosition - 2] == TEXT('·') && expn.input[cursorPosition - 1] == '(') || (expn.input[cursorPosition - 2] == ')' && expn.input[cursorPosition - 1] == TEXT('��'))))
        {
            expn.input.erase(cursorPosition - 2, 2);
            cursorPosition -= 2;
        }
        else if ((expn.input[cursorPosition - 1] == TEXT('·') && expn.input[cursorPosition] == '(') || (expn.input[cursorPosition - 1] == ')' && expn.input[cursorPosition] == TEXT('��')))
        {
            expn.input.erase(cursorPosition - 1, 2);
            cursorPosition--;
        }
        else
        {
            expn.input.erase(cursorPosition - 1, 1);
            cursorPosition--;
        }
    }
}

void CalculatorQT::equalPress()
{
    if (expn.inputRPN.size())
    {
        showwarningbar(QString::fromStdTString(expn.result));
    }
    else
    {
        if (expn.input.size())
            showwarningbar("Invalid expression!");
        else
            showwarningbar("No input!");
    }
}

void CalculatorQT::Clear()
{
    expn.input = TEXT("");
    expn.result = TEXT("");
    expn.inputRPN = {};
    cursorPosition = 0;

}