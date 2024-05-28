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

    // ����
    system("cls");
    // ��ӡ��¼����
    showNow();

    pos(30, 11);
    cout << "**********��ӭ����Henbnb���û�ϵͳ**********" << endl;
    pos(30, 13);
    cout << "* �����������˺�:                          " << endl;
    pos(30, 15);
    cout << "*                            " << endl;
    pos(30, 17);
    cout << "* ��������������:                                " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(30, 21);
    cout << "********************************************" << endl;
    pos(32, 15);
    cin >> id;
    pos(32, 19);
    cin >> password;

    // ��¼��֤
    if (guestMap.find(id) == guestMap.end())
    {
        cout << "���˺Ų�����!" << endl;
        system("pause");
    }
    // ������֤
    else if (guestMap[id].password == password)
    {
        pos(30, 23);
        cout << "��¼�ɹ�!" << endl;
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
        cout << "�˺Ż��������!" << endl;
        pos(30, 25);
        system("pause");
    }
}

void GuestClass::Register()
{
    // ����
    system("cls");

    // ��ӡ��¼����
    showNow();

    // ע�����
    string id, name, password, gender, phone, email;
    Date registerDate;
    pos(30, 11);
    cout << "**********��ӭ����Henbnb���û�ϵͳ**********" << endl;
    pos(30, 13);
    cout << "* �����������˺�(С��10λ):                          " << endl;

    pos(30, 15);
    cout << "*                                        " << endl;
    pos(31, 15);
    cin >> id;

    // �˺���֤
    if (guestMap.find(id) != guestMap.end())
    {
        pos(30, 39);
        cout << "���˺��Ѵ���!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }
    else if (id.length() > 9)
    {
        pos(30, 39);
        cout << "�˺Ź���!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }
    cin.ignore();

    pos(30, 17);
    cout << "* �������������루������20λ��:                          " << endl;
    pos(30, 19);
    cout << "*                                       " << endl;
    pos(32, 19);
    cin >> password;
    cin.ignore();
    if (password.length() > 8)
    {
        pos(30, 39);
        cout << "�������!" << endl;
        pos(30, 41);
        system("pause");
        return;
    }

    pos(30, 21);
    cout << "* ��������������:                                   " << endl;
    pos(30, 23);
    cout << "*                                                " << endl;
    pos(30, 25);
    cout << "* �����������Ա�:                                  " << endl;
    pos(30, 27);
    cout << "*                                                " << endl;
    pos(30, 29);
    cout << "* �����������ֻ���:                                " << endl;
    pos(30, 31);
    cout << "*                                               " << endl;
    pos(30, 33);
    cout << "* ��������������:                                  " << endl;
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
            cout << "�ֻ�������!" << endl;
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
        cout << "��������!" << endl;
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
    cout << "ע��ɹ�!" << endl;
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
        cout << "**********��ӭ����Henbnb���û�ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.��¼                           " << endl;
        pos(30, 15);
        cout << "* 2.ע��                             " << endl;
        pos(30, 17);
        cout << "* 3.�˳�                                 " << endl;
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

// ���캯��
Guest::Guest()
    : id(""), password(""), name(""), gender(""), registerDate({}), phone(""), email("")
{
}

// ��������
Guest::~Guest() {}

// �вι���
Guest::Guest(string id, string password, string name, string gender, Date registerDate, string phone, string email)
    : id(id), password(password), name(name), gender(gender), registerDate(registerDate), phone(phone), email(email) {}

void Guest::Menu()
{
    keyc = 0;
    bool flag = 1;
    // ���˵�
    while (flag)
    {
        system("cls");
        showNow();
        pos(30, 9);
        cout << name + "����" << endl;
        pos(30, 10);
        cout << "********��ӭ���� Henbnb���û�ϵͳ**********" << endl;
        pos(30, 11);
        cout << "*                                       " << endl;
        pos(30, 13);
        cout << "* 1.�鿴������Ϣ                             " << endl;
        pos(30, 15);
        cout << "* 2.�鿴�ҵĶ���                          " << endl;
        pos(30, 17);
        cout << "* 3.����                               " << endl;
        pos(30, 19);
        cout << "* 4.�ҵ���Ϣ                               " << endl;
        pos(30, 21);
        cout << "* 5.�˳�                                 " << endl;
        pos(30, 23);
        cout << "*                                   " << endl;
        pos(30, 25);
        cout << "********************************************" << endl;
        keyc = _getch();
        switch (keyc)
        {
        case '1':
            // ������Ϣ
            DoRoomInfo();
            break;
        case '2':
            // �ҵĶ���
            MyReserveInfo();
            break;
        case '3':
            // ����
            DoRepairInfo();
            break;
        case '4':
            //  �ҵ���Ϣ
            MyInfo();
            break;
        case '5':
            // �˳�
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
        // �ҵ���Ϣ
        system("cls");
        // �ҵ���Ϣ
        showNow();

        // �ҵ���Ϣ
        pos(30, 9);
        cout << name + "����" << endl;
        pos(30, 10);
        cout << "**********��ӭ����Henbnb���û�ϵͳ**********" << endl;
        pos(30, 12);
        cout << "* ��������Ҫ�޸ĵ���Ϣ(��q������һ��):                  " << endl;
        pos(30, 13);
        cout << "* 1.����" << endl;
        pos(30, 14);
        cout << "* 2.�Ա�" << endl;
        pos(30, 15);
        cout << "* 3.�ֻ���" << endl;
        pos(30, 16);
        cout << "* 4.����" << endl;
        pos(30, 17);
        cout << "* 5.����" << endl;
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
            cout << "* ����������������: ";
            pos(30, 21);
            cin >> name;
            break;
        }
        else if (keyc == '2')
        {
            pos(30, 20);
            cout << "* �������������Ա�: ";
            pos(30, 21);
            cin >> gender;
            break;
        }
        else if (keyc == '3')
        {
            pos(30, 20);
            cout << "* �������������ֻ���: ";
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
                cout << "�ֻ��ų���ӦΪ11λ" << endl;
                pos(30, 24);
                system("pause");
            }
        }
        else if (keyc == '4')
        {
            pos(30, 20);
            cout << "* ����������������: ";
            pos(30, 21);
            cin >> email;
            break;
        }
        else if (keyc == '5')
        {

            pos(30, 20);
            cout << "* �����������¾���: ";
            pos(30, 21);
            string password0;
            cin >> password0;
            //������
            if (password0 == password)
            {
                pos(30, 23);
                cout << "����������������: ";
                pos(30, 24);
                cin >> password;
                break;
            }
            else
            {
                pos(30, 23);
                cout << "�����������" << endl;
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
        // ������Ϣ
        system("cls");
        // ������Ϣ
        showNow();
        roomclass.show();
        pos(30, 9);
        cout << name + "����" << endl;
        pos(30, 10);
        cout << "**********��ӭ����Henbnb���û�ϵͳ**********" << endl;
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
    cout << "**********��Ԥ����Ϣ����**********************" << endl;
    pos(30, 12);
    cout << "*  ��q���ز˵�   ��sΪ��������   ��rȡ������ " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    pos(20, 16);
    cout << "���";
    pos(30, 16);
    cout << "�����";
    pos(40, 16);
    cout << "��ס����";
    pos(55, 16);
    cout << "�˷�����";
    pos(70, 16);
    cout << "״̬";
    pos(80, 16);
    cout << "����";
    pos(90, 16);
    cout << "����";

    // ������Ϣ
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
        if (i->status == "�����")
            i->score == -1 ? cout << "δ����" : cout << i->score;
        else
            cout << "-";

        order++;
    }
}

void Guest::DeleteReserve()
{
    showReserve();
    pos(20, 15);
    cout << "��������Ҫȡ���Ķ��������:                             ";
    pos(48, 15);
    int order;
    cin >> order;

    Date today;
    
    // �������
    if (order > myReserve.size() || order < 1)
    {
        pos(30, 2);
        cout << "�����ڸö���" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->checkin < today + 2)
    {
        pos(30, 2);
        cout << "������סʱ�䲻�����죬�޷�ȡ������" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->status == "��ȡ��")
    {
        pos(30, 2);
        cout << "�ö�����ȡ��" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else
    {
        moneyInfo.vec.push_back({today, '-' + myReserve[order - 1]->money, id + "ȡ������"});
        moneyInfo.update();

        myReserve[order - 1]->status = "��ȡ��";
        reserveInfo.update();
        roomclass.update();

        showReserve();

        pos(30, 2);
        cout << "ȡ���ɹ���" << myReserve[order - 1]->money << "Ԫ��ԭ֧����ʽ����" << endl;
        pos(30, 3);
        system("pause");
    }
}

void Guest::ScoreReserve()
{
    showReserve();
    pos(20, 15);
    cout << "��������Ҫ���ֵĶ��������:                             ";
    pos(48, 15);
    int order;
    cin >> order;
    if (order > myReserve.size() || order < 1)
    {
        pos(30, 2);
        cout << "�����ڸö���" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->status != "�����")
    {
        pos(30, 2);
        cout << "�ö���δ���" << endl;
        pos(30, 3);
        system("pause");
        return;
    }
    else if (myReserve[order - 1]->score != -1)
    {
        pos(30, 2);
        cout << "�ö���������, ȷ���޸����֣�(y/n)" << endl;
        pos(30, 3);
        char choice;
        cin >> choice;
        if (choice != 'y')
        {
            pos(30, 2);
            cout << "��ȡ��" << endl;
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
                cout << "��������������(0-10):                                        ";
                pos(51, 2);
                cin >> score;
                if (score >= 0 && score <= 10)
                    break;
                else
                {
                    pos(30, 2);
                    cout << "���ַ�ΧΪ0-10                         " << endl;
                    pos(50, 2);
                    system("pause");
                    pos(30, 3);
                }
            }
            myReserve[order - 1]->score = score;
            Reserveinfo_to_Roomscoreinfo();
            reserveInfo.update();
            pos(30, 3);
            cout << "���ֳɹ�" << endl;
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
            cout << "��������������(0-10):                                        ";
            pos(51, 2);
            cin >> score;
            if (score >= 0 && score <= 10)
                break;
            else
            {
                pos(30, 2);
                cout << "���ַ�ΧΪ0-10                                           " << endl;
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
        cout << "���ֳɹ�" << endl;
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
        cout << "��a�������ޣ���q����:" << endl;
        char keyc;
        pos(10, 12);
        cout << "���ı�����Ϣ����:" << endl;
        pos(10, 15);
        cout.setf(ios::left); // ���ö��뷽ʽΪleft
        cout << setw(10) << "���" << repairInfo.rpTitle << endl;

        for (auto i : repairInfo.vec)
        {
            if (i.reporter == id)
            {
                pos(10, 15 + order);
                cout.setf(ios::left); // ���ö��뷽ʽΪleft
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
    cout << "��������Ҫ���޵ķ����:                             ";
    roomclass.show();
    pos(48, 15);
    string roomNum;
    cin >> roomNum;
    if (roomclass.room.find(roomNum) == roomclass.room.end())
    {
        pos(30, 16);
        cout << "�����ڸ÷���" << endl;
        pos(30, 17);
        system("pause");
        return;
    }
    else
    {
        pos(30, 16);
        cout << "�����뷿������" << endl;
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
        repairInfo.vec.push_back({today, id, roomNum, problem, "δ����", "��", "0"});
        pos(30, 18);
        cout << "���޳ɹ�" << endl;
        pos(30, 19);
        system("pause");
        repairInfo.update();
    }
}
