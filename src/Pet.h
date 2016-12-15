
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
		std::string name;
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

		// Accesseurs
		std::string get_name();
		unsigned int get_generation();
		unsigned int get_weight();

		//
		void set_name(std::string);
		void set_generation(unsigned int);
		void set_weight(unsigned int);

		//
		void change_happiness(int n);

		// Actions
		void heal();
		void clean();
		void feed(int nutrition);

};

#endif
