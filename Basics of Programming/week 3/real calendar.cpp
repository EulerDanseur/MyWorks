#include<iostream>
#include<iomanip>
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

int IWeek(int iYear, int iMonth, int iDay)
{
    int iWeek, c, y;
    
    //special months
    switch(iMonth)
    case 1: case 2:
        {
            iMonth += 12;
            iYear -=1;
            break;
        }
    
    //calculate parameter
        c = iYear / 100;
        y = iYear % 100;
    
    iWeek = ((c / 4)-2*c + y + ( y / 4)+(26 * ( iMonth + 1) /10)+ iDay - 1) % 7;
    while(iWeek <= 0)
     iWeek += 7;
    return iWeek;
}

int main()
{
    int iWeek, iMonth, iYear;
    cin >> iYear >> iMonth;
    cout << iYear << "年" << iMonth <<"月"<<endl;
    
    
    //printing
        //pre-printing spaces
    int days = Days(iMonth, iYear);
    iWeek = IWeek(iYear, iMonth, 1);
    for(int space = 2; space <= iWeek; space++)
    {
        cout << setw(5) <<" ";
    }

        //print dates
    for(int date = 1; date <= days; date++)
    {
        iWeek=IWeek(iYear, iMonth, date);
        cout <<  date <<  setw(5) ;
        
        if (iWeek == 7)
            cout << endl;
    }
    cout << endl;
    //舒服多了~

    return 0;
}