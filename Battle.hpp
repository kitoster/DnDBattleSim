
#ifndef Battle_hpp
#define Battle_hpp
#include "Character.hpp"
#include <stdio.h>

class Battle {
private:
    Character playerCharacter;
    int difficulty; // New member variable for difficulty
    std::vector<std::string> battleScenes; // Store battle scenes


public:
    Battle(const Character& player);

    void setDifficulty(int diff);
    int getDifficulty() const;
    void chooseDifficulty();
    void generateScene();

    // Add methods to simulate the battle using the playerCharacter
    // You can access playerCharacter's attributes like health and stats
};

#endif /* Battle_hpp */
