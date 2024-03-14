#pragma once

#include <string>
#include <random>
#include <ctime>
#include "mokepon_move.h"
using std::wstring;


class mokepon
{
public:
	enum class element : uint16_t;

public:
	static const uint16_t MAX_ATTACKS = 4;

public:
	wstring			name;
	element			element;

private:
	int16_t			base_health;
	int16_t			base_attack;
	int16_t			base_defense;

public:
	mokepon(void);
	~mokepon(void);

public:
	void use_attack(mokepon&, uint16_t);
	void use_special();
	void reset_attacks(void);
};


enum class mokepon::element : uint16_t
{
	NORMAL,
	WATER,
	EARTH,
	FIRE
};
