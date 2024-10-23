#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, m;
    while (1)
    {
        cin >> n >> m;
        map<char, pair<vector<char>, vector<char>>> mp;
        char ch1, lessmark, ch2;
        bool ok = 0, rings = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> ch1 >> lessmark >> ch2;
            if (!ok)
            {
                mp[ch2].first.push_back(ch1);
                mp[ch1].second.push_back(ch2);
                for (auto it : mp[ch1].first)
                {
                    for (int i = 0; i < mp[it].second.size(); i++)
                    {
                        if (mp[it].second[i] == ch2)
                        {
                            mp[it].second.erase(mp[it].second.begin() + i);
                            for (int j = 0; j < mp[ch2].first.size(); j++)
                            {
                                if (mp[ch2].first[j] == it)
                                {
                                    mp[ch2].first.erase(mp[ch2].first.begin() + j);
                                }
                            }
                            i--;
                        }
                    }
                }
                for (auto it : mp[ch2].second)
                {
                    for (int i = 0; i < mp[it].first.size(); i++)
                    {
                        if (mp[it].first[i] == ch1)
                        {
                            mp[it].first.erase(mp[it].first.begin() + i);
                            for (int j = 0; j < mp[ch1].second.size(); j++)
                            {
                                if (mp[ch1].second[j] == mp[it].first[i])
                                {
                                    mp[ch1].second.erase(mp[ch1].second.begin() + j);
                                }
                            }
                            i--;
                        }
                    }
                }

                // check every node
                char head = 0, tail = 0;
                ok = 1;
                for (auto it : mp)
                {
                    if (it.second.first.size() > 1 || it.second.second.size() > 1)
                    {
                        ok = 0;
                    }
                    if (it.second.first.size() == 0 && it.second.second.size() == 1)
                    {
                        head = it.first;
                    }
                    if (it.second.first.size() == 1 && it.second.second.size() == 0)
                    {
                        tail = it.first;
                    }
                }
                if (tail == 0 || head == 0)
                    ok = 0;
                // check if there are rings
                if (ok = 1)
                {
                    char fast = mp[head].second[0], slow = head;
                    while (1)
                    {
                        if (fast == slow)
                        {
                            rings = 1;
                            ok = 0;
                            break;
                        }
                        else if (fast == tail || slow == tail)
                        {
                            break;
                        }
                        fast = mp[mp[fast].second[0]].second[0];
                        slow = mp[slow].second[0];
                    }
                }
                if (mp.size() != n)
                    ok = 0;
                if (ok)
                    cout << "YES" << endl;
                if(rings)
                    cout << "RINGS" << endl;
            }
        }
    }
}