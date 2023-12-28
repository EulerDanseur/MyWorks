#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node *Createset();
void Deleteset(node*);
node *Sortset(node*);
node *Insertnode(node*,node*);
node *Interset(node*, node*);
node *Unionset(node*, node*);
node *Diffset(node*, node*);

void Printset(node*);

int main()
{
    node *head1, *head2;
    head1 = Createset();
    head2 = Createset();
    node *inter = Sortset(Interset(head1, head2));
    node *unio = Sortset(Unionset(head1, head2));
    node *diff = Sortset(Diffset(head1, head2));
    Printset(inter);
    cout << endl;
    Printset(unio);
    cout << endl;
    Printset(diff);
    Deleteset(head1),Deleteset(head2),Deleteset(inter),Deleteset(unio),Deleteset(diff);
    return 0;
}

node *Createset()
{
    node * head;
    head = NULL;
    node *p = NULL;
    int num;
    cin >> num;
    while(num != -1)
    {
        p = new node;
        p->data = num;
        p->next = head;
        head = p;
        cin >> num;
    }

    return head;
}

void Deleteset(node* head)
{
    node *current = head;
    while(head != NULL)
    {
        head = head->next;
        delete current;
        current = head;
    }
}

node *Sortset(node* head)
{
   if(head == NULL || head->next == NULL) return head;
   node *current = head->next;
   head->next = NULL;
   while(current != NULL)
   {
        node *temp = current;
        current = current->next;
        head = Insertnode(head, temp);
   }
    return head;
}

node *Insertnode(node *head, node *temp)
{
    if(temp->data < head->data)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    node *prev = head;
    node *current = head;
    while(current && current->data < temp->data)
    {
        prev = current;
        current = current->next;
    }
    temp->next = current;
    prev->next = temp;
    return head;
}
node *Interset(node *head1, node *head2)
{
    if(head1 == NULL || head2 == NULL) return NULL;
    
    node *inter = NULL;
    node *p = NULL;
    for(node *cur1 = head1; cur1; cur1= cur1->next)
    {
        for(node *cur2 = head2; cur2; cur2= cur2->next)
        {
            if(cur1->data == cur2->data)
            {
                p = new node;
                p->data = cur1->data;
                p->next = inter;
                inter = p;
            }
        }
    }

    return inter;
}

node *Unionset(node* head1, node* head2) 
{
    node *unio = NULL;
    node *p = NULL;
    for(node *cur1 = head1; cur1; cur1= cur1->next)
    {
        p = new node;
        p->data = cur1->data;
        p->next = unio;
        unio = p;
    }
    
    bool flag = 1;

    for(node *cur1 = head2; cur1; cur1 = cur1->next)
    {
        for(node *cur2 = unio; cur2; cur2= cur2->next)
        {
            if(cur1->data == cur2->data)
            {
                flag = 0;
                break;
            }
        }
        if(flag || unio == NULL)
        {    
            p = new node;
            p->data = cur1->data;
            p->next = unio;
            unio = p;
        }

        flag = 1;
    }
    
    return unio;

}

node *Diffset(node*head1, node*head2)
{
    node *diff = NULL;
    node *p = NULL;
    bool flag = 1;
    for(node *cur1 = head1; cur1; cur1 = cur1->next)
    {
        for(node *cur2 = head2; cur2; cur2= cur2->next)
        {
            if(cur1->data == cur2->data)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {    
            p = new node;
            p->data = cur1->data;
            p->next = diff;
            diff = p;
        }

        flag = 1;
    }

    return diff;
}

void Printset(node *head)
{
    while(head)
    {
        cout << head->data <<' ';
        head = head->next;
    }
}