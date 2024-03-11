#include "attack.h"


attack::attack(void) : type(element_type::NORMAL) {}

attack::attack(element_type _Element) : type(_Element) {}

attack::~attack(void) {}
