#include "../include/loop.h"

void Loop::init(const int width, const int height, const char * title)
{
    window.create(sf::VideoMode(width, height), title);

    texture.loadFromFile("img/tiles.png");
    sprite.setTexture(texture);

    // solid
    solidTexture.loadFromFile("img/solid.png");
    solidSprite.setTexture(solidTexture);
}

void Loop::start()
{
    running = true;
    while (running)
    {
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = clock.getElapsedTime().asSeconds();
            clock.restart();
        } else continue;
        event();
        update(dt);

        window.clear();
        draw_map();
        draw();
        window.display();
    }
}

void Loop::draw_map()
{
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
        {
            tile_t &tile = map.tiles[y][x];
            sprite.setPosition(x*32, y*32);                 

            for (int z=0; z<DEPTH; z++)
            {
                if (is_empty(tile.images[z]))
                    break;

                int ix = tile.images[z].x*32;
                int iy = tile.images[z].y*32;

                sprite.setTextureRect((sf::IntRect){ix, iy, 32, 32});
                window.draw(sprite);
            }
        }
    
    
    for (int i=0; i<map.n_doors; i++)
    {
        door_t &door = map.doors[i];
        sprite.setPosition(door.x*32, door.y*32);    

        image_t &image = door.image;    
        sprite.setTextureRect((sf::IntRect){image.x, image.y, 32, 32});
        window.draw(sprite);
    }
    
}

void Loop::draw_solid()
{
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            if (map.tiles[y][x].isCollide)
                {
                    solidSprite.setPosition(x*32, y*32);                 
                    window.draw(solidSprite);
                }
}