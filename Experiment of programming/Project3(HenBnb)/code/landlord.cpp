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
            DoRoomInfo();
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
    
    keys = "all";
    bool flag = 0;
    while (flag)
    {
        reserveInfo.show(keys);
        keyc = _getch();
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
        else if (keyc == 'r')
        {
            pos(30, 7);
            cout << "������Ҫ�鿴�ķ������(����all��ʾȫ��)" << endl;
            pos(30, 8);
            cin >> keys;

            if (keys != "all" && room.roomInfo.find(keys) == room.roomInfo.end())
            {
                pos(30, 10);
                cout << "�÷��䲻����" << endl;
                pos(30, 11);
                system("pause");
            }
        }
        else
        {
            pos(30, 8);
            cout << "�������,����������" << endl;
        }
    }
}

void Landlord::DoRoomInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 12);
        cout << "* ��������Ҫ�鿴�ķ������(��q������һ��):                  " << endl;
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
            cout << "�÷��䲻����" << endl;
            pos(30, 16);
            system("pause");
        }
        else
        {
            pos(30, 15);
            cout << "�����: " << keys << endl;
            pos(30, 17);
            system("pause");

            room.roomInfo[keys].DoDateInfoLandlord();
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
