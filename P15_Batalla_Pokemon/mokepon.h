#pragma once

#include <string>
#include <random>
#include <ctime>
using std::wstring;
using std::random_device;
using std::mt19937;


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
	mt19937			random;
	random_device	device;

public:
	mokepon(void);
	mokepon(wstring);
	~mokepon(void);

public:
	void use_attack(mokepon&, uint16_t);
	void use_enrage(void);
	void use_defend(void);
	void use_heal(void);
	void generate_attacks(void);
};


enum class mokepon::element : uint16_t
{
	NORMAL,
	WATER,
	EARTH,
	FIRE
};
