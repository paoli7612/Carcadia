#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/editor.h"

using namespace std;

int main(int argc, char **argv)
{
    Editor editor;

    string name;

    if (argc != 2)
    {
        cout << "Inserisc il nome della mappa da modificare: ";
        cin >> name;
    }
    else
    {
        name = argv[1];
    }

    editor.start(name);
    
    exit(0);
}
