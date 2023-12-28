#include <iostream>
using namespace std;

int calculate(char* s)
{
    typedef struct node
    {
        int data;
        int sign;
        struct node *next;
    }node;
    node *head = NULL, *p = NULL;
    int symb = 1;
    int newdata = 1;
    int num;
    while(*s != 0)
    {
        switch(*s)
        {
            case ' ': s++; newdata = 1; break; 
            case '+': symb = 1; s++; newdata = 1; break;
            case '-': symb = -1; s++; newdata = 1; break;
            case '*': 
                num = 0;
                s++;
                while(*s == ' ' || *s >= '0' && *s <='9')
                {
                    if(*s == ' ')
                    {
                        s++;
                        continue;
                    }
                    num = num * 10 + *s - '0';
                    s++;
                }
                p->data *= num;
                newdata = 1;
                break;
            case '/':
                num = 0;
                s++;
                while(*s == ' ' || *s >= '0' && *s <='9')
                {
                    if(*s == ' ')
                    {
                        s++;
                        continue;
                    }
                    num = num * 10 + *s - '0';
                    s++;
                }
                p->data /= num;
                newdata = 1;
                break;
            default:
            if(newdata)
            {
                p = (node *) malloc(sizeof(node));
                p->data = *s - '0';
                p->sign = symb;
                p->next = head;
                head = p;
                newdata = 0;
                s++;
            }
            else
            {
                p->data *= 10;
                p->data += *s-'0';
                s++;
            }
        }
    }

    int result = 0;
    node *cur;
    while(p)
    {
        result += p->data * p->sign;
        cur = p;
        p = p->next;
        free(cur); 
    }

    return result;

}

int main()
{
    char s[10] = {0};
    cin >> s;
    cout << calculate(s);

}