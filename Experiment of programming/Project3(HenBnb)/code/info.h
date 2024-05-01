#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include "surface.h"
#include "calendar.h"
#include <string>
using namespace std;
typedef string DateYMD;

inline string toString(int num)
{
    return  (num < 10) ? ('0' + to_string(num)) : to_string(num);
}

typedef struct ReserveinfoSt
{
    DateYMD  checkin;
    DateYMD  checkout;
    string guest;

}ReserveinfoSt;

typedef struct RepairinfoSt
{
    DateYMD date;
    string reporter;
    string description;
    string status;
    string comment;

}RepairinfoSt;

typedef struct DateinfoSt
{
    string status;
    string price;

}DateinfoSt;

typedef struct moneyInfoSt
{
    string money;
    string source;

}moneyInfoSt;

class Reserveinfo
{
public:
    vector<ReserveinfoSt> vec;
    //TODO: 修改为map
    Reserveinfo();
    ~Reserveinfo();
    void update();
    void show();

};


class Repairinfo
{
public:

    RepairinfoSt rpTitle;
    vector<RepairinfoSt> vec;

    Repairinfo();
    ~Repairinfo();
    void update();
    void show(string status);
};

bool cmpRepair(RepairinfoSt a, RepairinfoSt b);



class Dateinfo
{
public:
    int year, month;
    string basicPrice;
    map<string, DateinfoSt> map;

    Dateinfo();
    ~Dateinfo();

    void show();
    void update();
};

class Moneyinfo
{
public:
    multimap<DateYMD, moneyInfoSt> mmap;

    Moneyinfo();
    ~Moneyinfo();
    void update();
    void show();
};


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
        mmap.insert({date, {money, source}});
    }
    file.close();
}

Moneyinfo::~Moneyinfo()
{
    update();
}


void Moneyinfo::update()
{
    fstream file;
    file.open("moneyinfo.txt", ios::out);
    for (auto i : mmap)
    {
        file << i.first << ' ' << i.second.money << ' ' << i.second.source << endl;
    }
    file.close();
}

void Moneyinfo::show()
{
    pos(30, 16);
    pos(30, 16 );
    cout << "序号";
    pos(40, 16 );
    cout << "日期";
    pos(60, 16 );
    cout << "流水";
    pos(75, 16 );
    cout << "来源/去向"<< endl;

    int order = 1;
    for (auto i : mmap)
    {
        pos(30, 16 + order);
        cout << order;
        pos(40, 16 + order);
        cout << i.first;
        pos(60, 16 + order);
        cout << i.second.money;
        pos(75, 16 + order);
        cout << i.second.source << endl;
        order++;
    }
}





















inline void ReserveinfoToDateinfo()
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
            dateInfo.map[datetemp].status = i.guest;
            if (dateInfo.map[datetemp].price == "")
                dateInfo.map[datetemp].price = "-1";

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
        dateInfo.map[datetemp].status = i.guest;
        if (dateInfo.map[datetemp].price == "")
            dateInfo.map[datetemp].price = "-1";
    }
}

extern Reserveinfo reserveInfo;
extern Repairinfo repairInfo;
extern Dateinfo dateInfo;
extern Moneyinfo moneyInfo;