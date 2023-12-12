#ifndef BRUTE_H
#define BRUTE_H
#include "Mage.h"
#include "Ninja.h"
#include "Soldier.h"
class Brute: public Soldier
{
private:
    double rageMeter;
public:
    Brute(std::string name, double health, double strength);
    std::string printSoldier();
    Brute& operator=(const Brute& brute);
    bool attack(class Brute* brute);
    bool attack(class Mage* mage);
    bool attack(class Ninja* ninja);
};
#endif
