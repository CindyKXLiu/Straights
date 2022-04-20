#include "computerStrategy.h"

Card *ComputerStrategy::makeMove(int name, vector<Card *> &hand, vector<Card *> &discarded, vector<Card *> &legalMoves, Card *&discardedCard){
    if(legalMoves.empty()){ // discard
        discarded.push_back(hand[0]);
        discardedCard = hand[0];
        hand.erase(hand.begin());
        return nullptr;
    }
    else{ // play
        for(int i = 0; i < hand.size(); ++i){
            if(legalMoves[0] == hand[i]){
                hand.erase(hand.begin()+i);
                return legalMoves[0];
            }
        }
    }
}
