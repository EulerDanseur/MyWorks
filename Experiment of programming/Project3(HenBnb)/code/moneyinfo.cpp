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
    cout << "**********资金流水**********" << endl;
    pos(30, 11);
    cout << " 1. 请选择:" << endl;
    pos(30, 13);
    cout << "* 2.修改资金流水" << endl;
    pos(30, 15);
    cout << "* 3.增加资金流水" << endl;
    pos(30, 17);
    cout << "* 按q返回房主界面 按r返回上一级" << endl;
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
    string date, money, source;
    pos(30, 22);
    cout << "日期:";
    pos(36, 22);
    cin >> date;
    pos(30, 24);
    cout << "金额:";
    pos(36, 24);
    cin >> money;
    pos(30, 26);
    cout << "来源:";
    pos(36, 26);
    cin >> source;
    vec.push_back(moneyInfoSt{date, money, source});
    sort(vec.begin(), vec.end(), cmpMoneyInfo);
    update();
    show();
    pos(30, 28);
    cout << "添加成功" << endl;
    pos(30, 30);
    system("pause");
}

void Moneyinfo::ChangeMoneyInfo()
{
    string date, money, source;
    int i = 0;
    pos(30, 20);
    cout << "请选择要修改的项:";
    pos(36, 21);
    cin >> i;
    pos(30, 22);
    cout << "日期:";
    pos(36, 22);
    cin >> date;
    pos(30, 24);
    cout << "金额:";
    pos(36, 24);
    cin >> money;
    pos(30, 26);
    cout << "来源:";
    pos(36, 26);
    cin >> source;
    vec[i] = moneyInfoSt{date, money, source};
    sort(vec.begin(), vec.end(), cmpMoneyInfo);
    update();
    show();
    pos(30, 28);
    cout << "修改成功" << endl;
    pos(30, 30);
    system("pause");
}

void Moneyinfo::DeleteMoneyInfo()
{
    int i = 0;
    pos(30, 20);
    cout << "请选择要删除的项:";
    pos(36, 21);
    cin >> i;
    vec.erase(vec.begin() + i);
    update();
    show();
    pos(30, 28);
    cout << "删除成功" << endl;
    update();
    show();
    pos(30, 30);
    system("pause");
}