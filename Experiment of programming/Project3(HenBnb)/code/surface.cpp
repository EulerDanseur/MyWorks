#include "surface.h"
#include "housing.h"
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������

char key = 0;
Housing housing;

void pos(int x,int y)
{
    COORD posPoint = {x,y}; //��������
    SetConsoleCursorPosition(hOut,posPoint);
}

void showMainMenu()
{
    system("cls");
    pos(30, 10);
    cout << "**********��ӭ����Henbnb�Ĺ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* 1.���Ƿ���                             " << endl;
    pos(30, 15);
    cout << "* 2.���Ƿ���                             " << endl;
    pos(30, 17);
    cout << "* 3.�˳�                                 " << endl;
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
            cout << "��������,����������" << endl;
            break;
    }
}
