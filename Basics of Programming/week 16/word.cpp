#include <iostream>
#include<cstring>
using namespace std;

typedef char word[11];
inline int Inlist(word i, word* list, int n)
{
    for(int j = 0; j<n; j++)
    {
        if(strcmp(i, list[j]) == 0)
        {
            return j + 1;
        }
    }
    return 0;
}
int main()
{
    int n, m, result = 0;
    int count = 0, length = 0;
    cin >> n;
    word *list = new word[n];
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    cin >> m;
    word *passage = new word[m];
    for(int i = 0; i < m; i++)
    {
        cin >> passage[i];
    }
    for(int i = 0; i < m; i++)
    {
        int cur;int index = 1;
        if(cur = Inlist(passage[i], list, n))
        {
            int usedlist[m] = {cur};
            count = 110000;
            int temp = count;
            for(int j = i + 1; j < m; j++)
            {
                int curr;
                if(curr = Inlist(passage[j], list, n))
                {
                    int flag = 1;
                    for(int k = 0; k < count/100000; k++)
                    {
                        if(curr == usedlist[k])
                        {
                            flag = 0;
                            break;
                        }
                    }

                    if(flag)
                    {
                        temp+=100000;
                        usedlist[index] = curr;
                        index++;
                    }
                }
                temp--;
                count = max(count, temp);
            }
            result = max(count, result);
        }
    }

    cout << result/100000<<endl;
    cout<<10001 - result % 100000;

}