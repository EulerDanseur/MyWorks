#include "interface.h"
#include "landlord.h"
#include "guest.h"
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼������

char keyc = 0;
string keys = "";
int keynum = 0;
Landlord landlord;

void pos(int x, int y)
{
    COORD posPoint = {x, y}; // ��������
    SetConsoleCursorPosition(hOut, posPoint);
}

void showMainMenu()
{
    while (true)
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

        keyc = _getch();

        switch (keyc)
        {
        case '1':
            landlord.Login();
            break;
        case '2':
            guestclass.GuestInterface();
            break;
        case '3':
            exit(0);
            break;
        default:
            pos(30, 23);
            cout << "��������,����������" << endl;
            break;
        }
    }
}
