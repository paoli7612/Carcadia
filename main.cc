#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.cc"
#include "tutorial.cc"

#define WIDTH 960
#define HEIGHT 640
#define TITLE "Carcadia"

// g++ main.cc -lsfml-graphics -lsfml-window -lsfml-system

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);;

Event event;
Player player;
Tutorial tutorial;
Clock c;
float dt;

void _load(){

    player = Player();
    player.load(100, 39,'1');
    tutorial.load();
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
                    // Escape
                    case  Keyboard::Escape:
                        window.close(); break;
                    // Arrow
                    case Keyboard::Up:
                        player.dy = -1; break;
                    case Keyboard::Down:
                        player.dy = 1; break;
                    case Keyboard::Left:
                        player.dx = -1; break;
                    case Keyboard::Right:
                        player.dx = 1; break;
                    // Q W
                    case Keyboard::Q:
                        player.use(kick); break;
                    case Keyboard::W:
                        player.use(punch); break;
                    // P
                    case Keyboard::P:
                        player.change(); break;
                }
                break;
            }
            // KEYRELEASED
            case Event::KeyReleased:{
                switch (event.key.code) {
                    // Arrow
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
    window.clear(Color(100,100,100,1));

    window.draw(player.sprite);
    tutorial.draw(window);
    window.display();
}

int main(int argc, char** argv){
    _load();
    while (window.isOpen()){
        if (c.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = c.getElapsedTime().asSeconds();
            c.restart();
        } else continue;
        _event();
        _update(dt);
        _draw();
    }
    return 0;
}
