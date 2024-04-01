#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n)
{
    vector<vector<string>> dp;
    dp.push_back({""});
    dp.push_back({"()"});
    for (int i = 2; i <= n; i++)
    {
        dp.push_back({});
        vector<string> l = dp[i - 1];
        for (int p = 0; p < i; p++)
        {
            for (auto t = dp[p].begin(); t != dp[p].end(); t++)
                for (auto o = dp[i - 1 - p].begin(); o != dp[i - 1 - p].end(); o++)
                {
                    string s = "(" + *t + ")" + *o;
                    dp[i].push_back(s);
                }
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<string> dp = generateParenthesis(n);
    for (auto p = dp.begin(); p != dp.end(); p++)
        cout << *p << endl;
}