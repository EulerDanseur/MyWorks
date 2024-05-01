#include "housing.h"
Housing::Housing()
{
    fstream file;
    file.open("housinginfo.txt", ios::in);
    file >> password;
    file.close();
}

void Housing::Login()
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

void Housing::Menu()
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

    key = 0;
    while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5' && key != '6')
    {
        key = _getch();
        switch (key)
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
            HousingInfo();
            break;
        case '6':
            showMainMenu();
            break;
        default:
            pos(30, 25);
            cout << "输入有误,请重新输入" << endl;
        }
    }
}

void Housing::HousingInfo()
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

    key = 0;
    while (key != '1' && key != '2' && key != '3' && key != '4')
    {
        key = _getch();
        switch (key)
        {
        case '1':
            ChangePassword();
            break;
        case '2':
            DoMoneyInfo();
            break;
        case '3':
            // clientInfo.show();
            break;
        case '4':
            showMainMenu();
            break;
        default:
            pos(30, 25);
            cout << "输入有误,请重新输入" << endl;
        }
    }
}
void Housing::DoMoneyInfo()
{
    bool flag = 1;
    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********资金流水**********" << endl;
        pos(30, 11);
        cout << "* 1.查看资金流水" << endl;
        pos(30, 13);
        cout << "* 2.修改资金流水" << endl;
        pos(30, 15);
        cout << "* 3.增加资金流水" << endl;
        pos(30, 17);
        cout << "* 按q返回房主界面 按r返回上一级" << endl;
        pos(30, 19);
        cout << "********************************************" << endl;
        key = _getch();

        switch (key)
        {
        case '1':
            moneyInfo.show();
            break;
        case '2':
            moneyInfo.ChangeMoneyInfo();
            break;
        case '3':
            moneyInfo.AddMoneyInfo();
            break;
        case 'r':
            HousingInfo();
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

void Housing::ChangePassword()
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
        cout << "请输入新密码" << endl;
        pos(30, 17);
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
}
