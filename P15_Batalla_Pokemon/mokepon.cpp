#include "mokepon.h"


mokepon::mokepon(void) : health(100), damage(1), defense(1), element(element_type::NORMAL), attacks() {}

mokepon::~mokepon(void) {}


void mokepon::reset_attacks(void)
{
	int32_t random_type = (rand() % 3) + 1;

	for (int16_t i = 0; i < MAX_ATTACKS; i++)
	{
		attacks[i] = attack{ (element_type)random_type };
	}
}

void mokepon::use_attack(mokepon& _Other, attack _Attack)
{
	
}
