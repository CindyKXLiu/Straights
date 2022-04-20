#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"

using namespace std;

const int SUITES[] = {1, 2, 3, 4};
const int RANKS[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

class Deck{
    vector<Card> cards;
    default_random_engine rng;

    void swap (Card &c1, Card &c2);

    public:
    Deck(unsigned seed);
    vector<Card> *getCards();
    void shuffle();
};

#endif
