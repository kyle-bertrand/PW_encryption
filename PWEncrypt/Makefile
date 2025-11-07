CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = password_make
OBJS = main.o PasswordManager.o encryption.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp PasswordManager.h encryption.h
	$(CXX) $(CXXFLAGS) -c main.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h encryption.h
	$(CXX) $(CXXFLAGS) -c PasswordManager.cpp

encryption.o: encryption.cpp encryption.h
	$(CXX) $(CXXFLAGS) -c encryption.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean