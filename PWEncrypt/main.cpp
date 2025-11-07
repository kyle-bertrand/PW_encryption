#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PasswordManager.h"
#include "encryption.h"

using namespace std;

void displayMenu() {
    cout << "\n╔════════════════════════════════════╗\n";
    cout << "║    PASSWORD MANAGER MENU           ║\n";
    cout << "╚════════════════════════════════════╝\n";
    cout << "1. Add new password\n";
    cout << "2. Get password\n";
    cout << "3. Generate random password\n";
    cout << "4. List all services\n";
    cout << "5. Update password\n";
    cout << "6. Delete password\n";
    cout << "7. Exit\n";
    cout << "\nChoice: ";
}

int main() {
    srand(time(0));
    
    cout << "╔════════════════════════════════════╗\n";
    cout << "║  ENCRYPTED PASSWORD MANAGER        ║\n";
    cout << "╚════════════════════════════════════╝\n\n";
    
    string masterPassword;
    cout << "Enter master password: ";
    getline(cin, masterPassword);
    
    if (masterPassword.length() < 4) {
        cout << "Master password too short! Must be at least 4 characters.\n";
        return 1;
    }
    
    PasswordManager pm(masterPassword);
    cout << "\n✓ Password manager initialized!\n";
    
    int choice;
    string service, password;
    
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                cout << "\nService name: ";
                getline(cin, service);
                cout << "Password: ";
                getline(cin, password);
                pm.addPassword(service, password);
                break;
            }
            case 2: {
                cout << "\nService name: ";
                getline(cin, service);
                pm.getPassword(service);
                break;
            }
            case 3: {
                int length;
                cout << "\nPassword length (8-32): ";
                cin >> length;
                cin.ignore();
                
                if (length < 8) length = 8;
                if (length > 32) length = 32;
                
                string generated = generatePassword(length);
                cout << "\nGenerated password: " << generated << "\n";
                cout << "Save this password? (y/n): ";
                char save;
                cin >> save;
                cin.ignore();
                
                if (save == 'y' || save == 'Y') {
                    cout << "Service name: ";
                    getline(cin, service);
                    pm.addPassword(service, generated);
                }
                break;
            }
            case 4: {
                pm.listServices();
                break;
            }
            case 5: {
                cout << "\nService name: ";
                getline(cin, service);
                cout << "New password: ";
                getline(cin, password);
                pm.updatePassword(service, password);
                break;
            }
            case 6: {
                cout << "\nService name: ";
                getline(cin, service);
                pm.removePassword(service);
                break;
            }
            case 7: {
                cout << "\n✓ Goodbye! Your passwords are safely encrypted.\n";
                return 0;
            }
            default: {
                cout << "\n✗ Invalid choice! Try again.\n";
            }
        }
    }
    
    return 0;
}