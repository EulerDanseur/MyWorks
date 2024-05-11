#include <iostream>
#include <fstream>
#include "interface.h"
#include <time.h>
#include <string>
using namespace std;

class Date;

ofstream &operator<<(ofstream &fout, string a);
ofstream &operator<<(ofstream &fout, char a);
ofstream &operator<<(ofstream &fout, int a);
ofstream &operator<<(ofstream &fout, bool d);
ofstream &operator<<(ofstream &fout, double a);
string to_string(const Date& d);

inline void showNow()
{
    time_t today = time(0);
    tm t;
    localtime_s(&t, &today);
    pos(2, 2);
    cout << t.tm_year + 1900 << "��" << t.tm_mon + 1 << "��" << t.tm_mday << "��" << endl;
    pos(2, 3);
    char dt[66];//�ȶ�����ʹ��,dt��ctime_s������ȥ��
    ctime_s(dt, sizeof dt, &today);//duty time
    cout << dt;
}

class Date
{
public:
    Date();
    Date(int year, int month, int day);
    ~Date() {}
    bool IsValid();
    int GetMonthDay(int year, int month);
    bool IsLeapYear(int year);
    void Show();


    Date &operator=(const Date &d);
    bool operator==(const Date &d) const;
    bool operator>(const Date &d) const;
    bool operator<(const Date &d) const;
    bool operator>=(const Date &d) const;
    bool operator<=(const Date &d) const;
    bool operator!=(const Date &d);
    Date operator+(int day);
    Date &operator+=(int day);
    Date operator-(int day);
    Date &operator-=(int day);
    int operator-(const Date &d); // ����-���� ��������
    Date &operator++();           // Ĭ��ǰ��
    Date operator++(int);         // �ò�����־����++
    Date &operator--();
    Date operator--(int);
    friend istream &operator>>(istream &in, Date &d);
    friend ostream &operator<<(ostream &out, const Date &d);
    friend ofstream &operator<<(ofstream &out, const Date &d);
    friend ifstream &operator>>(ifstream &in, Date &d);

    // private:
    int year;
    int month;
    int day;
};