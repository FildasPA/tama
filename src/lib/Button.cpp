
#include <SFML/Graphics.hpp>
#include "button.h"

Button::Button()
{
	texture = NULL;
	sprite  = NULL;
}



bool Button::Click(RenderWindow &window)
{

	int mouseX = Mouse::getPosition(window).x;
	int mouseY = Mouse::getPosition(window).y;

	if(mouseX > Sprite.getPosition().x
	&& mouseX < (Sprite.getPosition().x + Sprite.getGlobalBounds().width)
	&& mouseY > Sprite.getPosition().y)
	&& mouseY < (Sprite.getPosition().y + Sprite.getGlobalBounds().height) {

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return true;
		}

		return false;
	}
return false;
}
