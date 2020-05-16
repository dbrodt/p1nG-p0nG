#include "Paddle.h"

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



Paddle::Paddle(float x, float y) {
	position.x = x;
	position.y = y;
	rectangle.setSize(sf::Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
	rectangle.setPosition(position);
}

Paddle::~Paddle(){

	}

sf::FloatRect Paddle::getPosition()
{
    return rectangle.getGlobalBounds();
}
 
sf::RectangleShape Paddle::getShape()
{
    return rectangle;
}
 
void Paddle::moveLeft()
{
	position.x -= speed;
}
 
void Paddle::moveRight()
{
    position.x += speed;
}
 
void Paddle::update()
{
    rectangle.setPosition(position);
}