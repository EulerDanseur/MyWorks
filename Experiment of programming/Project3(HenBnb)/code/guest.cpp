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
        pos(30, 23);
        cout << "��¼�ɹ�!" << endl;
        pos(30, 25);
        system("pause");
        guestMap[id].Menu();
    }
    else
    {
        pos(30, 23);
        cout << "�˺Ż��������!" << endl;
        pos(30, 25);
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
    pos(32, 15);
    cin >> id;
    if (guestMap.find(id) != guestMap.end())
    {
        pos(30, 39);
        cout << "���˺��Ѵ���!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }

    pos(32, 19);
    cin >> password;
    pos(32, 23);
    cin >> name;
    pos(32, 27);
    cin >> gender;
    pos(32, 31);
    cin >> phone;
    pos(32, 35);
    cin >> email;
    time_t now = time(0);
    tm t;

    localtime_s(&t, &now);

    registerDate = toString(1900 + t.tm_year) + '.' + toString(t.tm_mon + 1) + '.' + toString(t.tm_mday);
    guestMap[id] = Guest(id, password, name, gender, registerDate, phone, email);
    update();
    pos(30, 39);
    cout << "ע��ɹ�!" << endl;
    pos(30, 41);
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

Guest::Guest()
    : id(""), password(""), name(""), gender(""), registerDate(""), phone(""), email("") {}

Guest::~Guest() {}

Guest::Guest(string id, string password, string name, string gender, DateYMD registerDate, string phone, string email)
    : id(id), password(password), name(name), gender(gender), registerDate(registerDate), phone(phone), email(email) {}

void Guest::Menu()
{
    keyc = 0;
    bool flag = 1;
    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�Ĺ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.�鿴������Ϣ                             " << endl;
        pos(30, 15);
        cout << "* 2.�鿴�ҵĶ���                          " << endl;
        pos(30, 17);
        cout << "* 3.�ҵ���Ϣ                               " << endl;
        pos(30, 19);
        cout << "* 4.�ҵ���Ϣ                               " << endl;
        pos(30, 21);
        cout << "* 5.�˳�                                 " << endl;
        pos(30, 23);
        cout << "*                                       " << endl;
        pos(30, 25);
        cout << "********************************************" << endl;
        keyc = _getch();
        switch (keyc)
        {
        case '1':
            DoDateInfo();
            break;
        case '2':
            // MyOrderInfo();
            break;
        case '3':
            // MyInfo();
            break;
        case '4':
            // MyMessage();
            break;
        case '5':
            flag = 0;
            break;
        }
    }
}

void Guest::DoDateInfo()
{
    time_t now = time(0);
    tm t;

    localtime_s(&t, &now);

    dateInfo.year = 1900 + t.tm_year;
    dateInfo.month = t.tm_mon + 1;
    bool flag = 1;
    while (flag)
    {
        dateInfo.showGuest();
        keyc = _getch();
        if (keyc == -32)
        {
            keyc = _getch();
            switch (keyc)
            {
            case UPKEY:
                dateInfo.month--;
                if (dateInfo.month == 0)
                {
                    dateInfo.month = 12;
                    dateInfo.year--;
                }
                dateInfo.showGuest();
                break;
            case DOWNKEY:
                dateInfo.month++;
                if (dateInfo.month == 13)
                {
                    dateInfo.month = 1;
                    dateInfo.year++;
                }
                dateInfo.showGuest();
                break;
            case LEFTKEY:
                dateInfo.year--;
                dateInfo.showGuest();
                break;
            case RIGHTKEY:
                dateInfo.year++;
                dateInfo.showGuest();
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                reserveInfo.MakeReserve(this);
                break;
            case 'q':
                Menu();
                flag = 0;
                break;
            case 'e':
                showMainMenu();
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
    }
}