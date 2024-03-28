#include "mokepon.h"


wstring mokepon::element_to_string(element _Element)
{
	switch (_Element)
	{
	case element::NONE:
		return L"None";
	case element::FIRE:
		return L"Fire";
	case element::WATER:
		return L"Water";
	case element::GRASS:
		return L"Grass";
	case element::ELECTRIC:
		return L"Electric";
	default:
		return L"Unknown";
	}
}


mokepon::mokepon(void) noexcept : attacks(), base_health(100), base_attack(1), base_defense(1), device(), random(device())
{
	// Assigns a random type to the mokepon.
	uint16_t rand_type = (random() % 4) + 1;

	type = static_cast<element>(rand_type);

	// Assigns a random name based on the type.
	name = MOKEPON_NAMES[(random() % 2) + ((rand_type - 1) * 2)];

	// Generates the attacks for the mokepon.
	generate_attacks();
}

mokepon::mokepon(wstring _Name) noexcept : mokepon()
{
	name = _Name;
}

mokepon::mokepon(const mokepon& _Mokepon) noexcept : mokepon()
{
	base_attack = _Mokepon.base_attack;
	base_defense = _Mokepon.base_defense;
}

mokepon::~mokepon(void) {}


void mokepon::generate_attacks(void)
{
	for (int16_t i = 0; i < MAX_ATTACKS; i++)
	{
		int16_t rand_type = (random() % 4) + 1;

		attacks[i].name = ATTACK_NAMES[(random() % 2) + ((rand_type - 1) * 2)];
		attacks[i].damage = (random() % 6) + 5;
		attacks[i].type = static_cast<element>(rand_type);
	}
}

uint16_t mokepon::use_attack(mokepon& _Other, uint16_t _AttackIndex)
{
	attack& attack = attacks[_AttackIndex];
	float32_t damage = attack.damage;

	// Calculates the damage based on the attacker's attack and the defender's defense.
	damage *= ((base_attack / 10.0F) + 1);
	damage /= ((_Other.base_defense / 10.0F) + 1);
	
	// Checks if the attack is strong or weak against the other mokepon's type.
	// If the attack type is strong against the defender type, the damage is doubled.

	if (attack.type == element::FIRE && _Other.type == element::GRASS)
		damage *= 2;
	else if (attack.type == element::WATER && _Other.type == element::FIRE)
		damage *= 2;
	else if (attack.type == element::GRASS && _Other.type == element::ELECTRIC)
		damage *= 2;
	else if (attack.type == element::ELECTRIC && _Other.type == element::WATER)
		damage *= 2;

	// If the attack type is weak against the defender type, the damage is halved.

	if (attack.type == element::FIRE && _Other.type == element::WATER)
		damage /= 2;
	else if (attack.type == element::WATER && _Other.type == element::GRASS)
		damage /= 2;
	else if (attack.type == element::GRASS && _Other.type == element::FIRE)
		damage /= 2;
	else if (attack.type == element::ELECTRIC && _Other.type == element::GRASS)
		damage /= 2;

	if (damage < 0)
		damage = 0;

	_Other.base_health -= damage;

	if (_Other.base_health < 0)
		_Other.base_health = 0;

	return damage;
}

uint16_t mokepon::use_enrage(void)
{
	// Generates a random number between 2 and 5.
	int16_t rand_points = (random() % 4) + 2;

	base_attack += rand_points;

	return rand_points;
}

uint16_t mokepon::use_defend(void)
{
	// Generates a random number between 2 and 5.
	int16_t rand_points = (random() % 4) + 2;

	base_defense += rand_points;

	return rand_points;
}

uint16_t mokepon::use_heal(void)
{
	// Generates a random number between 10 and 20.
	int16_t rand_points = (random() % 11) + 10;

	base_health += rand_points;

	if (base_health > 100)
		base_health = 100;

	return rand_points;
}


uint16_t mokepon::get_health_points(void) const
{
	return base_health;
}

uint16_t mokepon::get_attack_points(void) const
{
	return base_attack;
}

uint16_t mokepon::get_defense_points(void) const
{
	return base_defense;
}

mokepon::attack& mokepon::get_attack(uint16_t _Index)
{
	return attacks[_Index];
}

bool mokepon::is_alive(void) const
{
	return base_health > 0;
}


void mokepon::operator=(const mokepon& _Mokepon)
{
	name			= _Mokepon.name;
	type			= _Mokepon.type;
	base_health		= _Mokepon.base_health;
	base_attack		= _Mokepon.base_attack;
	base_defense	= _Mokepon.base_defense;
}
