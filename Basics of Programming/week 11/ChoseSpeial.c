#include<stdio.h>

int main()
{
    int stuAmt, coAmt;
    //cin >> stuAmt >> coAmt;
    scanf("%d %d", &stuAmt, &coAmt);
    int permitAmt[10]={0};
    for(int i = 0; i < coAmt; i++)
        scanf("%d", &permitAmt[i]);

    int name[1000][10] = {0};
    int will[1000][10] = {0};
    int admit[1000] = {0};
    int nonAdmit = stuAmt;
    _Bool admitted[1000] = {0};

    for(int i = 0; i < stuAmt; i++)
    {
        char ntemp[10] = {0};
        int rank;
        getchar();
        for(int i = 0; i < 10; i++)
        {
            ntemp[i] = getchar();

            if(ntemp[i] == ' ')
            {
                ntemp[i] = 0;
                break;
            }
        } 
        
        scanf("%d", &rank);

        for(int i = 0; i < 10; i++)
            name[rank - 1][i] = ntemp[i];
        
        for(int i = 0; i < coAmt; i++)
            scanf("%d", &will[rank - 1][i]);
        
        //getchar();
    }

    for(int w = 0; w < coAmt; w++)
    {
        for(int stu = 0; stu < stuAmt; stu++)
        {
            if(admitted[stu] == 0 && permitAmt[will[stu][w] - 1] != 0)
            {
                admit[stu] = will[stu][w];
                nonAdmit--;
                permitAmt[will[stu][w] - 1]--;
                admitted[stu] = 1;
            }
        }

        if(nonAdmit == 0) break;
    }

    for(int i = 0; i < stuAmt; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(name[i][j] == 0) break;
            //char letter = name[i][j];
            //cout << letter;
            printf("%c", name[i][j]);
        }

        printf(" %d\n", admit[i]);
    }
    return 0;
}