#include <easyx.h>
#include <graphics.h>
#include <vector>
#include "calculate.h"
#include <conio.h>
#include <ctime>

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

//为了支持vs2022，定义tstring，tcout（我写的时候用的vscode不支持gbk呜呜）
#ifdef _UNICODE
    typedef wstring tstring;
    #define tcout wcout
#else
    typedef string tstring;
    #define tcout cout
#endif

extern ExMessage mousemsg; // 鼠标信息

extern bool inputChanged;        // 输入是否改变
extern tstring input;            // 输入内容
extern tstring result;           // 计算结果
extern vector<tstring> inputRPN; // 逆波兰表达式
extern int counttime;            // 计算次数

// 显示屏幕
void showscreen();

// 按钮
bool button(int x, int y, int w, int h, TCHAR text);

// 区域判断
inline bool inArea(int mouseX, int mouseY, int x, int y, int w, int h)
{
    if (mouseX > x && mouseX < x + w && mouseY > y && mouseY < y + h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 警告框
inline void showwarningbar(tstring text)
{
    BeginBatchDraw();
    setfillcolor(RGB(85, 90, 96));
    solidrectangle(0, 150, 800, 250);
    settextcolor(RGB(255, 90, 96));
    setbkmode(OPAQUE);
    settextstyle(40, 0, TEXT("consolas"), 0, 0, 900, 0, 0, 0, 0, 0, 0, ANTIALIASED_QUALITY, 0);
    outtextxy(10, 200, text.c_str());
    EndBatchDraw();
}

// 清屏
inline void Clear()
{
    setfillcolor(RGB(85, 90, 96));
    solidrectangle(0, 0, 800, 200);
}

// 显示按键
void showMousebuttons();

// 显示键盘输入
void showKeyboard();

// 显示输入
void showinput();

// 显示光标
void showcursor();

// 显示结果
void showresult();



