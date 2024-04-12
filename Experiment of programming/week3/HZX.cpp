#include <stdio.h>
#include <string.h>
#include <iostream>
int n;
char s[25], g[25];
int ans[15], st[15];

int main()
{
    scanf("%s %s", s, g);
    n = strlen(s);

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
        st[s[i] - '0']++;

    for (int i = 0; i < n; i++)
    {
        int t = g[i] - '0';
        ans[t]++;
        if (s[i] == g[i])
        {
            a++;
            ans[t]--;
            st[t]--;
        }
    }

    for (int t = 0; t < 9; t++)
    {
        
        {
            //int t = g[i] - '0';
            if (ans[t] < st[t])
                b += (ans[t]);
            else
                b+=(st[t]);
        }
    }

    printf("%dA%dB", a, b);
    return 0;
}
