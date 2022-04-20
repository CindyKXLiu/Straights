#ifndef SMARTCOMPUTERSTRATEGY_H
#define DMARTCOMPUTERSTRATEGY_H

#include <vector>
#include "strategy.h"

using namespace std;

class SmartComputerStrategy: public Strategy{
    const static int NEW_PILE_RANK = 7;
    int smartMax(vector<Card *> &cards);

    public:
    Card* makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard) override;
};

#endif
