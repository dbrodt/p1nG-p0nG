#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Paddle.h"


class Ball
{
    sf::RectangleShape ballShape;
    float xVelocity = 0.2f;
    float yVelocity = 0.2f;
    sf::Vector2f position;
    

public:
    Ball(float x, float y);
    ~Ball();

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundPaddleOrTop();

    void hitBottom();

    void update();
};