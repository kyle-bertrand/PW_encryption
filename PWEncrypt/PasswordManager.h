#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> passwords;
    std::string masterKey;
    std::string filename;
    
    void savePasswords();
    void loadPasswords();

public:
    PasswordManager(const std::string& key, const std::string& file = "passwords.dat");
    
    void addPassword(const std::string& service, const std::string& password);
    void getPassword(const std::string& service);
    void listServices();
    void removePassword(const std::string& service);
    void updatePassword(const std::string& service, const std::string& newPassword);
};

#endif