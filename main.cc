#include <SFML/Graphics.hpp>

#include "classes/map.h"

// window
const int WIDTH = W*T, HEIGHT = H*T;
const char TITLE[] = "paoli7612 - Carcadia";

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE, Style::Close);
    /*Texture texture;
    if (!texture.loadFromFile("img/back.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);*/
    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    Text text("Hello SFML", font, 50);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color(160, 20, 50));
        //window.draw(sprite);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
