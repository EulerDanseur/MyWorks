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

void Landlord::Menu()
{

    keyc = 0;
    bool flag = 1;
    while (flag)
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
            cout << "��������,����������" << endl;
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
            cout << "�������,����������" << endl;
        }
        keyc = _getch();
    }
}

void Landlord::DoDateInfo()
{
    system("cls");
    pos(30, 2);
    cout << "��������鿴�����·�:" << endl;
    pos(30, 3);
    cin >> dateInfo.year >> dateInfo.month;
    while (dateInfo.year < 1000 || dateInfo.month > 12 || dateInfo.year > 2050 || dateInfo.month < 1)
    {
        pos(30, 3);
        cout << "��������,����������" << endl;
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
                cout << "��������,����������" << endl;
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
                cout << "��������,����������" << endl;
                break;
            }
    }
}

void Landlord::DoRepairInfo()
{
    repairInfo.show("ȫ��");
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
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("ȫ��");
            break;
        case '1':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("�Ѵ���");
            break;
        case '2':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("δ����");
            break;
        case 'd':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                repairInfo.DeleteRepairInfo();
            break;
        case 'r':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
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
            cout << "��������,����������" << endl;
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
            cout << "��������,����������" << endl;
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
            cout << "��������,����������" << endl;
        }
    }
}

void Landlord::ChangePassword()
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
        cout << "* ������������" << endl;
        pos(30, 17);
        cout << "*: " << endl;
        pos(32, 17);
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
    update();
}

void Landlord::update()
{
    ofstream fout;
    fout.open("landlordinfo.txt");
    fout << password << endl;
}
