#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isTransformable(string s, string t);

int main()
{
    string s, t;
    cin >> s >> t;
    cout << isTransformable(s, t);
}

bool isTransformable(string s, string t)
{
    int n = s.size();
    vector<queue<int>> pos(10);
    for (int i = 0; i < n; ++i)
    {
        pos[s[i] - '0'].push(i);
    }
    if (s.length() != t.length())
        return false;
    else if (pos == t)
        return true;

    for (int i = 0; i <= t.length(); i++)
    {
        auto end = pos.end();
        bool flag = 1;
        for (auto p = pos.begin(); p != end;)
        {
            if (flag && *p == t[i] - '0')
            {
                end = p;
                p = pos.begin();
                flag = 0;
                continue;
            }
            else if (flag == 0)
            {
                if (*p < t[i])
                    return 0;
            }
            p++;
        }
        if (flag)
            return 0;
        pos.erase(end);
    }
    return 1;
}