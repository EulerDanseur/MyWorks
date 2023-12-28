#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char *team[1005];
    char *s;
    int suma[1005] = {0}, sumb[1005] = {0}, sumc[1005] = {0};
    for (int i = 0; i < n; i++)
    {
        s = (char*)malloc(21*sizeof(char));
        scanf("%s", s);
        team[i] = s;
        s = NULL;
        for (int j = 0; j < 11; j++)
        {
            char name[21] = "";
            scanf("%s", name);
            int a, b, c;
            scanf(" %d %d %d", &a, &b, &c);
            suma[i] += a;
            sumb[i] += b;
            sumc[i] += c;
        }
        getchar();
    }

    printf("%s", team[0]);
}