#include "deck.h"

// private methods
void Deck::swap (Card &c1, Card &c2){
    int temp;

    temp = c1.getSuite();
    c1.setSuite(c2.getSuite());
    c2.setSuite(temp);

    temp = c1.getRank();
    c1.setRank(c2.getRank());
    c2.setRank(temp);
}

// public methods
Deck::Deck(unsigned seed){
    rng = default_random_engine{seed};
    for(auto suite: SUITES){
        for(auto rank: RANKS){
            cards.emplace_back(suite, rank);
        }
    }
}

vector<Card> *Deck::getCards(){
    return &cards;
}

void Deck::shuffle(){
    std::shuffle( cards.begin(), cards.end(), rng );
}
