#include <iostream>
using namespace std;

class Time
{
public:
    // ʱ���Сʱ�����Ӻ���
    int hour, minute, sec;

    // ���캯����������Сʱ�����Ӻ���
    Time(int h, int m, int s);

    // ���캯����������������
    Time(int s);

    // ���ƹ��캯��
    Time(Time const &x);

    // ����Сʱ�����Ӻ���
    void set(int h, int m, int s);

    // ��ʱ������һ��
    Time &increment();

    // �� HH:MM:SS ��ʽ��ӡʱ��
    virtual void display();

    // ���ʱ���Ƿ���ڸ���ʱ��
    bool equal(Time const &x);

    // ���ʱ���Ƿ�С�ڸ���ʱ��
    bool less_than(Time const &x);

    // ��ֵ�����
    Time &operator=(Time const &x);

    // ת��Ϊint����
    operator int();

    // ���������
    bool operator==(Time const &x) const;

    // С�������
    bool operator<(Time const &x) const;

    // ����n��
    Time operator+(int n) const;

    // ��ȥn��
    Time operator-(int n) const;

    // ���������
    Time &operator++();

    // �Լ������
    Time &operator--();

    // ��ȥ��һ��ʱ����󣬷���������
    int operator-(Time const &x) const;
};

class ExtTime : public Time
{
    int extHour, extminute;

public:
    // ���캯����������Сʱ�����ӡ����ʱ��ƫ��
    ExtTime(int h, int m, int s, int eh, int em);

    // ���ƹ��캯��
    ExtTime(ExtTime const &x);

    // �� HH:MM:SSGMTxxx ��ʽ��ӡʱ��
    virtual void display() override;

    // ���ʱ���Ƿ���ڸ���ʱ��
    bool equal(ExtTime const &x);

    // ���ʱ���Ƿ�С�ڸ���ʱ��
    bool less_than(ExtTime const &x);

    // ���������
    bool operator==(ExtTime const &x) const;

    // ��ֵ�����
    ExtTime &operator=(ExtTime const &x);

    // С�������
    bool operator<(ExtTime const &x) const;

    // ����n��
    ExtTime operator+(int n) const;

    // ��ȥn��
    ExtTime operator-(int n) const;

    // ���������
    ExtTime &operator++();

    // �Լ������
    ExtTime &operator--();

    // ��ȥ��һ��ʱ����󣬷���������
    int operator-(ExtTime const &x) const;
};

