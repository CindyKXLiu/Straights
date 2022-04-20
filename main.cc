#include <string>
#include <iostream>

#include "game.h"
using namespace std;

const unsigned DEFAULT_SEED = std::chrono::system_clock::now().time_since_epoch().count();
const string ENABLE_BONUS = "-enableBonus";

int main(int argv, char **argc){
    int seed = DEFAULT_SEED;
    bool enableBonus = false;
    bool converted = false;

    for(int i = 0; i < argv; ++i){
        if(argc[i] == ENABLE_BONUS){
            enableBonus = true;
        }
        else{
            try{
                seed = stoi(argc[i]);
                converted = true;
            } catch(...){}
        }
    }

    if(!converted){
        cout << "Could not convert seed. Using default seed: " << seed << endl << endl;
    }
    else{
        cout << "Seed used: " << seed << endl << endl;
    }

    // play game
    Game g{seed, enableBonus};
    g.play();
}
