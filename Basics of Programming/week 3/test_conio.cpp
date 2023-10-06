#include<iostream>
//#include<ncurses.h>
#include<conio.h>


using namespace std;
int main()
{
    //initscr();
    //keypad(stdscr,1);
    int c;
    
    while(1)
    {
         c = getch();
            
            cout << c;

    }
    return 0;
}