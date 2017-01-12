
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
		unsigned int generation;
		unsigned int health;
		unsigned int cleanliness;
		unsigned int weight;
		unsigned int hunger;
		unsigned int happiness;

		// Etats
		bool dead;
		bool sick;
		bool dirty;
		bool hungry;
		bool happy, sad;

		// Vérifier les états
		void checkAliveState();
		void checkHealthState();
		void checkCleanlinessState();
		void checkHungerState();
		void checkHappinessState();

		// Modifications
		void decreaseHunger(int);
		void increaseHunger(int);
		void decreaseWeight(int);
		void increaseWeight(int);

		// Dégradation
		void decayState();
		void decayStateAccordingToPassedTime(unsigned int);

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
		void updateState();
		void degradeState();
		void changeHappiness(int n);

		// Actions
		void heal();
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
		void changeStateAccordingToPassedTime(unsigned int);
};

#endif
