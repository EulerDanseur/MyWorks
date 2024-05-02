#pragma once
#include "interface.h"
#include "info.h"

typedef string DateYMD;
class Guest
{
public:
    string id;

    string password;
    string name;
    string gender;

    DateYMD registerDate;
    string phone;
    string email;

    Guest();
    Guest(string id, string name, string password, string gender, DateYMD registerDate, string phone, string email);
    ~Guest();
    void Menu();
    void update();
    void DoRoomInfo();
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