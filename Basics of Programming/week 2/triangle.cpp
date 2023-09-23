 #include<iostream>
using namespace std;

int main()
{
    //input
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 || b == 0 || c == 0)   
    {
        cout << "A";
        return 0;
    }
    if (a + b <= c || b + c <= a || a + c <= b)   
        cout << "A";
    else if (a == b && a == c)
        cout << "B";
    else if ( (a == b || b == c || c == a) && (a*a + b*b != c*c && a*a + c*c != b*b && b*b + c*c != a*a))
        cout << "C";
    else if ((a != b && b != c && c != a) && (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a))
        cout << "D";
    else
        cout << "E";
    return 0;
}