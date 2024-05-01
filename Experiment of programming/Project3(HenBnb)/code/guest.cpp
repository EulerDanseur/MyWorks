#include "guest.h"
GuestClass guestclass;
GuestClass::GuestClass()
{
    fstream file;
    file.open("guestinfo.txt", ios::in);
    string id;
    for (int i = 0; !file.eof(); i++)
    {
        file >> id;
        file >> guestMap[id].password >> guestMap[id].name >> guestMap[id].gender >> guestMap[id].registerDate >> guestMap[id].phone >> guestMap[id].email;
    }
    file.close();
}

GuestClass::~GuestClass()
{
    update();
}

void GuestClass::update()
{
    fstream file;
    file.open("guestinfo.txt", ios::out);
    for (auto i : guestMap)
    {
        file << i.first << ' ' << i.second.password << ' ' << i.second.name << ' ' << i.second.gender << ' ' << i.second.registerDate << ' ' << i.second.phone << ' ' << i.second.email << endl;
    }
    file.close();
}

void GuestClass::Login()
{
    string id, password;
    system("cls");
    pos(30, 11);
    cout << "**********��ӭ����Henbnb�Ĺ���ϵͳ**********" << endl;
    pos(30, 13);
    cout << "* �����������˺�:                          " << endl;
    pos(30, 15);
    cout << "*                            " << endl;
    pos(30, 17);
    cout << "* ��������������:                                " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(30, 21);
    cout << "********************************************" << endl;
    pos(32, 15);
    cin >> id;
    pos(32, 19);
    cin >> password;

    if (guestMap.find(id) == guestMap.end())
    {
        cout << "���˺Ų�����!" << endl;
        system("pause");
    }
    else if (guestMap[id].password == password)
    {
        cout << "��¼�ɹ�!" << endl;
        system("pause");
        guestMap[id].Menu();
    }
    else
    {
        cout << "�˺Ż��������!" << endl;
        system("pause");
    }
}

void GuestClass::Register()
{
    system("cls");
    string id, name, password, gender, phone, email;
    DateYMD registerDate;
    pos(30, 11);
    cout << "**********��ӭ����Henbnb�Ĺ���ϵͳ**********" << endl;
    pos(30, 13);
    cout << "* �����������˺�:                          " << endl;
    pos(30, 15);
    cout << "*                            " << endl;
    pos(30, 17);
    cout << "* ��������������:                                " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(30, 21);
    cout << "* ��������������:                                " << endl;
    pos(30, 23);
    cout << "*                                       " << endl;
    pos(30, 25);
    cout << "* �����������Ա�:                                " << endl;
    pos(30, 27);
    cout << "*                                       " << endl;
    pos(30, 29);
    cout << "* �����������ֻ���:                                " << endl;
    pos(30, 31);
    cout << "*                                       " << endl;
    pos(30, 33);
    cout << "* ��������������:                                " << endl;
    pos(30, 35);
    cout << "*                                       " << endl;
    pos(30, 37);
    cout << "********************************************" << endl;
    pos(32, 13);
    cin >> id;
    if (guestMap.find(id) != guestMap.end())
    {
        cout << "���˺��Ѵ���!" << endl;
        system("pause");
        return;
    }
    pos(32, 15);
    cin >> password;
    pos(32, 19);
    cin >> name;
    pos(32, 23);
    cin >> gender;
    pos(32, 27);
    cin >> phone;
    pos(32, 31);
    cin >> email;
    time_t now = time(0);

    tm *t = localtime(&now);

    registerDate = toString(1900 + t->tm_year) + '.' + toString(t->tm_mon + 1) + '.' + toString(t->tm_mday);
    guestMap[id] = Guest(id, password, name, gender, registerDate, phone, email);
    update();
    cout << "ע��ɹ�!" << endl;
    system("pause");
}
void GuestClass::GuestInterface()
{
    keyc = 0;
    bool flag = 1;
    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********��ӭ����Henbnb�Ĺ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.��¼                           " << endl;
        pos(30, 15);
        cout << "* 2.ע��                             " << endl;
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
            Login();
            break;
        case '2':
            Register();
            break;
        case '3':
            flag = 0;
            break;
        }
    }
}