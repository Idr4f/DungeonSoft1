#pragma once
#include <string>

using std::string;

class Direction {
private:
    char directionKey;
    string directionName;

public:
    Direction(char key);

    char getKey();
    string getDirection();
    bool isValid();
};