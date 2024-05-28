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
    // ������ת��Ϊ�ַ���
    return (num < 10) ? ('0' + to_string(num)) : to_string(num);
}

// Ԥ����Ϣ�ṹ
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

// Ԥ����Ϣ==����
bool operator==(const ReserveinfoSt &a, const ReserveinfoSt &b);

// ���ڼ۸�ṹ
typedef struct RoomDateSt
{
    string status;
    string price;

} RoomDateSt;

// �ʽ���Ϣ
typedef struct moneyInfoSt
{

    Date date;
    string money;
    string source;

} moneyInfoSt;

// Ԥ����Ϣ��
class Reserveinfo
{
public:
    vector<ReserveinfoSt> vec;

    Reserveinfo();                        // ���캯��
    ~Reserveinfo();                       // ��������
    void update();                        // ����Ԥ����Ϣ
    void showLandlord(string id = "all"); // չʾ����Ԥ����Ϣ
};

// ά����Ϣ�ṹ
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

// ά����Ϣ��
class Repairinfo
{
public:
    // ά����Ϣ����
    struct RpTitle
    {
        string date, reporter, room, description, status, comment, money;
    } rpTitle;

    vector<RepairinfoSt> vec;          // ά����Ϣ����
    Repairinfo();                      // ���캯��
    ~Repairinfo();                     // ��������
    void update();                     // ����ά����Ϣ
    void show(string status = "ȫ��"); // չʾά����Ϣ
    void showDeleteInterface();        // չʾɾ��ά����Ϣ����
    void DeleteRepairInfo();           // ɾ��ά����Ϣ
    void showReviseInterface();        // չʾ�޸�ά����Ϣ����
    void ReviseRepairChoose();         // �޸�ά����Ϣ
    void showReviseInfo();             // չʾ�޸�ά����Ϣ
    void ReviseRepairInfo();           // �޸�ά����Ϣ

    // ά����Ϣ<<>>����
    friend ostream &operator<<(ostream &out, const Repairinfo &repairinfo);
    friend istream &operator>>(istream &in, Repairinfo &repairinfo);
    friend ostream &operator<<(ostream &out, const RpTitle &i)
    {
        out << setw(13) << i.date << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
        return out;
    }
};

// ������
class Room
{
public:
    string basicPrice;  // �����۸�
    string id;          // �����
    bool accesible;     // �Ƿ��ԤԼ
    int usedTimes = 0;  // ��ʹ�ô���
    int scoreTimes = 0; // ���ִ���
    double score;       // ����

    int year, month;           // ����
    map<Date, RoomDateSt> map; // ���ڼ۸�
    void showCalendar();       // չʾ����

    void DoRoomInfoLandlord(); // չʾ������Ϣ
    void showChangePrice();    // չʾ�޸ļ۸����
    void showChangeSpare();    // չʾ�޸Ŀ���״̬����
    void ChangeDatePrice();    // �޸����ڼ۸�
    void ChangeDateSpare();    // �޸����ڿ���״̬

    void DoRoomInfoGuest(string guestid); // չʾ������Ϣ
    void MakeReserve(string guestid);     // Ԥ��

    void showLandlord(); // ����Ԥ����Ϣ
    void showGuest();    // չʾ����Ԥ����Ϣ

    friend ostream &operator<<(ostream &out, const Room &roominfo);
};

// �������
class RoomClass
{
public:
    vector<string> roomList; // �����б�
    map<string, Room> room;  // ��������
    RoomClass();             // ���캯��
    ~RoomClass();            // ��������
    void update();           // ���·�����Ϣ
    void show();             // չʾ������Ϣ
};

extern RoomClass roomclass;

class Moneyinfo
{
public:
    int total, totalExpenditure, totalIncome; // ����֧

    vector<moneyInfoSt> vec; // ��֧��¼

    Moneyinfo();            // ���캯��
    ~Moneyinfo();           // ��������
    void update();          // ������֧��¼
    void show();            // չʾ��֧��¼
    void AddMoneyInfo();    // �����֧��¼
    void ChangeMoneyInfo(); // �޸���֧��¼
    void DeleteMoneyInfo(); // ɾ����֧��¼
};

extern Reserveinfo reserveInfo;
extern Repairinfo repairInfo;
extern Moneyinfo moneyInfo;

// ��Ԥ����Ϣת��Ϊ����������Ϣ
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
        if (i.status != "��ȡ��" && i.status != "δ���")
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

// ��Ԥ����Ϣת��Ϊ����������Ϣ
inline void Reserveinfo_to_RoomDateinfo()
{
    for (auto i : reserveInfo.vec)
    {
        if (i.status == "��ȡ��")
        {
            // Ԥ����ȡ����������״̬����Ϊ����
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
                    roomclass.room[i.room].map[d].status = "����";
                }
            }
        }
        else // Ԥ��
            for (Date d = i.checkin; d < i.checkout; d++)
            {
                roomclass.room[i.room].map[d].status = i.guest;
                if (roomclass.room[i.room].map[d].price == "")
                    roomclass.room[i.room].map[d].price = roomclass.room[i.room].basicPrice;
            }
    }
}

// �ж��Ƿ�Ϊ����
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

// ��ά����Ϣת��Ϊ�ַ���
inline ostream &operator<<(ostream &out, const RepairinfoSt &i)
{
    out << setw(13) << to_string(i.date.year) + "." + to_string(i.date.month) + "." + to_string(i.date.day) << setw(10) << i.reporter << setw(8) << i.room << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << setw(10) << i.money << endl;
    return out;
}

//  ���ַ����ж�ȡά����Ϣ
inline ofstream &operator<<(ofstream &out, const RepairinfoSt &i)
{
    out << i.date << ' ' << i.reporter << ' ' << i.room << ' ' << i.description << ' ' << i.status << ' ' << i.comment << ' ' << i.money << endl;
    return out;
}

//  ���ַ����ж�ȡά����Ϣ
inline istream &operator>>(istream &in, RepairinfoSt &i)
{
    in >> i.date >> i.reporter >> i.room >> i.description >> i.status >> i.comment >> i.money;
    return in;
}