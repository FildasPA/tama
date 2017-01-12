
//=============================================================================
// ▼ Button
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __Button
#define __Button

#include <SFML/Graphics.hpp>
using namespace sf;

class Button
{

	private:
		Texture texture;

	public:
		Sprite  sprite;
		Button(const char*);
		bool isClicked(sf::RenderWindow &window);


};

#endif


