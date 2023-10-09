#include<stdio.h>
#include<assert.h>
//#include<stdlib.h>
#include"cards.h"

void assert_card_valid(card_t c)
{
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r)
{
    switch(r)
    {
        case 0: return "STRAIGHT_FLUSH";
        case 1: return "FOUR_OF_A_KIND"; 
        case 2: return "FULL_HOUSE"; 
        case 3: return "FLUSH"; 
        case 4: return "STRAIGHT"; 
        case 5: return "THREE_OF_A_KIN"; 
        case 6: return "TWO_PAIR"; 
        case 7: return "PAIR"; 
        case 8: return "NOTHING"; 
    }
}

char suit_letter(card_t c)
{
    switch(c.suit)
    {
        case 0: return 's';
        case 1: return 'h';
        case 2: return 'd';
        case 3: return 'c';
    }
}

char value_letter(card_t c)
{
    if (c.value == 10)
        return '0';
    else if (c.value == 11)
        return 'J';
    else if (c.value == 12)
        return 'Q';
    else if (c.value == 13)
        return 'K';
    else if (c.value == 14)
        return 'A';
    else 
        return c.value + 48;

}

void print_card(card_t c)
{
    char value, suit;
    value = value_letter(c);
    suit = suit_letter(c);
    printf("%c%c", value, suit);
}

card_t card_from_letters(char value_let, char suit_let)
{
    card_t c;
    
    //value_let match
    if (value_let >= '2' && value_let <= '9')
        c.value = value_let - 48;
    else if (value_let == '0')
        c.value == 10;
    else 
        switch(value_let)
        {
            case 'J':c.value = 11 ; break; 
            case 'Q':c.value = 12 ; break; 
            case 'K':c.value = 13 ; break; 
            case 'A':c.value = 14 ; break; 
            default: assert(0);
        }
    
    //suit_let match
    switch(suit_let)
    {
        case's': c.suit = SPADES ;break;
        case'h': c.suit = HEARTS ;break;
        case'd': c.suit = DIAMONDS ;break;
        case'c': c.suit = CLUBS ;break;
        default : assert(0);
    }

    return c;
}

card_t card_from_num(unsigned c)
{
    card_t card;
    unsigned suit;

    //map the suit by group    
    /*
    suit = c / 13;
    switch(suit)
    {
        case 0: card.suit = SPADES; break;
        case 1: card.suit = HEARTS; break;
        case 2: card.suit = DIAMONDS; break;
        case 3: card.suit = CLUBS; break;
    }
    */
    card.suit = c / 12;
    //map the value
    card.value = (c % 13) + 2;

    return card;

}