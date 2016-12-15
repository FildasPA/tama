
#ifndef __Shop
#define __Shop

#include <list>
#include <string>
#include "Object.h"
#include "Food.h"
#include "List.h"

//--------------------------------------------
// * Class object
//--------------------------------------------

class Shop
{
	private:
		std::list<Object> Storage;
		List list;

	public:

		// Fonctions primaires
		Shop();

		// Créer objets
		void generateObjects();
		void createObject();
		void createFood();

		// Affichage
		// void

		// Opérations
		void buySelectedObject();
		void updateList();

		void createRandomObject();
		void randomObjects(unsigned int number);
		void createObject(std::string name, std::string description, std::string picture, int nutrition=0);
		void displayStorage();
};

#endif
