#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value && c.value <= VALUE_ACE);
  assert(SPADES <= c.suit && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
    case STRAIGHT_FLUSH : return "STRAIGHT_FLUSH"; break;
    case FOUR_OF_A_KIND : return "FOUR_OF_A_KIND"; break;
    case FULL_HOUSE : return "FULL_HOUSE"; break;
    case FLUSH : return "FLUSH"; break;
    case STRAIGHT : return "STRAIGHT"; break;
    case THREE_OF_A_KIND : return "THREE_OF_A_KIND"; break;
    case TWO_PAIR : return "TWO_PAIR"; break;
    case PAIR : return "PAIR"; break;
    case NOTHING: return "NOTHING"; break;
    default : return "???"; break;
  }
}

char value_letter(card_t c) {
  if (c.value <= 10) {
    return c.value % 10 + '0';
  }
  switch (c.value)
  {
  case 10: 
    return '0';
  case 11:
    return 'J';
  case 12:
    return 'Q';
  case 13:
    return 'K';
  case 14:
    return 'A';
  default:
    return '?';
  }
}


char suit_letter(card_t c) {
  switch (c.suit)
  {
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return 'N';
  }
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if ('2' <= value_let && value_let <= '9') {
    temp.value = value_let - '0';  
  } else if (value_let == '0') {
    temp.value = 10;
  } else if (value_let == 'J') {
    temp.value = 11;
  } else if (value_let == 'Q') {
    temp.value = 12;
  } else if (value_let == 'K') {
    temp.value = 13;
  } else if (value_let == 'A') {
    temp.value = 14;
  } else {
    assert(0); // fail fast
  }
  switch (suit_let)
  {
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    printf("%c\n", suit_let);
    assert(0); // fail fast
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c / 4 + 2;
  temp.suit = c % 4;
  return temp;
}
