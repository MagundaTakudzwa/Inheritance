#include <iostream>
#include <sstream>
#include "Soldier.h"
//class Sword;
// #include "Sword.h"
using namespace std;
int Soldier::aliveSoldiers = 0;
int Soldier::deadSoldiers =0;
Soldier::Soldier(std::string name, double health, double strength)
    : name(name), health(health), strength(strength),sword(NULL)
{    
    aliveSoldiers++;
}

Soldier::~Soldier() {
    if (sword != NULL) {
        delete sword; 
        sword = NULL;
    }
   
}


std::string Soldier::printSoldier() {
    std::stringstream ss;
    ss << "Name: " << name << "\n";
    ss << "Health: " << health << "\n";
    ss << "Strength: " << strength << "\n";

    if(sword != NULL){
        ss<<sword->printSword();
    }
    return ss.str();
}


void Soldier::arm(Sword* sword) {
    if(this->sword == sword || sword == NULL){
        return;
    }
    if(this->sword != NULL){
        delete this->sword;
    }
    this->sword = sword;
}


bool Soldier::takeDamage(double damage) {
    if(!isAlive()){
        return false;
    }
    if (damage < 0) {
        return false;  
    }

    if (health <= 0) {
        return false;  
    }

    health -= damage;

    if (health < 0) {
        health = 0;
    }

    if (health == 0 ) {
        aliveSoldiers--;
        deadSoldiers++;
        return true;  
    }

    return false;
}


bool Soldier::isAlive() const {
    return health > 0;
}

Soldier& Soldier::operator=(const Soldier& soldier) {
    if (this != &soldier && this != NULL) {
        // Release the current sword object
        if (this->sword != NULL) {
            delete this->sword;
            this->sword = NULL;
        }

        // Copy the other soldier's data
        this->name = soldier.name;
        this->health = soldier.health;
        this->strength = soldier.strength;

        // Copy the sword object if it exists
        if (soldier.sword != NULL) {
            this->sword = new Sword(*soldier.sword);
        }else{
            this->sword = NULL;
        }
    }
    return *this;
}


// Soldier& Soldier::operator=(const Soldier& soldier) {

//     if (this != &soldier   &&  &soldier != NULL) {
       
//         this->name = soldier.name;
//         this->health = soldier.health;
//         this->strength = soldier.strength;

        
//         if (this->sword != NULL) {
//             delete this->sword;
//             //sword = NULL;
//             this->sword = soldier.sword;
//         }
            
//         if (soldier.sword == NULL) {
//             this->sword= NULL;
            
//         }
//         else
//     {this->sword=new Sword(*soldier.sword);}
    
//     }
//     return *this;
// }

