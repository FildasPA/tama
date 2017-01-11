
//=============================================================================
// ▼ File
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __button
#define __button

#include <SFML/Graphics.hpp>

class button 
{
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;


public:
	bool Click(sf::RenderWindow &window);
	

};

#endif


