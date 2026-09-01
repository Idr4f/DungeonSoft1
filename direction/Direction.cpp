#include "Direction.h"

Direction::Direction(char key){

    if (key == 'W' || key == 'w') {
        directionName = "Arriba";
    } else if (key == 'A' || key == 'a') {
        directionName = "Izquierda";
    } else if (key == 'S' || key == 's') {
        directionName = "Abajo";
    } else if (key == 'D' || key == 'd') {
        directionName = "Derecha";
    } else {
        directionName = "Dirección invalida";
    }

    directionKey = key;

}

char Direction::getKey() { return directionKey; }
string Direction::getDirection() { return directionName; }
bool Direction::isValid() { return directionName != "Dirección invalida"; }
