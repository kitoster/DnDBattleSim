

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string>

class Character {
private:
    std::string name;
    int age;
    std::string description;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int health;
    int DnDClass;

public:
    
    Character(); //default constructor
    Character(const std::string& n, int a, const std::string& desc, int str, int dex, int con, int intel, int wis, int cha, int h, int dnd);
    ~Character();
    

    // Getter methods
    std::string getName() const;
    int getAge() const;
    std::string getDescription() const;
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getIntelligence() const;
    int getWisdom() const;
    int getCharisma() const;
    int getHealth() const;
    int getDnDClass() const;

    // Setter methods
    void setName(const std::string& n);
    void setAge(int a);
    void setDescription(const std::string& desc);
    void setStrength(int str);
    void setDexterity(int dex);
    void setConstitution(int con);
    void setIntelligence(int intel);
    void setWisdom(int wis);
    void setCharisma(int cha);
    void setHealth(int h);
    void setDnDClass(int dnd);

    // Other member functions
    int rollDnDStat();
    void display() const;
    void inputAttributes();
    void updateAttributes();

};

#endif

