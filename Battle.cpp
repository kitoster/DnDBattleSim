#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"

Battle::Battle(const Character& player) : playerCharacter(player), difficulty(0) {
    // Initialize other attributes here
    battleScenes = {
            "You're standing on top of a misty mountain.",
            "You're on a deserted beach with crashing waves.",
            "You find yourself in a dark and eerie forest.",
            "The battle takes place in a mystical, ancient temple.",
            "You're surrounded by lava in a fiery cavern."
        };
}

void Battle::setDifficulty(int diff) {
    difficulty = diff;
}

int Battle::getDifficulty() const {
    return difficulty;
}

void Battle::chooseDifficulty() {
    char difficultyChoice;
    std::cout << "Would you like " << playerCharacter.getName() << " to play on easy, medium, or hard? E/M/H" << std::endl;
    std::cin >> difficultyChoice;
    
    // Handle difficulty choice here
    switch (difficultyChoice) {
        case 'E': {
            std::cout << "Great! " << playerCharacter.getName() << " will be playing on Easy mode." << std::endl;
            setDifficulty(1);
            playerCharacter.setHealth(100);
            break;
        }
        case 'M': {
            std::cout << "Great! " << playerCharacter.getName() << " will be playing on Medium mode." << std::endl;
            setDifficulty(2);
            playerCharacter.setHealth(75);
            break;
        }
        case 'H': {
            std::cout << "Great! " << playerCharacter.getName() << " will be playing on Hard mode." << std::endl;
            setDifficulty(3);
            playerCharacter.setHealth(50);
            break;
        }
        default: {
            std::cout << "Invalid difficulty choice. Using Medium by default." << std::endl;
            setDifficulty(2);
            playerCharacter.setHealth(75);
        }
    }
}

void Battle::generateScene() {
    // Use a random number generator to select a scene
    int randomIndex = rand() % battleScenes.size();
    std::string scene = battleScenes[randomIndex];
    
    // Output the selected scene to the console
    std::cout << "Scene: " << scene << std::endl;
}

/*When we suggest possible attacks we could potentially just retrieve
 character.dndclass and say if dndclass is = 1 then they're an example
 class and can cast witch bolt and thingy 
 
 
 */

