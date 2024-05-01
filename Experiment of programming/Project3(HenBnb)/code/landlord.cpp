#include "landlord.h"
Landlord::Landlord()
{
    fstream file;
    file.open("landlordinfo.txt", ios::in);
    file >> password;
    file.close();
}

Landlord::~Landlord()
{
    update();
}

void Landlord::Login()
{

    system("cls");
    pos(30, 10);
    cout << "**********欢迎来到Henbnb的房主系统**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* 请输入密码                             " << endl;
    pos(30, 15);
    cout << "*:                                   " << endl;
    pos(30, 17);
    cout << "*                                  " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(30, 21);
    cout << "********************************************" << endl;
    pos(32, 15);
    string inputpassword;
    cin >> inputpassword;
    if (inputpassword == password)
    {
        Menu();
    }
    else
    {
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
        system("cls");
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.已预订信息管理      2.维修信息查看                  " << endl;
        pos(30, 15);
        cout << "* 3.房间信息修改      4.我的信息                 " << endl;
        pos(30, 17);
        cout << "* 5.我的消息         6. 返回主菜单              " << endl;
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
            Reservedinfo();
            break;
        case '2':
            DoRepairInfo();
            break;
        case '3':
            DoDateInfo();
            break;
        case '4':
            LandlordInfo();
            break;
        case '6':
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
    reserveInfo.show();
    keyc = _getch();
    while (keyc)
    {
        if (keyc == 'q')
        {
            Menu();
            break;
        }
        else if (keyc == 'e')
        {
            showMainMenu();
            break;
        }
        else
        {
            pos(30, 8);
            cout << "输入错误,请重新输入" << endl;
        }
        keyc = _getch();
    }
}

void Landlord::DoDateInfo()
{
    system("cls");
    pos(30, 2);
    cout << "请输入想查看的年月份:" << endl;
    pos(30, 3);
    cin >> dateInfo.year >> dateInfo.month;
    while (dateInfo.year < 1000 || dateInfo.month > 12 || dateInfo.year > 2050 || dateInfo.month < 1)
    {
        pos(30, 3);
        cout << "输入有误,请重新输入" << endl;
        pos(30, 4);
        system("pause");
        pos(30, 3);
        cout << "                           " << endl;
        pos(30, 4);
        cout << "                           " << endl;
        pos(30, 3);
        cin >> dateInfo.year >> dateInfo.month;
    }

    bool flag = 1;
    while (flag)
    {
        dateInfo.showLandlord();
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
                dateInfo.showLandlord();
                break;
            case DOWNKEY:
                dateInfo.month++;
                if (dateInfo.month == 13)
                {
                    dateInfo.month = 1;
                    dateInfo.year++;
                }
                dateInfo.showLandlord();
                break;
            case LEFTKEY:
                dateInfo.year--;
                dateInfo.showLandlord();
                break;
            case RIGHTKEY:
                dateInfo.year++;
                dateInfo.showLandlord();
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                dateInfo.ChangeDatePrice();
                break;
            case '2':
                dateInfo.ChangeDateSpare();
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
                cout << "输入有误,请重新输入" << endl;
                break;
            }
    }
}

void Landlord::DoRepairInfo()
{
    repairInfo.show("全部");
    keyc = 0;
    bool flag = 1;
    while (flag)
    {
        keyc = _getch();
        switch (keyc)
        {
        case '0':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("全部");
            break;
        case '1':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("已处理");
            break;
        case '2':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("未处理");
            break;
        case 'd':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            else
                repairInfo.DeleteRepairInfo();
            break;
        case 'r':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            else
                repairInfo.ReviseRepairInfo();
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
        pos(30, 10);
        cout << "**********欢迎来到 Henbnb的房主系统**********" << endl;
        pos(30, 11);
        cout << "* 1.修改密码" << endl;
        pos(30, 13);
        cout << "* 2.资金流水" << endl;
        pos(30, 15);
        cout << "* 3.查看客户名单" << endl;
        pos(30, 17);
        cout << "* 4.返回主菜单" << endl;
        pos(30, 19);
        cout << "********************************************" << endl;

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
            break;
        case '4':
            flag = 0;
            break;
        default:
            pos(30, 25);
            cout << "输入有误,请重新输入" << endl;
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
            Menu();
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
        cout << "* 请输入新密码" << endl;
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
        ChangePassword();
    }
    update();
}

void Landlord::update()
{
    ofstream fout;
    fout.open("landlordinfo.txt");
    fout << password << endl;
}
