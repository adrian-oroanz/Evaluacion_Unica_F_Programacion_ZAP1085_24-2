#pragma once

#include <cstdint>


class attack
{
public:
	enum class type : uint16_t;

public:
	attack(void);
	~attack(void);
};


enum class attack::type : uint16_t
{
	FIRE,
	WATER,
	EARTH,
};

