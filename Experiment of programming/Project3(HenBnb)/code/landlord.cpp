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
    showNow();
    pos(30, 10);
    cout << "**********��ӭ����Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "*                                       " << endl;
    pos(30, 13);
    cout << "* ����������                             " << endl;
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
        showNow();
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.��Ԥ����Ϣ����      2.ά����Ϣ�鿴                  " << endl;
        pos(30, 15);
        cout << "* 3.������Ϣ�޸�        4.�ҵ���Ϣ                 " << endl;
        pos(30, 17);
        cout << "* 5.�ҵ���Ϣ            6. �������˵�              " << endl;
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
    bool flag = 1;
    while (flag)
    {
        reserveInfo.showLandlord(keys);
        keyc = _getch();
        if (keyc == 'q')
        {
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

            if (keys != "all" && roomclass.room.find(keys) == roomclass.room.end())
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
        showNow();
        roomclass.show();
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 12);
        cout << "* ��������Ҫ�鿴�ķ������(��q������һ��):                  " << endl;
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

            roomclass.room[keys].DoRoomInfoLandlord();
        }
    }
}

void Landlord::DoRepairInfo()
{
    keyc = 0;
    bool flag = 1;
    string status = "ȫ��";
    while (flag)
    {
        repairInfo.show(status);
        keyc = _getch();
        switch (keyc)
        {
        case '0':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "ȫ��";
            break;
        case '1':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "�Ѵ���";
            break;
        case '2':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "δ����";
            break;
        case 'd':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                repairInfo.DeleteRepairInfo();
            break;
        case 'r':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                repairInfo.ReviseRepairChoose();
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
        showNow();
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "* 1.�޸�����" << endl;
        pos(30, 13);
        cout << "* 2.�ʽ���ˮ" << endl;
        pos(30, 15);
        cout << "* 3.�������˵�" << endl;
        pos(30, 17);
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
    showNow();
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
        cout << "*������������" << endl;
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
