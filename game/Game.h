#pragma once
#include <string>
#include "../player/player.h"
#include "../room/Room.h"
#include "../lucky/Lucky.h"

class Player;
class Room;
class Lucky;
class Game {
    private:
        Player player;
        Room entrance;
        Room corridor;
        Room treasure;
        Lucky lucky;
        bool gameRunning;

        Game();

        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        bool confirmQuit();

    public:
        static Game& getInstance();

        void run();
        void stopGame();
};