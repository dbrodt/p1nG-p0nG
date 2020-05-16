
#pragma once

#include <SFML/Graphics.hpp>

const int PADDLE_VELOCITY_UP = 40;
const int PADDLE_VELOCITY_DOWN = -40;

class Paddle
{
    public:
        Paddle(int _width, int _height);
        void Update();

        float GetPositionX() { return m_position.x; };
        float GetPositionY() { return m_position.y; };
        //void UpdatePositionX(float _val) { m_position.x += _val; } // unused
        void UpdatePositionY(sf::RenderWindow* _window, float _val); // { m_position.y += _val; }
        void AddPositionY(float _val) { m_position.y += _val; }
        sf::Vector2<float> GetPositionVector() { return m_position; }
        float GetWidth() { return m_width; }
        float GetHeight() { return m_height; }

        void AddScore() { ++m_score; }
        int GetScore() { return m_score; }

        float PaddleOneControl();
        float PaddleTwoControl();

        void SetPosition(float x, float y)
        {
            m_position.x = x;
            m_position.y = y;
        }

        void SetSize(int _width, int _height)
        {
            m_width = _width;
            m_height = _height;
        }

    private:
        sf::Vector2<float> m_position;
        int m_width;
        int m_height;
        int m_score;
};

