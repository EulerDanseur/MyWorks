#include <iostream>
using namespace std;

typedef struct node
{
    char unitType;
    node *top;
    node *bottom;
    node *left;
    node *right;

}node;

node *RollSnow(node *);
node *GetSnowballGrid(int n, int m);
void Printlist(node *head)
{
    node *cur = head;
    while(head)
    {
        while(cur)
        {
            cout << cur->unitType;
            cur = cur->right;
        }

        cout << endl;
        head = head->bottom;
        cur = head;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    node *head = GetSnowballGrid(n, m);
    RollSnow(head);
    Printlist(head);
}

node *RollSnow(node *head)
{
    node *cur = head;
    int count = 0;
    while(head)
    {
        cur = head;
        while(cur)
        {
            count = 0;
            while(cur->bottom && cur->bottom->unitType != '#')
            {               
                if(cur->unitType == 'o')
                {
                    count++;
                    cur->unitType = '.';
                }
                cur = cur->bottom;
            }
            if(cur->unitType == 'o')
            {
                count++;
                cur->unitType = '.';
            }

            node *temp = cur;
            for(int i = 0; i < count; i++)
            {
                temp->unitType = 'o';
                temp = temp->top;
            }
            if(!cur->bottom) 
                break;
            else
                cur = cur->bottom->bottom;
        }        

        head = head->right;
    }
}

node *GetSnowballGrid(int n, int m)
{
    node *head = NULL, *tail = NULL, *up = NULL, *upcur = NULL,*p = NULL;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            p = new node;
            cin >> p->unitType;
            
            if(!head)
            {
                head = p;
            }
            else if(j != 0)
            {
                tail->right = p;
            }

            
            p->right = NULL;
            
            if(j == 0)
                p->left = NULL;
            else
                p->left = tail;

            tail = p; 

            p->bottom = NULL;
            if(upcur != NULL)
            {
                upcur->bottom = p;
                p->top = upcur;
                upcur = upcur->right;
            }
            else
                p->top = NULL;

        }
        if(i == 0)
            up = head;
        else 
            up = up->bottom;
        upcur = up;
        tail = up;

    }
    return head;
}