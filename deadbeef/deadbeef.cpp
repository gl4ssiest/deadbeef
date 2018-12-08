#include <bitset>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "deadbeef.h"

void cipher32b_WORD(uintptr_t input, std::string key, std::string& output)
{

	std::string hexkey			= "";
	std::string xoredBinString	= "";
	std::string xoredHexString	= "";
	
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
				
		xoredHexString = strBin2hex(xoredBinString);
		
	}

	//std::cout << xoredHexString;
}

void decipher32b_WORD(std::string input, std::string key, std::string& output)
{

	std::string hexkey = "";
	std::string xoredBinString = "";
	std::string xoredHexString = "";

	stream2hex(key, hexkey, false);
	std::bitset<32> binaryKeyRep = std::bitset<32>(std::stoul(hexkey, nullptr, 16));
	std::string stringKeyRep = binaryKeyRep.to_string();

	std::bitset<32> binaryRep = std::bitset<32>(input);
	std::string stringRep = binaryRep.to_string();


	if (stringRep.length() == stringKeyRep.length()) {

		for (int i = 0; i < stringRep.length(); ++i) {

			if (stringRep.at(i) == stringKeyRep.at(i))
				xoredBinString.append("0");
			else
				xoredBinString.append("1");
			//printf("-  string: %c key: %c xor: %c\n", stringRep.at(i), stringKeyRep.at(i), xoredString.at(i));

		}

		xoredHexString = strBin2hex(xoredBinString);

	}

	//std::cout << xoredHexString;
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

std::string strBin2hex(std::string strBinary)
{
	int result = 0;

	for (size_t count = 0; count < strBinary.length(); ++count)
	{
		result *= 2;
		result += strBinary[count] == '1' ? 1 : 0;
	}

	std::stringstream ss;
	ss << "0x" << std::hex << std::setw(8) << std::setfill('0') << result;
	
	return ss.str();
}