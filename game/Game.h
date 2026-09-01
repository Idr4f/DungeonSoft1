#pragma once
#include <string>
#include "../player/player.h"
#include "../room/Room.h"
#include "../lucky/Lucky.h"

class Game{
    private:
        Player player;
        Room entrance;
        Room corridor;
        Room treasure;
        Lucky lucky;

    public:
        Game();
        void run();
};