#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.cc"

#define WIDTH 960
#define HEIGHT 640
#define TITLE "Carcadia"

// g++ main.cc -lsfml-graphics -lsfml-window -lsfml-system

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);;
Event event;
Player player;
Clock c;

void _load(){
    player = Player();
    player.load();
}

void _event(){
    while (window.pollEvent(event)){        
        switch (event.type) {
            // QUIT
            case Event::Closed:{
                window.close();
                break;
            }
            // KEYPRESSED
            case Event::KeyPressed:{
                switch (event.key.code) {
                    case  Keyboard::Escape:
                        window.close(); break;
                    case Keyboard::Up:
                        player.dy = -1; break;
                    case Keyboard::Down:
                        player.dy = 1; break;
                    case Keyboard::Left:
                        player.dx = -1; break;
                    case Keyboard::Right:
                        player.dx = 1; break;
                }
                break;
            }
            // KEYRELEASED
            case Event::KeyReleased:{
                switch (event.key.code) {
                    case Keyboard::Up:
                    case Keyboard::Down:
                        player.dy = 0; break;
                    case Keyboard::Left:
                    case Keyboard::Right:
                        player.dx = 0; break;
                }
                break;
            }
        }
    }
}

void _update(float dt){
    player.update(dt);
}

void _draw(){
    window.clear();
    window.draw(player.sprite);
    window.display();
}

int main(int argc, char** argv){
    _load();
    while (window.isOpen()){

        if (c.getElapsedTime().asSeconds() >= 1.0f / 60){
            float dt = c.getElapsedTime().asSeconds();
            _event();
            _update(dt);
            _draw();
            c.restart();
        }
    }
    return 0;
}
