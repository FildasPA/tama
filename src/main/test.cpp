
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

// #include "menus/Object.h"
// #include "menus/Food.h"
// #include "menus/Shop.h"
#include "../entities/Pet.h"
#include "../entities/User.h"

#include "../lib/types.h"
#include "../lib/file.h"

#include "../lib/colors.cpp"
#include "../conf/files_names.h"

//=============================================================================
// ▼ Constantes
//=============================================================================

Pet *pet;
User *user;


//=============================================================================
// ▼ User
// ----------------------------------------------------------------------------
// Fonctions gérant la création/récupération des données de l'utilisateur dans
// un fichier.
//=============================================================================

//-----------------------------------------------------------------------------
// * Get user
//-----------------------------------------------------------------------------
void getUser()
{
	user = new User();
}


//=============================================================================
// ▼ Pet
// ----------------------------------------------------------------------------
// Fonctions gérant la création/récupération des données du familier dans un
// fichier.
//=============================================================================

//-----------------------------------------------------------------------------
// * Get Pet
//-----------------------------------------------------------------------------
void getPet()
{
	pet = new Pet();
}

//-----------------------------------------------------------------------------
// * Get last session time
//-----------------------------------------------------------------------------
int getLastSessionTime()
{
	std::cout << BLUE << "    Récupéraction de la date de la dernière session..." << RESET;

	const char* fileName = files::lastSessionDate.c_str();
	std::ifstream file(fileName);
	if(!file.is_open()) {
		file::errorCantOpen(fileName);
		return 0;
	}

	std::string line;
	getline(file,line);
	file.close();

	std::cout << GREEN << "\r  ✔ Date de la dernière session récupérée!         ";
	std::cout << RESET << std::endl;

	return types::stoi(line);
}

//-----------------------------------------------------------------------------
// * Write session time
//-----------------------------------------------------------------------------
void writeSessionTime()
{
	std::cout << BLUE << "    Sauvegarde de la date..." << RESET;

	const char *fileName = files::lastSessionDate.c_str();
	std::ofstream file(fileName);
	if(!file.is_open()) return file::errorCantOpen(fileName);

	file << time(NULL) << std::endl;

	file.close();
	std::cout << GREEN << "\r  ✔ Date sauvegardée!    ";
	std::cout << RESET << std::endl;
}

//-----------------------------------------------------------------------------
// * Update pet state
//-----------------------------------------------------------------------------
void updatePetState()
{
	int lastSessionTime, now, minutesLeft;
	now = time(NULL);

	std::cout << BLUE << "    Modification de l'état du familier..." << RESET;
	const char* fileName = files::lastSessionDate.c_str();
	if(file::exists(fileName)) {
		lastSessionTime = getLastSessionTime();
		now = time(NULL);
		minutesLeft = (now - lastSessionTime) / 60;
		std::cout << "Nombre de minutes passées: " << minutesLeft << std::endl;
		pet->changeStateAccordingToPassedTime(minutesLeft);
		std::cout << GREEN << "\r  ✔ Modifié l'état du familier!         ";
	} else
		std::cout << GREEN << "\r  ✔ Pas besoin de modifier l'état du familier!";
	std::cout << RESET << std::endl;
}



//=============================================================================
// ▼ Genealogy
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Get genealogy
//-----------------------------------------------------------------------------
void getGenealogy()
{
	// std::cout <<   "Récupération des données du pet...";
	// std::cout << "\rDonnées du pet récupérées!          " << std::endl;
}


//=============================================================================
// ▼ Main
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Print title
//-----------------------------------------------------------------------------
void printTitle()
{
	std::cout << std::endl;
	std::cout << "     ================" << std::endl;
	std::cout << "     >> Tamagotchi <<" << std::endl;
	std::cout << "     ================" << std::endl;
	std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// * Welcome message
//-----------------------------------------------------------------------------
void welcome()
{
	std::cout << BLUE << "Bonjour " << user->getName() << "!" << RESET << std::endl;
	std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// * Initialization
//-----------------------------------------------------------------------------
void init()
{
	printTitle();
	std::cout << YELLOW << "Initialisation..." << RESET << std::endl;
	getUser();
	getPet();
	pet->printCharacteristics();
	updatePetState();
	pet->printCharacteristics();
	getGenealogy();
	std::cout << std::endl;
	welcome();
}

//-----------------------------------------------------------------------------
// * Delete objects
//-----------------------------------------------------------------------------
void deleteObjects()
{
	delete user;
	delete pet;
}

//-----------------------------------------------------------------------------
// * End
//-----------------------------------------------------------------------------
void end()
{
	pet->writeInfos();
	writeSessionTime();
	deleteObjects();
}

//-----------------------------------------------------------------------------
// * Main
//-----------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	system("clear");
	init();

	// std::cout << std::endl;
	// user->print();
	// pet->printCharacteristics();
	// pet->generate(0);

	// pet->degradeState();
	// pet->degradeState();


	// pet->printCharacteristics();

	// callMainMenu();
	end();
}

