#include <iostream>
using namespace std;

class Time
{

public:
    int hour, minute, sec;

    Time(int h, int m, int s);

    Time(int s);

    Time(Time const &x);

    void set(int h, int m, int s);

    Time &increment();

    virtual void display();

    bool equal(Time const &x);

    bool less_than(Time const &x); // 比较两个时间大小

    Time &operator=(Time const &x);

    operator int();

    bool operator==(Time const &x);

    bool operator<(Time const &x);

    Time operator+(int n);

    Time operator-(int n);

    Time &operator++();

    Time &operator--();

    int operator-(Time const &x);
};

class ExtTime : public Time
{
    int ext;

public:
    ExtTime(int h, int m, int s, int e);

    ExtTime(ExtTime & x);

    void display() override
    {
        cout << hour << ':' << minute << ':' << sec << ' +' << ext << endl;
    }

    bool equal(ExtTime const &x);

    bool less_than(ExtTime const &x);

    bool operator==(ExtTime const &x);

    bool operator<(ExtTime const &x);
    
    int operator-(Time const &x);
};