#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node *CreateList()
{
    node *head = NULL, *tail=NULL, *p = NULL;
    int num;
    cin >> num;
    while(num != -1)
    {
        p = new node;
        p->data = num;
        p->next = NULL;
        if(!head) 
            head = p;
        else
            tail->next = p;
        tail = p;

        cin >> num;
    }

    return head;
}

bool HasLoop(node *head)
{
    typedef struct NodePointer
    {
        node *datap;
        NodePointer *next;
    }NodePointer;

    NodePointer *store = NULL, *p = NULL;

    while(true)
    {
        if(head == NULL)
            return false;
        else
        {
            for(NodePointer *cur = store; cur; cur = cur->next)
            {
                if(head == cur->datap)
                    return true;
            }
        }
        p = new NodePointer;
        p->datap = head;
        p->next = store;
        store = p;

        head = head->next;
    }
}

bool CreateLoop(node *head, int m)
{
    if(head == NULL) 
        return false;
    node *temp = head;
    int i = 0;
    for(i = 1; i < m; i++)
    {
        if(temp->next == NULL) 
            return false;
        temp = temp->next;
    }
    while(head && head->next)
    {
        head = head->next;
    }
    head->next = temp;
    return true;
}

int main()
{
    node *head = CreateList();
    int n;
    cin >> n;
    
    if(CreateLoop(head, n))
    for(int i = 0; i < 20; i++)
    {
        cout << head->data<<" ";
        head = head->next;
    }
    else
        cout << CreateLoop(head, n);
    cout <<endl<< (bool)HasLoop(head)<<endl;
}