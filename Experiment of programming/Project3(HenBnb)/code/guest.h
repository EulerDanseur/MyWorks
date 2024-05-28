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

    // ����Ԥ������
    vector<ReserveinfoSt *> myReserve;

    Guest();
    Guest(string id, string name, string password, string gender, Date registerDate, string phone, string email);
    ~Guest();

    // ����
    void Menu();

    // ����
    // Ԥ��
    void DoRoomInfo();
    
    // ����Ԥ��
    void MakeReserve(string guestid);
    // ����Ԥ����Ϣ
    void MyReserveInfo();
    
    //����
    void showReserve();
    
    // ����
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
    // ��д
    void update();
    // ����
    void GuestInterface();
    // ����
    // ��¼
    void Login();
    // ע��
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