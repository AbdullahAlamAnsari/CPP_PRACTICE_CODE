#include <iostream>
using namespace std;

class Character //uses multilevel inheritance
{
    protected:
    int health = 100; 
    
    public:

    static int charactercount ;
    Character(int health)
    {
        this->health = health;
    }
    void healthcheck()
    {
        cout<<"HEALTH: "<<health<<endl;
    }   
};


class Warrior : public Character
{
    protected:
    int strength = 100; 
    
    public:
    void strengthcheck()
    {
        cout<<"STRENGTH: "<<strength<<endl;
    }

    Warrior(int strength,int health) : Character(health)
    {
        this->strength = strength;
        this->health = health;

    }

};


class Armor : public Warrior
{
    protected:
    int armor = 100; 
    
    public:
    void armorcheck()
    {
        cout<<"ARMOR: "<<armor<<endl;
    }
    
    Armor(int strength, int health,int armor) : Warrior(strength, health)
    {
        this->strength = strength;
        this->health = health;
        this->armor = armor;
    }
};


int Character :: charactercount = 0;
int main()
{
    Armor* armorclass = new Armor(100,100,90);
    armorclass->armorcheck();
    armorclass->strengthcheck();
    armorclass->healthcheck();

}