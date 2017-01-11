
#include <SFML/Graphics.hpp>
#include "button.h"

bool Click(RenderWindow &window) 
{

	int mouseX = Mouse::getPosition(window).x;
	int mouseY = Mouse::getPosition(window).y;

	if(mouseX > buttonSprite.getPosition().x
	&& mouseX < (buttonSprite.getPosition().x + buttonSprite.getGlobalBounds().width)
	&& mouseY > buttonSprite.getPosition().y)
	&& mouseY < (buttonSprite.getPosition().y + buttonSprite.getGlobalBounds().height) {

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return true;
		}

		return false;
	}
return false;
}
