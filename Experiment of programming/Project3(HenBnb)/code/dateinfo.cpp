#include "landlord.h"

void Dateinfo::show()
{
    int startx = 76;
    int starty = 10;
    int width = 12;
    int height = 5;

    pos(startx + 8, starty - 4);
    cout << "当前年月为:" << year << " 年 " << month << "月" << endl;

    int daysAmount = DaysAmount(month, year);
    int DayOfWeek = CalcDayOfWeek(year, month, 1) - 1;
    string dateStr, monthStr = toString(month), yearStr = toString(year);
    string dateTempStr = yearStr + '.' + monthStr;

    pos(startx + width * 1, starty - 2);
    printf("%s\t", "Mon.");

    pos(startx + width * 2, starty - 2);
    printf("%s\t", "Tue.");

    pos(startx + width * 3, starty - 2);
    printf("%s\t", "Wed.");

    pos(startx + width * 4, starty - 2);
    printf("%s\t", "Thu.");

    pos(startx + width * 5, starty - 2);
    printf("%s\t", "Fri.");

    pos(startx + width * 6, starty - 2);
    printf("%s\t", "Sat.");

    pos(startx + width * 7, starty - 2);
    printf("%s\t", "Sun.");

    int row = 0;
    for (int date = 1; date <= daysAmount; date++)
    {
        DayOfWeek = CalcDayOfWeek(year, month, date);
        pos(startx + width * DayOfWeek, starty + row * height);
        printf("%d\t", date);

        dateStr = toString(date);
        dateTempStr = yearStr + '.' + monthStr + '.' + dateStr;

        if (map.find(dateTempStr) == map.end())
        {
            pos(startx + width * DayOfWeek, starty + row * height + 1);
            printf("%s\t", basicPrice.c_str());

            pos(startx + width * DayOfWeek, starty + row * height + 2);
            printf("%s\t", "空闲");
        }
        else
        {
            pos(startx + width * DayOfWeek, starty + row * height + 1);
            if (map[dateTempStr].price == "-1")
                printf("%s\t", basicPrice.c_str());
            else
                printf("%s\t", map[dateTempStr].price.c_str());

            pos(startx + width * DayOfWeek, starty + row * height + 2);
            printf("%s\t", map[dateTempStr].status.c_str());
        }
        if (DayOfWeek == 7)
            row++;
    }
    cout << endl;
}

void Dateinfo::showLandlord()
{
    system("cls");
    pos(30, 10);
    cout << "**********房间信息修改*******************" << endl;
    pos(30, 12);
    cout << "* 按r返回上一级                           " << endl;
    pos(30, 14);
    cout << "* 1.修改房价                               " << endl;
    pos(30, 16);
    cout << "* 2.增删空闲时间                           " << endl;
    pos(30, 18);
    cout << "* 3.修改房间状态                           " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;
    pos(30, 22);
    cout << id << "号房";
    pos(30, 24);
    if (accesible == 0)
        cout << "当前房间状态为:不可预约" << endl;
    else
        cout << "当前房间状态为:可预约" << endl;

    show();
}

void Dateinfo::DoDateInfoLandlord()
{
    time_t now = time(0);
    tm t;

    localtime_s(&t, &now);

    year = 1900 + t.tm_year;
    month = t.tm_mon + 1;

    bool flag = 1;
    while (flag)
    {
        showLandlord();
        keyc = _getch();
        if (keyc == -32)
        {
            keyc = _getch();
            switch (keyc)
            {
            case UPKEY:
                month--;
                if (month == 0)
                {
                    month = 12;
                    year--;
                }
                showLandlord();
                break;
            case DOWNKEY:
                month++;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
                showLandlord();
                break;
            case LEFTKEY:
                year--;
                showLandlord();
                break;
            case RIGHTKEY:
                year++;
                showLandlord();
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                ChangeDatePrice();
                room.update();
                break;
            case '2':
                ChangeDateSpare();
                room.update();
                break;
            case '3':
                accesible = !accesible;
                room.update();
                break;
            case 'r':
                flag = 0;
                break;
            case 'e':
                showMainMenu();
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
    }
}

void Dateinfo::DoDateInfoGuest()
{
    time_t now = time(0);
    tm t;

    localtime_s(&t, &now);

    year = 1900 + t.tm_year;
    month = t.tm_mon + 1;

    bool flag = 1;
    while (flag)
    {
        showGuest();
        keyc = _getch();
        if (keyc == -32)
        {
            keyc = _getch();
            switch (keyc)
            {
            case UPKEY:
                month--;
                if (month == 0)
                {
                    month = 12;
                    year--;
                }
                showGuest();
                break;
            case DOWNKEY:
                month++;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
                showGuest();
                break;
            case LEFTKEY:
                year--;
                showGuest();
                break;
            case RIGHTKEY:
                year++;
                showGuest();
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                MakeReserve();
                room.update();
                break;
            case 'r':
                flag = 0;
                break;
            case 'e':
                showMainMenu();
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
    }
}

void Dateinfo::showGuest()
{
    system("cls");
    pos(30, 10);
    cout << "**********房间信息修改*******************" << endl;
    pos(30, 12);
    cout << "* 按q返回菜单界面    按r返回上一级    " << endl;
    pos(30, 14);
    cout << "* 1.预定                     " << endl;
    pos(30, 16);
    cout << "*                         " << endl;
    pos(30, 18);
    cout << "*                         " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    show();
}

void Dateinfo::showChangePrice()
{
    system("cls");
    pos(30, 10);
    cout << "**********修改房价*************************" << endl;
    pos(30, 12);
    cout << "* 按r返回上一级           " << endl;
    pos(30, 14);
    cout << "* 1.基本价格                               " << endl;
    pos(30, 16);
    cout << "* 2.特定日期的价格                         " << endl;
    pos(30, 18);
    cout << "*                                       " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    show();

    keyc = _getch();
}

void Dateinfo::ChangeDatePrice()
{

    int price;
    int date;
    string datestr;
    bool flag = 1;

    while (flag)
    {
        showChangePrice();
        if (keyc == -32)
        {
            keyc = _getch();
            switch (keyc)
            {
            case UPKEY:
                month--;
                if (month == 0)
                {
                    month = 12;
                    year--;
                }
                showChangePrice();
                break;
            case DOWNKEY:
                month++;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
                showChangePrice();
                break;
            case LEFTKEY:
                year--;
                showChangePrice();
                break;
            case RIGHTKEY:
                year++;
                showChangePrice();
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                pos(30, 22);
                cout << "基本价格:" << endl;
                pos(30, 23);
                cin >> price;
                basicPrice = '$' + to_string(price);
                show();
                break;
            case '2':
                pos(30, 22);
                cout << "日期(如:21):" << endl;
                pos(30, 23);
                cin >> date;
                datestr = toString(year) + '.' + toString(month) + '.' + toString(date);
                pos(30, 24);
                cout << "价格:" << endl;
                pos(30, 25);
                cin >> price;
                if (map.find(datestr) == map.end())
                {
                    map[datestr].status = "空闲";
                }
                map[datestr].price = '$' + to_string(price);
                show();
                break;
            case 'r':
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
    }
}

void Dateinfo::showChangeSpare()
{
    system("cls");
    pos(30, 10);
    cout << "**********增删空闲时间*********************" << endl;
    pos(30, 12);
    cout << "*                                       " << endl;
    pos(30, 14);
    cout << "* 1.修改空闲状态                           " << endl;
    pos(30, 16);
    cout << "*                               " << endl;
    pos(30, 18);
    cout << "*                                       " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    show();

    keyc = _getch();
}

void Dateinfo::ChangeDateSpare()
{

    string status;
    int date;
    string datestr;
    bool flag = 1;

    while (flag)
    {
        showChangeSpare();
        if (keyc == -32)
        {
            keyc = _getch();
            switch (keyc)
            {
            case UPKEY:
                month--;
                if (month == 0)
                {
                    month = 12;
                    year--;
                }
                showChangeSpare();
                break;
            case DOWNKEY:
                month++;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
                showChangeSpare();
                break;
            case LEFTKEY:
                year--;
                showChangeSpare();
                break;
            case RIGHTKEY:
                year++;
                showChangeSpare();
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                pos(30, 22);
                cout << "日期(如:21):" << endl;
                pos(30, 23);
                cin >> date;
                datestr = toString(year) + '.' + toString(month) + '.' + toString(date);
                // pos(30, 24);
                // cout << "状态: " << endl;
                // pos(30, 25);
                // cin >> status;
                if (map.find(datestr) == map.end())
                {
                    map[datestr].price = "-1";
                    map[datestr].status = "房主占用";
                }
                else if (map[datestr].status == "空闲")
                {
                    map[datestr].status = "房主占用";
                }
                else if (map[datestr].status == "房主占用")
                {
                    map[datestr].status = "空闲";
                }
                else
                {
                    pos(30, 26);
                    cout << "该日期已被客户预定" << endl;
                    pos(30, 27);
                    system("pause");

                    // 可以增加联系客户的功能
                }
                show();
                break;
            case 'r':
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "输入有误,请重新输入" << endl;
                break;
            }
    }
}

void Dateinfo::MakeReserve()
{
    bool flag = 1;
    while (flag)
    {
        string idTemp, checkinTemp, checkoutTemp;
        system("cls");
        pos(30, 10);
        cout << "**********预定房间*********************" << endl;
        pos(30, 12);
        cout << "* 请输入房间号:                                      " << endl;
        pos(50, 14);
        cin >> idTemp;

        if (map.find(idTemp) == map.end())
        {
            pos(30, 16);
            cout << "该房间不存在" << endl;
            pos(30, 18);
            system("pause");
            continue;
        }
        pos(30, 14);
        cout << "* 请输入入住时间               " << endl;
        pos(50, 14);
        cin >> checkinTemp;
        pos(30, 16);
        cout << "* 请输入离店时间               " << endl;
        pos(50, 16);
        cin >> checkoutTemp;
        pos(30, 28);
        cout << "********************************************" << endl;

    }
}