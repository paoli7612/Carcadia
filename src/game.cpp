// game

#include <iostream>

#include "../include/loop.h"
#include "../include/map.h"
#include "../include/player.h"

using namespace std;

enum mode_t { TILE_MODE, SOLID_MODE };

class Game : public Loop {
    private:
        mode_t mode;

    public:
        Player player;

        Game()
        {
            init(800, 600, "Carcadia");
            map_load(map, "spawn");
            mode = TILE_MODE;
        }

        void event();
        void update(float);
        void draw();
};

void Game::event()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        player.up();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        player.down();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        player.right();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        player.left();

    sf::Event event;
    while (window.pollEvent(event))
    {  
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                running = false;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                    running = false;
                }
                break;
        }
    }
}

void Game::update(float dt)
{
    player.update(dt);
}

void Game::draw()
{
    sf::View view(sf::FloatRect(0.f, 0.f, 400.f, 300.f));
    view.setCenter(player.getPosition());
    window.setView(view);
    window.clear();
    draw_map();
    window.draw(player);
}

int main(int argc, char const *argv[])
{

    Game g;

    g.start();

    return 0;
}