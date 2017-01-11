
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

//-----------------------------------------------------------------------------
// * Constructeur
//-----------------------------------------------------------------------------
Button::Button(const char* fileName)
{
	if(!texture.loadFromFile(fileName))
		std::cerr << "Erreur chargement de la texture " << fileName << std::endl;
	else
		sprite.setTexture(texture);
}

//-----------------------------------------------------------------------------
// * Is button clicked?
//-----------------------------------------------------------------------------
bool Button::isClicked(RenderWindow &window)
{
	int mouseX = Mouse::getPosition(window).x;
	int mouseY = Mouse::getPosition(window).y;

	return (mouseX > sprite.getPosition().x &&
	        mouseY > sprite.getPosition().y &&
	        mouseX < (sprite.getPosition().x + sprite.getGlobalBounds().width) &&
	        mouseY < (sprite.getPosition().y + sprite.getGlobalBounds().height) &&
	        Mouse::isButtonPressed(Mouse::Left));
}
