#pragma once
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "calendar.h"
#include "date.h"
#include "interface.h"
using namespace std;

#define UPKEY 72
#define DOWNKEY 80
#define LEFTKEY 75
#define RIGHTKEY 77

typedef time_t Time;

class Guest;

inline string toString(int num)
{
    return (num < 10) ? ('0' + to_string(num)) : to_string(num);
}

typedef struct ReserveinfoSt
{
    string room;
    Date checkin;
    Date checkout;
    string guest;
    string money;
    string status;
    double score;

} ReserveinfoSt;

bool operator==(const ReserveinfoSt &a, const ReserveinfoSt &b);

typedef struct RoomDateSt
{
    string status;
    string price;

} RoomDateSt;

typedef struct moneyInfoSt
{

    Date date;
    string money;
    string source;

} moneyInfoSt;

class Reserveinfo
{
public:
    vector<ReserveinfoSt> vec;

    Reserveinfo();
    ~Reserveinfo();
    void update();
    void showLandlord(string id = "all");
};

typedef struct RepairinfoSt
{
    Date date;
    string reporter;
    string room;
    string description;
    string status;
    string comment;
    string money;

} RepairinfoSt;
class Repairinfo
{
public:
    struct RpTitle
    {
        string date, reporter, room, description, status, comment, money;
    } rpTitle;

    vector<RepairinfoSt> vec;
    Repairinfo();
    ~Repairinfo();
    void update();
    void show(string status = "全部");
    void showDeleteInterface();
    void DeleteRepairInfo();
    void showReviseInterface();
    void ReviseRepairChoose();
    void showReviseInfo();
    void ReviseRepairInfo();
    friend ostream &operator<<(ostream &out, const Repairinfo &repairinfo);
    friend istream &operator>>(istream &in, Repairinfo &repairinfo);
    friend ostream &operator<<(ostream &out, const RpTitle &i)
    {
        out << setw(13) << i.date << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
        return out;
    }
};

class Room
{
public:
    string basicPrice;
    string id;
    bool accesible;
    int usedTimes = 0;
    int scoreTimes = 0;
    double score;

    int year, month;
    map<Date, RoomDateSt> map;
    void showCalendar();

    void DoRoomInfoLandlord();
    void showChangePrice();
    void showChangeSpare();
    void ChangeDatePrice();
    void ChangeDateSpare();

    void DoRoomInfoGuest(string guestid);
    void MakeReserve(string guestid);

    void showLandlord();
    void showGuest();

    friend ostream &operator<<(ostream &out, const Room &roominfo);
};

class RoomClass
{
public:
    vector<string> roomList;
    map<string, Room> room;
    RoomClass();
    ~RoomClass();
    void update();
    void show();
};

extern RoomClass roomclass;

class Moneyinfo
{
public:
    int total, totalExpenditure, totalIncome;

    vector<moneyInfoSt> vec;

    Moneyinfo();
    ~Moneyinfo();
    void update();
    void show();
    void AddMoneyInfo();
    void ChangeMoneyInfo();
    void DeleteMoneyInfo();
};

extern Reserveinfo reserveInfo;
extern Repairinfo repairInfo;
extern Moneyinfo moneyInfo;

inline void Reserveinfo_to_Roomscoreinfo()
{
    for (auto i = roomclass.room.begin(); i != roomclass.room.end(); i++)
    {
        i->second.score = 0;
        i->second.scoreTimes = 0;
        i->second.usedTimes = 0;
    }

    for (auto i : reserveInfo.vec)
    {
        if (i.status != "已取消" && i.status != "未完成")
        {
            if (i.score != -1)
            {
                roomclass.room[i.room].score += i.score;
                roomclass.room[i.room].scoreTimes++;
            }
            roomclass.room[i.room].usedTimes++;
        }
    }
}
inline void Reserveinfo_to_RoomDateinfo()
{
    for (auto i : reserveInfo.vec)
    {
        if (i.status == "已取消")
        {
            for (Date d = i.checkin; d <= i.checkout; d++)
            {
                if (roomclass.room[i.room].map.find(d) == roomclass.room[i.room].map.end())
                {
                    continue;
                }
                else if (roomclass.room[i.room].map[d].price == roomclass.room[i.room].basicPrice)
                {
                    roomclass.room[i.room].map.erase(d);
                }
                else
                {
                    roomclass.room[i.room].map[d].status = "空闲";
                }
            }
        }
        else
            for (Date d = i.checkin; d <= i.checkout; d++)
            {
                roomclass.room[i.room].map[d].status = i.guest;
                if (roomclass.room[i.room].map[d].price == "")
                    roomclass.room[i.room].map[d].price = roomclass.room[i.room].basicPrice;
            }
    }
}

inline bool isnumber(string a)
{
    for (auto i : a)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}

inline ostream &operator<<(ostream &out, const RepairinfoSt &i)
{
    out << setw(13) << to_string(i.date.year) + "." + to_string(i.date.month) + "." + to_string(i.date.day) << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
    return out;
}

inline ofstream &operator<<(ofstream &out, const RepairinfoSt &i)
{
    out << i.date << ' ' << i.reporter << ' ' << i.room << ' ' << i.description << ' ' << i.status << ' ' << i.comment << ' ' << i.money << endl;
    return out;
}

inline istream &operator>>(istream &in, RepairinfoSt &i)
{
    in >> i.date >> i.reporter >> i.room >> i.description >> i.status >> i.comment >> i.money;
    return in;
}