#pragma once

#include <SFML/Graphics.hpp>

const int MAX_NUMBER_ITEMS = 3;

class Menu
{
public:
	Menu(float _width, float _height);
	~Menu();

	void draw(sf::RenderWindow& _window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectecItemIndex; }

private:
	int selectecItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_ITEMS];
};