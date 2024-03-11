#pragma once

#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "attack.h"
using std::wstring;
using std::vector;


class mokepon
{
public:
	static const uint16_t MAX_ATTACKS = 4;

public:
	wstring			name;
	int16_t			health;
	int16_t			damage;
	int16_t			defense;
	element_type	element;
	attack			attacks[MAX_ATTACKS];

public:
	mokepon(void);
	~mokepon(void);

public:
	void use_attack(mokepon&, attack);
	void use_defense(void);
	void use_heal(void);
	void reset_attacks(void);
};
