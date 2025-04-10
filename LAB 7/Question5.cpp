#include <iostream>
using namespace std;

class Character {
protected:
    string characterID, name, weaponType;
    int level, healthPoints;

public:
    Character(string id, string n, int lvl, int hp, string weapon = "None")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    
    virtual void attack() {
        cout << name << " attacks with " << weaponType << "!" << endl;
    }
    
    virtual void defend() {
        cout << name << " defends against the attack!" << endl;
    }
    
    virtual void displayStatus() const {
        cout << "Character ID: " << characterID << "\nName: " << name 
             << "\nLevel: " << level << "\nHealth Points: " << healthPoints 
             << "\nWeapon: " << weaponType << "\n";
    }
    
    virtual ~Character() {}
};

class Warrior : public Character {
    int armorStrength, meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, int armor, int dmg, string weapon)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(dmg) {}
    
    void attack() override {
        cout << name << " slashes with " << weaponType << " causing " << meleeDamage << " damage!" << endl;
    }

};

class Mage : public Character {
    int manaPoints, spellPower;
public:
    Mage(string id, string n, int lvl, int hp, int mana, int sp, string weapon)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(sp) {}
    
    void defend() override {
        cout << name << " conjures a magical barrier using " << manaPoints << " mana points!" << endl;
    }
};

class Archer : public Character {
    int arrowCount, rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, int arrows, int accuracy, string weapon)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    
    void attack() override {
        cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }
};

class Rogue : public Character {
    int stealthLevel, agility;
public:
    Rogue(string id, string n, int lvl, int hp, int stealth, int agi, string weapon)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}
    
    void displayStatus() const override {
        Character::displayStatus();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << "\n";
    }
};

int main() {
    Warrior w("W001", "Thorin", 10, 100, 50, 30, "Greatsword");
    Mage m("M001", "Gandalf", 12, 80, 100, 50, "Staff");
    Archer a("A001", "Legolas", 15, 90, 30, 85, "Bow");
    Rogue r("R001", "Ezio", 11, 85, 70, 95, "Dagger");

    Character* characters[] = { &w, &m, &a, &r };
    
    cout << "\n--- Character Actions ---\n";
    for (Character* c : characters) {
        c->attack();
        c->defend();
        cout << endl;
    }
    
    cout << "\n--- Character Stats ---\n";
    for (Character* c : characters) {
        c->displayStatus();
        cout << "--------------------\n";
    }
    
    return 0;
}
