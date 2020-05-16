
#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"


class Graphics
{
    public:
        Graphics() {};
        void Draw(sf::RenderWindow* _window, Paddle* paddleOne, Paddle* paddleTwo, Ball* ball);
        void DrawPaddle(sf::Vector2<float> _pos, sf::RenderWindow* _window, int _width, int _height);
        void DrawBall(sf::Vector2<float> _pos, sf::RenderWindow* _window, int _radius);
        void DrawScore(sf::RenderWindow* _window, int p1_score, int p2_score);

    //private:
};
