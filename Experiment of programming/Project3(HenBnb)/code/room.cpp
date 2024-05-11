#include "info.h"

RoomClass::RoomClass()
{
    fstream file;
    string id;
    
    file.open("roomlist.txt", ios::in);
    while (!file.eof())
    {

        file >> id;
        room[id].id = id;
        file >> room[id].basicPrice;
        file >> room[id].accesible;
        roomList.push_back(id);
    }
    file.close();

    if (roomList.size() == 1 && roomList[0] == "")
    {
        roomList.clear();
    }
    else
    {
        if (*roomList.rbegin() == *(roomList.rbegin() + 1))
        {
            roomList.pop_back();
        }
    }

    file.open("dateinfo.txt", ios::in);
    Date date;
    while (!file.eof())
    {
        file >> id;
        file >> date;
        file >> room[id].map[date].status;
        file >> room[id].map[date].price;
    }
    file.close();
    Reserveinfo_to_Roomscoreinfo();
    Reserveinfo_to_RoomDateinfo();
    update();
}

RoomClass::~RoomClass()
{
    update();
}

void RoomClass::update()
{
    ofstream file;
    file.open("roomlist.txt", ios::out);
    for (auto i : roomList)
    {
        file << i << ' ' << room[i].basicPrice << ' ' << room[i].accesible << endl;
    }
    file.close();

    Reserveinfo_to_RoomDateinfo();

    file.open("dateinfo.txt", ios::out);
    for (auto i : room)
    {
        for (auto j : i.second.map)
        {
            file << i.first << ' ' << j.first << ' ' << j.second.status << ' ' << j.second.price << endl;
        }
    }
    file.close();
}

void RoomClass::show()
{
    showNow();
    int order = 1;
    pos(90, 10);
    cout.setf(ios::left);
    cout << setw(5) << "号码"
         << setw(10) << "状态"
         << setw(10) << "基本价格"
         << setw(10) << "使用次数"
         << setw(6) << "评分"
         << setw(10) << "评分次数";
    for (auto i : room)
    {
        pos(90, 10 + order);
        cout << i.second;
        order++;
    }
}