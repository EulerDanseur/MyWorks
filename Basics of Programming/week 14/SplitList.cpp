#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node* next = NULL; 
}node;

inline void PrintList(node *head)
{
    while(head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}

node *InsertList();
node *SplitList(node *head);
int main()
{
    node *head1 = InsertList();
    node *head2 = SplitList(head1);
    
    PrintList(head1);
    cout << endl;
    PrintList(head2);
}


node *InsertList()
{
    node *head = NULL, *tail = NULL, *p;
    int temp;
    cin >> temp;
    while(temp != -1)
    {
        p = new node;
        p->data = temp;
        p->next = NULL;
        
        if(head == NULL) 
            head = p;
        else
            tail->next = p;
        tail = p;
        
        cin >> temp;
    }
    return head;
}

node *SplitList(node *head)
{
    while(head->data != 0)
        head = head->next;

    node *head2 = head->next;
    head->next = NULL;
    return head2;
}