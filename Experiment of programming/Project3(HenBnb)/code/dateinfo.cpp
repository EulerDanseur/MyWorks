#include "housing.h"

Dateinfo dateInfo;

Dateinfo::Dateinfo()
{
    month = 0, year = 0;
    fstream file;
    file.open("dateinfo.txt", ios::in);
    file >> basicPrice;
    string date, price;
    while (!file.eof())
    {
        file >> date;
        file >> map[date].status;
        file >> map[date].price;
    }
    file.close();

    update();
}

Dateinfo::~Dateinfo()
{
    update();
}

void Dateinfo::show()
{
    update();

    int startx = 76;
    int starty = 10;
    int width = 12;
    int height = 5;

    pos(startx + 8, starty - 4);
    cout << "��ǰ����Ϊ:" << year << " �� " << month << "��" << endl;

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
            printf("%s\t", "����");
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

void Dateinfo::update()
{
    ReserveinfoToDateinfo();
    fstream file;
    file.open("dateinfo.txt", ios::out);
    file << basicPrice << endl;
    for (auto i : map)
    {
        file << i.first << ' ' << i.second.status << ' ' << i.second.price << endl;
    }
    file.close();
}
void Housing::DoDateInfo()
{
    system("cls");
    pos(30, 2);
    cout << "��������鿴�����·�:" << endl;
    pos(30, 10);
    cout << "**********������Ϣ�޸�*******************" << endl;
    pos(30, 12);
    cout << "* ��q���ط�������                            " << endl;
    pos(30, 14);
    cout << "* 1.�޸ķ���                               " << endl;
    pos(30, 16);
    cout << "* 2.��ɾ����ʱ��                           " << endl;
    pos(30, 18);
    cout << "*                         " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    pos(30, 3);
    cin >> dateInfo.year >> dateInfo.month;
    while (dateInfo.year < 1000 || dateInfo.month > 12 || dateInfo.year > 2050 || dateInfo.month < 1)
    {
        pos(30, 3);
        cout << "��������,����������" << endl;
        pos(30, 4);
        system("pause");
        pos(30, 3);
        cout << "                           " << endl;
        pos(30, 4);
        cout << "                           " << endl;
        pos(30, 3);
        cin >> dateInfo.year >> dateInfo.month;
    }

    ShowDateInfo();

    key = _getch();
    bool flag = 1;
    while (flag)
    {
        if (key == -32)
        {
            key = _getch();
            switch (key)
            {
            case UPKEY:
                dateInfo.month--;
                if (dateInfo.month == 0)
                {
                    dateInfo.month = 12;
                    dateInfo.year--;
                }
                ShowDateInfo();
                break;
            case DOWNKEY:
                dateInfo.month++;
                if (dateInfo.month == 13)
                {
                    dateInfo.month = 1;
                    dateInfo.year++;
                }
                ShowDateInfo();
                break;
            case LEFTKEY:
                dateInfo.year--;
                ShowDateInfo();
                break;
            case RIGHTKEY:
                dateInfo.year++;
                ShowDateInfo();
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (key)
            {
            case '1':
                DatePrice();
                break;
            case '2':
                DateSpare();
                break;
            case 'q':
                Menu();
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
        key = _getch();
    }
}

void Housing::ShowDateInfo()
{
    system("cls");
    pos(30, 10);
    cout << "**********������Ϣ�޸�*******************" << endl;
    pos(30, 12);
    cout << "* ��q���ط�������                            " << endl;
    pos(30, 14);
    cout << "* 1.�޸ķ���                               " << endl;
    pos(30, 16);
    cout << "* 2.��ɾ����ʱ��                           " << endl;
    pos(30, 18);
    cout << "*                         " << endl;
    pos(30, 20);
    cout << "********************************************" << endl;

    dateInfo.show();
}

void Housing::DatePrice()
{

    int price;
    int date;
    string datestr;
    bool flag = 1;

    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********�޸ķ���*************************" << endl;
        pos(30, 12);
        cout << "* ��q���ط������� ��r������һ��           " << endl;
        pos(30, 14);
        cout << "* 1.�����۸�                               " << endl;
        pos(30, 16);
        cout << "* 2.�ض����ڵļ۸�                         " << endl;
        pos(30, 18);
        cout << "*                                       " << endl;
        pos(30, 20);
        cout << "********************************************" << endl;

        dateInfo.show();

        key = _getch();

        if (key == -32)
        {
            key = _getch();
            switch (key)
            {
            case UPKEY:
                dateInfo.month--;
                if (dateInfo.month == 0)
                {
                    dateInfo.month = 12;
                    dateInfo.year--;
                }
                ShowDateInfo();
                break;
            case DOWNKEY:
                dateInfo.month++;
                if (dateInfo.month == 13)
                {
                    dateInfo.month = 1;
                    dateInfo.year++;
                }
                ShowDateInfo();
                break;
            case LEFTKEY:
                dateInfo.year--;
                ShowDateInfo();
                break;
            case RIGHTKEY:
                dateInfo.year++;
                ShowDateInfo();
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (key)
            {
            case '1':
                pos(30, 22);
                cout << "�����۸�:" << endl;
                pos(30, 23);
                cin >> price;
                dateInfo.basicPrice = '$' + to_string(price);
                dateInfo.update();
                dateInfo.show();
                break;
            case '2':
                pos(30, 22);
                cout << "����(�磺21):" << endl;
                pos(30, 23);
                cin >> date;
                datestr = toString(dateInfo.year) + '.' + toString(dateInfo.month) + '.' + toString(date);
                pos(30, 24);
                cout << "�۸�:" << endl;
                pos(30, 25);
                cin >> price;
                if (dateInfo.map.find(datestr) == dateInfo.map.end())
                {
                    dateInfo.map[datestr].status = "����";
                }
                dateInfo.map[datestr].price = '$' + to_string(price);
                dateInfo.update();
                dateInfo.show();
                break;
            case 'r':
                ShowDateInfo();
                flag = 0;
                break;
            case 'q':
                Menu();
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

void Housing::DateSpare()
{

    string status;
    int date;
    string datestr;
    bool flag = 1;

    while (flag)
    {
        system("cls");
        pos(30, 10);
        cout << "**********��ɾ����ʱ��*********************" << endl;
        pos(30, 12);
        cout << "*                                       " << endl;
        pos(30, 14);
        cout << "* 1.�޸Ŀ���״̬                           " << endl;
        pos(30, 16);
        cout << "*                               " << endl;
        pos(30, 18);
        cout << "*                                       " << endl;
        pos(30, 20);
        cout << "********************************************" << endl;

        dateInfo.show();

        key = _getch();

        if (key == -32)
        {
            key = _getch();
            switch (key)
            {
            case UPKEY:
                dateInfo.month--;
                if (dateInfo.month == 0)
                {
                    dateInfo.month = 12;
                    dateInfo.year--;
                }
                ShowDateInfo();
                break;
            case DOWNKEY:
                dateInfo.month++;
                if (dateInfo.month == 13)
                {
                    dateInfo.month = 1;
                    dateInfo.year++;
                }
                ShowDateInfo();
                break;
            case LEFTKEY:
                dateInfo.year--;
                ShowDateInfo();
                break;
            case RIGHTKEY:
                dateInfo.year++;
                ShowDateInfo();
                break;
            default:
                pos(30, 22);
                cout << "��������,����������" << endl;
                break;
            }
        }
        else
            switch (key)
            {
            case '1':
                pos(30, 22);
                cout << "����(�磺21):" << endl;
                pos(30, 23);
                cin >> date;
                datestr = toString(dateInfo.year) + '.' + toString(dateInfo.month) + '.' + toString(date);
                //pos(30, 24);
                //cout << "״̬: " << endl;
                //pos(30, 25);
                //cin >> status;
                if (dateInfo.map.find(datestr) == dateInfo.map.end() )
                {
                    dateInfo.map[datestr].price = "-1";
                    dateInfo.map[datestr].status = "����ռ��";
                }
                else if(dateInfo.map[datestr].status == "����")
                {
                    dateInfo.map[datestr].status = "����ռ��";
                }
                else if(dateInfo.map[datestr].status == "����ռ��")
                {
                    dateInfo.map[datestr].status = "����";
                }
                else
                {
                    pos(30, 26);
                    cout << "�������ѱ��ͻ�Ԥ��" << endl;
                    pos(30, 27);
                    system("pause");

                    //����������ϵ�ͻ��Ĺ���
                }
                dateInfo.update();
                dateInfo.show();
                break;
            case 'r':
                ShowDateInfo();
                flag = 0;
                break;
            case 'q':
                Menu();
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
