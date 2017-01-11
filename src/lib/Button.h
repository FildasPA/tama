
//=============================================================================
// ▼ File
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __button
#define __button

#include <SFML/Graphics.hpp>

class Button 
{
	sf::Texture Texture;
	sf::Sprite Sprite;


public:
	Button();
	Button(Texture texture, Sprite sprite);
	bool Click(sf::RenderWindow &window);
	

};

#endif


