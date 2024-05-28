#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "interface.h"
#include "info.h"
#include "calendar.h"
#include "guest.h"
using namespace std;
extern HANDLE hOut;

class Landlord
{

public:
    string password;

    // 构造函数
    Landlord();
    // 析构函数
    ~Landlord();

    // 成员函数

    // 菜单
    void Menu();
    // 登录
    void Login();

    // 信息管理

    void Reservedinfo();   // 预订信息管理
    void DoRepairInfo();   // 维修信息管理
    void DoRoomInfo();     // 房间信息管理
    void LandlordInfo();   // 房主信息管理
    void ChangePassword(); // 修改密码
    void DoMoneyInfo();    // 资金信息管理

    void update(); // 更新文件
    void GuestList(); // 用户列表
};
