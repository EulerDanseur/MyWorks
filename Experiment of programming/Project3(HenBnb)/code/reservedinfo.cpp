#include "landlord.h"
Reserveinfo::Reserveinfo()
{
    Date today;
    ifstream file;
    file.open("reservedinfo.txt");
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i].checkin >> vec[i].checkout >> vec[i].room >> vec[i].guest >> vec[i].money >> vec[i].status >> vec[i].score;
        if (vec[i].checkout < today && vec[i].status == "未完成")
            vec[i].status = "已完成";
    }
    file.close();
    if (vec.size() == 1 && vec[0].room == "")
    {
        vec.clear();
    }
    else
    {
        for (auto i = vec.begin(); !vec.empty() && i != vec.end(); i++)
        {
            if (i->room == "")
            {
                i--;
                vec.erase(i + 1);
            }
        }
    }
    update();
}

Reserveinfo::~Reserveinfo()
{
    update();
}

void Reserveinfo::showLandlord(string id)
{
    system("cls");
    showNow();

    pos(30, 10);
    cout << "**********已预订信息管理*******************" << endl;
    pos(30, 12);
    cout << "*  按q返回房主菜单   按e返回主菜单   " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    pos(20, 16);
    cout << "序号";
    pos(30, 16);
    cout << "房间号";
    pos(40, 16);
    cout << "用户";
    pos(60, 16);
    cout << "入住日期";
    pos(75, 16);
    cout << "退房日期";
    pos(90, 16);
    cout << "费用";
    pos(100, 16);
    cout << "状态" << endl;
    pos(120, 16);
    cout << "评分" << endl;

    int order = 1;
    if (id == "all")
        for (auto i : vec)
        {
            pos(20, 16 + order);
            cout << order;
            pos(30, 16 + order);
            cout << i.room;
            pos(40, 16 + order);
            cout << i.guest;
            pos(60, 16 + order);
            cout << i.checkin;
            pos(75, 16 + order);
            cout << i.checkout << endl;
            pos(90, 16 + order);
            cout << i.money << endl;
            pos(100, 16 + order);
            cout << i.status << endl;
            pos(120, 16 + order);
            if (i.status == "已完成")
                i.score == -1 ? cout << "未评分" : cout << i.score;
            else
                cout << "-";

            order++;
        }
    else
        for (auto i : vec)
            if (i.room == id)
            {
                pos(20, 16 + order);
                cout << order;
                pos(30, 16 + order);
                cout << i.room;
                pos(40, 16 + order);
                cout << i.guest;
                pos(60, 16 + order);
                cout << i.checkin;
                pos(75, 16 + order);
                cout << i.checkout << endl;
                pos(90, 16 + order);
                cout << i.money << endl;
                pos(100, 16 + order);
                cout << i.status << endl;
                pos(120, 16 + order);
                cout << i.score << endl;

                order++;
            }
}

void Reserveinfo::update()
{
    sort(vec.begin() + 1, vec.end(), [](ReserveinfoSt a, ReserveinfoSt b)
         { return a.checkin < b.checkin; });
    ofstream file;
    file.open("reservedinfo.txt");
    for (auto i : vec)
    {
        file << i.checkin << ' ' << i.checkout << ' ' << i.room << ' ' << i.guest << ' ' << i.money << ' ' << i.status << ' ' << i.score << endl;
    }
    file.close();
}

bool operator==(const ReserveinfoSt &a, const ReserveinfoSt &b)
{
    return a.room == b.room && a.checkin == b.checkin && a.checkout == b.checkout && a.guest == b.guest && a.money == b.money && a.status == b.status && a.score == b.score;
}