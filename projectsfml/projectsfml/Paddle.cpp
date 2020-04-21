#include "Paddle.h"

Paddle::Paddle() {
	score = 0;
	rectangle.setSize(sf::Vector2f(10, 100));
	rectangle.setOrigin(rectangle.getSize().x/2, rectangle.getSize().y/2);
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(25, 300);
}

Paddle::~Paddle(){

	}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
}

sf::RectangleShape Paddle::get_rect() {
	return rectangle;
}

void Paddle::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		if (rectangle.getPosition().y-30-100 <= 0)
		{
			rectangle.setPosition(rectangle.getPosition().x, 50);
			return;
		}
		rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y-30);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (rectangle.getPosition().y+30+100 >= 600)
		{
			rectangle.setPosition(rectangle.getPosition().x, 550);
			return;
		}
		rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y+30);
	}
};