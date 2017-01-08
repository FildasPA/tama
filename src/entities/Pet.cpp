
#include <iostream>
#include <string>
#include <fstream>

#include "../conf/files_names.h"
#include "../lib/colors.h"
#include "../lib/types.h"
#include "../lib/file.h"
#include "Pet.h"


//=============================================================================
// ▼ Constantes
// ----------------------------------------------------------------------------
//
//=============================================================================

namespace defaultChara
{
	unsigned int health      = 0;
	unsigned int cleanliness = 0;
	unsigned int weight      = 0;
	unsigned int hunger      = 0;
	unsigned int happiness   = 0;
}

namespace max
{
	unsigned int health      = 100;
	unsigned int cleanliness = 100;
	unsigned int weight      = 100;
	unsigned int hunger      = 100;
	unsigned int happiness   = 5;
}

namespace variation
{
	unsigned int hunger = 1;
	unsigned int weight = 1;

	namespace happiness
	{
		const int feed  = 1;
		const int heal  = 1;
		const int clean = 1;
	}
}

//=============================================================================
// ▼ Fonctions primaires
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Constructeur
// Si un fichier pet existe, récupère les informations qui s'y trouvent.
// Sinon, génère un nouveau Pet avant de l'écrire ses caractéristiques dans
// un fichier.
//-----------------------------------------------------------------------------
Pet::Pet()
{
	if(file::exists(files::petInfos.c_str()))
		readInfos();
	else {
		std::cout << "Choix de l'oeuf..." << std::endl;
		generate(0);
		writeInfos();
	}
}

//-----------------------------------------------------------------------------
// * Destructeur
//-----------------------------------------------------------------------------
Pet::~Pet()
{
}

//-----------------------------------------------------------------------------
// * Generate
//-----------------------------------------------------------------------------
void Pet::generate(unsigned int generation)
{
	std::cout << "Génération du pet..." << std::endl;

	std::cout << "Veuillez donner un nom à donner au pet: ";
	getline(std::cin,name);

	health      = defaultChara::health;
	cleanliness = defaultChara::cleanliness;
	weight      = defaultChara::weight;
	hunger      = defaultChara::hunger;
	happiness   = defaultChara::happiness;

	this->generation  = generation;
}

//=============================================================================
// ▼ Accesseurs et moduleurs
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Get name
//-----------------------------------------------------------------------------
std::string Pet::getName() { return name; }

//-----------------------------------------------------------------------------
// * Get generation
//-----------------------------------------------------------------------------
unsigned int Pet::getGeneration() { return generation; }

//-----------------------------------------------------------------------------
// * Get health
//-----------------------------------------------------------------------------
unsigned int Pet::getHealth() { return health; }

//-----------------------------------------------------------------------------
// * Get cleanliness
//-----------------------------------------------------------------------------
unsigned int Pet::getCleanliness() { return cleanliness; }

//-----------------------------------------------------------------------------
// * Get weight
//-----------------------------------------------------------------------------
unsigned int Pet::getWeight() { return weight; }

//-----------------------------------------------------------------------------
// * Get hunger
//-----------------------------------------------------------------------------
unsigned int Pet::getHunger() { return hunger; }

//-----------------------------------------------------------------------------
// * Get happiness
//-----------------------------------------------------------------------------
unsigned int Pet::getHappiness() { return happiness; }



//=============================================================================
// ▼ Mutateurs
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Set name
//-----------------------------------------------------------------------------
void Pet::setName(std::string name) { this->name = name; }
//-----------------------------------------------------------------------------
// * Set generation
//-----------------------------------------------------------------------------
void Pet::setGeneration(unsigned int generation) { this->generation = generation; }

//-----------------------------------------------------------------------------
// * Set health
//-----------------------------------------------------------------------------
void Pet::setHealth(unsigned int health) { this->health = health; }

//-----------------------------------------------------------------------------
// * Set cleanliness
//-----------------------------------------------------------------------------
void Pet::setCleanliness(unsigned int cleanliness) { this->cleanliness = cleanliness; }

//-----------------------------------------------------------------------------
// * Set weight
//-----------------------------------------------------------------------------
void Pet::setWeight(unsigned int weight) { this->weight = weight; }

//-----------------------------------------------------------------------------
// * Set hunger
//-----------------------------------------------------------------------------
void Pet::setHunger(unsigned int hunger) { this->hunger = hunger; }

//-----------------------------------------------------------------------------
// * Set happiness
//-----------------------------------------------------------------------------
void Pet::setHappiness(unsigned int happiness) { this->happiness = happiness; }

//-----------------------------------------------------------------------------
// * Set value from string
//-----------------------------------------------------------------------------
void Pet::setValueFromString(std::string parameter, std::string value,
                             bool &success)
{
	// std::cout << "  Parameter: " << parameter << std::endl;
	// std::cout << "  Value:     " << value << std::endl;
	     if(parameter == "name")        setName(value);
	else if(parameter == "generation")  setGeneration((unsigned int) types::stoi(value));
	else if(parameter == "health")      setHealth((unsigned int) types::stoi(value));
	else if(parameter == "cleanliness") setCleanliness((unsigned int) types::stoi(value));
	else if(parameter == "weight")      setWeight((unsigned int) types::stoi(value));
	else if(parameter == "hunger")      setHunger((unsigned int) types::stoi(value));
	else if(parameter == "happiness")   setHappiness((unsigned int) types::stoi(value));
	else {
		if(success) std::cout << std::endl;
		std::cerr << YELLOW << "      Avertissement:" << RESET << " paramètre ";
		std::cerr << parameter << " inconnu." << std::endl;
		success = false;
	}
}

//-----------------------------------------------------------------------------
// * Increase happiness
//-----------------------------------------------------------------------------
void Pet::changeHappiness(int n)
{
	this->happiness += 1;
	if(this->happiness >= max::happiness) this->happiness = max::happiness;
}


//=============================================================================
// ▼ Actions
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Feed
// Decrease hunger and increase weight.
// Increase happiness.
//-----------------------------------------------------------------------------
void Pet::feed(int nutrition)
{
	this->hunger += variation::hunger * nutrition;
	if(this->hunger > max::hunger) this->hunger = max::hunger;

	this->weight += variation::weight * nutrition;
	if(this->weight > max::weight) this->weight = max::weight;

	changeHappiness(variation::happiness::feed);
}

//-----------------------------------------------------------------------------
// * Heal
// Set "health" attribute to max.
// Increase happiness.
//-----------------------------------------------------------------------------
void Pet::heal()
{
	this->health = max::health;

	changeHappiness(variation::happiness::heal);
}

//-----------------------------------------------------------------------------
// * Wash
// Set "cleanliness" attribute to max.
// Increase happiness.
//-----------------------------------------------------------------------------
void Pet::clean()
{
	this->cleanliness = max::cleanliness;

	changeHappiness(variation::happiness::clean);
}

//=============================================================================
// ▼ File
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Read infos
//-----------------------------------------------------------------------------
void Pet::readInfos()
{
	std::cout << BLUE << "    Récupération des données du familier..." << RESET;

	const char* fileName = files::petInfos.c_str();
	std::ifstream file(fileName);
	if(!file.is_open()) return file::errorCantOpen(fileName);

	bool success = true;
	std::size_t f;
	std::string line;
	std::string parameter, value;

	while(getline(file,line)) {
		if((f = line.find(":")) == std::string::npos) continue;
		parameter  = line.substr(0,f);
		value      = line.substr(f+2);
		setValueFromString(parameter,value,success);
	}

	file.close();
	std::cout << GREEN << "\r  ✔ Données du familier récupérées!        ";
	std::cout << RESET << std::endl;
}

//-----------------------------------------------------------------------------
// * Write infos
//-----------------------------------------------------------------------------
void Pet::writeInfos()
{
	std::cout << BLUE << "    Sauvegarde des données du familier..." << RESET;

	const char *fileName = files::petInfos.c_str();
	std::ofstream file(fileName);
	if(!file.is_open()) return file::errorCantOpen(fileName);

	file << "name: "        << name        << std::endl;
	file << "generation: "  << generation  << std::endl;
	file << "health: "      << health      << std::endl;
	file << "cleanliness: " << cleanliness << std::endl;
	file << "weight: "      << weight      << std::endl;
	file << "hunger: "      << hunger      << std::endl;
	file << "happiness: "   << happiness   << std::endl;

	std::cout << GREEN << "\r  ✔ Données du familier sauvegardées!    ";
	std::cout << RESET << std::endl;
	file.close();
}


//=============================================================================
// ▼ Affichage
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Afficher
//-----------------------------------------------------------------------------
void Pet::printCharacteristics()
{
	std::cout << YELLOW << "Caractéristiques du familier:" << RESET<< std::endl;
	std::cout << "  name:        " << GREEN << name        << RESET << std::endl;
	std::cout << "  generation:  " << GREEN << generation  << RESET << std::endl;
	std::cout << "  health:      " << GREEN << health      << RESET << std::endl;
	std::cout << "  cleanliness: " << GREEN << cleanliness << RESET << std::endl;
	std::cout << "  weight:      " << GREEN << weight      << RESET << std::endl;
	std::cout << "  hunger:      " << GREEN << hunger      << RESET << std::endl;
	std::cout << "  happiness:   " << GREEN << happiness   << RESET << std::endl;
}
