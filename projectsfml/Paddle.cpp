#include "Paddle.h"

Paddle::Paddle(int _width, int _height)
{
    SetSize(_width, _height);

    m_score = 0;
}

void Paddle::Update()
{
    // to add paddle control in Update() for both paddles
}

// paddle collision
void Paddle::UpdatePositionY(sf::RenderWindow* _window, float _val)
{
    int window_y = _window->getSize().y;

    // if y + value > maximum y down - the height of the paddle
    if (GetPositionY() + _val > window_y - GetHeight()) // down collision
    {
        return;
    }
    // if y + value < minimum y up
    if (GetPositionY() + _val < 0) // up collision
        {
            return;
        }

    else AddPositionY(_val);
}

float Paddle::PaddleOneControl()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        return PADDLE_VELOCITY_DOWN;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return PADDLE_VELOCITY_UP;

    return 0;
}

float Paddle::PaddleTwoControl()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        return PADDLE_VELOCITY_DOWN;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        return PADDLE_VELOCITY_UP;

    return 0;
}
