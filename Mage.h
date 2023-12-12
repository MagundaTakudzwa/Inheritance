#ifndef MAGE_H
#define MAGE_H
#include "ShadowBone.h"
#include "Brute.h"
#include "Ninja.h"
#include "Soldier.h"
class Brute;
class Ninja;

class Mage:public Soldier
{
private:
    ShadowBone* shadowBone;
public:
    Mage(std::string name, double health, double strength);
    void armShadow( ShadowBone* shadowBone);
    Mage& operator=( const Mage& mage);
    std::string  printSoldier();
    bool attack(Brute* brute);
    bool attack(Mage* mage);
    bool attack(Ninja* ninja);

};

#endif
