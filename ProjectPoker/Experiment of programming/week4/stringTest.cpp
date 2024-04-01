#include <iostream>
#include <cmath>
using namespace std;
int a[10000] = {0};
bool Judge(int n)
{
    if (n == 1)
        return false;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void Cal()
{
    int count = 0;
    for (int i = 2; i <= 10000; i++)
        if (Judge(i))
        {
            a[count] = i;
            count++;
        }
}

int Count0(int n)
{
    int count = 0;
    int duan = 0;
    while (a[duan] <= n)
        duan++;
    for (int i = 0; i < duan; i++)
    {
        int sum = 0;
        for (int j = i; j < duan; j++)
        {
            sum += a[j];
            if (sum == n)
            {
                count++;
                break;
            }
            if (sum > n)
                break;
        }
    }
    return count;
}

int main()
{
    Cal();
    int n;
    cin >> n;
    while (n != 0)
    {
        int result = Count0(n);
        if (result == 0 && !Judge(n))
            cout << "0" << endl;
        else
            cout << result << endl;
        cin >> n;
    }
    return 0;
}
