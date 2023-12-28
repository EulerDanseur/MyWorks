#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
}node;

node *InsertList(int n);
int Josephus(node *head, int k);

int main()
{
    int n, k;
    cin >> n >> k;
    node *head = InsertList(n);
    cout << Josephus(head, k);
    return 0;
}

node *InsertList(int n)
{
    node *head = NULL, *tail = NULL, *p;
    for(int i = 1; i <= n; i++)
    {
        p = new node;
        p->data = i;
        p->next = head;
        
        if(head == NULL) 
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    return head;
}

int Josephus(node *head, int k)
{
    if(head->next == head)
        return head->data;

    for(int i = 0; i < k - 2; i++)
    {
        head = head->next;
    }

    node *temp = head->next->next;
    delete head->next;
    head->next = temp;
    return Josephus(head->next, k);

}
