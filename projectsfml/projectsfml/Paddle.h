#pragma once
#include <SFML/Graphics.hpp>


class Paddle {
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	float speed = 0.3f;

public:
	Paddle(float x, float y);
	~Paddle();
	
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void update();

};