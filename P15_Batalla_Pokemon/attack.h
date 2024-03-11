#pragma once

#include <cstdint>
#include <string>
using std::wstring;


enum class element_type : uint16_t
{
	NORMAL,
	WATER,
	EARTH,
	FIRE
};


class attack
{
public:
	wstring			name;
	element_type	type;

public:
	attack(void);
	attack(element_type);
	~attack(void);
};
