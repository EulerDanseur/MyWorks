#include <iostream>
using namespace std;

typedef struct 
{
    string name;
    int voted = 0;
}candi;

int main()
{
    int m, n;
    cin >> m >> n;
    candi candidate[m];
    string elector[n];
    for(int i = 0; i < m; i++)
        getline(cin,candidate[i].name);
    for(int i = 0; i < n; i++)
    {
        getline(cin, elector[i]);
        for(int j = 0; j < m; j++)
        {
            if(candidate[j].name == elector[i])
            {
                candidate[j].voted++;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++)
        cout << candidate[i].name << candidate[i].voted << endl;

    return 0;
}
