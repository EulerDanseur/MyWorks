#include <stdio.h>
#include <stdlib.h>
typedef struct pile
{
    int value;
    struct pile *up;
}pile;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    pile **top = malloc(n * sizeof(pile *));
    
    for (int i = 0; i < n; i++)
    {
        pile *new_pile;
        new_pile = malloc(sizeof(pile));
        new_pile->value = i + 1;
        new_pile->up = NULL;
        top[i] = new_pile;
    }
    
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        pile *temp = top[y - 1];
        if(temp == 0)
        {
            top[y - 1] = top[x - 1];
            top[x - 1] = NULL;
        }
        else
        {
            while(temp->up)
            {
                temp= temp->up;
            }
            pile *cur = top[x - 1];            
            if(cur == 0||cur->up == 0)
            {
                temp->up = top[x - 1];
                top[x - 1] = NULL;
            }
            else
            {
                pile *next = cur->up;
                pile *curr;
                while(cur && next)
                {
                    curr = next->up;
                    next->up = cur;
                    cur = next;
                    next = curr;
                }
                top[x - 1]->up = 0;
                temp->up = cur;
                top[x - 1] = NULL;                
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (top[i] != NULL)
        {
            while(top[i])
            {
                printf("%d ", top[i]->value);
                top[i] = top[i]->up;
            }
        }
        else
        {
            printf("0");
        }
        printf("\n");
    }

    return 0;
}