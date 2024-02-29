// 015_P_Batalla_Pokemon.cpp
// Adrian Orozco Anzures
// Simulador de batallas pokemón or smth like that ig
//

#include <iostream>
#include <random>
#include <ctime>
using std::cout; using std::endl;


class pokemon
{
public:
    short base_health;
    short base_attack;
    short base_defense;

public:
    pokemon() : base_health(100), base_attack(2), base_defense(2) { }

    void attack(pokemon&);
    void defend(void);
    void enrage(void);
    void recover(void);
};


void pokemon::attack(pokemon& _Other)
{
    int random = (rand() % 5) + 1;
    int damage = random + base_attack;

    // Opponent absorbs all damage if true.
    if (_Other.base_defense >= damage)
        return;

    _Other.base_health -= (damage - _Other.base_defense);
}

void pokemon::defend(void)
{
    base_defense += (rand() % 2) + 1;
}

void pokemon::enrage(void)
{
    base_attack += (rand() % 2) + 1;
}

void pokemon::recover(void)
{
    base_health += (rand() % 20) + 1;
}


int main()
{
    // Set the random seed.
    srand((unsigned int)time(NULL));

    pokemon player, opponent;

    while (true)
    {
        
    }
}
