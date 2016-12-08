
//=============================================================================
// ▼ Pet
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __Pet
#define __Pet

#include <string>

class Pet
{
	private:

		// Variables
		string name;
		unsigned int generation;
		unsigned int health;
		unsigned int cleanliness;
		unsigned int weight;
		unsigned int hunger;
		unsigned int happiness;


	public:

		// Fonctions primaires
		Pet();
		~Pet();
		void generate();

		//
		void change_happiness(int n);

		// Actions
		void heal();
		void clean();
		void feed(int nutrition);

};

#endif
