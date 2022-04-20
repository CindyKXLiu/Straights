#ifndef COMPUTERSTRATEGY_H
#define COMPUTERSTRATEGY_H

#include <vector>
#include "strategy.h"

using namespace std;

class ComputerStrategy: public Strategy{
    public:
    Card *makeMove(int name, vector<Card *> &hand, vector<Card *> &discarded, vector<Card *> &legalMoves, Card *&discardedCard) override;
};

#endif
