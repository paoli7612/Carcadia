
#ifndef INCLUDE_EDITOR_H_
#define INCLUDE_EDITOR_H_

#include "../include/loop.h"

enum editor_mode { TILE_MODE, SOLID_MODE, DOOR_MODE };
/**
 * @brief 
 * 
 */
class Editor : public Loop {
    private:
        editor_mode mode;
        void click(const bool isLeft, const int x, const int y);

    public:
        /**
         * @brief Construct a new Editor object
         * 
         * @param title title of map to edit
         */
        Editor(const char title[10]);

        void event();
        void update(float dt);
        void draw();
        
        sf::Texture cursorTexture;
        sf::Sprite cursorSprite;

        sf::RenderWindow tilesWindow;
        sf::Texture tilesTextureBackground; // background
        sf::Sprite tilesSpriteBackground; 
        sf::Sprite tilesSpriteSelector; // using cursorTexture
};

#endif /* INCLUDE_EDITOR_H_ */