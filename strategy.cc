#include "strategy.h"

int Strategy::findMax(vector<Card *> &cards){
    int maxIndex = 0;
    int maxRank = cards[0]->getRank();

    for(int i = 0; i < cards.size(); ++i){
        if(cards[i]->getRank() > maxRank){
            maxRank = cards[i]->getRank();
            maxIndex = i;
        }
    }

    return maxIndex;
}

int Strategy::findMin(vector<Card *> &cards){
    int minIndex = 0;
    int minRank = cards[0]->getRank();
    
    for(int i = 0; i < cards.size(); ++i){
        if(cards[i]->getRank() < minRank){
            minRank = cards[i]->getRank();
            minIndex = i;
        }
    }

    return minIndex;
}
