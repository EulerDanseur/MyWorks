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

    // ���캯��
    Landlord();
    // ��������
    ~Landlord();

    // ��Ա����

    // �˵�
    void Menu();
    // ��¼
    void Login();

    // ��Ϣ����

    void Reservedinfo();   // Ԥ����Ϣ����
    void DoRepairInfo();   // ά����Ϣ����
    void DoRoomInfo();     // ������Ϣ����
    void LandlordInfo();   // ������Ϣ����
    void ChangePassword(); // �޸�����
    void DoMoneyInfo();    // �ʽ���Ϣ����

    void update(); // �����ļ�
    void GuestList(); // �û��б�
};
