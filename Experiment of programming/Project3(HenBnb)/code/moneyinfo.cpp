#include "info.h"

Moneyinfo moneyInfo;

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

    pos(50, 4);
    cout << "总支出: " << totalExpenditure << endl;
    pos(50, 5);
    cout << "总收入: " << totalIncome << endl;
    pos(50, 6);
    cout << "总金额: " << total << endl;
    pos(50, 10);
    cout << "序号";
    pos(55, 10);
    cout << "日期";
    pos(70, 10);
    cout << "流水";
    pos(78, 10);
    cout << "来源/去向" << endl;

    int order = 1;
    for (auto i : vec)
    {
        pos(50, 10 + order);
        cout << order;
        pos(55, 10 + order);
        cout << i.date;
        pos(70, 10 + order);
        cout << i.money;
        pos(78, 10 + order);
        cout << i.source << endl;
        order++;
    }
}