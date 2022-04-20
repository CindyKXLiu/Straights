#include "display.h"

const string Display::YES = "yes";
const string Display::NO = "no";

void Display::print (Card *card){
    cout << NUM_TO_RANK.at(card->getRank()) << NUM_TO_SUITE.at(card->getSuite());
}

void Display::print (Card card){
    cout << NUM_TO_RANK.at(card.getRank()) << NUM_TO_SUITE.at(card.getSuite());
}

void Display::printSuite(set<int> &suite){
    for(auto &card: suite){
        cout << " " << NUM_TO_RANK.at(card);
    }
    cout << endl;
}

void Display::printInvalidInvite(){
    cout << "Invalid player." << endl;
}

void Display::printNewRound(int name){
    cout << endl << "A new round begins. It's Player" << name << "'s turn to play." << endl << endl;
}

void Display::printEndRound(vector<Player> &players){
    for(int i = 0; i < players.size(); ++i){
        // printing player's discarded pile
        cout << "Player" << players[i].getName() << "'s discards:";
        for(auto &d: players[i].getDiscarded()){
            cout << " ";
            print(d);
        }
        cout << endl;

        // printing player's score
        cout << "Player" << players[i].getName() << "'s score: " << players[i].getScores()[0];

        for(int j = 1; j < players[i].getScores().size(); ++j){
            cout << " + " << players[i].getScores()[j];
        }
    
        cout << " = " << players[i].getTotalScore() << endl;
    }
}

void Display::printWinners(vector<Player *> &winners){
    for(auto &w: winners){
        cout << "Player" << w->getName() << " wins!" << endl;
    }
}

void Display::printTable(set<int> table[NUM_OF_SUITE]){
    cout << "Cards on the table:" << endl;
    for(int i = 0; i < NUM_OF_SUITE; ++i){
        cout << TABLE_LOOKUP.at(i);
        printSuite(table[i]);
    }
}

void Display::printHand(Player &p){
    cout << "Your hand:";

    for(auto &c : p.getHand()){
        cout << " ";
        print(c);
    }

    cout << endl;
}

void Display::printLegalMoves(vector<Card *> &legalPlays){
    cout << "Legal plays:";

    for(auto &l: legalPlays){
        cout << " ";
        print(l);
    }

    cout << endl;
}

void Display::printPlay(Player &player, Card *card){
    cout << "Player" << player.getName() << " plays ";
    print(card);
    cout << "." << endl;
}

void Display::printDiscarded(Player &player, Card *card){
    cout << "Player" << player.getName() << " discards ";
    print(card);
    cout << "." << endl;
}

void Display::printDeck(Deck &d){
    int count = 0;
    for(auto &card: *d.getCards()){
        ++count;
        print(card);
        
        if(count == 13){
            count = 0;
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
}

void Display::printRagequit(Player &player){
    cout << "Player" << player.getName() << " ragequits. A computer will now take over." << endl;
}

void Display::printNormalComp(){
    cout << "I am a normal computer player." << endl;
}

void Display::printDumbComp(){
    cout << "I am a dumb computer player."<< endl;
}

void Display::printSmartComp(){
    cout << "I am a smart computer player." << endl;
}

bool Display::getRandCompOptions(){
    string cmd;

    while(true){
        cout << "If you want a random selection of computer players, enter yes, if not enter no." << endl;
        if(cin >> cmd && (cmd == YES ||cmd == NO)){
            if(cmd == YES){
                return true;
            } else{
                return false;
            }
        }

        cout << "Invalid answer." << endl;
    }
}

bool Display::getCompChoiceOp(){
    string cmd;
    
    while(true){
        cout << "If you want a wider selection of computer players, enter yes, if not enter no." << endl;
        
        if(cin >> cmd && (cmd == YES ||cmd == NO)){
            if(cmd == YES){
                return true;
            } else{
                return false;
            }
        }

        cout << "Invalid answer." << endl;
    }
}

bool Display::getRagequitOp(){
    string cmd;
    
    while(true){
        cout << "If you want human players to be able to choose which computer player is going to take over when they ragequit, enter yes, if not enter no." << endl;

        if(cin >> cmd && (cmd == YES ||cmd == NO)){
            if(cmd == YES){
                cout << endl;
                return true;
            } else{
                cout << endl;
                return false;
            }
        }

        cout << "Invalid answser." << endl;
    }
}

string Display::invitePlayer(int name){
    string ret;
    cout << "Is Player" << name << " a human (h) or a computer (c)?" << endl;
    cin >> ret;
    return ret;
}

string Display::inviteComp(){
    string ret;
    cout << "Do you want a dumb computer (d), a normal computer (n), or a smart computer (s)?" << endl;
    cin >> ret;
    return ret;
}

string Display::inviteCompRagequit(){
    string ret;
    cout << "Do you want a dumb computer (d), a normal computer (n), or a smart computer (s)?" << endl;
    cin >> ret;
    return ret;
}
