#include "landlord.h"

Landlord::Landlord()
{
    // 读取文件中的密码
    fstream file;
    file.open("landlordinfo.txt", ios::in);
    file >> password;
    file.close();
}

Landlord::~Landlord()
{
    // 更新密码
    update();
}

void Landlord::Login()
{

    system("cls"); // 清屏
    showNow();     // 显示当前时间

    // 显示登录界面
    pos(30, 10);
    cout << "**********欢迎来到Henbnb的房主系统**********" << endl;
    pos(30, 11);
    cout << "* 确认您是房主？                            " << endl;
    pos(30, 13);
    cout << "* 1.是                                     " << endl;
    pos(30, 15);
    cout << "* 2.否                                     " << endl;
    pos(30, 17);
    cout << "******************************************" << endl;
    char input = _getch();
    if(input == '2')    return;

    // 显示密码输入界面
        system("cls"); // 清屏
    showNow();     // 显示当前时间
    // 输入密码
    pos(30, 10);
    cout << "**********欢迎来到Henbnb的房主系统**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* 请输入密码                             " << endl;
    pos(30, 15);
    cout << "*:                                      " << endl;
    pos(30, 17);
    cout << "*                                       " << endl;
    pos(30, 19);
    cout << "*                                        " << endl;
    pos(30, 21);
    cout << "******************************************" << endl;
    pos(32, 15);
    string inputpassword;

    cin >> inputpassword;
    if (inputpassword == password)
    {
        // 登录成功
        Menu();
    }
    else
    {
        // 登录失败
        pos(32, 17);
        cout << "密码错误" << endl;
        pos(32, 19);
        system("pause");
        Login();
    }
}

void Landlord::Menu()
{
    keyc = 0;
    bool flag = 1;
    while (flag)
    {
        system("cls"); // 清屏
        showNow();     // 显示当前时间
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.已预订信息管理      2.维修信息查看                  " << endl;
        pos(30, 15);
        cout << "* 3.房间信息修改        4.我的信息                 " << endl;
        pos(30, 17);
        cout << "* 5.返回主菜单              " << endl;
        pos(30, 19);
        cout << "*                            " << endl;
        pos(30, 21);
        cout << "*                        " << endl;
        pos(30, 23);
        cout << "********************************************" << endl;

        keyc = _getch();
        switch (keyc)
        {
        case '1':
            // 已预订信息管理
            Reservedinfo();
            break;
        case '2':
            // 维修信息查看
            DoRepairInfo();
            break;
        case '3':
            // 房间信息修改
            DoRoomInfo();
            break;
        case '4':
            //  我的信息
            LandlordInfo();
            break;
        case '5':
            flag = 0;
            break;
        default:
            pos(30, 25);
            cout << "输入有误,请重新输入" << endl;
        }
    }
}

void Landlord::Reservedinfo()
{

    
    bool flag = 1;
    while (flag)
    {
        keys = "all";
        reserveInfo.showLandlord(keys); // 显示已预订信息
        keyc = _getch();
        if (keyc == 'q')
        {
            break;
        }
        else if (keyc == 'e')
        {
            // 返回主菜单
            showMainMenu();
            break;
        }
        
        // else if (keyc == 'r')
        // {
        //     pos(30, 7);
        //     cout << "请输入要查看的房间号码(输入all表示全部)" << endl;
        //     pos(30, 8);
        //     // 输入要查看的房间号码
        //     cin >> keys;

        //     // 判断房间号码是否存在
        //     if (keys != "all" && roomclass.room.find(keys) == roomclass.room.end())
        //     {
        //         pos(30, 9);
        //         cout << "该房间不存在" << endl;
        //         pos(50, 9);
        //         system("pause");
        //     }
        // }

        else
        {
            pos(30, 8);
            cout << "输入错误,请重新输入" << endl;
        }
    }
}

void Landlord::DoRoomInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        system("cls");    // 清屏
        showNow();        // 显示当前时间
        roomclass.show(); // 显示房间信息
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 12);
        cout << "* 请输入您要查看的房间号码(按q返回上一级):                  " << endl;
        pos(30, 13);

        // 输入要查看的房间号码
        cin >> keys;

        if (keys == "q")
        {
            flag = 0;
            break;
        }
        else if (roomclass.room.find(keys) == roomclass.room.end()) // 判断房间号码是否存在
        {
            pos(30, 15);
            cout << "该房间不存在" << endl;
            pos(30, 16);
            system("pause");
        }
        else
        {

            // 显示房间信息
            pos(30, 15);
            cout << "房间号: " << keys << endl;
            pos(30, 17);
            system("pause");

            roomclass.room[keys].DoRoomInfoLandlord();
        }
    }
}

void Landlord::DoRepairInfo()
{
    keyc = 0;
    bool flag = 1;
    string status = "全部";
    while (flag)
    {
        repairInfo.show(status);
        keyc = _getch();
        switch (keyc)
        {
        case '0':
            if (repairInfo.vec.size() == 1) // 判断修理列表是否为空
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            status = "全部"; // 显示全部
            break;
        case '1':
            if (repairInfo.vec.size() == 0) // 判断修理列表是否为空
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            status = "已处理"; // 显示已处理
            break;
        case '2':
            if (repairInfo.vec.size() == 0) // 判断修理列表是否为空
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            status = "未处理"; // 显示未处理
            break;
        case 'd':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            else
                repairInfo.DeleteRepairInfo(); // 删除
            break;
        case 'r':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            else
                repairInfo.ReviseRepairChoose(); // 修改
            break;
        case 'q':
            flag = 0;
            break;
        case 'e':
            showMainMenu();
            flag = 0;
            break;
        default:
            pos(30, 2);
            cout << "输入有误,请重新输入" << endl;
            break;
        }
    }
}

void Landlord::LandlordInfo()
{

    keyc = 0;
    bool flag = 1;
    while (flag)
    {
        system("cls");
        showNow();
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 11);
        cout << "* 1.修改密码" << endl;
        pos(30, 13);
        cout << "* 2.资金流水" << endl;
        pos(30, 15);
        cout << "* 3.返回主菜单" << endl;
        pos(30, 17);
        cout << "* 4.用户列表" << endl;

        keyc = _getch();
        switch (keyc)
        {
        case '1':
            ChangePassword();
            break;
        case '2':
            DoMoneyInfo();
            break;
        case '3':
            flag = 0;
            break;
        case '4':
            GuestList();
            break;
        default:
            pos(30, 25);
            cout << "输入有误,请重新输入" << endl;
        }
    }
}

void Landlord::GuestList()
{
    while(true)
    {
        system("cls");
        showNow();
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 11);
        cout << "*用户列表" << endl;
        pos(30, 13);
        cout << "*按q退出" << endl;

        int i = 0;
        for(auto it : guestclass.guestMap)
        {
            pos(30, 15 + i);
            //界面不完善
            //printf("%d. %s\t\t\t %s\t\t\t %s\t\t %s\t\t %s\n", i + 1, it.second.id.c_str(), it.second.name.c_str(),it.second.gender.c_str(), it.second.phone.c_str(), it.second.email.c_str());
            cout.setf(ios::left);
            cout << i + 1 << ' ' << it.second.registerDate << setw(5)<< ' ' << setw(10) << it.second.id << setw(15) << it.second.name << setw(30) << it.second.phone << setw(10) << it.second.email;
            i++;
        }
        
        keyc = _getch();
        if(keyc == 'q')
        {
            break;
        }
    }
}

void Landlord::DoMoneyInfo()
{
    bool flag = 1;
    while (flag)
    {
        moneyInfo.show();
        keyc = _getch();

        switch (keyc)
        {
        case '1':
            moneyInfo.DeleteMoneyInfo();
            break;
        case '2':
            moneyInfo.ChangeMoneyInfo();
            break;
        case '3':
            moneyInfo.AddMoneyInfo();
            break;
        case 'r':
            LandlordInfo();
            flag = 0;
            break;
        case 'q':
            flag = 0;
            break;
        default:
            pos(30, 21);
            cout << "输入有误,请重新输入" << endl;
        }
    }
}

void Landlord::ChangePassword()
{
    system("cls");
    showNow();
    pos(30, 10);
    cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
    pos(30, 11);
    cout << "* 请输入原密码" << endl;
    pos(30, 13);
    cout << "*: " << endl;
    pos(32, 13);
    string inputpassword;

    cin >> inputpassword;
    if (inputpassword == password)
    {
        pos(30, 15);
        cout << "*请输入新密码" << endl;
        pos(30, 17);
        cout << "*: " << endl;
        pos(32, 17);

        cin >> password;
        pos(30, 19);
        cout << "密码修改成功" << endl;
        pos(30, 21);
        system("pause");
    }
    else
    {
        pos(30, 15);
        cout << "密码错误" << endl;
        pos(30, 17);
        system("pause");
        return;
    }
    update();
}

void Landlord::update()
{
    ofstream fout;
    fout.open("landlordinfo.txt");
    fout << password << endl;
}
