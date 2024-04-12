#include "graphicSurface.h"
int counttime = 0;

int main()
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    initgraph(430, 850); // 初始化窗口

    SetWindowText(GetHWnd(), TEXT("Calculator")); // 设置窗口标题

    setbkcolor(RGB(85, 90, 96)); // 设置背景颜色

    cleardevice();

    showMousebuttons(); // 显示按键

    while (true) // 主循环
    {
        setbkcolor(RGB(85, 90, 96)); // 设置背景颜色
        showscreen();
    }

    return 0;
}