#include <stdio.h>
#include "deadbeef.h"
#include <string>


int main() {

	auto exampleHex					= 0x000fffff;
	std::string	four_byte_key		= "keya";
	int output						= NULL;

	cipher32b_WORD(exampleHex, four_byte_key, output);
	printf(" Im ciphering %p with key %s ---> %i", (uintptr_t)exampleHex, four_byte_key, output);




}