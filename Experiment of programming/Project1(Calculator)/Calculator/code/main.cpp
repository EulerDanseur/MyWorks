#include "graphicSurface.h"
int counttime = 0;

int main()
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    initgraph(430, 850); // ��ʼ������

    SetWindowText(GetHWnd(), TEXT("Calculator")); // ���ô��ڱ���

    setbkcolor(RGB(85, 90, 96)); // ���ñ�����ɫ

    cleardevice();

    showMousebuttons(); // ��ʾ����

    while (true) // ��ѭ��
    {
        setbkcolor(RGB(85, 90, 96)); // ���ñ�����ɫ
        showscreen();
    }

    return 0;
}