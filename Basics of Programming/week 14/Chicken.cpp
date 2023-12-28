#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node* next = NULL; 
}node;

node *InsertList();
node *MaxList(node* head);
void ListReform(node* head, node* newhead);
void PrintList(node* head);

int main()
{
    node *head = InsertList(), *hen = MaxList(head);
    ListReform(head, hen);
    PrintList(hen);
    return 0;    
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

node *MaxList(node *head)
{
    int temp = -1;
    node *max = NULL;
    while(head != NULL)
    {
        if(head->data > temp)
        {
            temp = head->data;
            max = head;
        }
        head = head->next;
    }
    
    return max;
}

void ListReform(node *head, node *newhead)
{
    if(head == newhead) return;
    
    node *temp = head;
    while(temp->next != newhead)
        temp = temp->next;
    temp->next = NULL;
    temp = newhead;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head;

}

void PrintList(node *head)
{
    while(head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}