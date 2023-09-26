#include<iostream>
using namespace std;

int Days(int month, int year)
{
    int day;
        switch(month)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            day = 31;
            break;
        case 2:
        {   
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                day = 29;
            else
                day = 28;
            break;
        }
        case 4: case 6: case 9: case 11: 
            day = 30;
            break;
        default: 
            day = 0;
    }
    return day;    
}

int IWeek(int c, int y, int iMonth, int iDay)
{
    int iWeek;
    iWeek = ((c / 4)-2*c + y + ( y / 4)+(26 * ( iMonth + 1) /10)+ iDay - 1) % 7;
    while(iWeek <= 0)
     iWeek += 7;
    return iWeek;
}

int main()
{
    int iWeek, iMonth, iYear, c, y;
    cin >> iYear >> iMonth;
    cout << iYear << "年" << iMonth <<"月"<<endl;
    
    //Days
    int days = Days(iMonth, iYear);
    
    //Special months
    switch(iMonth)
    case 1: case 2:
        {
            iMonth += 12;
            iYear -=1;
            break;
        }
    

    //calculate parameters
    c = iYear / 100;
    y = iYear % 100;
    
    //nested and nested...omg, these sh*t needs to be optimised..... 
    for(int date = 1; date <= days; date++)
    {   
        iWeek=IWeek(c, y, iMonth, date);
        
        if(date == 1)
        {
            for(int i=1; i < iWeek - 1; i++)
                cout << "    ";
            cout << 1 << "    ";
            if(iWeek == 7)
                cout << endl;
            continue;
        }
        
        for(int week = 1; week <= 7; week++)
        {
            if(iWeek == week)
                {
                cout << date << "    ";
                if(week == 7) cout << endl;
                break;
                }
        }
    }
    
    return 0;
}