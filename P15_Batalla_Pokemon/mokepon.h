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
	enum class element : uint16_t
	{
		NORMAL = 0,
		FIRE,
		WATER,
		GRASS,
		ELECTRIC
	};

public:
	struct attack
	{
		wstring		name;
		element		type;
		int16_t		damage;
	};

public:
	static const uint16_t MAX_ATTACKS = 4;

public:
	static mokepon& from(mokepon&);
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
	~mokepon(void) noexcept;

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
