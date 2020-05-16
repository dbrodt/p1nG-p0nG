#include "Ball.h"

const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 600;

const float UPDATE_MS = 33;

const float BALL_RADIUS = 10;
const float BALL_VELOCITY = 400;
const float BALL_VEL_INCR = 60;

const float PADDLE_WIDTH = 10;
const float PADDLE_LENGTH = 50;
const float PADDLE_PADDING = 20;
const float PADDLE_SPEED = 400;

const float COURT_MARGIN = 10;


Ball::Ball(float x, float y)
{
    position.x = x;
    position.y = y;

    ballShape.setSize(BALL_RADIUS);
    ballShape.setPosition(position);
}


Ball::~Ball()
{

}

sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::CircleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundPaddleOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;

}


void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}
 
void Ball::update()
{
    
    position.y += yVelocity;
    position.x += xVelocity;
 
    
    ballShape.setPosition(position);
}