#include <iostream>
#include <sstream>
#include <string>
#include "Sword.h"
#include "Mage.h"
#include "Brute.h"
#include "Ninja.h"
#include "Soldier.h"
#include "ShadowBone.h"
using namespace std;

int main(){

    //sword class
    Sword mySword("Excalibur", 50.0);
    std::string swordInfo = mySword.printSword();
    std::cout << "Initial Sword Info:\n" << swordInfo << std::endl;

    // Calculate and print the damage
    int playerStrength = 30; // Assuming player strength
    double damage = mySword.damage(playerStrength);
    std::cout << "Damage Dealt: " << damage << std::endl;

    // Copy constructor test
    Sword copiedSword = mySword; // Using the copy constructor
    std::string copiedSwordInfo = copiedSword.printSword();
    std::cout << "Copied Sword Info:\n" << copiedSwordInfo << std::endl;


    //shadowbone
std::cout<<" ShadowBone \n";
     // Create a ShadowBone object
    ShadowBone myShadowBone("Dark Blade", 60.0, 5.0);

    // Print the sword details (including magicMultiplier)
    std::string sword_bone = myShadowBone.printSword();
    std::cout << "Initial ShadowBone Info:\n" << sword_bone << std::endl;


    // Print the updated ShadowBone details (including magicMultiplier)
    sword_bone = myShadowBone.printSword();
    std::cout << "Updated ShadowBone Info:\n" << sword_bone << std::endl;

    // Calculate and print the damage (including magicMultiplier)
    int playerLevel = 10; // Assuming player level
    double damage1 = myShadowBone.damage(playerLevel);
    std::cout << "Damage Dealt: " << damage1 << std::endl;

    // Copy constructor test (including magicMultiplier)
    ShadowBone copiedShadowBone = myShadowBone; // Using the copy constructor
    std::string copiedSwordInfo1 = copiedShadowBone.printSword();
    std::cout << "Copied ShadowBone Info:\n" << copiedSwordInfo1 << std::endl;

// Create a Sword object
    Sword* mySword1= new Sword("Excalibur", 50.0);

    // Create a Soldier object
    Soldier mySoldier("John", 100.0, 50.0);


    // // Arm the soldier with the sword
     mySoldier.arm(mySword1);

    // // Print the soldier details
    
     std::cout << "Initial Soldier Info:\n" <<mySoldier.printSoldier()<< std::endl;

    // Check if the soldier is alive
    bool isAlive = mySoldier.isAlive();
    std::cout << "Is Soldier Alive? " << (isAlive ? "Yes" : "No") << std::endl;

    // Take some damage
    double damage2 = 30.0;
    bool damageTaken = mySoldier.takeDamage(damage2);
    std::cout << "Damage Taken: " << damage2 << std::endl;

    // // Print the updated soldier details
    std::cout << "Updated Soldier Info:\n" << mySoldier.printSoldier() << std::endl;

    // // Check if the soldier is alive after taking damage
     isAlive = mySoldier.isAlive();
     std::cout << "Is Soldier Alive? " << (isAlive ? "Yes" : "No") << std::endl;

    // Copy constructor test
    Soldier copiedSoldier("taku", 70, 30); 
    copiedSoldier= mySoldier; 
    std::cout << "Copied Soldier Info:\n"<< copiedSoldier.printSoldier() << std::endl;


// Mage a("taku",100,100);
// Mage b("tino",90,78);
// a=b;

Brute a("taku",100,100);
Brute b("john",75,41);
a=b;

Ninja c("taku",74,20);
Ninja d("ez",56,89);
c=d;


   //Create a Sword object
    Sword* sword7= new Sword("Excalibur", 50.0);

    // Create a Soldier object
    Soldier soldier10("John", 100.0, 50.0);

    // // Arm the soldier with the sword
     soldier10.arm(sword7);

    // // Create another Soldier
     Soldier soldier20("Alice", 90.0, 45.0);

    // // Copy the data from soldier1 to soldier2
    soldier20 = soldier10;

    // Print the details of both soldiers
    std::cout << "Soldier 1:\n" << soldier10.printSoldier() << std::endl;
    std::cout << "Soldier 2:\n" << soldier20.printSoldier() << std::endl;
  // Create a soldier
    Soldier soldier11("John", 100.0, 50.0);

    // Display soldier information
    std::cout << "Soldier Info:\n" << soldier11.printSoldier() << std::endl;

    // Create a sword and arm the soldier with it
    Sword *sword1 = new Sword("Legendary Sword", 30.0);
    soldier11.arm(sword1);

    // Display updated soldier information
    std::cout << "Soldier Info (after arming with a sword):\n" << soldier11.printSoldier() << std::endl;

    // Test takeDamage method
    bool damageResult = soldier11.takeDamage(20.0);
    std::cout << "Take damage result: " << (damageResult ? "Alive" : "Dead") << std::endl;

    // Test isAlive method
    bool alive = soldier11.isAlive();
    std::cout << "Is alive: " << (alive ? "Yes" : "No") << std::endl;

    // Create a brute
    Brute brute("Hulk", 150.0, 70.0);

    // Display brute information
    std::cout << "\nBrute Info:\n" << brute.printSoldier() << std::endl;

    // Create a sword and arm the brute with it
    Sword*  bruteSword = new Sword("Mighty Sword", 40.0);
    brute.arm(bruteSword);

    // Display updated brute information
    std::cout << "Brute Info (after arming with a sword):\n" << brute.printSoldier() << std::endl;

    // Test the attack method (you can also create another brute to attack)
    bool bruteAttackResult = brute.attack(&brute);
    std::cout << "Brute's Attack result: " << (bruteAttackResult ? "Success" : "Failed") << std::endl;

    // // Create a mage
    Mage mage("Gandalf", 120.0, 60.0);

   
    ShadowBone *shadowBone = new ShadowBone("Dark Staff", 35.0, 0.5);
     mage.armShadow(shadowBone);

  

    // // Display updated mage information
    //cause of seg fault
     std::cout << "Mage Info (after arming with a ShadowBone):\n" << mage.printSoldier() << std::endl;
   delete shadowBone;
     shadowBone =  NULL;
    // // Test the attack method (you can also create another mage to attack)
    bool mageAttackResult = mage.attack(&mage);
    std::cout << "Mage's Attack result: " << (mageAttackResult ? "Success" : "Failed") << std::endl;

    
// Create a Sword object
    Sword* sword11 = new Sword("Excalibur", 50.0);

    // Create a Soldier object
    Soldier soldier1("John", 100.0, 50.0);

    // Arm the soldier with the sword
    soldier1.arm(sword11);

    // Create another Soldier
    Soldier soldier2("Alice", 90.0, 45.0);

    // Copy the data from soldier1 to soldier2
    soldier2 = soldier1;

    // Print the details of both soldiers
    std::cout << "Soldier 1:\n" << soldier1.printSoldier() << std::endl;
    std::cout << "Soldier 2:\n" << soldier2.printSoldier() << std::endl;

    // Create a Brute
    Brute brute1("Hulk", 150.0, 70.0);

    // Create a Brute sword and arm the brute with it
    Sword* bruteSword1 = new Sword("Mighty Sword", 40.0);
    brute1.arm(bruteSword1);

    // Test the Brute's attack method
    bool bruteAttackResult1 = brute1.attack(&brute1);
    std::cout << "Brute's Self-Attack result: " << (bruteAttackResult1 ? "Success" : "Failed") << std::endl;

    // Create a Mage
    Mage mage1("Gandalf", 120.0, 60.0);

    // Create a ShadowBone and arm the mage with it
    ShadowBone* shadowBone1 = new ShadowBone("Dark Staff", 35.0, 0.5);
    mage1.armShadow(shadowBone1);

    // Test the Mage's attack method
    bool mageAttackResult1 = mage1.attack(&mage1);
    std::cout << "Mage's Self-Attack result: " << (mageAttackResult1 ? "Success" : "Failed") << std::endl;

    delete shadowBone;
    delete shadowBone1;
    shadowBone1=NULL;
    shadowBone = NULL;
  
      // Create a Ninja object
    Ninja* ninja1 = new Ninja("Naruto", 100.0, 60.0);
    bool damageResult33 = ninja1->takeDamage(20.0); // Ninja takes damage
    std::cout << "Take damage result: " << (damageResult33 ? "Alive" : "Dead") << std::endl;

    // Test the isAlive method
    bool alive23 = ninja1->isAlive();
    std::cout << "Is alive: " << (alive23 ? "Yes" : "No") << std::endl;

    // Create another Ninja object
    Ninja ninja2("Sasuke", 90.0, 55.0);
    ninja2 = *ninja1;

    // Test the Ninja's attack method
    bool attackResult = ninja1->attack(&ninja2); // Ninja1 attacks Ninja2
    std::cout << "Ninja1's Attack result on Ninja2: " << (attackResult ? "Success" : "Failed") << std::endl;
  delete ninja1;
ninja1 = NULL;


 // Create a Mage object
    Mage mage12("Gandalf", 120.0, 60.0);

    // Create a ShadowBone object
    ShadowBone* shadowBone45 = new ShadowBone("Dark Staff", 35.0, 0.5);

    // Arm the Mage with the ShadowBone
    mage12.armShadow(shadowBone45);

    // Test the printSoldier method
    std::string mageInfo = mage12.printSoldier();
    std::cout << "Mage Info:\n" << mageInfo << std::endl;

    // Create another Mage object
    Mage mage23("Dumbledore", 110.0, 55.0);
  
    // Test the Mage's attack method
    bool attackResult67 = mage1.attack(&mage23); // Mage1 attacks Mage2
    std::cout << "Mage1's Attack result on Mage2: " << (attackResult67 ? "Success" : "Failed") << std::endl;
delete shadowBone45;
shadowBone45=NULL;
  

    return 0;}
