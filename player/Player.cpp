#include <iostream>
#include "player.h"

using std::cout;
using std::endl;

Player::Player(string name)
        : playerName(name),
          playerHealth(73),
          playerHasLockpick(false),
          playerHasCompass(false),
          playerScore(0) {}


    string Player::getName()  { return playerName; }
    int Player::getHealth()  { return playerHealth; }
    bool Player::hasLockpickItem()  { return playerHasLockpick; }
    bool Player::hasCompassItem()  { return playerHasCompass; }
    int Player::getScore()  { return playerScore; }

    void Player::setHealth(int health) { playerHealth = health; }
    void Player::heal(int amount) { playerHealth += amount; }
    void Player::takenDamage(int damage) { playerHealth -= damage; }
    void Player::addScore(int score) { playerScore += score; }
    void Player::fullHeal(){ playerHealth = 100; }
    void Player::pickupLockpick() {
        playerHasLockpick = true;
        playerScore++;
        cout << "Has recogido una Ganzua." << endl;
    }

    void Player::pickupCompass() {
       cout << "Has recogido la Brujula." << endl;
        playerHasCompass = true;
    }

    void Player::displayStatus() {
        cout << "\n---" << playerName << "---" << endl;
        cout << "Salud: " << playerHealth << endl;
        cout << "Puntos: " << playerScore << endl;
        cout << (hasLockpickItem() ? " [Ganzua]" : "") << " | " << (hasCompassItem() ? "[Brujula]" : "") << endl;
    }