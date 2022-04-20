#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include <unordered_map>

#include "display.h"
#include "player.h"
#include "deck.h"
#include "humanStrategy.h"
#include "computerStrategy.h"
#include "dumbComputerStrategy.h"
#include "smartComputerStrategy.h"

using namespace std;

class Game{
    const static int NUM_OF_PLAYERS = 4;
    const static int NUM_OF_SUITE = 4;
    const static int NUM_CARD_PER_PERSON = 13;
    const static int STARTING_SUITE = 4;
    const static int STARTING_RANK = 7;
    const static int CARD_NOT_FOUND = -1;
    const static int MIN_RANK = 1;
    const static int MAX_RANK = 13;
    const static int END_GAME_SCORE = 80;

    bool enableBonus = false;
    bool ragequitOp = false;
    bool randCompOp = false;
    bool compChoiceOp = false;

    HumanStrategy humanStrat{};
    ComputerStrategy compStrat{};
    DumbComputerStrategy dumbCompStrat{};
    SmartComputerStrategy smartCompStrat{};

    Deck deck;
    Display display;
    vector<Player> players;
    int seed;
    set<int> table[NUM_OF_SUITE];
    
    const unordered_map<string, Strategy *> STRAT_LOOKUP {{"c", &compStrat}, {"h", &humanStrat}};
    const unordered_map<string, Strategy *> COMP_STRAT_LOOKUP {{"d", &dumbCompStrat}, {"n", &compStrat}, {"s", &smartCompStrat}};
    const unordered_map<int, Strategy *> COMP_STRAT_LOOKUP_BY_INDEX {{0, &compStrat}, {1, &dumbCompStrat}, {2, &smartCompStrat}};
    void reset();
    void deal();
    int findStartingPlayer();
    void storeCurrentScore();
    vector<Player *> findWinners();
    bool endRound();
    bool endGame();
    bool tableEmpty();
    vector<Card *> getLegalMoves(vector<Card *> &hand);
    int findCard(int suite, int rank, vector<Card *> &hand);
    void ragequit(int player);

    void invitePlayers();
    void newRound();

    public:
    Game(unsigned seed, bool enableBonus);
    void play();
};

#endif
