#include "info.h"
#include "interface.h"

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