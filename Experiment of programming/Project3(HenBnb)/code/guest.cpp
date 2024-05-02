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
    cout << "**********欢迎来到Henbnb的管理系统**********" << endl;
    pos(30, 13);
    cout << "* 请输入您的账号:                          " << endl;
    pos(30, 15);
    cout << "*                            " << endl;
    pos(30, 17);
    cout << "* 请输入您的密码:                                " << endl;
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
        cout << "该账号不存在!" << endl;
        system("pause");
    }
    else if (guestMap[id].password == password)
    {
        pos(30, 23);
        cout << "登录成功!" << endl;
        pos(30, 25);
        system("pause");
        guestMap[id].Menu();
    }
    else
    {
        pos(30, 23);
        cout << "账号或密码错误!" << endl;
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
    cout << "**********欢迎来到Henbnb的管理系统**********" << endl;
    pos(30, 13);
    cout << "* 请输入您的账号:                          " << endl;
    pos(30, 15);
    cout << "*                            " << endl;
    pos(30, 17);
    cout << "* 请输入您的密码:                                " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(30, 21);
    cout << "* 请输入您的姓名:                                " << endl;
    pos(30, 23);
    cout << "*                                       " << endl;
    pos(30, 25);
    cout << "* 请输入您的性别:                                " << endl;
    pos(30, 27);
    cout << "*                                       " << endl;
    pos(30, 29);
    cout << "* 请输入您的手机号:                                " << endl;
    pos(30, 31);
    cout << "*                                       " << endl;
    pos(30, 33);
    cout << "* 请输入您的邮箱:                                " << endl;
    pos(30, 35);
    cout << "*                                       " << endl;
    pos(30, 37);
    cout << "********************************************" << endl;
    pos(32, 15);
    cin >> id;
    if (guestMap.find(id) != guestMap.end())
    {
        pos(30, 39);
        cout << "该账号已存在!" << endl;
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
    cout << "注册成功!" << endl;
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
        cout << "**********欢迎来到Henbnb的管理系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.登录                           " << endl;
        pos(30, 15);
        cout << "* 2.注册                             " << endl;
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
        cout << "**********欢迎来到 Henbnb的管理系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.查看房间信息                             " << endl;
        pos(30, 15);
        cout << "* 2.查看我的订单                          " << endl;
        pos(30, 17);
        cout << "* 3.我的信息                               " << endl;
        pos(30, 19);
        cout << "* 4.我的消息                               " << endl;
        pos(30, 21);
        cout << "* 5.退出                                 " << endl;
        pos(30, 23);
        cout << "*                                       " << endl;
        pos(30, 25);
        cout << "********************************************" << endl;
        keyc = _getch();
        switch (keyc)
        {
        case '1':
            DoRoomInfo();
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

void Guest::DoRoomInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
        pos(30, 12);
        cout << "* 请输入您要查看的房间号码(按q返回上一级):                  " << endl;
        pos(30, 13);
        cin >> keys;
        room.show();
        if (keys == "q")
        {
            flag = 0;
            break;
        }
        else if (room.roomInfo.find(keys) == room.roomInfo.end())
        {
            pos(30, 15);
            cout << "该房间不存在" << endl;
            pos(30, 16);
            system("pause");
        }
        else
        {
            pos(30, 15);
            cout << "房间号: " << keys << endl;
            pos(30, 17);
            system("pause");

            room.roomInfo[keys].DoDateInfoLandlord();
        }
    }
}