#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    switch(n)
    {    case 1:
            cout << "毓琇书院";
            break;
        case 2:
            cout << "健雄书院";
           break;
        case 3:
            cout << "有训书院";
            break;
        case 4:
            cout << "安邦书院";
            break;
        case 5:
            cout << "秉文书院";
            break;
        default:
            cout << "行知书院";
    }
    return 0;
}
