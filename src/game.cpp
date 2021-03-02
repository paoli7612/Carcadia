
#include "../include/game.h"

using namespace std;

Game::Game()
{
}

void Game::start()
{
    window.start(WIDTH*TILE, HEIGHT*TILE);
    images.set_window(window);
    loop();
}

void Game::loop()
{
    while (window.isOpen())
    {
        event();
        update();
        draw();
    }
}

void Game::event()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.dy = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.dy = 1;
    else
        player.dy = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.dx = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.dx = 1;
    else
        player.dx = 0;


    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseMoved: {
                //std::cout << event.mouseMove.x << std::endl;
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                }
                break;
            }
            case sf::Event::Closed: {
                window.close();
                break;
            }

        }
      
    }
  
}

void Game::update()
{
    player.update();

}

void Game::draw()
{
    window.clear();
    //window.draw(world);
    //window.draw(text);
    draw_world();
    window.draw(player);
    window.display();
}

void Game::draw_world()
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            tile_t tile = world.get(x, y);
            for (int z=0; z<DEPTH; z++)
            {
                images.draw(x, y, tile.image[z].x, tile.image[z].y);
            }
        }
            
}