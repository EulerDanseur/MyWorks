#include "guest.h"



GuestClass::GuestClass()
{
    fstream file;
    file.open("guestinfo.txt", ios::in);
    string id;
    for (int i = 0; !file.eof(); i++)
    {
        file >> id;
        file >> guestMap[id];
        guestMap[id].id = id;
    }
    file.close();
}

GuestClass::~GuestClass()
{
    update();
}

void GuestClass::update()
{
    ofstream file;
    file.open("guestinfo.txt");
    for (auto i : guestMap)
    {
        file << i.second;
    }
    file.close();
}

void GuestClass::Login()
{
    string id, password;

    // 清屏
    system("cls");
    // 打印登录界面
    showNow();

    pos(30, 11);
    cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
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

    // 登录验证
    if (guestMap.find(id) == guestMap.end())
    {
        cout << "该账号不存在!" << endl;
        system("pause");
    }
    // 密码验证
    else if (guestMap[id].password == password)
    {
        pos(30, 23);
        cout << "登录成功!" << endl;
        for (auto i = 0; i < reserveInfo.vec.size(); i++)
        {
            if (reserveInfo.vec[i].guest == id)
            {
                if (find(guestMap[id].myReserve.begin(), guestMap[id].myReserve.end(), &reserveInfo.vec[i]) == guestMap[id].myReserve.end())
                    guestMap[id].myReserve.push_back(&reserveInfo.vec[i]);
            }
        }
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
    // 清屏
    system("cls");

    // 打印登录界面
    showNow();

    // 注册界面
    string id, name, password, gender, phone, email;
    Date registerDate;
    pos(30, 11);
    cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
    pos(30, 13);
    cout << "* 请输入您的账号(小于10位):                          " << endl;

    pos(30, 15);
    cout << "*                                        " << endl;
    pos(31, 15);
    cin >> id;

    // 账号验证
    if (guestMap.find(id) != guestMap.end())
    {
        pos(30, 39);
        cout << "该账号已存在!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }
    else if (id.length() > 9)
    {
        pos(30, 39);
        cout << "账号过长!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }
    cin.ignore();

    pos(30, 17);
    cout << "* 请输入您的密码（不超过20位）:                          " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(32, 19);
    cin >> password;
    cin.ignore();
    if (password.length() > 8)
    {
        pos(30, 39);
        cout << "密码过长!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }

    pos(30, 21);
    cout << "* 请输入您的姓名:                                   " << endl;
    pos(30, 23);
    cout << "*                                                " << endl;
    pos(30, 25);
    cout << "* 请输入您的性别:                                  " << endl;
    pos(30, 27);
    cout << "*                                                " << endl;
    pos(30, 29);
    cout << "* 请输入您的手机号:                                " << endl;
    pos(30, 31);
    cout << "*                                               " << endl;
    pos(30, 33);
    cout << "* 请输入您的邮箱:                                  " << endl;
    pos(30, 35);
    cout << "*                                               " << endl;
    pos(30, 37);
    cout << "********************************************" << endl;
    pos(32, 15);

    pos(32, 23);
    name = "\n";
    getline(cin, name);
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ')
        {
            name[i] = '_';
        }
    }

    pos(32, 27);
    cin >> gender;
    cin.ignore();

    pos(32, 31);
    cin >> phone;
    for (int i = 0; i < phone.length(); i++)
    {
        if (phone[i] < '0' || phone[i] > '9' || phone.length() != 11)
        {
            pos(30, 39);
            cout << "手机号有误!" << endl;
            pos(30, 41);
            system("pause");
            return;
        }
    }

    pos(32, 35);
    cin >> email;
    if (cin.peek() != '\n')
    {
        pos(30, 39);
        cout << "邮箱有误!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }

    time_t today = time(0);
    tm t;
    localtime_s(&t, &today);
    registerDate.year = t.tm_year + 1900;
    registerDate.month = t.tm_mon + 1;
    registerDate.day = t.tm_mday;

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
        showNow();
        pos(30, 10);
        cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
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

// 构造函数
Guest::Guest()
    : id(""), password(""), name(""), gender(""), registerDate({}), phone(""), email("")
{
}

// 析构函数
Guest::~Guest() {}

// 有参构造
Guest::Guest(string id, string password, string name, string gender, Date registerDate, string phone, string email)
    : id(id), password(password), name(name), gender(gender), registerDate(registerDate), phone(phone), email(email) {}

void Guest::Menu()
{
    keyc = 0;
    bool flag = 1;
    // 主菜单
    while (flag)
    {
        system("cls");
        showNow();
        pos(30, 9);
        cout << name + "您好" << endl;
        pos(30, 10);
        cout << "********欢迎来到 Henbnb的用户系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.查看房间信息                             " << endl;
        pos(30, 15);
        cout << "* 2.查看我的订单                          " << endl;
        pos(30, 17);
        cout << "* 3.报修                               " << endl;
        pos(30, 19);
        cout << "* 4.我的信息                               " << endl;
        pos(30, 21);
        cout << "* 5.退出                                 " << endl;
        pos(30, 23);
        cout << "*                                   " << endl;
        pos(30, 25);
        cout << "********************************************" << endl;
        keyc = _getch();
        switch (keyc)
        {
        case '1':
            // 房间信息
            DoRoomInfo();
            break;
        case '2':
            // 我的订单
            MyReserveInfo();
            break;
        case '3':
            // 报修
            DoRepairInfo();
            break;
        case '4':
            //  我的信息
            MyInfo();
            break;
        case '5':
            // 退出
            flag = 0;
            break;
        }
    }
}

void Guest::MyInfo()
{
    keyc = ' ';
    bool flag = 1;
    while (flag)
    {
        // 我的信息
        system("cls");
        // 我的信息
        showNow();

        // 我的信息
        pos(30, 9);
        cout << name + "您好" << endl;
        pos(30, 10);
        cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
        pos(30, 12);
        cout << "* 请输入您要修改的信息(按q返回上一级):                  " << endl;
        pos(30, 13);
        cout << "* 1.姓名" << endl;
        pos(30, 14);
        cout << "* 2.性别" << endl;
        pos(30, 15);
        cout << "* 3.手机号" << endl;
        pos(30, 16);
        cout << "* 4.邮箱" << endl;
        pos(30, 17);
        cout << "* 5.密码" << endl;
        pos(30, 18);
        cout << "********************************************" << endl;
        keyc = _getch();
        if (keyc == 'q')
        {
            flag = 0;
            break;
        }
        else if (keyc == '1')
        {
            pos(30, 20);
            cout << "* 请输入您的新名字: ";
            pos(30, 21);
            cin >> name;
            break;
        }
        else if (keyc == '2')
        {
            pos(30, 20);
            cout << "* 请输入您的新性别: ";
            pos(30, 21);
            cin >> gender;
            break;
        }
        else if (keyc == '3')
        {
            pos(30, 20);
            cout << "* 请输入您的新手机号: ";
            pos(30, 21);
            string ph;
            cin >> ph;
            if (ph.size() == 11)
            {
                phone = ph;
                break;
            }
            else
            {
                pos(30, 23);
                cout << "手机号长度应为11位" << endl;
                pos(30, 24);
                system("pause");
            }
        }
        else if (keyc == '4')
        {
            pos(30, 20);
            cout << "* 请输入您的新邮箱: ";
            pos(30, 21);
            cin >> email;
            break;
        }
        else if (keyc == '5')
        {

            pos(30, 20);
            cout << "* 请输入您的新旧码: ";
            pos(30, 21);
            string password0;
            cin >> password0;
            //密码检查
            if (password0 == password)
            {
                pos(30, 23);
                cout << "请输入您的新密码: ";
                pos(30, 24);
                cin >> password;
                break;
            }
            else
            {
                pos(30, 23);
                cout << "密码输入错误" << endl;
                pos(30, 24);
                system("pause");
            }
        }
    }
}

void Guest::DoRoomInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        // 房间信息
        system("cls");
        // 房间信息
        showNow();
        roomclass.show();
        pos(30, 9);
        cout << name + "您好" << endl;
        pos(30, 10);
        cout << "**********欢迎来到Henbnb的用户系统**********" << endl;
        pos(30, 12);
        cout << "* 请输入您要查看的房间号码(按q返回上一级):                  " << endl;
        pos(30, 13);
        cin >> keys;

        if (keys == "q")
        {
            flag = 0;
            break;
        }
        else if (roomclass.room.find(keys) == roomclass.room.end())
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

            roomclass.room[keys].DoRoomInfoGuest(id);
        }
    }
}

void Guest::MyReserveInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        showReserve();
        keyc = _getch();

        if (keyc == 'q')
        {
            break;
        }
        else if (keyc == 's')
        {
            ScoreReserve();
        }
        else if (keyc == 'r')
        {
            DeleteReserve();
        }
    }
}

void Guest::showReserve()
{
    system("cls");
    showNow();
    pos(30, 10);
    cout << "**********已预订信息管理**********************" << endl;
    pos(30, 12);
    cout << "*  按q返回菜单   按s为订单评分   按r取消订单 " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    pos(20, 16);
    cout << "序号";
    pos(30, 16);
    cout << "房间号";
    pos(40, 16);
    cout << "入住日期";
    pos(55, 16);
    cout << "退房日期";
    pos(70, 16);
    cout << "状态";
    pos(80, 16);
    cout << "费用";
    pos(90, 16);
    cout << "评分";

    // 房间信息
    int order = 1;
    for (auto i : myReserve)
    {
        pos(20, 16 + order);
        cout << order;
        pos(30, 16 + order);
        cout << i->room;
        pos(40, 16 + order);
        cout << i->checkin;
        pos(55, 16 + order);
        cout << i->checkout;
        pos(70, 16 + order);
        cout << i->status;
        pos(80, 16 + order);
        cout << i->money;
        pos(90, 16 + order);
        if (i->status == "已完成")
            i->score == -1 ? cout << "未评分" : cout << i->score;
        else
            cout << "-";

        order++;
    }
}

void Guest::DeleteReserve()
{
    showReserve();
    pos(20, 15);
    cout << "请输入您要取消的订单的序号:                             ";
    pos(48, 15);
    int order;
    cin >> order;

    Date today;
    
    // 订单检查
    if (order > myReserve.size() || order < 1)
    {
        pos(30, 2);
        cout << "不存在该订单" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->checkin < today + 2)
    {
        pos(30, 2);
        cout << "距离入住时间不足两天，无法取消订单" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->status == "已取消")
    {
        pos(30, 2);
        cout << "该订单已取消" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else
    {
        moneyInfo.vec.push_back({today, '-' + myReserve[order - 1]->money, id + "取消订单"});
        moneyInfo.update();

        myReserve[order - 1]->status = "已取消";
        reserveInfo.update();
        roomclass.update();

        showReserve();

        pos(30, 2);
        cout << "取消成功，" << myReserve[order - 1]->money << "元按原支付方式返回" << endl;
        pos(30, 3);
        system("pause");
    }
}

void Guest::ScoreReserve()
{
    showReserve();
    pos(20, 15);
    cout << "请输入您要评分的订单的序号:                             ";
    pos(48, 15);
    int order;
    cin >> order;
    if (order > myReserve.size() || order < 1)
    {
        pos(30, 2);
        cout << "不存在该订单" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->status != "已完成")
    {
        pos(30, 2);
        cout << "该订单未完成" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->score != -1)
    {
        pos(30, 2);
        cout << "该订单已评分, 确认修改评分？(y/n)" << endl;
        pos(30, 3);
        char choice;
        cin >> choice;
        if (choice != 'y')
        {
            pos(30, 2);
            cout << "已取消" << endl;
            pos(30, 3);
            system("pause");
            return;
        }
        else
        {
            double score;
            while (true)
            {
                pos(30, 2);
                cout << "请输入您的评分(0-10):                                        ";
                pos(51, 2);
                cin >> score;
                if (score >= 0 && score <= 10)
                    break;
                else
                {
                    pos(30, 2);
                    cout << "评分范围为0-10                         " << endl;
                    pos(50, 2);
                    system("pause");
                    pos(30, 3);
                }
            }
            myReserve[order - 1]->score = score;
            Reserveinfo_to_Roomscoreinfo();
            reserveInfo.update();
            pos(30, 3);
            cout << "评分成功" << endl;
            pos(30, 4);
            system("pause");
        }
    }
    else
    {

        double score;
        while (true)
        {
            pos(30, 2);
            cout << "请输入您的评分(0-10):                                        ";
            pos(51, 2);
            cin >> score;
            if (score >= 0 && score <= 10)
                break;
            else
            {
                pos(30, 2);
                cout << "评分范围为0-10                                           " << endl;
                pos(40, 2);
                system("pause");
                pos(30, 3);
            }
        }
        myReserve[order - 1]->score = score;

        roomclass.room[myReserve[order - 1]->room].score += score;
        roomclass.room[myReserve[order - 1]->room].scoreTimes++;
        reserveInfo.update();
        pos(30, 3);
        cout << "评分成功" << endl;
        pos(30, 4);
        system("pause");
    }
}

void Guest::DoRepairInfo()
{

    while (true)
    {
        system("cls");
        showNow();
        int order = 1;
        pos(10, 10);
        cout << "按a新增报修，按q返回:" << endl;
        char keyc;
        pos(10, 12);
        cout << "您的报修信息如下:" << endl;
        pos(10, 15);
        cout.setf(ios::left); // 设置对齐方式为left
        cout << setw(10) << "序号" << repairInfo.rpTitle << endl;

        for (auto i : repairInfo.vec)
        {
            if (i.reporter == id)
            {
                pos(10, 15 + order);
                cout.setf(ios::left); // 设置对齐方式为left
                cout << setw(10) << order << i;
                order++;
            }
        }

        keyc = _getch();
        if (keyc == 'a')
        {
            RepairReport();
        }
        else if (keyc == 'q')
        {
            return;
        }
    }
}

void Guest::RepairReport()
{
    system("cls");
    showNow();
    pos(20, 15);
    cout << "请输入您要报修的房间号:                             ";
    roomclass.show();
    pos(48, 15);
    string roomNum;
    cin >> roomNum;
    if (roomclass.room.find(roomNum) == roomclass.room.end())
    {
        pos(30, 16);
        cout << "不存在该房间" << endl;
        pos(30, 17);
        system("pause");
        return;
    }
    else
    {
        pos(30, 16);
        cout << "请输入房间问题" << endl;
        pos(30, 17);
        string problem;
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
        getline(cin, problem);
        for (int i = 0; i < problem.size(); i++)
        {
            if (problem[i] == ' ')
            {
                problem[i] = '-';
            }
        }
        Date today;
        repairInfo.vec.push_back({today, id, roomNum, problem, "未处理", "无", "0"});
        pos(30, 18);
        cout << "报修成功" << endl;
        pos(30, 19);
        system("pause");
        repairInfo.update();
    }
}
