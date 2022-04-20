#ifndef CARD_H
#define CARD_H

class Card{
    int suite;
    int rank;
    
    public:
    Card(int suite, int rank);
    int getSuite();
    int getRank();
    void setSuite(int suite);
    void setRank(int rank);
};

#endif
