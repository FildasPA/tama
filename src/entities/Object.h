
#ifndef __Object
#define __Object

#include <string>
// #include <SFML/Graphics.hpp>



//=============================================================================
// ▼ Object
// ----------------------------------------------------------------------------
//
//=============================================================================

class Object
{
	private:
		unsigned int id;
		std::string name;
		std::string description;
		// sf::Sprite sprite;
		// sf::Texture texture;

	public:

		// Fonctions primaires
		Object();
		Object(unsigned int);
		Object(unsigned int,std::string,std::string);
		// Object(unsigned int,string,string);

};

#endif
