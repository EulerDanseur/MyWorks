#include "landlord.h"

Landlord::Landlord()
{
    // ��ȡ�ļ��е�����
    fstream file;
    file.open("landlordinfo.txt", ios::in);
    file >> password;
    file.close();
}

Landlord::~Landlord()
{
    // ��������
    update();
}

void Landlord::Login()
{

    system("cls"); // ����
    showNow();     // ��ʾ��ǰʱ��

    // ��ʾ��¼����
    pos(30, 10);
    cout << "**********��ӭ����Henbnb�ķ���ϵͳ**********" << endl;
    pos(30, 11);
    cout << "* ȷ�����Ƿ�����                            " << endl;
    pos(30, 13);
    cout << "* 1.��                                     " << endl;
    pos(30, 15);
    cout << "* 2.��                                     " << endl;
    pos(30, 17);
    cout << "******************************************" << endl;
    char input = _getch();
    if(input == '2')    return;

    // ��ʾ�����������
        system("cls"); // ����
    showNow();     // ��ʾ��ǰʱ��
    // ��������
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
        // ��¼�ɹ�
        Menu();
    }
    else
    {
        // ��¼ʧ��
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
        system("cls"); // ����
        showNow();     // ��ʾ��ǰʱ��
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.��Ԥ����Ϣ����      2.ά����Ϣ�鿴                  " << endl;
        pos(30, 15);
        cout << "* 3.������Ϣ�޸�        4.�ҵ���Ϣ                 " << endl;
        pos(30, 17);
        cout << "* 5.�������˵�              " << endl;
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
            // ��Ԥ����Ϣ����
            Reservedinfo();
            break;
        case '2':
            // ά����Ϣ�鿴
            DoRepairInfo();
            break;
        case '3':
            // ������Ϣ�޸�
            DoRoomInfo();
            break;
        case '4':
            //  �ҵ���Ϣ
            LandlordInfo();
            break;
        case '5':
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

    
    bool flag = 1;
    while (flag)
    {
        keys = "all";
        reserveInfo.showLandlord(keys); // ��ʾ��Ԥ����Ϣ
        keyc = _getch();
        if (keyc == 'q')
        {
            break;
        }
        else if (keyc == 'e')
        {
            // �������˵�
            showMainMenu();
            break;
        }
        
        // else if (keyc == 'r')
        // {
        //     pos(30, 7);
        //     cout << "������Ҫ�鿴�ķ������(����all��ʾȫ��)" << endl;
        //     pos(30, 8);
        //     // ����Ҫ�鿴�ķ������
        //     cin >> keys;

        //     // �жϷ�������Ƿ����
        //     if (keys != "all" && roomclass.room.find(keys) == roomclass.room.end())
        //     {
        //         pos(30, 9);
        //         cout << "�÷��䲻����" << endl;
        //         pos(50, 9);
        //         system("pause");
        //     }
        // }

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
        system("cls");    // ����
        showNow();        // ��ʾ��ǰʱ��
        roomclass.show(); // ��ʾ������Ϣ
        pos(30, 10);
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 12);
        cout << "* ��������Ҫ�鿴�ķ������(��q������һ��):                  " << endl;
        pos(30, 13);

        // ����Ҫ�鿴�ķ������
        cin >> keys;

        if (keys == "q")
        {
            flag = 0;
            break;
        }
        else if (roomclass.room.find(keys) == roomclass.room.end()) // �жϷ�������Ƿ����
        {
            pos(30, 15);
            cout << "�÷��䲻����" << endl;
            pos(30, 16);
            system("pause");
        }
        else
        {

            // ��ʾ������Ϣ
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
            if (repairInfo.vec.size() == 1) // �ж������б��Ƿ�Ϊ��
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "ȫ��"; // ��ʾȫ��
            break;
        case '1':
            if (repairInfo.vec.size() == 0) // �ж������б��Ƿ�Ϊ��
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "�Ѵ���"; // ��ʾ�Ѵ���
            break;
        case '2':
            if (repairInfo.vec.size() == 0) // �ж������б��Ƿ�Ϊ��
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            status = "δ����"; // ��ʾδ����
            break;
        case 'd':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                repairInfo.DeleteRepairInfo(); // ɾ��
            break;
        case 'r':
            if (repairInfo.vec.size() == 0)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                repairInfo.ReviseRepairChoose(); // �޸�
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
        cout << "* 4.�û��б�" << endl;

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
            cout << "��������,����������" << endl;
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
        cout << "**********��ӭ���� Henbnb�ķ���ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*�û��б�" << endl;
        pos(30, 13);
        cout << "*��q�˳�" << endl;

        int i = 0;
        for(auto it : guestclass.guestMap)
        {
            pos(30, 15 + i);
            //���治����
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
