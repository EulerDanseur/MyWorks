#include "interface.h"
#include "landlord.h"
#include "guest.h"
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出句柄

char keyc = 0;
string keys = "";
int keynum = 0;

// 创建对象
Landlord landlord;
Reserveinfo reserveInfo;
RoomClass roomclass;
GuestClass guestclass;
Moneyinfo moneyInfo;
Repairinfo repairInfo;

void pos(short x, short y)
{
    COORD posPoint = {x, y}; // 设置坐标
    SetConsoleCursorPosition(hOut, posPoint);
}

void showMainMenu()
{
    // 按键控制
    while (true)
    {
        system("cls");
        showNow();

        pos(30, 10);
        cout << "**********欢迎来到Henbnb的管理系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.您是房主                             " << endl;
        pos(30, 15);
        cout << "* 2.您是房客                             " << endl;
        pos(30, 17);
        cout << "* 3.退出                                 " << endl;
        pos(30, 19);
        cout << "*                                       " << endl;
        pos(30, 21);
        cout << "********************************************" << endl;

        keyc = _getch();

        switch (keyc)
        {
        case '1':
            // 房主登录
            landlord.Login();
            break;
        case '2':
            // 房客登录
            guestclass.GuestInterface();
            break;
        case '3':
            // 退出
            exit(0);
            break;
        default:
            pos(30, 23);
            cout << "输入有误,请重新输入" << endl;
            break;
        }
    }
}
