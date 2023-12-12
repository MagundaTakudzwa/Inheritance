#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "ShadowBone.h"
// #include "Sword.h"
using namespace std;


ShadowBone::ShadowBone(std::string name, double attack, double magicMultiplier)
    : Sword(name, attack), magicMultiplier(magicMultiplier) {
}


ShadowBone::ShadowBone(const ShadowBone& shadowBone)
    : Sword(shadowBone), magicMultiplier(shadowBone.magicMultiplier)  {}



double ShadowBone::damage(int playerLevel) {
    
    double baseDamage = attack + (attack * ((playerLevel * 0.1 + level * 0.2) + magicMultiplier));

    return baseDamage;
}

std::string ShadowBone::printSword() {
    
    std::string swordInfo = Sword::printSword();
    std::ostringstream ss;
    ss << "Magic Multiplier: " << magicMultiplier;
    swordInfo +=  ss.str();

    return swordInfo;
}