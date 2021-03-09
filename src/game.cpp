
#include "../include/game.h"

void Game::start()
{
    map_load(map, "spawn");

    window.create(sf::VideoMode(800, 800), "Carcadia - editor", sf::Style::Fullscreen);
    sf::Vector2u size = window.getSize();

    player.start(size.x/2, size.y/2);
    player.setMap(map);

    textures[INTERIOR].loadFromFile("img/interior.png");
    textures[OUTSIDE].loadFromFile("img/outside.png");
    textures[TERRAIN].loadFromFile("img/terrain.png");

    for (int i=0; i<3; i++)
        tile[i].setTexture(textures[i]);

    loop();
}

void Game::loop()
{
    running = true;
    while (running)
    {
        // Tick
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = clock.getElapsedTime().asSeconds();
            clock.restart();
        } else continue;

        event();
        update();
        draw();
    }
}

void Game::event()
{
    sf::Event event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.up();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.down();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.right();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.left();
    else player.stand();

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        running = false;
                        break;
                }
                break;
            }
            case sf::Event::Closed:
                running = false;
                break;
        }
    }
}

void Game::update()
{
    player.update(dt);
}

void Game::draw()
{
    window.clear(sf::Color(100, 50, 120));

    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            tile_t t = map.tiles[y][x];
            for (int z=0; z<DEPTH; z++)
            {
                image_t image = t.image[z];
                if (image.ix == 7612 && image.iy == 7612)
                    continue;
                kind_t kind = image.kind;
                tile[kind].setTextureRect(sf::IntRect(image.ix*32, image.iy*32, 32, 32));
                tile[kind].setPosition(x*32, y*32);
                window.draw(tile[kind]);
            }
        }

    window.draw(player);
    window.display();
}
