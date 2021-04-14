#ifndef INCLUDE_LOOP_H_
#define INCLUDE_LOOP_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Loop {
    private:
        sf::Clock clock;
        bool running;
        float dt;
        sf::RenderWindow window;

    protected:
        void init(const int, const int, const char *);
        void set_fun(void *e(void), void *u(float), void *d(void));
    public:
        void event();
        void update(float);
        void draw();

        void start();
        
};

#endif /* INCLUDE_LOOP_H_ */
