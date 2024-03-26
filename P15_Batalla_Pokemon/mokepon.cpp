#include "mokepon.h"


mokepon& mokepon::from(mokepon& _Mokepon)
{
	mokepon new_mokepon;

	new_mokepon.base_attack = _Mokepon.base_attack;
	new_mokepon.base_defense = _Mokepon.base_defense;

	return new_mokepon;
}

wstring mokepon::element_to_string(element _Element)
{
	switch (_Element)
	{
	case element::NORMAL:
		return L"Normal";
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


mokepon::mokepon(void) noexcept : base_health(100), base_attack(1), base_defense(1), type(element::NORMAL), device(), random(device())
{
	generate_attacks();
}

mokepon::mokepon(wstring _Name) noexcept : mokepon()
{
	name = _Name;
}

mokepon::~mokepon(void) {}


void mokepon::generate_attacks(void)
{
	for (int16_t i = 0; i < MAX_ATTACKS; i++)
	{
		int16_t rand_type = (random() % 4) + 1;

		attacks[i].name = L"Attack " + std::to_wstring(i + 1);
		attacks[i].damage = (random() % 10) + 1;
		attacks[i].type = static_cast<element>(rand_type);
	}
}

void mokepon::use_enrage(void)
{
	int16_t rand_points = (random() % 2) + 1;

	base_attack += rand_points;
}

void mokepon::use_defend(void)
{
	int16_t rand_points = (random() % 3) + 1;

	base_defense += rand_points;
}

void mokepon::use_heal(void)
{
	int16_t rand_points = (random() % 20) + 1;

	base_health += rand_points;

	if (base_health > 100)
		base_health = 100;
}


int16_t mokepon::get_health_points(void) const
{
	return base_health;
}

int16_t mokepon::get_attack_points(void) const
{
	return base_attack;
}

int16_t mokepon::get_defense_points(void) const
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
	name = _Mokepon.name;
	type = _Mokepon.type;
	base_health = _Mokepon.base_health;
	base_attack = _Mokepon.base_attack;
	base_defense = _Mokepon.base_defense;
}
