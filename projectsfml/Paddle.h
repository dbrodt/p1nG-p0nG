#pragma once
#include <SFML/Graphics.hpp>


class Paddle {
	sf::RenderWindow* window; // „T„{„p„x„p„„„u„|„Ž „~„p „€„{„~„€, „~„…„w„u„~ „t„|„‘ „€„„„‚„y„ƒ„€„r„{„y
	sf::RectangleShape rectangle; // „R„€„q„ƒ„„„r„u„~„~„€, „ƒ„p„}„p „‚„p„{„u„„„{„p
	float y; // „K„€„€„‚„t„y„~„p„„„p y „‚„p„{„u„„„{„y (x „}„ „x„p„t„p„u„} „r „{„€„t„u)
	int player; // „N„€„}„u„‚ „y„s„‚„€„{„p (1 „y„|„y 2)
	int score;
public:
	Paddle(sf::RenderWindow* window, int player);
	~Paddle() {};
	void increment_score() {	score++; }
	int get_score() {	return score; };
	void draw() {	this->window->draw(this->rectangle); }
	void set_position(int x, int y) {rectangle.setPosition(x, y);}
	sf::Vector2f get_size(){return sf::Vector2f(	rectangle.getLocalBounds().width, rectangle.getLocalBounds().height);}
	sf::Vector2f get_y(){	return rectangle.getPosition();}
	void update(float y, unsigned int windowHeight);

};