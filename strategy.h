#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "card.h"

using namespace std;

class Strategy{
    protected:
    int findMax(vector<Card *> &cards);
    int findMin(vector<Card *> &cards);
    
    public:
    virtual Card *makeMove(int name, vector<Card *> &hand, vector<Card *> &discarded, vector<Card *> &legalMoves, Card *&discardedCard) = 0;
};

#endif
