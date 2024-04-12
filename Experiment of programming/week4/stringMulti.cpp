#include <bits\stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    if(num1 == "0" || num2 == "0")  return "0";
    
    string a;
    int l = num2.length(), m = num1.length();
    int base = 0, cur = 0;
    int pro = 0;
    for (int i = l; i >= 1; i--)
    {
        base = l - i;
        pro = 0;
        for (int p = m - 1; p >= 0; p--)
        {
            if (base >= a.length())
                a.push_back(0);
            
            char k = num1[p], e = num2[i - 1], u = a[base];

            if (a[base] == 0)
                cur = (num1[p] - '0') * (num2[i - 1] - '0') + pro;
            else
                cur = a[base] - '0' + (num1[p] - '0') * (num2[i - 1] - '0') + pro;
            if (cur > 9)
                pro = cur / 10;
            else
                pro = 0;
            cur %= 10;

            a[base] = cur + '0';
            base++;
        }
        if(pro != 0)
            a.push_back(pro + '0');
    }


    reverse(a.begin(), a.end());

    return a;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b);
}