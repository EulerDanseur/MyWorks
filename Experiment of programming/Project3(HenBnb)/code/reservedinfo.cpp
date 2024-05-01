#include "housing.h"

Reserveinfo reserveInfo;

Reserveinfo::Reserveinfo()
{
    fstream file;
    file.open("reservedinfo.txt", ios::in);
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i].guest >> vec[i].checkin >> vec[i].checkout;
    }
    file.close();
    update();
}

Reserveinfo::~Reserveinfo()
{
    update();
}

void Reserveinfo::show()
{
    pos(30, 16);
    pos(30, 16 );
    cout << "���";
    pos(40, 16 );
    cout << "�û�";
    pos(60, 16 );
    cout << "��ס����";
    pos(75, 16 );
    cout << "�˷�����" << endl;

    int order = 1;
    for (auto i : vec)
    {
        pos(30, 16 + order);
        cout << order;
        pos(40, 16 + order);
        cout << i.guest;
        pos(60, 16 + order);
        cout << i.checkin;
        pos(75, 16 + order);
        cout << i.checkout << endl;
        order++;
    }
}

void Reserveinfo::update()
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if (i->guest == "")
        {
            i--;
            vec.erase(i + 1);
        }
    }

    fstream file;
    file.open("reservedinfo.txt", ios::out);
    for (auto i : vec)
    {
        file << i.guest << ' ' << i.checkin << ' ' << i.checkout << endl;
    }
    file.close();
}



void Housing::Reservedinfo()
{
    system("cls");
    pos(30, 10);
    cout << "**********��Ԥ����Ϣ����*******************" << endl;
    pos(30, 12);
    cout << "*  ��q���ط����˵�       ��e�������˵�        " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;
    reserveInfo.show();
    key = _getch();
    while (key)
    {
        if (key == 'q')
        {
            Menu();
            break;
        }
        else if (key == 'e')
        {
            showMainMenu();
            break;
        }
        key = _getch();
    }
}