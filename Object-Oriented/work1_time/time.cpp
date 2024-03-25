#include "time.h"

Time::Time(int h, int m, int s)
    : hour(h), minute(m), sec(s){};

Time::Time(int s)
{
    hour = s / 3600;
    s %= 3600;
    minute = s / 60;
    s %= 60;
    sec = s;
}

Time::Time(Time const &x)
{
    hour = x.hour;
    minute = x.minute;
    sec = x.sec;
}

void Time::set(int h, int m, int s)
{
    hour = h;
    minute = m;
    sec = s;
}

Time &Time::increment()
{
    sec++;

    if (sec >= 60)
    {
        sec = 0;
        minute++;
        if (minute >= 60)
        {
            minute = 0;
            hour = (hour + 1) % 24;
        }
    }
    return *this;
}

void Time::display()
{
    cout << hour << ':' << minute << ':' << sec << endl;
}

bool Time::equal(Time const &x)
{
    if (x.hour == hour && x.minute == minute && x.sec == sec)
        return 1;
    else
        return 0;
}

bool Time::less_than(Time const &x)
{
    if (x.hour * 3600 + x.minute * 60 + x.sec > sec + minute * 60 + hour * 3600)
        return 1;
    else
        return 0;
}

Time &Time::operator=(Time const &x)
{
    hour = x.hour;
    minute = x.minute;
    sec = x.sec;
    return *this;
}

Time::operator int()
{
    return sec + hour * 3600 + minute * 60;
}

bool Time::operator==(Time const &x)
{
    if (x.hour * 3600 + x.minute * 60 + x.sec == hour * 3600 + minute * 60 + sec)
        return true;
    else
        return false;
}

bool Time::operator<(Time const &x)
{
    if (x.hour * 3600 + x.minute * 60 + x.sec > hour * 3600 + minute * 60 + sec)
        return true;
    else
        return false;
}

Time Time::operator+(int n)
{
    n += hour * 3600 + minute * 60 + sec;
    hour = n / 3600;
    hour %= 24;
    n %= 3600;
    minute = n / 60;
    n %= 60;
    sec = n;

    return *this;
}

Time Time::operator-(int n)
{
    n = hour * 3600 + minute * 60 + sec - n;
    hour = n / 3600;
    hour %= 24;
    n %= 3600;
    minute = n / 60;
    n %= 60;
    sec = n;

    return *this;
}

Time &Time::operator++()
{
    sec++;

    if (sec >= 60)
    {
        sec = 0;
        minute++;
        if (minute >= 60)
        {
            minute = 0;
            hour = (hour + 1) % 24;
        }
    }
    return *this;
}

Time &Time::operator--()
{
    sec++;

    if (sec < 0)
    {
        sec += 60;
        minute--;
        if (minute < 0)
        {
            minute += 60;
            hour = (hour - 1) % 24;
        }
    }
    return *this;
}

int Time::operator-(Time const &x)
{
    return hour * 3600 + minute * 60 + sec - x.hour * 3600 + x.minute * 60 + x.sec;
}

ExtTime::ExtTime(int h, int m, int s, int e) : Time(h, m, s)
{
    ext = e;
}

ExtTime::ExtTime(ExtTime &x) : Time(x.hour, x.minute, x.sec)
{
    ext = x.ext;
}

bool ExtTime::equal(ExtTime const &x)
{
    if ((ext + x.hour) * 3600 + x.minute * 60 + x.sec ==(ext + hour) * 3600 + minute * 60 + sec)
        return true;
    else
        return false;
}

// bool ExtTime::less_than(ExtTime const &x)

