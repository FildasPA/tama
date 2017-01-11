
//=============================================================================
// ▼ File
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __button
#define __button

#include <SFML/Graphics.hpp>
using namespace sf;

class Button
{

	private:
		Texture texture;
		Sprite  sprite;

	public:

		Button(const char*);
		bool isClicked(sf::RenderWindow &window);


};

#endif


