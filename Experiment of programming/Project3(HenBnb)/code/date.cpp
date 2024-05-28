// date.cpp
#include "date.h"

Date::Date()
{
    time_t today = time(0);
    tm t;
    localtime_s(&t, &today);
    year = t.tm_year + 1900;
    month = t.tm_mon + 1;
    day = t.tm_mday;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day)
{
    if (!IsValid()) 
    {
        cout << "valid Date";
    }
}

bool Date::IsValid()
{
    return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= GetMonthDay(year, month));
}

int Date::GetMonthDay(int year, int month)
{
    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
    {
        ++arr[2];
    }
    return arr[month];
}

bool Date::IsLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void Date::Show()
{
    cout << year << "." << month << "." << day << endl;
}

string to_string(const Date& d)
{
    return std::to_string(d.year) + "." + std::to_string(d.month) + "." + std::to_string(d.day);
}

//  运算符重载经历以下几个步骤
//  (d1==d2)
//  d1.operator==(d2)
//  d1.operator==(&d1,d2)
//  bool Date::operator==(Date* this,const Date& d)
bool Date::operator==(const Date &d) const
{
    if (year == d.year && month == d.month && day == d.day)
        return true;
    return false;
}

// 传值返回：会多调用一次拷贝构造函数
// 传引用返回：直接返回，不需要调用拷贝构造
//             出了作用于变量还在，尽量使用传引用返回
Date &Date::operator=(const Date &d)
{
    if (this != &d)
    {
        year = d.year;
        month = d.month;
        day = d.day;
    }
    return *this;
}

bool Date::operator>=(const Date &d) const
{
    return !(*this < d);
}

bool Date::operator<=(const Date &d) const
{
    return ((*this < d) || (*this == d));
}
bool Date::operator!=(const Date &d)
{
    return !(*this == d);
}

bool Date::operator>(const Date &d) const
{
    return !(*this <= d);
}

bool Date::operator<(const Date &d) const
{
    if ((year < d.year) ||
        (year == d.year && month < d.month) ||
        (year == d.year && month == d.month && day < d.day))
        return true;
    return false;
}

Date Date::operator+(int day)
{
    if (day < 0)
    {
        return (*this) - (-day);
    }
    Date d(*this);
    d.day += day;
    while (d.IsValid() == false)
    {
        int month_day = GetMonthDay(d.year, d.month);
        d.day -= month_day;
        ++d.month;
        if (d.month > 12)
        {
            d.month = 1;
            ++d.year;
        }
    }
    return d;
}

Date &Date::operator+=(int day)
{
    *this = (*this + day);
    return *this;
}

Date Date::operator-(int day)
{
    if (day < 0)
    {
        return (*this) + (-day);
    }
    Date d(*this);
    d.day -= day;
    while (d.IsValid() == false)
    {
        --d.month;
        if (d.month == 0)
        {
            --d.year;
            d.month = 12;
        }
        int pre_month_day = GetMonthDay(d.year, d.month);
        d.day += pre_month_day;
    }
    return d;
}

Date &Date::operator-=(int day)
{
    *this = (*this - day);
    return *this;
}

int Date::operator-(const Date &d) // 日期-日期 返回天数
{
    int flag = 1;
    Date max = (*this);
    Date min = d;
    if ((*this) < d)
    {
        max = d;
        min = (*this);
        flag = -1;
    }
    int count = 0;
    while (max != min)
    {
        ++min;
        ++count;
    }
    return flag * count;
}

//  ++d1 ->  d1.operator++(&d1);
Date &Date::operator++() // 默认前置
{
    *this += 1; // 只调用一个函数
    //*this = *this + 1; //调用两个函数，还要调用拷贝构造函数
    return *this;
}

//  d1++ ->  d1.operator++(&d1,0);
Date Date::operator++(int) // 用参数标志后置++
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}

Date &Date::operator--()
{
    *this -= 1;
    return *this;
}

Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

istream &operator>>(istream &in, Date &d)
{
    in >> d.year >> d.month >> d.day;
    return in;
}

ostream &operator<<(ostream &out, const Date &d)
{
    out << d.year << "." << d.month << "." << d.day;
    return out;
}

ifstream &operator>>(ifstream &in, Date &d)
{
    in >> d.year >> d.month >> d.day;
    return in;
}

ofstream &operator<<(ofstream &fout, const Date &d)
{
    return fout << d.year << ' ' << d.month << ' ' << d.day;
}

ofstream &operator<<(ofstream &fout, string a)
{
    ostream* ofs = &fout;
    *ofs << a;
    return fout;
}

ofstream &operator<<(ofstream &fout, char a)
{
    ostream* ofs = &fout;
    *ofs << a;
    return fout;
}

ofstream &operator<<(ofstream &fout, int a)
{
    ostream* ofs = &fout;
    *ofs << a;
    return fout;
}

ofstream &operator<<(ofstream &fout, bool a)
{
    ostream* ofs = &fout;
    *ofs << a;
    return fout;
}

ofstream &operator<<(ofstream &fout, double a)
{
    ostream* ofs = &fout;
    *ofs << a;
    return fout;
}