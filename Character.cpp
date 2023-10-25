//So what it looks like we can do is turn the chooseCharacter 

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Battle.hpp"
#include <cstdlib>
#include <ctime>

/* Default constructor implementation
   Provides a  way to create a 'Character' object without specifying initial values.
 */
Character::Character() : name(""), age(0), description(""), strength(0), dexterity(0), constitution(0), intelligence(0), wisdom(0), charisma(0), health(0), DnDClass(0) {}


Character::Character(const std::string& n, int a, const std::string& desc, int str, int dex, int con, int intel, int wis, int cha, int h, int dnd)
    : name(n), age(a), description(desc), strength(str), dexterity(dex), constitution(con), intelligence(intel), wisdom(wis), charisma(cha), health(h), DnDClass(dnd) {
    // Constructor implementation here
}

// Implement destructor if needed
Character::~Character() {
    // Destructor implementation here
}

// Implement getter methods
std::string Character::getName() const {
    return name;
}

int Character::getAge() const {
    return age;
}

std::string Character::getDescription() const {
    return description;
}

int Character::getStrength() const {
    return strength;
}

int Character::getDexterity() const {
    return dexterity;
}

int Character::getConstitution() const {
    return constitution;
}

int Character::getIntelligence() const {
    return intelligence;
}

int Character::getWisdom() const {
    return wisdom;
}

int Character::getCharisma() const {
    return charisma;
}

int Character::getHealth() const {
    return health;
}

int Character::getDnDClass() const {
    return DnDClass;
}

// Implement setter methods
void Character::setName(const std::string& n) {
    name = n;
}

void Character::setAge(int a) {
    age = a;
}

void Character::setDescription(const std::string& desc) {
    description = desc;
}

void Character::setStrength(int str) {
    strength = str;
}

void Character::setDexterity(int dex) {
    dexterity = dex;
}

void Character::setConstitution(int con) {
    constitution = con;
}

void Character::setIntelligence(int intel) {
    intelligence = intel;
}

void Character::setWisdom(int wis) {
    wisdom = wis;
}

void Character::setCharisma(int cha) {
    charisma = cha;
}

void Character::setHealth(int h) {
    health = h;
}

void Character::setDnDClass(int dnd) {
    DnDClass = dnd;
}

// Implement other member functions
int Character::rollDnDStat() {
       int rolls[4];
    
    for (int i = 0; i < 4; i++) {
        rolls[i] = rand() % 6 + 1; // Roll a 6-sided die
    }

    // Sort the rolls in descending order
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (rolls[j] < rolls[j + 1]) {
                int temp = rolls[j];
                rolls[j] = rolls[j + 1];
                rolls[j + 1] = temp;
            }
        }
    }

    // Sum the three highest rolls
    int sum = rolls[0] + rolls[1] + rolls[2];

    return sum;
}


void Character::display() const {
    if (name.empty()) {
           std::cout << "No character exists." << std::endl;
       } else {
           std::cout << "------------";
           std::cout << "Character Details:" << std::endl;
           std::cout << "Name: " << name << std::endl;
           std::cout << "Age: " << age << std::endl;
           std::cout << "Description: " << description << std::endl;
           std::cout << "Class: " << DnDClass << std::endl;
           std::cout << "Stats: ";
           std::cout << "Strength: " << strength << std::endl;
           std::cout << "Dexterity: " << dexterity << std::endl;
           std::cout << "Constitution: " << constitution << std::endl;
           std::cout << "Intelligence: " << intelligence << std::endl;
           std::cout << "Wisdom: " << wisdom << std::endl;
           std::cout << "Charisma: " << charisma << std::endl;
           std::cout << "------------";
       }
}

void Character::inputAttributes() {
    std::cout << "Enter strength: ";
    int newStrength;
    std::cin >> newStrength;
    setStrength(newStrength);
    
    std::cout << "Enter dexterity: ";
    int newDexterity;
    std::cin >> newDexterity;
    setDexterity(newDexterity);
    
    std::cout << "Enter constitution: ";
    int newConstitution;
    std::cin >> newConstitution;
    setConstitution(newConstitution);
    
    std::cout << "Enter intelligence: ";
    int newIntelligence;
    std::cin >> newIntelligence;
    setIntelligence(newIntelligence);
    
    std::cout << "Enter wisdom: ";
    int newWisdom;
    std::cin >> newWisdom;
    setWisdom(newWisdom);
    
    std::cout << "Enter charisma: ";
    int newCharisma;
    std::cin >> newCharisma;
    setCharisma(newCharisma);
}

void Character::updateAttributes() {
    std::cout << "Enter updated name: ";
    std::string newName;
    std::getline(std::cin, newName);
    setName(newName);

    std::cout << "Enter updated age: ";
    int newAge;
    std::cin >> newAge;
    setAge(newAge);

    std::cin.ignore(); // Consume the newline character
    std::cout << "Enter updated description: ";
    std::string newDescription;
    std::getline(std::cin, newDescription);
    setDescription(newDescription);

    std::cout << "Enter updated strength: ";
    int newStrength;
    std::cin >> newStrength;
    setStrength(newStrength);

    std::cout << "Enter updated dexterity: ";
    int newDexterity;
    std::cin >> newDexterity;
    setDexterity(newDexterity);

    std::cout << "Enter updated constitution: ";
    int newConstitution;
    std::cin >> newConstitution;
    setConstitution(newConstitution);

    std::cout << "Enter updated intelligence: ";
    int newIntelligence;
    std::cin >> newIntelligence;
    setIntelligence(newIntelligence);

    std::cout << "Enter updated wisdom: ";
    int newWisdom;
    std::cin >> newWisdom;
    setWisdom(newWisdom);

    std::cout << "Enter updated charisma: ";
    int newCharisma;
    std::cin >> newCharisma;
    setCharisma(newCharisma);
}




