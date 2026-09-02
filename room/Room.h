#pragma once
#include <string>

using std::string;

class Room
{
private:
    static const int MAX_ITEMS = 10;
    string roomItems[MAX_ITEMS];
    bool itemExamined[MAX_ITEMS];
    int itemCount;
    string roomName;
    string roomDescription;
    int findItem(string itemName);

public:
    Room(string name, string description);
    //setters
    bool addItem(string itemName);
    bool removeItem(string itemName);
    bool markAsExamined(string itemName);
    //getters
    bool hasItem(string itemName);
    string getName();
    string getDescription();
    bool hasBeenExamined(string itemName);
};