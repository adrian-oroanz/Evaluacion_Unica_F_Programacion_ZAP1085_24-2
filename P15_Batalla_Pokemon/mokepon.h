#pragma once

#include <string>
#include <random>
#include <ctime>
using std::wstring;
using std::random_device;
using std::mt19937;


typedef float float32_t;


const wstring MOKEPON_NAMES[] =
{
	// Fire types
	L"Charmanther",
	L"Fireball",
	// Water types
	L"Waterbottle",
	L"Waterfall",
	// Grass types
	L"Grassquatch",
	L"Grasshopper",
	// Electric types
	L"Electruff",
	L"Electrode",
};

const wstring ATTACK_NAMES[] =
{
	// Fire attacks
	L"Ember",
	L"Flamethrower",
	// Water attacks
	L"Water Gun",
	L"Hydro Pump",
	// Grass attacks
	L"Vine Whip",
	L"Razor Leaf",
	// Electric attacks
	L"Thunder Shock",
	L"Thunderbolt",
};


class mokepon
{
public:
	/*
	Represents the different elements a mokepon and their attacks can have.
	Fire is weak to Water,
	Water is weak to Electric,
	Electric is weak to Grass,
	Grass is weak to Fire.
	*/
	enum class element : uint16_t
	{
		NONE		= 0,
		FIRE		= 1,
		WATER		= 2,
		GRASS		= 3,
		ELECTRIC	= 4,
	};

public:
	struct attack
	{
		wstring		name;
		element		type	= element::NONE;
		int16_t		damage	= 0;
	};

public:
	static const uint16_t MAX_ATTACKS = 4;

public:
	static wstring	element_to_string(element);

public:
	wstring			name;
	element			type;

private:
	int16_t			base_health;
	int16_t			base_attack;
	int16_t			base_defense;
	mt19937			random;
	random_device	device;
	attack			attacks[MAX_ATTACKS];

public:
	mokepon(void) noexcept;
	mokepon(wstring) noexcept;
	mokepon(const mokepon&) noexcept;
	~mokepon(void) noexcept;

private:

public:
	void use_attack(mokepon&, uint16_t);
	void use_enrage(void);
	void use_defend(void);
	void use_heal(void);
	void generate_attacks(void);

public:
	int16_t get_health_points(void) const;
	int16_t get_attack_points(void) const;
	int16_t get_defense_points(void) const;
	attack& get_attack(uint16_t);
	bool	is_alive(void) const;

public:
	void operator=(const mokepon&);
};
