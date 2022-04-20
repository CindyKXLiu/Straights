#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include "player.h"
#include "deck.h"

using namespace std;

class Display{
    const static int NUM_OF_SUITE = 4;
    const static string YES;
    const static string NO;
    const unordered_map<int, char> NUM_TO_SUITE {{1, 'C'}, {2, 'D'}, {3, 'H'}, {4, 'S'}};
    const unordered_map<int, char> NUM_TO_RANK {{1, 'A'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, 
                                             {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'T'}, 
                                             {11, 'J'}, {12, 'Q'}, {13, 'K'}};
    const unordered_map<char, int> SUITE_TO_NUM {{'C', 1}, {'D', 2}, {'H', 3}, {'S', 4}};
    const unordered_map<char, int> RANK_TO_NUM {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, 
                                             {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, 
                                             {'J', 11}, {'Q', 12}, {'K', 13}};
    const unordered_map<int, string> TABLE_LOOKUP {{0, "Clubs:"}, {1, "Diamonds:"}, {2, "Hearts:"}, {3, "Spades:"}};
    
    void print (Card *card);
    void print (Card card);
    void printSuite(set<int> &suite);

    public:
    void printInvalidInvite();
    void printNewRound(int name);
    void printEndRound(vector<Player> &players);
    void printWinners(vector<Player *> &winners);
    void printTable(set<int> table[NUM_OF_SUITE]);
    void printHand(Player &player);
    void printLegalMoves(vector<Card *> &legalPlays);
    void printPlay(Player &player, Card *card);
    void printDiscarded(Player &player, Card *card);
    void printDeck(Deck &deck);
    void printRagequit(Player &player);
    void printNormalComp();
    void printDumbComp();
    void printSmartComp();
    bool getRandCompOptions();
    bool getCompChoiceOp();
    bool getRagequitOp();
    string invitePlayer(int name);
    string inviteComp();
    string inviteCompRagequit();
};

#endif
