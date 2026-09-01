#include "Room.h"

Room::Room(string name, string description)
        : roomName(name), roomDescription(description) {}

string Room::getName() {
    return roomName;
}

string Room::getDescription() {
    return roomDescription;
}