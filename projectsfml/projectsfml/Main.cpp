#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Paddle.h"
#include "Ball.h"

const unsigned WIDTH = 800;
const unsigned HEIGHT = 600;

int main()
{
    Graphics* gameWindow = new Graphics();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong Clone");

    Paddle paddleOne(10, 100); // 100 - same value as in Paddle::UpdatePositionY()
    paddleOne.SetPosition(50, 250);

    Paddle paddleTwo(10, 100);
    paddleTwo.SetPosition(750, 250);

    Ball ball(5);
    ball.SetVelocity(3, 1);
    ball.SetPosition(400, 300);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        paddleOne.UpdatePositionY(&window, paddleOne.PaddleOneControl());
        paddleTwo.UpdatePositionY(&window, paddleTwo.PaddleTwoControl());

        paddleOne.Update();
        paddleTwo.Update();

        ball.Update(&paddleOne, &paddleTwo, HEIGHT);

        if (ball.GetPositionX() > WIDTH) // player 1 scored
        {
            paddleOne.AddScore();
            ball.SetPosition(400, 300); // reset the ball's position
        }

        if (ball.GetPositionX() < 0) // played 2 scored
        {
            paddleTwo.AddScore();
            ball.SetPosition(400, 300); // reset the ball's position
        }

        gameWindow->Draw(&window, &paddleOne, &paddleTwo, &ball);
    }

    return 0;
}