
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include "../include/loop.h"
#include "../include/player.h"

/**
 * @brief 
 * 
 */
class Game : public Loop {
    private:
        Player player;
        
    public:
        Game();
        
        void event();
        void update(float);
        void draw();
};

#endif /* INCLUDE_GAME_H_ */