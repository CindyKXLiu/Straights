#include "card.h"
 
Card::Card(int suite, int rank) : suite{suite}, rank{rank} {}

int Card::getSuite(){
    return suite;
}

int Card::getRank(){
    return rank;
}

void Card::setSuite(int suite){
    this->suite = suite;
}
    
void Card::setRank(int rank){
    this->rank = rank;
}
