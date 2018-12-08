#pragma once
#include <string>

void cipher32b_WORD(uintptr_t input, std::string key, std::string& output);
void decipher32b_WORD(std::string input, std::string key, std::string& output);
void stream2hex(const std::string str, std::string& hexstr, bool capital);
void hex2stream(std::string hexstr, std::string& str);
std::string strBin2hex(std::string strBinary);