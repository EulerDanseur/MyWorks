#include <iostream>
using namespace std;

class Time
{
public:
    // 时间的小时、分钟和秒
    int hour, minute, sec;

    // 构造函数用于设置小时、分钟和秒
    Time(int h, int m, int s);

    // 构造函数用于设置总秒数
    Time(int s);

    // 复制构造函数
    Time(Time const &x);

    // 设置小时、分钟和秒
    void set(int h, int m, int s);

    // 将时间增加一秒
    Time &increment();

    // 以 HH:MM:SS 格式打印时间
    virtual void display();

    // 检查时间是否等于给定时间
    bool equal(Time const &x);

    // 检查时间是否小于给定时间
    bool less_than(Time const &x);

    // 赋值运算符
    Time &operator=(Time const &x);

    // 转换为int类型
    operator int();

    // 等于运算符
    bool operator==(Time const &x) const;

    // 小于运算符
    bool operator<(Time const &x) const;

    // 加上n秒
    Time operator+(int n) const;

    // 减去n秒
    Time operator-(int n) const;

    // 自增运算符
    Time &operator++();

    // 自减运算符
    Time &operator--();

    // 减去另一个时间对象，返回秒数差
    int operator-(Time const &x) const;
};

class ExtTime : public Time
{
    int extHour, extminute;

public:
    // 构造函数用于设置小时、分钟、秒和时区偏移
    ExtTime(int h, int m, int s, int eh, int em);

    // 复制构造函数
    ExtTime(ExtTime const &x);

    // 以 HH:MM:SSGMTxxx 格式打印时间
    virtual void display() override;

    // 检查时间是否等于给定时间
    bool equal(ExtTime const &x);

    // 检查时间是否小于给定时间
    bool less_than(ExtTime const &x);

    // 等于运算符
    bool operator==(ExtTime const &x) const;

    // 赋值运算符
    ExtTime &operator=(ExtTime const &x);

    // 小于运算符
    bool operator<(ExtTime const &x) const;

    // 加上n秒
    ExtTime operator+(int n) const;

    // 减去n秒
    ExtTime operator-(int n) const;

    // 自增运算符
    ExtTime &operator++();

    // 自减运算符
    ExtTime &operator--();

    // 减去另一个时间对象，返回秒数差
    int operator-(ExtTime const &x) const;
};

