#ifndef HUMANSTRATEGY_H
#define HUMANSTRATEGY_H

#include <vector>
#include <iostream>
#include <stdexcept> 
#include <string>
#include <unordered_map>
#include "strategy.h"

using namespace std;

class HumanStrategy: public Strategy{
    const int RANK = 0;
    const int SUITE = 1;
    const int CARD_NOT_FOUND = -1;
    const unordered_map<char, int> SUITE_TO_NUM{{'C', 1}, {'D', 2}, {'H', 3}, {'S', 4}};
    const unordered_map<char, int> RANK_TO_NUM{{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, 
                                             {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, 
                                             {'J', 11}, {'Q', 12}, {'K', 13}};
    
    int findCard(string &card, vector<Card *>& pile);
    bool isCard(string &card);

    public:
    Card* makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard) override;
};

// signals
class ShowDeck{};
class Ragequit{};
class Quit{};

#endif
