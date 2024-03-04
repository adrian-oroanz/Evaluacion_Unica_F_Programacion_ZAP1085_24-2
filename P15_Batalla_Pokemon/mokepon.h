#pragma once

#include <string>
using std::wstring;


class mokepon
{
public:
	wstring name;
	int16_t health;
	int16_t attack;
	int16_t defense;

public:
	mokepon(void);
	~mokepon(void);
};
