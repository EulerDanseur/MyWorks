#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

// Function Declarations
int Days(int month, int year);
int IWeek(int iYear, int iMonth, int iDay);
void printCalendar(int iYear, int iMonth);

int main()
{
    int iMonth, iYear;
    cout << "Enter year and month (e.g.: 2023 9): ";
    cin >> iYear >> iMonth;
    getchar();

    while (true)
    {
        system("cls"); // Clear the screen
        printCalendar(iYear, iMonth); // Print the calendar

        int c = getch(); // Read user input without echoing
        if (c == -32) // Special key prefix for arrow keys in _getch()
        {
            c = getch(); // Read the arrow key code
            if (c == 80)
            {
                // Up arrow key, increase the month
                if (iMonth == 12)
                {
                    iMonth = 1;
                    iYear++;
                }
                else
                    iMonth++;
            }
            else if (c == 72)
            {
                // Down arrow key, decrease the month
                if (iMonth == 1)
                {
                    iMonth = 12;
                    iYear--;
                }
                else
                    iMonth--;
            }
            else if (c == 75)
                iYear -= 1;
                //Left arrow key, decrease the year
            else if (c == 77)
                iYear += 1;
                //Right arrow key, increase the year
        }   
        else if (c == 'q' || c == 'e')
            break; // If the user enters 'q' or 'Q', exit the program
    }

    return 0;
}

// Function Definitions

// Calculate the number of days in a given month and year
int Days(int month, int year)
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
int IWeek(int iYear, int iMonth, int iDay)
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
void printCalendar(int iYear, int iMonth)
{
    cout << iYear << " Year " << iMonth << " Month" << endl;

    int days = Days(iMonth, iYear);
    int iWeek = IWeek(iYear, iMonth, 1);
    for (int space = 2; space <= iWeek; space++)
        printf("\t");

    for (int date = 1; date <= days; date++)
    {
        iWeek = IWeek(iYear, iMonth, date);
        printf("%d\t", date);
        if (iWeek == 7)
            cout << endl;
    }
    cout << endl;
}
