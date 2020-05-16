#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include <iostream>
#include <string>
#include <sstream>

void Graphics::Draw(sf::RenderWindow* _window, Paddle* paddleOne, Paddle* paddleTwo, Ball* ball)
{
    _window->clear();

    DrawPaddle(paddleOne->GetPositionVector(), _window, paddleOne->GetWidth(), paddleOne->GetHeight());
    DrawPaddle(paddleTwo->GetPositionVector(), _window, paddleTwo->GetWidth(), paddleTwo->GetHeight());

    DrawBall(ball->GetPositionVector(), _window, ball->GetRadius());

    DrawScore(_window, paddleOne->GetScore(), paddleTwo->GetScore());

    _window->display();
}

void Graphics::DrawPaddle(sf::Vector2<float> _pos, sf::RenderWindow* _window, int _width, int _height)
{
    sf::RectangleShape paddle(sf::Vector2f(_width, _height));

    paddle.setPosition(_pos.x, _pos.y);
    paddle.setFillColor(sf::Color(255, 255, 255));

    _window->draw(paddle);
}

void Graphics::DrawBall(sf::Vector2<float> _pos, sf::RenderWindow* _window, int _radius)
{
    sf::CircleShape ball(_radius);

    ball.setPosition(_pos.x, _pos.y);
    ball.setFillColor(sf::Color(255, 0, 0));

    _window->draw(ball);
}

void Graphics::DrawScore(sf::RenderWindow* _window, int p1_score, int p2_score)
{
        sf::Font font;

        font.loadFromFile("TimesNewRoman.ttf");

        std::ostringstream tmp;
        tmp << p1_score << " - " << p2_score;

        sf::Text text(tmp.str(), font);
        text.setCharacterSize(165);

        text.setPosition(795, 0);

        _window->draw(text);
}
