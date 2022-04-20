#include "game.h"

void Game::reset(){
    // resets players' hand and discarded
    for(auto &p: players){
        p.reset();
    }

    // clear the table
    for(int i = 0; i < NUM_OF_SUITE; ++i){
        table[i].clear();
    }
}

void Game::deal(){
    int cardCounter = 0;
    int playerIndex = 0;
    
    deck.shuffle();

    // deals the cards to the players
    for (int i = 0; i < deck.getCards()->size(); ++i){
        ++cardCounter;
        players[playerIndex].addCard(&deck.getCards()->at(i));
        
        if(cardCounter == NUM_CARD_PER_PERSON){
            cardCounter = 0;
            ++playerIndex;
        }
    }
}

int Game::findStartingPlayer(){
    for(int i = 0; i < NUM_OF_PLAYERS; ++i){
        if(players[i].hasSevenOfSpades()){
            return i;
        }
    }
}

void Game::storeCurrentScore(){
    for(int i = 0; i < players.size(); ++i){
        players[i].storeScore();
    }
}

vector<Player *> Game::findWinners(){
    vector<Player *> winners;
    int minScore = players[0].getTotalScore();

    // find winning score
    for(int i = 0; i < players.size(); ++i){
        if(players[i].getTotalScore() < minScore){
            minScore = players[i].getTotalScore();
        }
    }

    // find players with the winning score
    for(int i = 0; i < players.size(); ++i){
        if(players[i].getTotalScore() == minScore){
            winners.push_back(&players[i]);
        }
    }

    return winners;
}

bool Game::endRound(){
    for(auto &p: players){
        if(!p.getHand().empty()){
            return false;
        }
    }

    return true;
}

bool Game::endGame(){
    for(auto &p: players){
        if(p.getTotalScore() >= END_GAME_SCORE){
            return true;
        }
    }

    return false;
}

bool Game::tableEmpty(){
    for(int i = 0; i < NUM_OF_SUITE; ++i){
        if(!table[i].empty()){
            return false;
        }
    }
    
    return true;
}

vector<Card *> Game::getLegalMoves(vector<Card *> &hand){
    vector<Card *> myLegalMoves;
    
    // if this is the first play of the game
    if(tableEmpty() && findCard(STARTING_SUITE, STARTING_RANK, hand) != CARD_NOT_FOUND){
        myLegalMoves.push_back(hand[findCard(STARTING_SUITE, STARTING_RANK, hand)]);
        return myLegalMoves;
    }

    for(int i = 0; i < NUM_OF_SUITE; ++i){
        int suite = i + 1;

        if(table[i].empty()){ // put the seven of that suite
            if(findCard(suite, STARTING_RANK, hand) != CARD_NOT_FOUND){
                myLegalMoves.push_back(hand[findCard(suite, STARTING_RANK, hand)]);
            }
        }
        else{
            int lowerRank = *table[i].begin();
            int upperRank = *table[i].rbegin();

            if(lowerRank > MIN_RANK){
                if(findCard(suite, lowerRank - 1, hand) != CARD_NOT_FOUND){
                    myLegalMoves.push_back(hand[findCard(suite, lowerRank - 1, hand)]);
                }
            }

            if(upperRank < MAX_RANK){
                if(findCard(suite, upperRank + 1, hand) != CARD_NOT_FOUND){
                    myLegalMoves.push_back(hand[findCard(suite, upperRank + 1, hand)]);
                }
            }
        }
    }

    return myLegalMoves;
}

int Game::findCard(int suite, int rank, vector<Card *> &hand){
    for(int i = 0; i < hand.size(); ++i){
        if(suite == hand[i]->getSuite() && rank == hand[i]->getRank()){
            return i;
        }
    }

    return CARD_NOT_FOUND;
}

void Game::invitePlayers(){
    int i = 0;

    while(i < NUM_OF_PLAYERS){
        try{
            Strategy  *playerStrat = STRAT_LOOKUP.at(display.invitePlayer(i+1));
            
            if(playerStrat != &humanStrat){
                if(compChoiceOp){
                    playerStrat = COMP_STRAT_LOOKUP.at(display.inviteComp());
                }
                else if(randCompOp){
                    srand(seed); 
                    seed = seed * 2 - 1;
                    int compOp = rand() % 3;

                    if(compOp == 0){
                        display.printNormalComp();
                    } 
                    else if(compOp == 1){
                        display.printDumbComp();
                    }
                    else{
                        display.printSmartComp();
                    }

                    playerStrat = COMP_STRAT_LOOKUP_BY_INDEX.at(compOp);
                }
            }

            players.emplace_back(i+1, playerStrat);
            ++i;
        } catch (...){
            display.printInvalidInvite();
        }
    }
}

void Game::ragequit(int player){
    Strategy *s;

    if(ragequitOp){
        try{
            s = COMP_STRAT_LOOKUP.at(display.inviteCompRagequit());
        } catch (...){
            display.printInvalidInvite();   
        }
    }
    else{
        s = &compStrat;
    }

    players[player].setStrategy(s);
    display.printRagequit(players[player]);

}

void Game::newRound(){
    // setting up the new round
    reset();
    deal();

    int currPlayer = findStartingPlayer();
    display.printNewRound(currPlayer + 1);

    // start playing
    while(!endRound()){
        // get legal moves for the current player
        vector<Card *> legalMoves = getLegalMoves(players[currPlayer].getHand());
        
        display.printTable(table);
        display.printHand(players[currPlayer]);
        display.printLegalMoves(legalMoves);

        // asking the player to play
        Card * cardPlayed = nullptr;
        Card * discardedCard = nullptr;
        bool signalThrown = true;

        while(signalThrown){
            try{
                cardPlayed = players[currPlayer].makeMove(legalMoves, discardedCard);
                signalThrown = false;
            } catch(ShowDeck){
                display.printDeck(deck);
            } catch(Ragequit){
                ragequit(currPlayer);
            }
        }

        // printing the player's move
        if(cardPlayed == nullptr){ // discarded
            display.printDiscarded(players[currPlayer], discardedCard);
        }
        else{ // played
            display.printPlay(players[currPlayer], cardPlayed);
        }

        cout << endl;

        // update table
        if(cardPlayed != nullptr){
            table[cardPlayed->getSuite() - 1].emplace(cardPlayed->getRank());
        }

        // call next player
        ++currPlayer;
        if(currPlayer >= NUM_OF_PLAYERS){
            currPlayer = 0;
        }
    }

    // store the scores
    storeCurrentScore();

    // print scores
    cout << endl;
    display.printEndRound(players);

    // check if game has ended
    if(endGame()){
        vector<Player *> winners= findWinners();
        display.printWinners(winners);
    }
    else{
        newRound();
    }
}

Game::Game(unsigned seed, bool enableBonus) 
    : seed{seed}, deck{Deck{seed}}, enableBonus{enableBonus}{}

void Game::play(){
    if(enableBonus){
        randCompOp = display.getRandCompOptions();
        
        if(!randCompOp){
            compChoiceOp = display.getCompChoiceOp();
        }

        ragequitOp = display.getRagequitOp();
    }

    invitePlayers();
    newRound();
}
