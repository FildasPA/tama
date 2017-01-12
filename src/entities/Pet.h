
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

		// Charactéristiques
		std::string name;
		int generation;
		int health;
		int cleanliness;
		int weight;
		int hunger;
		int happiness;

		// Modifications
		void decreaseHunger(int);
		void increaseHunger(int);
		void decreaseWeight(int);
		void increaseWeight(int);

		// Dégradation
		// void degradeStateAccordingToPassedTime(unsigned int);

		void updateCharacteristics();
		int getLastSessionTime();

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

		// Modifications
		// void updateState();
		// void degradeState();
		void changeHappiness(int n);
		void degradeCharacteristics();

		// Actions
		void heal();
		void play();
		void wash();
		void feed(int nutrition);

		// Vérifications
		bool isDead();
		bool isSick();
		bool isHungry();
		bool isDirty();
		bool isSad();
		bool isHappy();

		// Fichier
		void readInfos();
		void writeInfos();

		// Affichage
		void printCharacteristics();
		void changeCharacteristicsAccordingToPassedTime(unsigned int);
};

#endif
