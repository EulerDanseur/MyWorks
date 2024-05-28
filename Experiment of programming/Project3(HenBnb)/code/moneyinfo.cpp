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
    cout << "**********资金流水**********" << endl;
    pos(30, 11);
    cout << "* 1.删除资金流水 " << endl;
    pos(30, 13);
    cout << "* 2.修改资金流水" << endl;
    pos(30, 15);
    cout << "* 3.增加资金流水" << endl;
    pos(30, 17);
    cout << "* 按q或r返回上一级" << endl;
    pos(30, 19);
    cout << "********************************************" << endl;

    pos(100, 10);
    cout << "总支出: " << totalExpenditure << endl;
    pos(100, 11);
    cout << "总收入: " << totalIncome << endl;
    pos(100, 12);
    cout << "总金额: " << total << endl;
    pos(100, 15);
    cout << "序号";
    pos(105, 15);
    cout << "日期";
    pos(120, 15);
    cout << "流水";
    pos(128, 15);
    cout << "来源/去向" << endl;

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
        cout << "日期:";
        pos(36, 22);

        cin >> date;
        if (!date.IsValid())
        {
            pos(30, 24);
            cout << "日期不合法" << endl;
            pos(30, 26);
            system("pause");
            break;
        }
        else
        {
            pos(30, 24);
            cout << "金额:";
            pos(36, 24);

            string money0 = "";
            cin >> money0;
            if (!isnumber(money0))
            {
                pos(30, 24);
                cout << "金额不合法" << endl;
                pos(30, 26);
                system("pause");
                break;
            }
            money = money0;
            pos(30, 26);
            cout << "来源:";
            pos(36, 26);

            cin >> source;
            vec.push_back(moneyInfoSt{date, money, source}); // moneyInfoSt{date, money, source};
            sort(vec.begin(), vec.end(), [](moneyInfoSt a, moneyInfoSt b)
                 { return a.date < b.date; });
            update();
            show();
            pos(30, 28);
            cout << "修改成功" << endl;
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
        cout << "请选择要修改的项(按0返回):";
        pos(36, 21);

        cin >> i;
        if (i == 0)
        {
            break;
        }
        if (vec.size() < i || i < 0)
        {
            pos(30, 22);
            cout << "无此项";
            system("pause");
            break;
        }
        pos(30, 22);
        cout << "日期:";
        pos(36, 22);

        cin >> date;
        if (!date.IsValid())
        {
            pos(30, 24);
            cout << "日期不合法" << endl;
            pos(30, 26);
            system("pause");
            break;
        }
        else
        {
            pos(30, 24);
            cout << "金额:";
            pos(36, 24);
            string money0 = "";
            cin >> money0;
            if (!isnumber(money0))
            {
                pos(30, 24);
                cout << "金额不合法" << endl;
                pos(30, 26);
                system("pause");
                break;
            }
            money = money0;
            pos(30, 26);
            cout << "来源:";
            pos(36, 26);

            cin >> source;
            vec[i - 1] = moneyInfoSt{date, money, source};
            sort(vec.begin(), vec.end(), [](moneyInfoSt a, moneyInfoSt b)
                 { return a.date < b.date; });
            update();
            show();
            pos(30, 28);
            cout << "修改成功" << endl;
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
    cout << "请选择要删除的项(0返回):";
    pos(30, 22);

    cin >> i;
    if (i == 0)
    {
        return;
    }
    if (vec.size() < i || i < 0)
    {
        pos(30, 22);
        cout << "无此项";
        system("pause");
        return;
    }
    vec.erase(vec.begin() + i - 1);
    update();
    show();
    pos(30, 28);
    cout << "删除成功" << endl;
    update();
    show();
    pos(30, 30);
    system("pause");
}