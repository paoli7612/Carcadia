
#include "../include/editor.h"

void Editor::start()
{
    map_load(map, "spawn");

    window.create(sf::VideoMode(32*40, 32*25), "Carcadia - editor", sf::Style::Close);
    tools.create(sf::VideoMode(32*32, 32*32), "Carcadia", sf::Style::Titlebar);

    textures[INTERIOR].loadFromFile("img/interior.png");
    textures[OUTSIDE].loadFromFile("img/outside.png");
    textures[TERRAIN].loadFromFile("img/terrain.png");

    tools_back_sprite.setTexture(textures[tools_kind]);
    tools_back_sprite.setPosition(0, 0);
    //tools_back_sprite.setScale(0.8, 0.8);

    selector.texture.loadFromFile("img/cursor.png");
    selector.setTexture(selector.texture);
    selector.setPosition(0, 0);

    for (int i=0; i<3; i++)
        tile[i].setTexture(textures[i]);

    loop();
}

void Editor::loop()
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

void Editor::event()
{
    sf::Event event;
    // tools
    while (tools.pollEvent(event));
    
    // window
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        if (selector.iy)
                        {
                            selector.move(0, -32);
                            selector.iy -= 1;
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (selector.iy < 31)
                        {
                            selector.move(0, 32);
                            selector.iy += 1;
                        }
                        break;
                    case sf::Keyboard::Right:
                        if (selector.ix < 31)
                        {
                            selector.move(32, 0);
                            selector.ix += 1;
                        } 
                        break;
                    case sf::Keyboard::Left:
                        if (selector.ix)
                        {
                            selector.move(-32, 0);
                            selector.ix -= 1;
                        }
                        break;
                    
                    case sf::Keyboard::S:
                        map_save(map, "spawn");
                        break;
                }
                break;
            }
         
            case sf::Event::MouseMoved: {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    click(true);
                break;
            }
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                    click(true);
                else if (event.mouseButton.button == sf::Mouse::Right)
                    click(false);
                else if (event.mouseButton.button == sf::Mouse::Middle)
                    change_kind();
                break;
            case sf::Event::Closed:
                running = false;
                break;
        }
    }
}

void Editor::click(bool isRight)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    int x = pos.x/32;
    int y = pos.y/32;

    image_t image = {selector.ix, selector.iy, tools_kind};

    if (isRight)
        map_add_up(map, x, y, image);
    else
        map_add_down(map, x, y, image);
}

void Editor::change_kind()
{
    tools_kind = (kind_t)((tools_kind+1)%3);
    tools_back_sprite.setTexture(textures[tools_kind]);
}

void Editor::update()
{

}

void Editor::draw()
{
    // tools
    tools.clear();
    tools.draw(tools_back_sprite);
    tools.draw(selector);
    tools.display();
    // window
    window.clear();

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

    window.display();
}
