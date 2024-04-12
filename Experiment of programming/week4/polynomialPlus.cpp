#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/* int main()
{
    map<int, int> l;
    string a, b;
    cin >> a >> b;
    int base = 1, g = 0, h = 0, max = 0, flag1 = 1, flag2 = 0;
    for (auto p = a.begin(); p != a.end(); p++)
    {
        if (*p == 'x')
        {
            p += 2;
            flag1 = 0;
            flag2 = 1;
        }
        else if (*p == '+')
        {
            l[h] = base * g;
            flag2 = 0;
            flag1 = 1;
            g = 0;
            if (max < h)
                max = h;
            h = 0;
            p++;
            base = 1;
        }
        else if (*p == '-')
        {
            l[h] = base * g;
            flag2 = 0;
            flag1 = 1;
            g = 0;
            if (max < h)
                max = h;
            h = 0;
            p++;
            base = -1;
        }
        if (flag1)
        {
            g *= 10;
            g += *p - '0';
        }
        if (flag2)
        {
            h *= 10;
            h += *p - '0';
        }
    }
    l[h] = base * g;
    flag2 = 0;
    flag1 = 1;
    g = 0;
    h = 0;
    base = 1;
    auto p = b.begin();
    if (*b.begin() == '-')
    {
        base = -1;
        p++;
    }
    for (; p != b.end(); p++)
    {
        if (*p == 'x')
        {
            p += 2;
            flag1 = 0;
            flag2 = 1;
        }
        else if (*p == '+')
        {
            if (l[h] != 0)
                l[h] += base * g;
            else
                l[h] = base * g;
            if (l[h] == 0)
                l.erase(h);
            flag2 = 0;
            flag1 = 1;
            g = 0;
            if (max < h)
                max = h;
            h = 0;
            p++;
            base = 1;
        }
        else if (*p == '-')
        {
            if (l[h] != 0)
                l[h] += base * g;
            else
                l[h] = base * g;

            if (l[h] == 0)
                l.erase(h);
            flag2 = 0;
            flag1 = 1;
            g = 0;
            if (max < h)
                max = h;
            h = 0;
            p++;
            base = -1;
        }
        if (flag1)
        {
            g *= 10;
            g += *p - '0';
        }
        if (flag2)
        {
            h *= 10;
            h += *p - '0';
        }
    }
    if (l[h] != 0)
        l[h] += base * g;
    else
        l[h] = base * g;

    if (l[h] == 0)
        l.erase(h);
    flag2 = 0;
    flag1 = 1;
    g = 0;
    h = 0;
    // 	for (int i = 0; i < 1000; i++)
        {
            if (l[i] != 0) flag1 = 0;

        }
        if (flag1 == 1)
        {
            cout << 0;
            return 0;
        }
        cout << l[max] << "x^" << max;
        for(int i = max - 1; i >= 0; i--)
        {
            if(l[i] > 0)
                cout << "+" << l[i] << "x^" << i ;
            else if (l[i] < 0)
                cout << l[i] << "x^" << i;
        } //

    if (l.size() == 0)
    {
        cout << 0;
        return 0;
    }
    // map<int, int>::iterator q;

    cout << l.rbegin()->second << "x^" << l.rbegin()->first;
    auto q = l.rbegin();
    q++;
    for (; q != l.rend(); q++)
    {

        if (q->second > 0)
            cout << "+" << q->second << "x^" << q->first;
        else if (q->second < 0)
            cout << q->second << "x^" << q->first;
    }
} */

int main()
{
    map<int, int> l;
    string a, b;
    cin >> a >> b;
    int base = 1, g = 0, h = 0, max = 0;

    for (auto p = a.begin(); p != a.end(); p++)
    {
        if (*p == 'x')
        {
            p += 2;
            l[h] = base * g;
            max = max > h ? max : h;
            h = 0;
            base = 1;
            g = 0;
        }
        else if (*p == '+' || *p == '-')
        {
            l[h] = base * g;
            max = max > h ? max : h;
            h = 0;
            g = 0;
            base = *p == '+' ? 1 : -1;
        }
        else
            g = g * 10 + *p - '0';
    }
    l[h] = base * g;
    max = max > h ? max : h;

    base = 1;
    for (auto p = b.begin(); p != b.end(); p++)
    {
        if (*p == 'x')
        {
            p += 2;
            h = 0;
            base = 1;
        }
        else if (*p == '+')
        {
            h = 0;
            base = 1;
        }
        else if (*p == '-')
        {
            h = 0;
            base = -1;
        }
        else
            h = h * 10 + *p - '0';
        
        if (l.find(h) != l.end())
            l[h] += base * (p[0] == '-' ? -l[h] : l[h]);
        else if (base != 0)
            l[h] = base * l[h];
    }

    if (l.size() == 0)
    {
        cout << 0;
        return 0;
    }

    cout << l[max] << "x^" << max;
    for (auto q = l.rbegin(); q != --l.rend(); q++)
        if (q->second > 0)
            cout << "+" << q->second << "x^" << q->first;
        else
            cout << q->second << "x^" << q->first;

    return 0;
}

