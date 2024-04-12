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

//Ϊ��֧��vs2022������tstring��tcout����д��ʱ���õ�vscode��֧��gbk���أ�
#ifdef _UNICODE
    typedef wstring tstring;
    #define tcout wcout
#else
    typedef string tstring;
    #define tcout cout
#endif

extern ExMessage mousemsg; // �����Ϣ

extern bool inputChanged;        // �����Ƿ�ı�
extern tstring input;            // ��������
extern tstring result;           // ������
extern vector<tstring> inputRPN; // �沨�����ʽ
extern int counttime;            // �������

// ��ʾ��Ļ
void showscreen();

// ��ť
bool button(int x, int y, int w, int h, TCHAR text);

// �����ж�
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

// �����
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

// ����
inline void Clear()
{
    setfillcolor(RGB(85, 90, 96));
    solidrectangle(0, 0, 800, 200);
}

// ��ʾ����
void showMousebuttons();

// ��ʾ��������
void showKeyboard();

// ��ʾ����
void showinput();

// ��ʾ���
void showcursor();

// ��ʾ���
void showresult();



