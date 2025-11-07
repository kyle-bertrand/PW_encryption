# PW_encryption
Simple Password Encryption and tracker for basic computer needs. DO NOT USE FOR WORK
First hobby project to show a level of competence with C++
Makefile is unresponsive so need to manually compile the code within wsl using:
g++ -std=c++11 -c encryption.cpp
g++ -std=c++11 -c PasswordManager.cpp
g++ -std=c++11 -c main.cpp
g++ -std=c++11 -o password_manager main.o PasswordManager.o encryption.o
./password_manager
