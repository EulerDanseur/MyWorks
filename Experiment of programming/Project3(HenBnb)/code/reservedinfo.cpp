#include "landlord.h"

Reserveinfo reserveInfo;

Reserveinfo::Reserveinfo()
{
    fstream file;
    file.open("reservedinfo.txt", ios::in);
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i].room >> vec[i].guest >> vec[i].checkin >> vec[i].checkout;
    }
    file.close();
    update();
}

Reserveinfo::~Reserveinfo()
{
    update();
}

void Reserveinfo::show(string id)
{
    system("cls");
    pos(30, 10);
    cout << "**********��Ԥ����Ϣ����*******************" << endl;
    pos(30, 12);
    cout << "*  ��q���ط����˵�   ��e�������˵�   ��r�鿴ĳ������ " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    pos(20, 16);
    cout << "���";
    pos(30, 16);
    cout << "�����";
    pos(40, 16);
    cout << "�û�";
    pos(60, 16);
    cout << "��ס����";
    pos(75, 16);
    cout << "�˷�����" << endl;
    int order = 1;
    if (id == "all")
        for (auto i : vec)
        {
            pos(20, 16 + order);
            cout << order;
            pos(30, 16 + order);
            cout << i.room;
            pos(40, 16 + order);
            cout << i.guest;
            pos(60, 16 + order);
            cout << i.checkin;
            pos(75, 16 + order);
            cout << i.checkout << endl;

            order++;
        }
    else
        for (auto i : vec)
            if (i.room == id)
            {
                pos(20, 16 + order);
                cout << order;
                pos(30, 16 + order);
                cout << i.room;
                pos(40, 16 + order);
                cout << i.guest;
                pos(60, 16 + order);
                cout << i.checkin;
                pos(75, 16 + order);
                cout << i.checkout << endl;

                order++;
            }
}

void Reserveinfo::update()
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if (i->guest == "")
        {
            i--;
            vec.erase(i + 1);
        }
    }
    //RoomReserveinfoToRoomDateinfo();
    fstream file;
    file.open("reservedinfo.txt", ios::out);
    for (auto i : vec)
    {
        file << i.room << ' ' << i.guest << ' ' << i.checkin << ' ' << i.checkout << endl;
    }
    file.close();
}

void Reserveinfo::MakeReserve(Guest *)
{
    system("cls");
    pos(30, 10);
    cout << "**********Ԥ������*******************" << endl;
    pos(30, 12);
    cout << "*  ��q���ط����˵�       ��e�������˵�        " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    string roomTemp, checkinTemp, checkoutTemp;

    pos(30, 15);
    cout << "�����:";
    pos(40, 15);
    cin >> roomTemp;
    pos(30, 16);
    cout << "��ס����(��2023.01.01):";
    pos(55, 16);
    cin >> checkinTemp;
    pos(30, 18);
    cout << "�˷�����:";
    pos(40, 18);
    cin >> checkoutTemp;
}
