#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow* window, int player) {
	this->score = 0;
	this->y = 300;
	this->player = player;
	
	this->window = window;
	this->rectangle.setSize(sf::Vector2f(10, 100));

	this->rectangle.setOrigin(5, 50);

	if (this->player == 1) {
		this->rectangle.setPosition(25, this->y);
	}
	else {
		this->rectangle.setPosition(775, this->y);
	}
}


void Paddle::update(float y, unsigned int windowHeight) {
	if (this->player == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			if (get_y().y <= 0)
			{
				return;
			}
			rectangle.move(0, -y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (get_y().y + get_size().y >= windowHeight)
			{
				return;
			}
			rectangle.move(0, y);
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			if (get_y().y <= 0)
			{
				return;
			}
			rectangle.move(0, -y);
		}
		if (get_y().y + get_size().y >= windowHeight)
		{
			return;
		}
		rectangle.move(0, y);
	}
};
