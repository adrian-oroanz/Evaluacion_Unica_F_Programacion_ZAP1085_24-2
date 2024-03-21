#include "mokepon.h"


mokepon::mokepon(void) : base_health(100), base_attack(1), base_defense(1), element(element::NORMAL), device(), random(device())
{
	generate_attacks();
}

mokepon::mokepon(wstring _Name) : mokepon()
{
	name = _Name;
}

mokepon::~mokepon(void) {}


void mokepon::generate_attacks(void)
{
	for (int16_t i = 0; i < MAX_ATTACKS; i++)
	{
		int16_t rand_type = (random() % 4) + 1;
		// TODO: Add a new attack to the array.
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
