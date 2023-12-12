#include <iostream>
#include <sstream>
#include "Ninja.h"

using namespace std;


Ninja::Ninja(std::string name, double health, double strength)
    : Soldier(name, health, strength), moveCount(0) {}


bool Ninja::takeDamage(double damage) {
    if (moveCount == 2) {
        moveCount = 0; 
        return false;  
    }
        moveCount++; 
    

    return Soldier::takeDamage(damage);
    }


Ninja& Ninja::operator=(const Ninja& ninja) {
    if (this != &ninja   && &ninja != NULL && this != NULL) {

        Soldier::operator=(ninja);
        moveCount = ninja.moveCount;
        return *this;
    }
    return *this;
}


bool Ninja::isAlive() const {
    return Soldier::isAlive();
    
}


bool Ninja::attack(Brute* brute) {
    if (sword ==NULL || brute == NULL || !brute->isAlive()) {
        return false;  
    }

    

      if( brute->takeDamage( sword->damage(strength))){
        return true; }
    
    return false;  
}


bool Ninja::attack(Mage* mage) {
   //!isAlive() ||
    if (this == NULL || this->sword == NULL || mage == NULL || !mage->isAlive()) {
        return false;  
    }

    if (this->sword != NULL){
      if( mage->takeDamage( Soldier:: sword->damage(strength))){
        return true; 
    }
    return false;
    }

    return false; 
}


bool Ninja::attack(Ninja* ninja) {
    if(this == NULL || this->sword == NULL || ninja == NULL || !ninja->isAlive()) {
        return false; 
    }

      
   if( ninja->takeDamage( Soldier:: sword->damage(strength))){
        return true; 
    }

    return false; 
}
