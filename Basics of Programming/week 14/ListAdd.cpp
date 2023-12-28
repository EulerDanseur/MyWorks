#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next; 

}node;

node *InsertList(int n);
node *DeleteNode(node* head);

int ListSum(node *head);

int main()
{
    int n;
    cin >> n;
    node *head = InsertList(n);
    cout << ListSum(head);

    return 0;
}

node *InsertList(int n)
{
    node *head = NULL;
    node *p;
    for(int i = 0; i < n; i++)
    {
        p = new node;
        cin >> p->data;
        p->next = head;
        head = p;
    }
    return head;
}

node *DeleteNode(node* head)
{
    node *temp = head->next;
    delete head;

    return temp;
}

int ListSum(node *head)
{
    if(head == NULL) return 0;

    int i = head->data;
    head = DeleteNode(head);
    
    return i + ListSum(head);
}