#include "encryption.h"
#include <cstdlib>

std::string encrypt(const std::string& text, const std::string& key) {
    std::string result = text;
    for (size_t i = 0; i < text.length(); i++) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

std::string decrypt(const std::string& text, const std::string& key) {
    return encrypt(text, key);
}

std::string toHex(const std::string& str) {
    std::stringstream ss;
    for (unsigned char c : str) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return ss.str();
}

std::string fromHex(const std::string& hex) {
    std::string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2);
        char chr = (char)(int)strtol(byte.c_str(), nullptr, 16);
        result.push_back(chr);
    }
    return result;
}

std::string generatePassword(int length) {
    const std::string chars = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
    std::string password;
    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }
    return password;
}