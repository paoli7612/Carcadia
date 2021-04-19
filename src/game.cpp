// game

#include <iostream>

#include "../include/loop.h"
#include "../include/map.h"
#include "../include/player.h"

using namespace std;

class Game : public Loop {
    public:
        Player player;
        sf::View view;


        Game()
        {
            init(800, 600, "Carcadia");
            map_load(map, "spawn");
            view.setSize((sf::Vector2f){400, 400});
            window.setView(view);
        }

        void event();
        void update(float);
        void draw();
};

void Game::event()
{
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

    


    window.display();

}

int main(int argc, char const *argv[])
{

    Game g;

    g.start();

    return 0;
}
