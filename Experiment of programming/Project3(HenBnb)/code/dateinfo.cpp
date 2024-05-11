#include "landlord.h"
#include "guest.h"

void Room::showCalendar()
{
    showNow();

    int startx = 76;
    int starty = 10;
    int width = 12;
    int height = 5;

    pos(startx + 8, starty - 4);
    cout << "��ǰ����Ϊ:" << year << " �� " << month << "��" << endl;

    int daysAmount = DaysAmount(month, year);
    int DayOfWeek = CalcDayOfWeek(year, month, 1) - 1;
    Date dateTemp = Date(year, month, 1);

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
        dateTemp = Date(year, month, date);

        if (map.find(dateTemp) == map.end())
        {
            pos(startx + width * DayOfWeek, starty + row * height + 1);
            printf("%s\t", basicPrice.c_str());

            pos(startx + width * DayOfWeek, starty + row * height + 2);
            printf("%s\t", "����");
        }
        else
        {
            pos(startx + width * DayOfWeek, starty + row * height + 1);
            if (map[dateTemp].price == "-1")
                printf("%s\t", basicPrice.c_str());
            else
                printf("%s\t", map[dateTemp].price.c_str());

            pos(startx + width * DayOfWeek, starty + row * height + 2);
            printf("%s\t", map[dateTemp].status.c_str());
        }
        if (DayOfWeek == 7)
            row++;
    }
    cout << endl;
}

void Room::showLandlord()
{
    system("cls");
    showNow();
    pos(30, 10);
    cout << "**********������Ϣ�޸�*******************" << endl;
    pos(30, 12);
    cout << "* ��r������һ��                           " << endl;
    pos(30, 14);
    cout << "* 1.�޸ķ���                               " << endl;
    pos(30, 16);
    cout << "* 2.��ɾ����ʱ��                           " << endl;
    pos(30, 18);
    cout << "* 3.�޸ķ���״̬                           " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;
    pos(30, 22);
    cout << id << "�ŷ�";
    pos(30, 24);
    if (accesible == 0)
        cout << "��ǰ����״̬Ϊ:����ԤԼ" << endl;
    else
        cout << "��ǰ����״̬Ϊ:��ԤԼ" << endl;

    showNow();
    showCalendar();
}

void Room::DoRoomInfoLandlord()
{
    time_t today = time(0);
    tm t;

    localtime_s(&t, &today);

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
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                ChangeDatePrice();
                roomclass.update();
                break;
            case '2':
                ChangeDateSpare();
                roomclass.update();
                break;
            case '3':
                accesible = !accesible;
                roomclass.update();
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
                cout << "��������,����������" << endl;
                break;
            }
    }
}

void Room::DoRoomInfoGuest(string id)
{
    time_t today = time(0);
    tm t;

    localtime_s(&t, &today);

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
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                if (accesible == 1)
                    MakeReserve(id);
                else
                {
                    pos(30, 22);
                    cout << "��ǰ���䲻��ԤԼ" << endl;
                    pos(30, 24);
                    system("pause");
                }
                roomclass.update();
                break;
            case 'r':
                flag = 0;
                break;
            case 'q':
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
    }
}

void Room::showGuest()
{
    system("cls");
    showNow();
    pos(30, 10);
    printf("**********%s������Ϣ*******************", id.c_str());
    pos(30, 12);
    cout << "* ��q���ز˵�����    ��r������һ��    " << endl;
    pos(30, 14);
    cout << "* 1.Ԥ��                     " << endl;
    pos(30, 16);
    cout << "*                         " << endl;
    pos(30, 18);
    cout << "*                         " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    showCalendar();
}

void Room::showChangePrice()
{
    system("cls");
    showNow();
    pos(30, 10);
    cout << "**********�޸ķ���*************************" << endl;
    pos(30, 12);
    cout << "* ��r������һ��           " << endl;
    pos(30, 14);
    cout << "* 1.�����۸�                               " << endl;
    pos(30, 16);
    cout << "* 2.�ض����ڵļ۸�                         " << endl;
    pos(30, 18);
    cout << "*                                       " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    showCalendar();

    keyc = _getch();
}

void Room::ChangeDatePrice()
{

    int price;
    int date;
    Date dateD;
    bool flag = 1;

    while (flag)
    {
        showChangePrice();
        showNow();
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
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                pos(30, 22);
                cout << "�����۸�:" << endl;
                pos(30, 23);
                cin >> price;
                basicPrice = '$' + to_string(price);
                roomclass.update();

                showCalendar();
                break;
            case '2':
                pos(30, 22);
                cout << "����(��:21):" << endl;
                pos(30, 23);
                cin >> date;
                dateD = Date(year, month, date);
                if (map.find(dateD) == map.end())
                {
                    map[dateD].status = "����";
                }
                else if (map[dateD].status != "����")
                {
                    pos(30, 26);
                    cout << "�������ѱ��ͻ�Ԥ��" << endl;
                    pos(30, 27);
                    system("pause");
                    showCalendar();
                    break;
                }
                pos(30, 24);
                cout << "�۸�:" << endl;
                pos(30, 25);
                cin >> price;

                map[dateD].price = '$' + to_string(price);
                roomclass.update();
                showCalendar();
                break;
            case 'r':
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
    }
}

void Room::showChangeSpare()
{
    system("cls");
    showNow();
    pos(30, 10);
    cout << "**********��ɾ����ʱ��*********************" << endl;
    pos(30, 12);
    cout << "*                                       " << endl;
    pos(30, 14);
    cout << "* �޸Ŀ���״̬                           " << endl;
    pos(30, 16);
    cout << "*                               " << endl;
    pos(30, 18);
    cout << "* ��r������һ��                                      " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    showCalendar();

    keyc = _getch();
}

void Room::ChangeDateSpare()
{

    string status;
    int date;
    Date dateD;
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
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (keyc)
            {
            case '1':
                pos(30, 22);
                cout << "����(��:21):" << endl;
                pos(30, 23);
                cin >> date;
                dateD = Date(year, month, date);
                if (map.find(dateD) == map.end())
                {
                    map[dateD].price = "-";
                    map[dateD].status = "����ռ��";
                }
                else if (map[dateD].status == "����")
                {
                    map[dateD].price = "-";
                    map[dateD].status = "����ռ��";
                }
                else if (map[dateD].status == "����ռ��")
                {
                    map.erase(dateD);
                }
                else
                {
                    pos(30, 26);
                    cout << "�������ѱ��ͻ�Ԥ��" << endl;
                    pos(30, 27);
                    system("pause");

                    // ����������ϵ�ͻ��Ĺ���
                }
                showCalendar();
                break;
            case 'r':
                flag = 0;
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
    }
}

void Room::MakeReserve(string guestid)
{
    bool flag = 1;
    while (flag)
    {
        Date checkinTemp, checkoutTemp;
        system("cls");
        showNow();
        showCalendar();
        pos(30, 9);
        cout << "**********Ԥ������*********************" << endl;
        pos(30, 11);
        printf("* ȷ��ԤԼ��ǰ%s����?(��yȷ��, �����������)           ", id.c_str());
        pos(30, 12);
        char choice;
        choice = _getch();
        if (choice != 'y')
        {
            break;
        }

        pos(30, 14);
        cout << "* ��������סʱ��(��ʽ:yyyy mm dd)               " << endl;
        pos(64, 14);
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
        cin >> checkinTemp;
        if (checkinTemp < checkoutTemp)
        {
            pos(30, 16);
            cout << "��סʱ�䲻�����ڽ���" << endl;
            pos(30, 18);
            system("pause");
            continue;
        }
        pos(30, 16);
        cout << "* ���������ʱ��(��ʽ:yyyy mm dd)               " << endl;
        pos(64, 16);
        cin >> checkoutTemp;
        pos(30, 28);
        cout << "********************************************" << endl;
        int price = 0;
        if (checkinTemp.IsValid() == false || checkoutTemp.IsValid() == false)
        {
            pos(30, 20);
            cout << "ʱ���ʽ����" << endl;
            pos(30, 22);
            system("pause");
            continue;
        }
        else if (checkinTemp > checkoutTemp)
        {
            pos(30, 20);
            cout << "���ʱ�䲻��������סʱ��" << endl;
            pos(30, 22);
            system("pause");
            continue;
        }
        for (Date d = checkinTemp; d <= checkoutTemp; d++)
        {
            if (map.find(d) != map.end())
            {
                if (map[d].status == "����")
                {
                    pos(30, 20);
                    price += stoi(map[d].price.substr(1, map[d].price.length() - 1));
                }
                else
                {
                    pos(30, 20);
                    cout << "��ʱ���ѱ�ռ��" << endl;
                    pos(30, 22);
                    flag = 0;
                    system("pause");
                    break;
                }
            }
            else
            {
                price += stoi(basicPrice.substr(1, basicPrice.length() - 1));
            }
        }

        if (flag)
        {
            while (true)
            {
                pos(30, 20);
                cout << "Ԥ���ɹ�" << endl;
                pos(30, 22);
                cout << "��֧������:" << price << endl;
                pos(30, 24);
                cout << "�Ƿ�֧��?(y/n)" << endl;
                char pay;
                pay = _getch();
                if (pay == 'y')
                {
                    pos(30, 26);
                    cout << "����������" << endl;
                    string password;
                    pos(30, 27);
                    cin >> password;
                    if (password != guestclass.guestMap[guestid].password)
                    {
                        pos(30, 28);
                        cout << "�������" << endl;
                        pos(30, 30);
                        system("pause");

                        pos(30, 26);
                        cout << "                                            " << endl;
                        pos(30, 27);
                        cout << "                                            " << endl;
                        pos(30, 28);
                        cout << "********************************************" << endl;
                        pos(30, 30);
                        cout << "                                            " << endl;
                    }
                    else
                    {
                        pos(30, 28);
                        cout << "֧���ɹ�" << endl;
                        pos(30, 30);
                        system("pause");

                        reserveInfo.vec.push_back({id, checkinTemp, checkoutTemp, guestid, to_string(price), "δ���", -1});
                        guestclass.guestMap[guestid].myReserve.push_back(&reserveInfo.vec[reserveInfo.vec.size() - 1]);
                        reserveInfo.update();

                        moneyInfo.vec.push_back({checkinTemp, to_string(price), id + "Ԥ��" + id});

                        Reserveinfo_to_RoomDateinfo();
                        roomclass.update();
                        return;
                    }
                }
                else if (pay == 'n')
                {
                    break;
                }
            }
        }
    }
}

ostream &operator<<(ostream &out, const Room &roominfo)
{
    out.setf(ios::left);
    string score = "";
    if (roominfo.scoreTimes != 0)
        score = to_string(roominfo.score / roominfo.scoreTimes).substr(0, 4);
    else
        score = "-";

    if (roominfo.accesible == 0)
        out << setw(5) << roominfo.id
            << setw(10) << "����ԤԼ"
            << setw(10) << roominfo.basicPrice
            << setw(10) << roominfo.usedTimes
            << setw(6) << score
            << setw(10) << roominfo.scoreTimes;
    else
        out << setw(5) << roominfo.id
            << setw(10) << "��ԤԼ"
            << setw(10) << roominfo.basicPrice
            << setw(10) << roominfo.usedTimes
            << setw(6) << score
            << setw(10) << roominfo.scoreTimes;
    return out;
}