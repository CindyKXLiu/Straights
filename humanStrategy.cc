#include "humanStrategy.h"

int HumanStrategy::findCard(string &card, vector<Card *>& pile){
    int rank = RANK_TO_NUM.at(card[RANK]);
    int suite = SUITE_TO_NUM.at(card[SUITE]);

    for(int i = 0; i < pile.size(); ++i){
        if(pile[i]->getSuite() == suite && pile[i]->getRank() == rank){
            return i;
        }
    }
    return CARD_NOT_FOUND;
}

bool HumanStrategy::isCard(string &card){
    if(card.length() != 2){
        cout << "Invalid card." << endl;
        return false; 
    }
    else{
        // check if rank is a valid rank
        try{
            RANK_TO_NUM.at(card[RANK]);
        } catch(out_of_range){
            cout << "Invalid rank." << endl;
            return false;
        }

        // check if suite is a valid suite
        try{
            SUITE_TO_NUM.at(card[SUITE]);
        } catch(out_of_range){
            cout << "Invalid suite." << endl;
            return false;
        }
        
        return true;
    }
}

// public methods
Card* HumanStrategy::makeMove(int name, vector<Card *>& hand, vector<Card *>& discarded, vector<Card *>& legalMoves, Card *&discardedCard){
    string cmd;
    while(cin >> cmd){
        if(cmd == "play"){
            string card;

            if (cin >> card){
                if(isCard(card) && findCard(card, legalMoves) != CARD_NOT_FOUND){ // if legal play
                    int cardPlayedIndex = findCard(card, hand);
                    Card *cardPlayed = hand[cardPlayedIndex];
                    hand.erase(hand.begin() + cardPlayedIndex);
                    return cardPlayed;
                }
            }
            else{
                cout << "Failed to obtain a card." << endl; // may be changed
            }

            cout << "This is not a legal play." << endl;

        }
        else if(cmd == "discard"){
            string card;
            
            if(legalMoves.empty()){
                if(cin >> card){
                    if(isCard(card) && findCard(card, hand) != CARD_NOT_FOUND){
                        int cardDiscardedIndex = findCard(card, hand);
                        discarded.push_back(hand[cardDiscardedIndex]);
                        discardedCard = hand[cardDiscardedIndex];
                        hand.erase(hand.begin() + cardDiscardedIndex);
                        return nullptr;
                    }
                }
                else {
                    cout << "Failed to obtain a card." << endl;
                }

                cout << "This is not a legal discard." << endl;
            }
            else{
                cin >> card;
                cout << "You have a legal play. You may not discard." << endl;
            }

        }
        else if(cmd == "deck"){
            throw ShowDeck{};
        }
        else if (cmd == "ragequit"){
            throw Ragequit{};
        }
        else if(cmd == "quit"){
            cout << "Player" << name << " has quit the game." << endl;
            exit(0);
        }
        else{
            cout << "Invalid command: " << cmd << endl;
        }
    }
}
