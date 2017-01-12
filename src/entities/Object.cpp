
#include <string>
// #include <SFML/Graphics.hpp>

#include "Object.h"

//=============================================================================
// ▼ Fonctions primaires
// ----------------------------------------------------------------------------
// Constructeurs
//=============================================================================


//-----------------------------------------------------------------------------
// * Constructeur
//-----------------------------------------------------------------------------
Object::Object()
{
	id          = 0;
	name        = "";
	description = "";
}

//-----------------------------------------------------------------------------
// * Constructeur (unsigned int)
// Créer un objet Object à partir son id.
// Récupère les informations dans un fichier.
//-----------------------------------------------------------------------------
Object::Object(unsigned int id)
{
	id          = id;
	// name        = ...;
	// description = ...;
}

//-----------------------------------------------------------------------------
// * Constructeur (unsigned int,string,string)
//-----------------------------------------------------------------------------
Object::Object(unsigned int id,std::string name,std::string picture)
{
	this->id   = id;
	this->name = name;
	// if(!texture.loadFromFile(picture)) {
   		// return;
	// }
	// sprite.setTexture(texture);
}
