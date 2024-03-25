#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

int main()
{
    int k;
    cin >> k;
    map<string, int> m;
    string word;
    getchar();
    while (cin >> word)
    {
        if (!((word[word.length()-1] >= 'a' && word[word.length()-1] <= 'z') || (word[word.length()-1] >= 'A' && word[word.length()-1] <= 'Z')))
        {
            word.pop_back();
        }
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        m[word]++;
    }

    vector<pair<string, int>> vec;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        vec.push_back(pair<string, int>(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), cmp);

    auto p = vec.begin();
    int i = 0;
    while (p != vec.end() && i < k)
    {
        cout << p->first << ' ' << p->second;
        p++;
        i++;
    }
}