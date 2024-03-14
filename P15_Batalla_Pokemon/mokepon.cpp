#include "mokepon.h"


mokepon::mokepon(void) : base_health(100), base_attack(1), base_defense(1), element(element_type::NORMAL), attacks() {}

mokepon::~mokepon(void) {}


void mokepon::reset_attacks(void)
{
	int32_t random_type = (rand() % 3) + 1;

	for (int16_t i = 0; i < MAX_ATTACKS; i++)
	{
		// TODO: Add a new attack to the array.
	}
}

void mokepon::use_attack(mokepon& _Other, uint16_t _AttIndex)
{
	
}
