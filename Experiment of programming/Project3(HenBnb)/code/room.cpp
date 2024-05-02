#include "info.h"
Room room;

Room::Room()
{
    fstream file;
    string id;
    file.open("roomlist.txt", ios::in);
    while(!file.eof())
    {
        
        file >> id;
        roomInfo[id].id = id;
        file >> roomInfo[id].basicPrice;
        file >> roomInfo[id].accesible;
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
    string date;
    while (!file.eof())
    {
        file >> id;
        file >> date;
        file >> roomInfo[id].map[date].status;
        file >> roomInfo[id].map[date].price;
    }
    file.close();
}

Room::~Room()
{
    update();
}

void Room::update()
{
    fstream file;
    file.open("roomlist.txt", ios::out);
    for (auto i : roomList)
    {
        file << i << ' ' << roomInfo[i].basicPrice << ' ' << roomInfo[i].accesible << endl;
    }
    file.close();

    RoomReserveinfoToRoomDateinfo();

    file.open("dateinfo.txt", ios::out);
    for (auto i : roomInfo)
    {
        for (auto j : i.second.map)
        {
            file << i.first << ' ' << j.first << ' ' << j.second.status << ' ' << j.second.price << endl;
        }
    }
    file.close();
}

void Room::show()
{
    int order = 0;
    pos(70, 10);
    for(auto i : roomList)
    {
        pos(70, 10 + order);
        cout << i << endl;
        order++;
    }
}