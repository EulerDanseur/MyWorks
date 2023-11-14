#include<iostream>
using namespace std;
int direction;
int carriage, mouse, cat, train;
void mousemove();
void catmove();

int main()
{
    cin >> carriage >> mouse >> cat;
    
    cin >> direction;

    int time;
    cin >> time;

    if(cat == mouse)
    {
        cout << mouse;
        return 0;
    }

    for(int i = 0; i < time; i++)
    {
        cin >> train;
        mousemove();
        catmove();
        if(mouse == cat)
        {
            cout << cat; 
            return 0;
        }
    }
    cout << -1;
    return 0;
}

void catmove()
{
    if(cat == 1 && direction == -1) direction = 1;
    else if(cat == carriage && direction == 1) direction = -1;

    cat += direction;
}

void mousemove()
{
    if(train)
    {
        if(cat == 1) 
            mouse = carriage;
        else if(cat == carriage) 
            mouse = 1;
        else if(direction == -1)
            mouse = carriage;
        else
            mouse = 1;
    }
    else if(mouse != 1 && mouse != carriage)
    {
        if(cat < mouse)
            mouse++;
        else
            mouse--;
    }
}