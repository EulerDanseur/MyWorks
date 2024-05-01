#include "surface.h"
#include "housing.h"
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄

char key = 0;
Housing housing;

void pos(int x,int y)
{
    COORD posPoint = {x,y}; //设置坐标
    SetConsoleCursorPosition(hOut,posPoint);
}

void showMainMenu()
{
    system("cls");
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

    key = _getch();

    switch (key)
    {
        case '1':
            housing.Login();
            break;
        case '2':
            break;
        case '3':
            exit(0);
            break;
        default:
            pos(30 , 23);
            cout << "输入有误,请重新输入" << endl;
            break;
    }
}
