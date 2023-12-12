#ifndef NINJA_H
#define NINJA_H
#include "Mage.h"
#include "Brute.h"
#include "Mage.h" 
#include "Soldier.h"
class Brute;
class Mage;
class Ninja: private Soldier
{ private:
int moveCount;

public:
Ninja(std::string name, double health, double strength);
bool takeDamage( double damage);
Ninja& operator=(const Ninja& ninja);
bool isAlive()const;
bool attack(class Brute* brute);
bool attack(class Mage* mage);
bool attack(class Ninja* ninja);

};
#endif