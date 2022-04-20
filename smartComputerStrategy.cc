#include "smartComputerStrategy.h"

// discards the lowest in the hand
// plays the highest in the legalMoves, holds on to the seven

int SmartComputerStrategy::smartMax(vector<Card *> &cards){
    int maxIndex = 0;
    int maxRank = 0;

    for(int i = 0; i < cards.size(); ++i){
        if(cards[i]->getRank() != NEW_PILE_RANK && cards[i]->getRank() > maxRank){
            maxRank = cards[i]->getRank();
            maxIndex = i;
        }
    }

    return maxIndex; 
}

Card* SmartComputerStrategy::makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard){
    if(legalMoves.empty()){ // discard
        int min = findMin(hand);
        discarded.push_back(hand[min]);
        discardedCard = hand[min];
        hand.erase(hand.begin() + min);
        return nullptr;
    }
    else{ // play
        int max = smartMax(legalMoves);

        for(int i = 0; i < hand.size(); ++i){
            if(legalMoves[max] == hand[i]){
                hand.erase(hand.begin()+i);
                return legalMoves[max];
            }
        }
    }
}
