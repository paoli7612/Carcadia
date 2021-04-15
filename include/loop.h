#ifndef INCLUDE_LOOP_H_
#define INCLUDE_LOOP_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Loop {
    private:
        sf::Clock clock;
        float dt;

    protected:
        bool running;

        sf::RenderWindow window;

        void init(const int, const int, const char *);
        void set_fun(void *e(void), void *u(float), void *d(void));
        
    public:
        virtual void event(){}
        virtual void update(float){}
        virtual void draw(){}

        void start();
        
};

#endif /* INCLUDE_LOOP_H_ */
