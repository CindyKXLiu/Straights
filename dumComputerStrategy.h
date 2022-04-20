#ifndef DUMBCOMPUTERSTRATEGY_H
#define DUMBCOMPUTERSTRATEGY_H

#include <vector>
#include "strategy.h"

using namespace std;

class DumbComputerStrategy: public Strategy{
    public:
    Card* makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard) override;
};

#endif
