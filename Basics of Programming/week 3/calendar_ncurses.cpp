#include <iostream>
#include <ncurses.h>

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
    
    initscr(); // Initialize ncurses
    //raw(); // Set character input to raw mode
    keypad(stdscr, 1); // Enable special keys
    //noecho(); // Turn off character echoing
    //curs_set(0); // Hide cursor
    int ch;

   

    while (true)
    {
        //clear(); // Clear the screen
        printCalendar(iYear, iMonth); // Print the calendar
        //refresh(); // Refresh the screen

        ch = getch(); // Read user input

        if (ch == KEY_DOWN)
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
        else if (ch == KEY_UP)
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
        else if (ch == KEY_LEFT)
        {
            // Left arrow key, decrease the year
            iYear--;
        }
        else if (ch == KEY_RIGHT)
        {
            // Right arrow key, increase the year
            iYear++;
        }
        else if (ch == 'q' || ch == 'e')
            break; // If the user enters 'q' or 'e', exit the program
    }

    endwin(); // Clean up ncurses
    return 0;
}

// Function Definitions
// (Same as in your original code)

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
