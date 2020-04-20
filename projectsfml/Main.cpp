#include <SFML/Graphics.hpp>
#include "Paddle.h"

int main()
{
    //create a window for application
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Pong");
    
    Paddle p1(&window, 1), p2(&window, 2);

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


 
        window.clear();
      

        window.display();
    }

    return 0;
}