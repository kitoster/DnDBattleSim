//Created by Kit Oster, September 2023
#include <iostream>
#include "Character.hpp"
#include "Battle.hpp"

//To do list: Character.display() shows the class as the numeric value


std::vector<Character> characters; //CHARACTER VECTOR

int main() {
    char choice;
    Character character("", 0, "", 0, 0, 0, 0, 0, 0, 0, 0);
    
    while(true) {
        std::cout << "Character Management and Battle Simulator. What is Project Scope\n";
        std::cout << "1. Add a new character\n";
        std::cout << "2. View existing character\n";
        std::cout << "3. Update a character\n";
        std::cout << "4. Battle Simulator\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case '1': {
                Character character("", 0, "", 0, 0, 0, 0, 0, 0, 0, 0);

                std::cin.ignore(); // Consume the newline character
                std::cout << "Enter character name: ";
                std::string newName;
                std::getline(std::cin, newName);
                character.setName(newName);
                std::cout << "Enter character age: ";
                int newAge;
                std::cin >> newAge;
                character.setAge(newAge);
                
                //Enter description
                std::cin.ignore(); // Consume the newline character
                std::cout << "Enter character description: ";
                std::string newDescription;
                std::getline(std::cin, newDescription);
                character.setDescription(newDescription);
                
                //Enter Class
                std::cout << "Enter your character's class. Options are listed below.";
                std::cout << "\n 1. Barbarian \n 2. Bard \n 3. Cleric \n 4. Druid \n 5. Fighter \n 6. Monk \n 7. Paladin \n 8. Ranger \n 9. Rogue \n 10. Sorcerer \n 11. Warlock \n 12. Wizard \n";
                int newDnD;
                std::cin >> newDnD;
                character.setDnDClass(newDnD);
                
                
                // Option to manually enter or generate stats
                std::cout << "Do you want to enter stats manually (M) or generate them (G)? ";
                char statChoice;
                std::cin >> statChoice;
                
                if (statChoice == 'M' || statChoice == 'm') {
                    
                    character.inputAttributes();
                    
                } else if (statChoice == 'G' || statChoice == 'g') {

                    //Assign Stats
                    character.setStrength(character.rollDnDStat());
                    character.setDexterity(character.rollDnDStat());
                    character.setConstitution(character.rollDnDStat());
                    character.setIntelligence(character.rollDnDStat());
                    character.setWisdom(character.rollDnDStat());
                    character.setCharisma(character.rollDnDStat());
                    
                    //Call character display function to show all entered attributes
                    character.display();
                    
                } else {
                    std::cout << "Invalid choice. Using manual entry by default.\n";
                    character.inputAttributes();
                }
                characters.push_back(character); //CHARACTER VECTOR

                break;
            }
            case '2': {
                if (characters.empty()) {
                    std::cout << "No characters exist." << std::endl;
                } else {
                    std::cout << "Existing characters:\n";
                    for (const Character& character : characters) {
                        character.display();
                        std::cout << "-------------------" << std::endl;
                    }
                }
                break;
            }
            case '3': {
                
                std::cin.ignore(); // Consume the newline character
                std::cout << "Enter the name of the character you want to update: ";
                std::string charNameToUpdate;
                std::getline(std::cin, charNameToUpdate);
                bool found = false;

                /*Iterates through characters vector,checks each character's name, and updates the attributes for the one that matches the entered name. It sets the found flag to true when the character is found.*/
                    for (Character& charac : characters) {
                        if (charac.getName() == charNameToUpdate) {
                            found = true;
                            std::cout << "Character found. Update the character's attributes.\n";
                            charac.updateAttributes();
                            break; // Exit the loop after finding the character
                        }
                    }

                    if (!found) {
                        std::cout << "Character not found with the entered name.\n";
                    }
                break;
            }
            case '4': {
                std::cout << "Entering battle!\n";
                
                // Check if there are characters available
                if (characters.empty()) {
                    std::cout << "No characters available for battle." << std::endl;
                } else {
                    // Consume any remaining newline characters
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    std::cout << "Enter the name of the character to enter into battle: ";
                    std::string characterName;
                    std::getline(std::cin, characterName);
                    
                    bool found = false;
                    Character selectedCharacter;
                    
                    for (const Character& character : characters) {
                        if (character.getName() == characterName) {
                            found = true;
                            selectedCharacter = character;
                            std::cout << "Character found: " << characterName << std::endl;
                            break; // Exit the loop after finding the character
                        }
                    }
                    
                    if (found) {
                        // Create a Battle instance using the selected character
                        Battle battle(selectedCharacter);
                        // Call function to choose difficulty
                        battle.chooseDifficulty();
                        // Generate a scene
                        battle.generateScene();

                        
                        
                        // Start the battle here
                        // Think of this as a bunch of function calls that will generate attacks rather than a story.
                        // Should not take much code.
                        
                        
                    } else {
                        std::cout << "Character not found with the entered name." << std::endl;
                    }
                }
                break;
            }
            case '5': {
                std::cout << "Exiting the program.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
        
        return 0;
    }
