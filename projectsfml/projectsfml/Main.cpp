#include <SFML/Graphics.hpp>
#include "Paddle.h"

int main()
{
    //create a window for application
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Pong");
    window.setFramerateLimit(60);

    Paddle p1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //besides the usual exit, we can exit via esc button
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        p1.update();
 
        window.clear();
        p1.draw(window);

        window.display();
    }

    return 0;
}