#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>

#include "interface.h"
#include "calendar.h"

using namespace std;

#define UPKEY 72
#define DOWNKEY 80
#define LEFTKEY 75
#define RIGHTKEY 77

typedef time_t Time;
typedef string DateYMD;

class Guest;

inline string toString(int num)
{
    return (num < 10) ? ('0' + to_string(num)) : to_string(num);
}

typedef struct ReserveinfoSt
{
    string room;
    DateYMD checkin;
    DateYMD checkout;
    string guest;

} ReserveinfoSt;

typedef struct RepairinfoSt
{
    DateYMD date;
    string reporter;
    string room;
    string description;
    string status;
    string comment;

} RepairinfoSt;

typedef struct DateinfoSt
{
    string status;
    string price;

} DateinfoSt;

typedef struct moneyInfoSt
{

    DateYMD date;
    string money;
    string source;

} moneyInfoSt;

class Reserveinfo
{
public:
    vector<ReserveinfoSt> vec;
    // TODO: 修改为map
    Reserveinfo();
    ~Reserveinfo();
    void update();
    void show(string id = "all");
    void MakeReserve(Guest *);
    void deleteReserve(Guest *) {}
};

class Repairinfo
{
public:
    RepairinfoSt rpTitle;
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
};

bool cmpRepair(RepairinfoSt a, RepairinfoSt b);

class Dateinfo
{
public:
    int year, month;
    string basicPrice;
    string id;
    bool accesible;
    map<string, DateinfoSt> map;

    void DoDateInfoLandlord();
    void DoDateInfoGuest();
    void MakeReserve();
    void show();
    void showLandlord();
    void showGuest();
    void showChangePrice();
    void showChangeSpare();
    void ChangeDatePrice();
    void ChangeDateSpare();
};

class Room
{
public:
    vector<string> roomList;
    map<string, Dateinfo> roomInfo;
    Room();
    ~Room();
    void update();
    void show();
};

extern Room room;

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
bool cmpMoneyInfo(moneyInfoSt a, moneyInfoSt b);

extern Reserveinfo reserveInfo;
extern Repairinfo repairInfo;
// extern Dateinfo dateInfo;
extern Moneyinfo moneyInfo;

inline void RoomReserveinfoToRoomDateinfo()
{
    for (auto i : reserveInfo.vec)
    {
        int checkInYear = stoi(i.checkin.substr(0, 4));
        int checkInMonth = stoi(i.checkin.substr(5, 2));
        int checkInDay = stoi(i.checkin.substr(8, 2));
        int checkOutYear = stoi(i.checkout.substr(0, 4));
        int checkOutMonth = stoi(i.checkout.substr(5, 2));
        int checkOutDay = stoi(i.checkout.substr(8, 2));

        string daytemp, monthtemp, datetemp;

        while (!(checkInYear == checkOutYear && checkInMonth == checkOutMonth && checkInDay == checkOutDay))
        {
            daytemp = toString(checkInDay);
            monthtemp = toString(checkInMonth);
            datetemp = to_string(checkInYear) + '.' + monthtemp + '.' + daytemp;
            room.roomInfo[i.room].map[datetemp].status = i.guest;
            if (room.roomInfo[i.room].map[datetemp].price == "")
                room.roomInfo[i.room].map[datetemp].price = "-1";

            checkInDay++;
            if (checkInDay > DaysAmount(checkInMonth, checkInYear))
            {
                checkInDay = 1;
                checkInMonth++;
                if (checkInMonth > 12)
                {
                    checkInMonth = 1;
                    checkInYear++;
                }
            }
        }
        daytemp = toString(checkInDay);
        monthtemp = toString(checkInMonth);
        datetemp = to_string(checkInYear) + '.' + monthtemp + '.' + daytemp;
        room.roomInfo[i.room].map[datetemp].status = i.guest;
        if (room.roomInfo[i.room].map[datetemp].price == "")
            room.roomInfo[i.room].map[datetemp].price = "-1";
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
