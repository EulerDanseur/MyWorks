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

    vector<ReserveinfoSt *> myReserve;

    Guest();
    Guest(string id, string name, string password, string gender, Date registerDate, string phone, string email);
    ~Guest();

    void Menu();

    void DoRoomInfo();
    void MakeReserve(string guestid);
    void MyReserveInfo();
    void showReserve();
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
    void update();
    void GuestInterface();
    void Login();
    void Register();
};

extern GuestClass guestclass;