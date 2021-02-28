#include <SFML/Graphics.hpp>

const int WIDTH = 1080, HEIGHT = 1080;
const char TITLE[] = "paoli7612 - Carcadia";


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("img/back.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
