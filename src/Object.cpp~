#include <string>
#include <SFML/Graphics.hpp>

Object::Object()
{
	name = "";
	id = null;
	description = "";
	
}


Object::Object(string name, int id)
{
	this.name = name;
	this.id = id;
	if (!texture.loadFromFile(picture)){
   		return -1;
	}
	sprite.setTexture(texture);
}
