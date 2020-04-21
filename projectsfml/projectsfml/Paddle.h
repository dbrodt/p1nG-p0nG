#pragma once
#include <SFML/Graphics.hpp>


class Paddle {
	sf::RectangleShape rectangle;
	float rect_velocity;
	int score;
public:
	Paddle();
	~Paddle();

	void increment_score() {	score++; }
	int get_score() {	return score; };
	void draw(sf::RenderWindow& window);
	sf::RectangleShape get_rect();
	void update();

};