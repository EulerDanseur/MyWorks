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
    cout << "**********已预订信息管理*******************" << endl;
    pos(30, 12);
    cout << "*  按q返回房主菜单   按e返回主菜单   按r查看某个房间 " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    pos(20, 16);
    cout << "序号";
    pos(30, 16);
    cout << "房间号";
    pos(40, 16);
    cout << "用户";
    pos(60, 16);
    cout << "入住日期";
    pos(75, 16);
    cout << "退房日期" << endl;
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
    cout << "**********预订房间*******************" << endl;
    pos(30, 12);
    cout << "*  按q返回房主菜单       按e返回主菜单        " << endl;
    pos(30, 14);
    cout << "********************************************" << endl;

    string roomTemp, checkinTemp, checkoutTemp;

    pos(30, 15);
    cout << "房间号:";
    pos(40, 15);
    cin >> roomTemp;
    pos(30, 16);
    cout << "入住日期(如2023.01.01):";
    pos(55, 16);
    cin >> checkinTemp;
    pos(30, 18);
    cout << "退房日期:";
    pos(40, 18);
    cin >> checkoutTemp;
}
