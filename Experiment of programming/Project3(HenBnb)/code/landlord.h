#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "interface.h"
#include "info.h"
#include "calendar.h"
using namespace std;


extern HANDLE hOut;

class Landlord
{

public:
    string password;

    Landlord();
    ~Landlord();
    void Menu();
    void Login();
    void Reservedinfo();    
    void DoRepairInfo();
    void DoDateInfo();

    void LandlordInfo();
    void ChangePassword();
    void DoMoneyInfo();

    void update();

};
