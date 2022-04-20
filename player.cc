#include "player.h"

Player::Player(int name, Strategy *strat)
    : name{name}, strat{strat}{}

// accessors
int Player::getName(){
    return name;
}

vector<Card *> &Player::getHand(){
    return hand;
}

vector<Card *> &Player::getDiscarded(){
    return discarded;
}

vector<int> &Player::getScores(){
    return scores;
}

int Player::getTotalScore(){
    int score = 0;
    for(auto &s: scores){
        score += s;
    }
    return score;
}

bool Player::hasSevenOfSpades(){
    for(auto &card: hand){
        if(card->getSuite() == STARTING_SUITE && card->getRank() == STARTING_RANK){
            return true;
        }
    }

    return false;
}

// mutators
void Player::addCard(Card *card){
    hand.push_back(card);
}

void Player::setStrategy(Strategy *strat){
    this->strat = strat;
}

void Player::storeScore(){
    int score = 0;
    for(auto &card : discarded){
        score += card->getRank();
    }

    scores.push_back(score);
}

void Player::reset(){
    hand.clear();
    discarded.clear();
}

Card *Player::makeMove(vector<Card *> &legalMoves, Card *&discardedCard){
    return strat->makeMove(name, hand, discarded, legalMoves, discardedCard);
}
