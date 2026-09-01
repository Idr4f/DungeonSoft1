#pragma once
#include <string>

using std::string;

class Player {

    private:
        string playerName;
        int playerHealth;
        bool playerHasLockpick;
        bool playerHasCompass;
        int playerScore;

    public:
        Player(string name);
        //getters 
        string getName();
        int getHealth();
        bool hasLockpickItem();
        bool hasCompassItem();
        int getScore();
        void displayStatus();
        //setters
        void setHealth(int health);
        void heal(int amount);
        void takenDamage(int damage);
        void addScore(int score);
        void fullHeal();
        void pickupLockpick();
        void pickupCompass();
};