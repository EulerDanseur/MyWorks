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
    cout << "**********��ӭ����Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* ����������                             " << endl;
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
        cout << "�������" << endl;
        pos(32, 19);
        system("pause");
        Login();
    }
}

void Housing::Menu()
{
    system("cls");
    pos(30, 10);
    cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* 1.��Ԥ����Ϣ����      2.ά����Ϣ�鿴                  " << endl;
    pos(30, 15);
    cout << "* 3.������Ϣ�޸�      4.�ҵ���Ϣ                 " << endl;
    pos(30, 17);
    cout << "* 5.�ҵ���Ϣ         6. �������˵�              " << endl;
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
            cout << "��������,����������" << endl;
        }
    }
}

void Housing::HousingInfo()
{
    system("cls");
    pos(30, 10);
    cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "* 1.�޸�����" << endl;
    pos(30, 13);
    cout << "* 2.�ʽ���ˮ" << endl;
    pos(30, 15);
    cout << "* 3.�鿴�ͻ�����" << endl;
    pos(30, 17);
    cout << "* 4.�������˵�" << endl;
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
            cout << "��������,����������" << endl;
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
        cout << "**********�ʽ���ˮ**********" << endl;
        pos(30, 11);
        cout << "* 1.�鿴�ʽ���ˮ" << endl;
        pos(30, 13);
        cout << "* 2.�޸��ʽ���ˮ" << endl;
        pos(30, 15);
        cout << "* 3.�����ʽ���ˮ" << endl;
        pos(30, 17);
        cout << "* ��q���ط������� ��r������һ��" << endl;
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
            cout << "��������,����������" << endl;
        }
    }
}

void Housing::ChangePassword()
{
    system("cls");
    pos(30, 10);
    cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "* ������ԭ����" << endl;
    pos(30, 13);
    cout << "*: " << endl;
    pos(32, 13);
    string inputpassword;
    cin >> inputpassword;
    if (inputpassword == password)
    {
        pos(30, 15);
        cout << "������������" << endl;
        pos(30, 17);
        cin >> password;
        pos(30, 19);
        cout << "�����޸ĳɹ�" << endl;
        pos(30, 21);
        system("pause");
    }
    else
    {
        pos(30, 15);
        cout << "�������" << endl;
        pos(30, 17);
        system("pause");
        ChangePassword();
    }
}
