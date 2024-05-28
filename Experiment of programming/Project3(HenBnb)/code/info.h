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
    // 将数字转换为字符串
    return (num < 10) ? ('0' + to_string(num)) : to_string(num);
}

// 预定信息结构
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

// 预定信息==重载
bool operator==(const ReserveinfoSt &a, const ReserveinfoSt &b);

// 日期价格结构
typedef struct RoomDateSt
{
    string status;
    string price;

} RoomDateSt;

// 资金信息
typedef struct moneyInfoSt
{

    Date date;
    string money;
    string source;

} moneyInfoSt;

// 预定信息类
class Reserveinfo
{
public:
    vector<ReserveinfoSt> vec;

    Reserveinfo();                        // 构造函数
    ~Reserveinfo();                       // 析构函数
    void update();                        // 更新预定信息
    void showLandlord(string id = "all"); // 展示房东预定信息
};

// 维修信息结构
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

// 维修信息类
class Repairinfo
{
public:
    // 维修信息标题
    struct RpTitle
    {
        string date, reporter, room, description, status, comment, money;
    } rpTitle;

    vector<RepairinfoSt> vec;          // 维修信息容器
    Repairinfo();                      // 构造函数
    ~Repairinfo();                     // 析构函数
    void update();                     // 更新维修信息
    void show(string status = "全部"); // 展示维修信息
    void showDeleteInterface();        // 展示删除维修信息界面
    void DeleteRepairInfo();           // 删除维修信息
    void showReviseInterface();        // 展示修改维修信息界面
    void ReviseRepairChoose();         // 修改维修信息
    void showReviseInfo();             // 展示修改维修信息
    void ReviseRepairInfo();           // 修改维修信息

    // 维修信息<<>>重载
    friend ostream &operator<<(ostream &out, const Repairinfo &repairinfo);
    friend istream &operator>>(istream &in, Repairinfo &repairinfo);
    friend ostream &operator<<(ostream &out, const RpTitle &i)
    {
        out << setw(13) << i.date << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
        return out;
    }
};

// 房间类
class Room
{
public:
    string basicPrice;  // 基础价格
    string id;          // 房间号
    bool accesible;     // 是否可预约
    int usedTimes = 0;  // 已使用次数
    int scoreTimes = 0; // 评分次数
    double score;       // 评分

    int year, month;           // 日期
    map<Date, RoomDateSt> map; // 日期价格
    void showCalendar();       // 展示日历

    void DoRoomInfoLandlord(); // 展示房间信息
    void showChangePrice();    // 展示修改价格界面
    void showChangeSpare();    // 展示修改空闲状态界面
    void ChangeDatePrice();    // 修改日期价格
    void ChangeDateSpare();    // 修改日期空闲状态

    void DoRoomInfoGuest(string guestid); // 展示房间信息
    void MakeReserve(string guestid);     // 预定

    void showLandlord(); // 房东预定信息
    void showGuest();    // 展示客人预定信息

    friend ostream &operator<<(ostream &out, const Room &roominfo);
};

// 房间大类
class RoomClass
{
public:
    vector<string> roomList; // 房间列表
    map<string, Room> room;  // 房间容器
    RoomClass();             // 构造函数
    ~RoomClass();            // 析构函数
    void update();           // 更新房间信息
    void show();             // 展示房间信息
};

extern RoomClass roomclass;

class Moneyinfo
{
public:
    int total, totalExpenditure, totalIncome; // 总收支

    vector<moneyInfoSt> vec; // 收支记录

    Moneyinfo();            // 构造函数
    ~Moneyinfo();           // 析构函数
    void update();          // 更新收支记录
    void show();            // 展示收支记录
    void AddMoneyInfo();    // 添加收支记录
    void ChangeMoneyInfo(); // 修改收支记录
    void DeleteMoneyInfo(); // 删除收支记录
};

extern Reserveinfo reserveInfo;
extern Repairinfo repairInfo;
extern Moneyinfo moneyInfo;

// 将预定信息转换为房间评分信息
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

// 将预定信息转换为房间日期信息
inline void Reserveinfo_to_RoomDateinfo()
{
    for (auto i : reserveInfo.vec)
    {
        if (i.status == "已取消")
        {
            // 预定已取消，将房间状态设置为空闲
            for (Date d = i.checkin; d < i.checkout; d++)
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
        else // 预定
            for (Date d = i.checkin; d < i.checkout; d++)
            {
                roomclass.room[i.room].map[d].status = i.guest;
                if (roomclass.room[i.room].map[d].price == "")
                    roomclass.room[i.room].map[d].price = roomclass.room[i.room].basicPrice;
            }
    }
}

// 判断是否为数字
inline bool isnumber(string a)
{
    int flagdot = 0, flag0 = 1;
    for (auto i : a)
    {
        if (!isdigit(i))
        {
            if(i == '.')
            {
                if(flagdot == 1) return false;
                flagdot = 1;
            }
            else if(i == '-' && flag0 == 1)
            {
                flag0 = 0;
            }
            else
                return false;
        }
        flag0 = 0;
    }
    return true;
}

// 将维修信息转换为字符串
inline ostream &operator<<(ostream &out, const RepairinfoSt &i)
{
    out << setw(13) << to_string(i.date.year) + "." + to_string(i.date.month) + "." + to_string(i.date.day) << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
    return out;
}

//  从字符串中读取维修信息
inline ofstream &operator<<(ofstream &out, const RepairinfoSt &i)
{
    out << i.date << ' ' << i.reporter << ' ' << i.room << ' ' << i.description << ' ' << i.status << ' ' << i.comment << ' ' << i.money << endl;
    return out;
}

//  从字符串中读取维修信息
inline istream &operator>>(istream &in, RepairinfoSt &i)
{
    in >> i.date >> i.reporter >> i.room >> i.description >> i.status >> i.comment >> i.money;
    return in;
}