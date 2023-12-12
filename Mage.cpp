
#include <iostream>
#include <sstream>
#include "Mage.h"

using namespace std;
Mage::Mage(std::string name, double health, double strength)
    : Soldier(name, health, strength) {
        this->shadowBone=NULL;
        
    }


void Mage::armShadow(ShadowBone* shadowBone) {
    //
    if (this->shadowBone == shadowBone || shadowBone == NULL) {
        return;  
    }

    if (this->shadowBone != NULL) {
        delete this->shadowBone;  
        }

    this->shadowBone = shadowBone;
}


Mage& Mage::operator=(const Mage& mage) {
    
    if (this != &mage  && &mage != NULL && this != NULL ) {
        
        Soldier::operator=(mage);

        
        if (this->shadowBone != NULL  && mage.shadowBone != NULL) {

            delete this->shadowBone;
              this->shadowBone =  new ShadowBone(*mage.shadowBone);
        }
       
                
    }

    return *this;
}


std::string Mage::printSoldier() {
    std::stringstream ss;
    ss << Soldier::printSoldier();
    if (this->shadowBone != NULL) {
        ss << "ShadowBone: " << shadowBone->printSword() << "\n";
    }
    return ss.str();
}


bool Mage::attack(Brute* brute) {
    

    if (this->sword == NULL && this->shadowBone == NULL || brute == NULL || !brute->isAlive() ) {
        return false;  
    }

    if (shadowBone != NULL) {
        bool  attack;
        attack = brute->takeDamage(shadowBone->damage(strength)); 
        if (attack == true) {
            return true;  }
    }


    if (this->sword != NULL) {
      
    return brute->takeDamage(sword->damage(strength));
}

return false;
}

bool Mage::attack(Mage* mage) {
    if(this != NULL){
    if ( mage == NULL || !mage->isAlive() || this->sword == NULL) {
        return false;  
    }

    if (this->sword != NULL) {
        double damage = sword->damage(strength);  
        if (mage->takeDamage(damage)) {
            return true;  
        }
    }
    }

    return false; 
}


bool Mage::attack(Ninja* ninja) {
       

    if ( ninja == NULL || !ninja->isAlive() || this->shadowBone == NULL   && this->sword == NULL) {
        return false;  
    }

    if (this->shadowBone != NULL) {
        
        bool attack;
        attack= ninja->takeDamage(shadowBone->damage(strength)); 
        if (attack == true) {
            return true;  
        }
    }


    if (this->sword != NULL) {
      return ninja->takeDamage(sword->damage(strength));
    }
    return false;
}