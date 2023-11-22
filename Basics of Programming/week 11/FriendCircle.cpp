#include <iostream>
using namespace std;
int n = 0;
bool relation[100][100] = {0};
void SearchFriend(int );

int main ()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        cin >> relation[i][j];
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(relation[i][i])
        {
            relation[i][i] = 0;
            SearchFriend(i);
            count++;
        }
    }

    cout << count;
    return 0;

}

void SearchFriend(int person)
{
    for(int i = 0; i < n; i++)
    {
        if(relation[person][i])
        {
            relation[person][i] = 0;
            relation[i][person] = 0;
            relation[i][i] = 0;
            SearchFriend(i);
        }
    }

}