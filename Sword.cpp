#include <cmath>
#include <sstream>
# include<iostream>
#include "Sword.h" 
using namespace std;
Sword::Sword(std::string name, double attack) 
: name(name), attack(attack), level(1), xp(0) {}


Sword::Sword(const Sword& sword)
 {

    if(&sword == NULL){
     return;
    }
    else{
        name = sword.name;
        attack = sword.attack;
        level = sword.level;
        xp = sword.xp;
    }
 }


int Sword::getXPForNextLevel() {

return pow(log(2*(level+1)),3);

}


void Sword::addXP(double damage) {
    xp += 0.10*damage;
  //*
    if (xp >= getXPForNextLevel()) {

        level++;
        xp = 0;
    }
  
}


std::string Sword::printSword() {  
    std::stringstream output;
    output << "Sword: " << name << "\n";
    output << "Attack: " << attack << "\n";
    output << "Level: " << level << "\n";
    output << "XP: " << xp << "\n";
    return output.str();
}

double Sword::damage(int playerStrength) {
       
    double damageDealt = attack + (attack * (playerStrength * 0.1 + level * 0.2));
    
    addXP(damageDealt);
    
    return damageDealt;
}
