#pragma once
#include <string>

using std::string;

class Room {
private:
    string roomName;
    string roomDescription;

    public:
        Room(string name, string description);
        
        string getName();
        string getDescription();
};