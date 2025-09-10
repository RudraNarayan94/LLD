#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////
// Prototype Class: Character
///////////////////////////////////////////////

class Character
{
private:
  string name;
  int health;
  int attackPower;
  int level;

public:
  // Constructor
  Character(string name, int health, int attackPower, int level)
      : name(name), health(health), attackPower(attackPower), level(level) {}

  // Clone method (Prototype Pattern)
  Character *clone() const
  {
    return new Character(*this); // Shallow copy using copy constructor
  }

  // Show character info
  void showCharacterInfo() const
  {
    cout << "Character [Name=" << name
         << ", Health=" << health
         << ", AttackPower=" << attackPower
         << ", Level=" << level
         << "]" << endl;
  }

  // Getters (needed for factory to access private members)
  string getName() const { return name; }
  int getHealth() const { return health; }
  int getAttackPower() const { return attackPower; }
  int getLevel() const { return level; }
};

///////////////////////////////////////////////
// Factory using Prototype
///////////////////////////////////////////////

class CharacterFactory
{
private:
  Character *prototypeCharacter; // Prototype object

public:
  // Constructor to create default prototype
  CharacterFactory()
  {
    prototypeCharacter = new Character("DefaultName", 100, 50, 1);
  }

  // Destructor
  ~CharacterFactory()
  {
    delete prototypeCharacter;
  }

  // Create character with new name
  Character *createCharacterWithNewName(const string &name)
  {
    Character *cloned = prototypeCharacter->clone();
    return new Character(name, cloned->getHealth(),
                         cloned->getAttackPower(), cloned->getLevel());
  }

  // Create character with new level
  Character *createCharacterWithNewLevel(int level)
  {
    Character *cloned = prototypeCharacter->clone();
    return new Character(cloned->getName(), cloned->getHealth(),
                         cloned->getAttackPower(), level);
  }

  // Create character with new attack power
  Character *createCharacterWithNewAttackPower(int attackPower)
  {
    Character *cloned = prototypeCharacter->clone();
    return new Character(cloned->getName(), cloned->getHealth(),
                         attackPower, cloned->getLevel());
  }
};

///////////////////////////////////////////////
// Main function
///////////////////////////////////////////////

int main()
{
  cout << "Prototype Pattern in C++" << endl;

  CharacterFactory factory;

  // Create a new character with a different name
  Character *hero = factory.createCharacterWithNewName("Hero");
  hero->showCharacterInfo();

  // Create another character with a different level
  Character *boss = factory.createCharacterWithNewLevel(10);
  boss->showCharacterInfo();

  // Create another character with a different attack power
  Character *warrior = factory.createCharacterWithNewAttackPower(80);
  warrior->showCharacterInfo();

  // Clean up
  delete hero;
  delete boss;
  delete warrior;

  return 0;
}
