#pragma once
#include <string>

int cipher32b_WORD(uintptr_t input, std::string key, int& output);
void stream2hex(const std::string str, std::string& hexstr, bool capital);
void hex2stream(std::string hexstr, std::string& str);