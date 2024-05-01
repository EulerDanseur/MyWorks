#include "calendar.h"


// Calculate the number of days in a given month and year
int DaysAmount(int month, int year)
{
    int day;
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        day = 31;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            day = 29;
        else
            day = 28;
        break;
    case 4: case 6: case 9: case 11:
        day = 30;
        break;
    default:
        day = 0; // This default case won't occur as the month range is 1-12
    }
    return day;
}

// Calculate the day of the week for a given date
int CalcDayOfWeek(int iYear, int iMonth, int iDay)
{
    int iWeek, c, y;

    if (iMonth == 1 || iMonth == 2)
    {
        iMonth += 12;
        iYear -= 1;
    }

    c = iYear / 100;
    y = iYear % 100;

    iWeek = ((c / 4) - 2 * c + y + (y / 4) + (26 * (iMonth + 1) / 10) + iDay - 1) % 7;
    while (iWeek <= 0)
        iWeek += 7;

    
    return iWeek;
}

// Print the calendar for a given month and year

