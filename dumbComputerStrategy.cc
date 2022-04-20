#include "dumbComputerStrategy.h"
 
// discards the highest in the hand
// plays the lowest in the legalMoves

Card* DumbComputerStrategy::makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard){
    if(legalMoves.empty()){ // discard
        int max = findMax(hand);
        discarded.push_back(hand[max]);
        discardedCard = hand[max];
        hand.erase(hand.begin() + max);
        return nullptr;
    }
    else{ // play
        int min = findMin(legalMoves);

        for(int i = 0; i < hand.size(); ++i){
            if(legalMoves[min] == hand[i]){
                hand.erase(hand.begin()+i);
                return legalMoves[min];
            }
        }
    }
}
