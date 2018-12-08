#include <bitset>
#include <string>
#include <sstream>
#include "deadbeef.h"

int cipher32b_WORD(uintptr_t input, std::string key, int& output)
{

	std::string hexkey			= "";
	std::string xoredBinString		= "";
	
	stream2hex(key, hexkey, false);
	std::bitset<32> binaryKeyRep= std::bitset<32>(std::stoul(hexkey, nullptr, 16));
	std::string stringKeyRep	= binaryKeyRep.to_string();
	
	std::bitset<32> binaryRep	= std::bitset<32>(input);
	std::string stringRep		= binaryRep.to_string();

	
	if (stringRep.length() == stringKeyRep.length()) {
	
		for (int i = 0; i < stringRep.length(); ++i) {
			
			if (stringRep.at(i) == stringKeyRep.at(i))
				xoredBinString.append("0");
			else
				xoredBinString.append("1");

			//printf("-  string: %c key: %c xor: %c\n", stringRep.at(i), stringKeyRep.at(i), xoredString.at(i));

		}

		for (int i = 0; i < xoredBinString.length(); ++i) {
/*
			if ((i + 1) % 4 == 0) {
				//convert 4 temp binaries to hex
			}
			else {
			
				
			
			}
			//printf("-  string: %c key: %c xor: %c\n", stringRep.at(i), stringKeyRep.at(i), xoredString.at(i));
*/
		}
		
		std::bitset<32> binaryXoredRep = std::bitset<32>(xoredBinString);
	}



	printf(" %p ----> %s", binaryRep, stringRep);
	return input;



}

// Convert string of chars to its representative string of hex numbers
void stream2hex(const std::string str, std::string& hexstr, bool capital = false)
{
	hexstr.resize(str.size() * 2);
	const size_t a = capital ? 'A' - 1 : 'a' - 1;

	for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF)
	{
		hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
		hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
	}
}

// Convert string of hex numbers to its equivalent char-stream
void hex2stream(std::string hexstr, std::string& str)
{
	str.resize((hexstr.size() + 1) / 2);

	for (size_t i = 0, j = 0; i < str.size(); i++, j++)
	{
		str[i] = (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) << 4, j++;
		str[i] |= (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) & 0xF;
	}
}
