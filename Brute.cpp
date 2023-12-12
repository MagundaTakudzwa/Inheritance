#include "Brute.h"
#include <sstream>
#include "Mage.h"

#include "Ninja.h"
#include "Soldier.h"
// Constructor
class Mage;
class Ninja;

Brute::Brute(std::string name, double health, double strength)
    : Soldier(name, health, strength), rageMeter(0.0) {
    }


std::string Brute::printSoldier() {
    std::stringstream ss;
    ss << Soldier::printSoldier();
    ss << "Rage meter: " << rageMeter;
    return ss.str();
}


Brute& Brute::operator=(const Brute& brute) {

    if (this != &brute && this != NULL) {
        Soldier::operator=(brute);
        // brute-specific attributes
        rageMeter = brute.rageMeter;
    }

    // if(brute.sword != NULL){
    //     this->sword = new Sword(*brute.sword);
    // }

    return *this;
}

bool Brute::attack(Brute* brute) {
  
     if (this->sword ==NULL || brute == NULL || !brute->isAlive()) {
        return false;  
    }

     double attackStrength=  strength * 2 + strength * (rageMeter-10)*0.1; 
    if(rageMeter >= 10 ){
       brute->takeDamage(sword->damage(attackStrength));
    }else{
        attackStrength = strength*0.5;
        brute->takeDamage(sword->damage(attackStrength));

    }

   if(brute->isAlive()){
    rageMeter++;
    return false;
   }else{
    rageMeter = 0.0;
    return true;
   }
   return brute->isAlive();
}


bool Brute::attack(Mage* mage) {
    
        if (this->sword ==NULL ||  mage == NULL || !mage->isAlive()) {
        return false;  
    }
 
     double attackStrength=  strength * 2 + strength * (rageMeter-10)*0.1;
    if(rageMeter >= 10 ){
       mage->takeDamage(sword->damage(attackStrength));
    }else{
        attackStrength = strength;
        mage->takeDamage(sword->damage(strength));
    }
    
if(mage->isAlive()){
    rageMeter++;
    return false;
}else{
    rageMeter =0.0;
    return true;
}
    return mage->isAlive();
}


bool Brute::attack(Ninja* ninja) {
   
 if ( this->sword == NULL || ninja == NULL || !ninja->isAlive()) {
        return false; 
    }
      double attackStrength=  strength * 2 + strength * (rageMeter-10)*0.1;
    if(rageMeter >= 10 ){
        ninja->takeDamage(sword->damage(attackStrength));
        
    }else{
        ninja->takeDamage(sword->damage(strength));
    }
    
      
  if(ninja->isAlive()){
    rageMeter++;
    return false; 
  }else{
    rageMeter=0.0;
    return true;
  }
  return ninja->isAlive();
}



