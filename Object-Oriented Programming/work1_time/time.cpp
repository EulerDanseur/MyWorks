#include "time.h"

Time::Time(int h, int m, int s)
{
    int totalSeconds = h * 3600 + m * 60 + s;
    hour = totalSeconds / 3600;
    minute = (totalSeconds % 3600) / 60;
    sec = totalSeconds % 60;
    while (hour > 24)
    {
        hour %= 24;
    }
}

Time::Time(int s) : hour(s / 3600), minute(s % 3600 / 60), sec(s % 60) {}

Time::Time(Time const &x) : hour(x.hour), minute(x.minute), sec(x.sec) {}

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

bool Time::operator==(Time const &x) const
{
    if (x.hour * 3600 + x.minute * 60 + x.sec == hour * 3600 + minute * 60 + sec)
        return true;
    else
        return false;
}

bool Time::operator<(Time const &x) const
{
    if (x.hour * 3600 + x.minute * 60 + x.sec > hour * 3600 + minute * 60 + sec)
        return true;
    else
        return false;
}

Time Time::operator+(int n) const
{
    int total_seconds = hour * 3600 + minute * 60 + sec + n;
    int hours = total_seconds / 3600;
    while (hours > 24)
        hours %= 24;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    return Time(hours, minutes, seconds);
}

Time Time::operator-(int timeInSeconds) const
{
    int hours, minutes, seconds;
    timeInSeconds = hour * 3600 + minute * 60 + sec - timeInSeconds;
    while(timeInSeconds < 0)
    {
        timeInSeconds += 24 * 3600;
    }
    hours = timeInSeconds / 3600;
    hours %= 24;
    timeInSeconds %= 3600;
    minutes = timeInSeconds / 60;
    timeInSeconds %= 60;
    seconds = timeInSeconds;

    return Time(hours, minutes, seconds);
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
    sec--;

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

int Time::operator-(Time const &x) const
{
    return hour * 3600 + minute * 60 + sec - x.hour * 3600 + x.minute * 60 + x.sec;
}

ExtTime::ExtTime(int h, int m, int s, int eh, int em) : Time(h, m, s)
{
    hour = h;
    minute = m;
    sec = s;
    extHour = eh;
    extminute = em;
}

ExtTime::ExtTime(ExtTime const &x) : Time(x.hour, x.minute, x.sec)
{
    extHour = x.extHour;
    extminute = x.extminute;
}

void ExtTime::display()
{
    cout << hour << ':' << minute << ':' << sec << " GMT " << extHour << ':' << extminute << endl;
}

bool ExtTime::equal(ExtTime const &x)
{
    if ((x.extHour + x.hour) * 3600 + (x.minute + x.extminute) * 60 + x.sec == (extHour + hour) * 3600 + (minute + extminute) * 60 + sec)
        return true;
    else
        return false;
}

bool ExtTime::less_than(ExtTime const &x)
{
    if ((x.extHour + x.hour) * 3600 + (x.minute + x.extminute) * 60 + x.sec > (extHour + hour) * 3600 + (minute + extminute) * 60 + sec)
        return true;
    else
        return false;
}

bool ExtTime::operator==(ExtTime const &x) const
{
    if ((x.extHour + x.hour) * 3600 + (x.minute + x.extminute) * 60 + x.sec == (extHour + hour) * 3600 + (minute + extminute) * 60 + sec)
        return true;
    else
        return false;
}

bool ExtTime::operator<(ExtTime const &x) const
{
    if ((x.extHour + x.hour) * 3600 + (x.minute + x.extminute) * 60 + x.sec > (extHour + hour) * 3600 + (minute + extminute) * 60 + sec)
        return true;
    else
        return false;
}

ExtTime &ExtTime::operator=(ExtTime const &x)
{
    if (this == &x)
        return *this; // handle self assignment
    hour = x.hour;
    minute = x.minute;
    sec = x.sec;
    extHour = x.extHour;
    extminute = x.extminute;
    return *this;
}
ExtTime ExtTime::operator+(int n) const
{
    
    int total_seconds = hour * 3600 + minute * 60 + sec + n;
    int hours = total_seconds / 3600;
    while (hours > 24)
        hours %= 24;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;
    
    return ExtTime(hours, minutes, seconds, extHour, extminute);
}

ExtTime ExtTime::operator-(int timeInSeconds) const
{
    int hours, minutes, seconds;
    timeInSeconds = hour * 3600 + minute * 60 + sec - timeInSeconds;
    while(timeInSeconds < 0)
    {
        timeInSeconds += 24 * 3600;
    }
    hours = timeInSeconds / 3600;
    hours %= 24;
    timeInSeconds %= 3600;
    minutes = timeInSeconds / 60;
    timeInSeconds %= 60;
    seconds = timeInSeconds;
    
    return ExtTime(hours, minutes, seconds, extHour, extminute);
}

ExtTime &ExtTime::operator++()
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

ExtTime &ExtTime::operator--()
{
    sec--;
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

int ExtTime::operator-(ExtTime const &x) const
{
    return (extHour + hour) * 3600 + (minute + extminute) * 60 + sec - (x.extHour + x.hour) * 3600 + (x.minute + x.extminute) * 60 + x.sec;
}
