#include "info.h"

Moneyinfo moneyInfo;

bool cmpMoneyInfo(moneyInfoSt a, moneyInfoSt b)
{
    return a.date < b.date;
}

Moneyinfo::Moneyinfo()
{
    DateYMD date;
    string money;
    string source;
    fstream file;
    file.open("moneyinfo.txt", ios::in);
    for (int i = 0; !file.eof(); i++)
    {
        file >> date;
        file >> money;
        file >> source;
        vec.push_back({date, money, source});
    }
    file.close();

    totalExpenditure = 0;
    totalIncome = 0;
    total = 0;
    for (auto i : vec)
    {
        total += atoi(i.money.c_str());
        if (atoi(i.money.c_str()) < 0)
            totalExpenditure -= atoi(i.money.c_str());
        else
            totalIncome += atoi(i.money.c_str());
    }
}

Moneyinfo::~Moneyinfo()
{
    update();
}

void Moneyinfo::update()
{
    totalExpenditure = 0;
    totalIncome = 0;
    total = 0;
    for (auto i : vec)
    {
        total += atoi(i.money.c_str());
        if (atoi(i.money.c_str()) < 0)
            totalExpenditure -= atoi(i.money.c_str());
        else
            totalIncome += atoi(i.money.c_str());
    }

    fstream file;
    file.open("moneyinfo.txt", ios::out);
    for (auto i : vec)
    {
        file << i.date << ' ' << i.money << ' ' << i.source << endl;
    }
    file.close();
}

void Moneyinfo::show()
{
    system("cls");
    pos(30, 9);
    cout << "**********�ʽ���ˮ**********" << endl;
    pos(30, 11);
    cout << " 1. ��ѡ��:" << endl;
    pos(30, 13);
    cout << "* 2.�޸��ʽ���ˮ" << endl;
    pos(30, 15);
    cout << "* 3.�����ʽ���ˮ" << endl;
    pos(30, 17);
    cout << "* ��q���ط������� ��r������һ��" << endl;
    pos(30, 19);
    cout << "********************************************" << endl;

    pos(100, 10);
    cout << "��֧��: " << totalExpenditure << endl;
    pos(100, 11);
    cout << "������: " << totalIncome << endl;
    pos(100, 12);
    cout << "�ܽ��: " << total << endl;
    pos(100, 15);
    cout << "���";
    pos(105, 15);
    cout << "����";
    pos(120, 15);
    cout << "��ˮ";
    pos(128, 15);
    cout << "��Դ/ȥ��" << endl;

    int order = 1;
    for (auto i : vec)
    {
        pos(100, 15 + order);
        cout << order;
        pos(105, 15 + order);
        cout << i.date;
        pos(120, 15 + order);
        cout << i.money;
        pos(128, 15 + order);
        cout << i.source << endl;
        order++;
    }
}

void Moneyinfo::AddMoneyInfo()
{
    string date, money, source;
    pos(30, 22);
    cout << "����:";
    pos(36, 22);
    cin >> date;
    pos(30, 24);
    cout << "���:";
    pos(36, 24);
    cin >> money;
    pos(30, 26);
    cout << "��Դ:";
    pos(36, 26);
    cin >> source;
    vec.push_back(moneyInfoSt{date, money, source});
    sort(vec.begin(), vec.end(), cmpMoneyInfo);
    update();
    show();
    pos(30, 28);
    cout << "��ӳɹ�" << endl;
    pos(30, 30);
    system("pause");
}

void Moneyinfo::ChangeMoneyInfo()
{
    string date, money, source;
    int i = 0;
    pos(30, 20);
    cout << "��ѡ��Ҫ�޸ĵ���:";
    pos(36, 21);
    cin >> i;
    pos(30, 22);
    cout << "����:";
    pos(36, 22);
    cin >> date;
    pos(30, 24);
    cout << "���:";
    pos(36, 24);
    cin >> money;
    pos(30, 26);
    cout << "��Դ:";
    pos(36, 26);
    cin >> source;
    vec[i] = moneyInfoSt{date, money, source};
    sort(vec.begin(), vec.end(), cmpMoneyInfo);
    update();
    show();
    pos(30, 28);
    cout << "�޸ĳɹ�" << endl;
    pos(30, 30);
    system("pause");
}

void Moneyinfo::DeleteMoneyInfo()
{
    int i = 0;
    pos(30, 20);
    cout << "��ѡ��Ҫɾ������:";
    pos(36, 21);
    cin >> i;
    vec.erase(vec.begin() + i);
    update();
    show();
    pos(30, 28);
    cout << "ɾ���ɹ�" << endl;
    update();
    show();
    pos(30, 30);
    system("pause");
}