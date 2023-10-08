#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "input.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
    deck_t *ans = malloc(sizeof(*ans));
    ans->cards = NULL;
    ans->n_cards = 0;
    for (int i=0, len=strlen(str); i < len; ) {
        if (str[i] == '\n' || str[i] == ' ') {
            i++;
            continue;
        }
        assert(i+1 < len);
        char v = str[i++], s = str[i];
        if (v == '?') {
            assert(isdigit(s));
            // Observe the digit after '?' may >= 10 !!!
            size_t sz = 0;
            char num[len];
            for (; isdigit(str[i]); i++, sz++) {
                num[sz] = str[i];
            }
            num[sz] = '\0';
            card_t *ptr = add_empty_card(ans);
            add_future_card(fc, atoi(num), ptr);
        } else {
            i++;
            assert(str[i] == ' ' || str[i] == '\n');
            card_t card = card_from_letters(v, s);
            // card_t *tmp = malloc(sizeof(*tmp));
            // tmp->value = card.value;
            // tmp->suit = card.suit;
            // ans->cards = realloc(ans->cards, (ans->n_cards+1)*sizeof(*(ans->cards)));
            // ans->cards[ans->n_cards] = tmp;
            // ans->n_cards++;
            //= The above equals to the below
            add_card_to(ans, card);
        }
    }
    if (ans->n_cards < 5) {
        perror("there are fewer than 5 cards\n");
        exit(-1);
    }
    return ans;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
    int n = 0;
    deck_t **ans = NULL;
    size_t sz = 0;
    char * buf = NULL;
    for (; getline(&buf, &sz, f) >= 0; ) {
        deck_t *deck = hand_from_string(buf, fc);
        ans = realloc(ans, (n+1)*sizeof(*ans));
        ans[n] = deck;
        n++;
    }
    *n_hands = n;
    free(buf);
    return ans;
}
