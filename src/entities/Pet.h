
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
		void generate(unsigned int);

		// Accesseurs
		std::string getName();
		unsigned int getGeneration();
		unsigned int getHealth();
		unsigned int getCleanliness();
		unsigned int getWeight();
		unsigned int getHunger();
		unsigned int getHappiness();

		// Mutateurs
		void setName(std::string);
		void setGeneration(unsigned int);
		void setHealth(unsigned int);
		void setCleanliness(unsigned int);
		void setWeight(unsigned int);
		void setHunger(unsigned int);
		void setHappiness(unsigned int);
		void setValueFromString(std::string,std::string,bool&);
		void changeHappiness(int n);

		// Actions
		void heal();
		void clean();
		void feed(int nutrition);

		// Fichier
		void readInfos();
		void writeInfos();

		// Affichage
		void printCharacteristics();
};

#endif
