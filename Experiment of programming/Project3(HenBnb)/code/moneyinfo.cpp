#include "info.h"

Moneyinfo::Moneyinfo()
{
    ifstream file;
    file.open("moneyinfo.txt");
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i].date >> vec[i].money >> vec[i].source;
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
    if (vec.size() == 1 && vec[0].money == "")
    {
        vec.clear();
    }
    else
    {
        for (auto i = vec.begin(); !vec.empty() && i != vec.end(); i++)
        {
            if (i->money == "")
            {
                i--;
                vec.erase(i + 1);
            }
        }
    }
    update();
}

Moneyinfo::~Moneyinfo()
{
    update();
}

void Moneyinfo::update()
{
    sort(vec.begin(), vec.end(), [](moneyInfoSt a, moneyInfoSt b)
         { return a.date < b.date; });
    ofstream file;
    file.open("moneyinfo.txt");
    for (auto i : vec)
    {
        file << i.date << ' ' << i.money << ' ' << i.source << endl;
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

void Moneyinfo::show()
{
    system("cls");
    showNow();
    pos(30, 9);
    cout << "**********�ʽ���ˮ**********" << endl;
    pos(30, 11);
    cout << "* 1.ɾ���ʽ���ˮ " << endl;
    pos(30, 13);
    cout << "* 2.�޸��ʽ���ˮ" << endl;
    pos(30, 15);
    cout << "* 3.�����ʽ���ˮ" << endl;
    pos(30, 17);
    cout << "* ��q��r������һ��" << endl;
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
    Date date;
    string money, source;
    while (true)
    {
        pos(30, 20);
        cout << "����:";
        pos(36, 22);

        cin >> date;
        if (!date.IsValid())
        {
            pos(30, 24);
            cout << "���ڲ��Ϸ�" << endl;
            pos(30, 26);
            system("pause");
            break;
        }
        else
        {
            pos(30, 24);
            cout << "���:";
            pos(36, 24);

            string money0 = "";
            cin >> money0;
            if (!isnumber(money0))
            {
                pos(30, 24);
                cout << "���Ϸ�" << endl;
                pos(30, 26);
                system("pause");
                break;
            }
            money = money0;
            pos(30, 26);
            cout << "��Դ:";
            pos(36, 26);

            cin >> source;
            vec.push_back(moneyInfoSt{date, money, source}); // moneyInfoSt{date, money, source};
            sort(vec.begin(), vec.end(), [](moneyInfoSt a, moneyInfoSt b)
                 { return a.date < b.date; });
            update();
            show();
            pos(30, 28);
            cout << "�޸ĳɹ�" << endl;
            pos(30, 30);
            system("pause");
            return;
        }
    }
}

void Moneyinfo::ChangeMoneyInfo()
{
    Date date;
    string money, source;
    int i = 0;
    while (true)
    {
        pos(30, 20);
        cout << "��ѡ��Ҫ�޸ĵ���(��0����):";
        pos(36, 21);

        cin >> i;
        if (i == 0)
        {
            break;
        }
        if (vec.size() < i || i < 0)
        {
            pos(30, 22);
            cout << "�޴���";
            system("pause");
            break;
        }
        pos(30, 22);
        cout << "����:";
        pos(36, 22);

        cin >> date;
        if (!date.IsValid())
        {
            pos(30, 24);
            cout << "���ڲ��Ϸ�" << endl;
            pos(30, 26);
            system("pause");
            break;
        }
        else
        {
            pos(30, 24);
            cout << "���:";
            pos(36, 24);
            string money0 = "";
            cin >> money0;
            if (!isnumber(money0))
            {
                pos(30, 24);
                cout << "���Ϸ�" << endl;
                pos(30, 26);
                system("pause");
                break;
            }
            money = money0;
            pos(30, 26);
            cout << "��Դ:";
            pos(36, 26);

            cin >> source;
            vec[i - 1] = moneyInfoSt{date, money, source};
            sort(vec.begin(), vec.end(), [](moneyInfoSt a, moneyInfoSt b)
                 { return a.date < b.date; });
            update();
            show();
            pos(30, 28);
            cout << "�޸ĳɹ�" << endl;
            pos(30, 30);
            system("pause");
            return;
        }
    }
}

void Moneyinfo::DeleteMoneyInfo()
{
    int i = 0;
    pos(30, 20);
    cout << "��ѡ��Ҫɾ������(0����):";
    pos(30, 22);

    cin >> i;
    if (i == 0)
    {
        return;
    }
    if (vec.size() < i || i < 0)
    {
        pos(30, 22);
        cout << "�޴���";
        system("pause");
        return;
    }
    vec.erase(vec.begin() + i - 1);
    update();
    show();
    pos(30, 28);
    cout << "ɾ���ɹ�" << endl;
    update();
    show();
    pos(30, 30);
    system("pause");
}