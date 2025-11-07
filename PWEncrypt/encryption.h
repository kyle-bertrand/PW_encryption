#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <sstream>
#include <iomanip>

std::string encrypt(const std::string& text, const std::string& key);
std::string decrypt(const std::string& text, const std::string& key);
std::string toHex(const std::string& str);
std::string fromHex(const std::string& hex);
std::string generatePassword(int length = 16);

#endif