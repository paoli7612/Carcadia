
#include "../include/cursor.h"

Cursor::Cursor()
{
    texture.loadFromFile("img/cursor.png");
    setTexture(texture);
    setPosition(0, 0);
}

void Cursor::up()
{
    move(0, -32);
    y--;
}

void Cursor::down()
{
    move(0, 32);
    y++;
}

void Cursor::right()
{
    move(32, 0);
    x++;
}

void Cursor::left()
{
    move(-32, 0);
    x--;
}



