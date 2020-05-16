
#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
    public:
        Ball(int _radius);
        void Update(Paddle* paddleOne, Paddle* paddleTwo, int _height);
        sf::Vector2<float> GetPositionVector() { return m_position; }

        float GetPositionX() { return m_position.x; }
        float GetPositionY() { return m_position.y; }

        int GetRadius() { return m_radius; }

        void SetPosition(float x, float y)
        {
            m_position.x = x;
            m_position.y = y;
        }

        void SetVelocity(float x, float y)
        {
            m_velocity.x = x;
            m_velocity.y = y;
        }

        void SetRadius(int _radius)
        {
            m_radius = _radius;
        }

    private:
        sf::Vector2<float> m_position;
        sf::Vector2<float> m_velocity;
        int m_radius;
};

