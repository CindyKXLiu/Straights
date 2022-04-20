#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "strategy.h"
#include "card.h"

using namespace std;

class Player{
    const int STARTING_RANK = 7;
    const int STARTING_SUITE = 4;
    
    int name;
    vector<Card *> hand;
    vector<Card *> discarded;
    vector<int> scores;
    Strategy *strat;

    public:
    Player(int name, Strategy *strat);

    // accessors
    int getName();
    vector<Card *> &getHand();
    vector<Card *> &getDiscarded();
    vector<int> &getScores();
    int getTotalScore();
    bool hasSevenOfSpades();

    // mutators
    void addCard(Card *card);
    void setStrategy(Strategy *strat);
    void storeScore();
    void reset();
    Card *makeMove(vector<Card *> &legalMoves, Card *&discardedCard);
};

#endif
