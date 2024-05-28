#pragma once
#include "interface.h"
#include "info.h"

class Guest
{
public:
    string id;

    string password;
    string name;
    string gender;
    Date registerDate;
    string phone;
    string email;

    // 房间预定容器
    vector<ReserveinfoSt *> myReserve;

    Guest();
    Guest(string id, string name, string password, string gender, Date registerDate, string phone, string email);
    ~Guest();

    // 界面
    void Menu();

    // 功能
    // 预定
    void DoRoomInfo();
    
    // 房间预定
    void MakeReserve(string guestid);
    // 房间预定信息
    void MyReserveInfo();
    
    //界面
    void showReserve();
    
    // 功能
    void DeleteReserve();
    void ScoreReserve();

    void DoRepairInfo();
    void RepairReport();

    void MyInfo();
    void Message();
};

class GuestClass
{
public:
    map<string, Guest> guestMap; // <id, guest>

    GuestClass();
    ~GuestClass();
    // 读写
    void update();
    // 界面
    void GuestInterface();
    // 功能
    // 登录
    void Login();
    // 注册
    void Register();
};

extern GuestClass guestclass;

inline istream &operator>>(istream &is, Guest &guest)
{
    is >> guest.password >> guest.name >> guest.gender >> guest.registerDate >> guest.phone >> guest.email;
    return is;
}

inline ostream &operator<<(ostream &os, Guest &guest)
{
    os << guest.id << ' '
       << guest.password << ' '
       << guest.name << ' '
       << guest.gender << ' '
       << guest.registerDate << ' '
       << guest.phone << ' '
       << guest.email << endl;
    return os;
}

inline ofstream &operator<<(ofstream &ofs, Guest &guest)
{
    ofs << guest.id << ' '
        << guest.password << ' '
        << guest.name << ' '
        << guest.gender << ' '
        << guest.registerDate << ' '
        << guest.phone << ' '
        << guest.email << endl;
    return ofs;
}