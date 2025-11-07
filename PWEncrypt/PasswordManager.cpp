#include "PasswordManager.h"
#include "encryption.h"
#include <iostream>
#include <fstream>

using namespace std;

PasswordManager::PasswordManager(const string& key, const string& file) 
    : masterKey(key), filename(file) {
    loadPasswords();
}

void PasswordManager::addPassword(const string& service, const string& password) {
    string encrypted = encrypt(password, masterKey);
    passwords[service] = toHex(encrypted);
    savePasswords();
    cout << "✓ Password for '" << service << "' saved successfully!\n";
}

void PasswordManager::getPassword(const string& service) {
    if (passwords.find(service) == passwords.end()) {
        cout << "✗ No password found for '" << service << "'\n";
        return;
    }
    
    string encrypted = fromHex(passwords[service]);
    string decrypted = decrypt(encrypted, masterKey);
    cout << "Password for '" << service << "': " << decrypted << "\n";
}

void PasswordManager::listServices() {
    if (passwords.empty()) {
        cout << "No passwords stored yet.\n";
        return;
    }
    
    cout << "\n=== Stored Services ===\n";
    int count = 1;
    for (const auto& pair : passwords) {
        cout << count++ << ". " << pair.first << "\n";
    }
    cout << "=======================\n";
}

void PasswordManager::removePassword(const string& service) {
    if (passwords.erase(service)) {
        savePasswords();
        cout << "✓ Password for '" << service << "' removed.\n";
    } else {
        cout << "✗ No password found for '" << service << "'\n";
    }
}

void PasswordManager::updatePassword(const string& service, const string& newPassword) {
    if (passwords.find(service) == passwords.end()) {
        cout << "✗ No password found for '" << service << "'\n";
        return;
    }
    addPassword(service, newPassword);
    cout << "✓ Password updated for '" << service << "'\n";
}

void PasswordManager::savePasswords() {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not save passwords to file.\n";
        return;
    }
    
    for (const auto& pair : passwords) {
        file << pair.first << ":" << pair.second << "\n";
    }
    file.close();
}

void PasswordManager::loadPasswords() {
    ifstream file(filename);
    if (!file.is_open()) {
        return;
    }
    
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string service = line.substr(0, pos);
            string encryptedHex = line.substr(pos + 1);
            passwords[service] = encryptedHex;
        }
    }
    file.close();
}