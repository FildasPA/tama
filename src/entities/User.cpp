
#include <iostream>
#include <string>
#include <fstream>

#include "../conf/files_names.h"
#include "../lib/colors.h"
#include "../lib/types.h"
#include "../lib/file.h"
#include "User.h"

//=============================================================================
// ▼ Utilisateur
// ----------------------------------------------------------------------------
// Fonctions gérant la création/récupération des informations de l'utilisateur
// dans un fichier.
//=============================================================================

//-----------------------------------------------------------------------------
// * Constructeur
// Si un fichier utilisateur existe, récupère les informations qui s'y
// trouvent.
// Sinon, demande les informations à l'utilisateur avant de les écrire dans
// un fichier.
//-----------------------------------------------------------------------------
User::User()
{
	if(fileExists())
		readInfos();
	else {
		askInfos();
		writeFile();
	}
}


//=============================================================================
// ▼ Accesseurs
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Get name
//-----------------------------------------------------------------------------
std::string User::getName() { return name; }

//-----------------------------------------------------------------------------
// * Get birthday
//-----------------------------------------------------------------------------
std::string User::getBirthday() { return birthday; }


//=============================================================================
// ▼ Mutateurs
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Set name
//-----------------------------------------------------------------------------
void User::setName(std::string name) { this->name = name; }

//-----------------------------------------------------------------------------
// * Set birthday
//-----------------------------------------------------------------------------
void User::setBirthday(std::string birthday) { this->birthday = birthday; }

//-----------------------------------------------------------------------------
// * Set value from string
//-----------------------------------------------------------------------------
void User::setValueFromString(std::string parameter, std::string value,
                              bool &success)
{
	// std::cout << "  Parameter: " << parameter << std::endl;
	// std::cout << "  Value:     " << value << std::endl;
	     if(parameter == "name")        setName(value);
	else if(parameter == "birthday")    setBirthday(value);
	else {
		if(success) std::cout << std::endl;
		std::cerr << YELLOW << "      Avertissement:" << RESET << " paramètre ";
		std::cerr << parameter << " inconnu." << std::endl;
		success = false;
	}
}

//-----------------------------------------------------------------------------
// * Get user infos
//-----------------------------------------------------------------------------
void User::askInfos()
{
	std::cout << "Veuillez entrer votre nom: ";
	getline(std::cin,name);

	std::cout << "Veuillez entrer votre date d'anniversaire (JJ/MM/AA): ";
	getline(std::cin,birthday);
}


//=============================================================================
// ▼ File
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * User file exists?
//-----------------------------------------------------------------------------
bool User::fileExists()
{
	return file::exists(files::userInfos.c_str());
}

//-----------------------------------------------------------------------------
// * Get user infos
//-----------------------------------------------------------------------------
void User::readInfos()
{
	std::cout << BLUE << "    Récupéraction des données utilisateur..." << RESET;

	const char* fileName = files::userInfos.c_str();
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

	std::cout << GREEN << "\r  ✔ Données utilisateur récupérées!         ";
	std::cout << RESET << std::endl;
}

//-----------------------------------------------------------------------------
// * Write user infos
//-----------------------------------------------------------------------------
void User::writeFile()
{
	std::cout << BLUE << "    Sauvegarde des données utilisateur..." << RESET;

	const char *fileName = files::userInfos.c_str();
	std::ofstream file(fileName);
	if(!file.is_open()) return file::errorCantOpen(fileName);

	file << "name: " << name << std::endl;
	file << "birthday: " << birthday << std::endl;

	file.close();

	std::cout << GREEN << "\r  ✔ Données utilisateur sauvegardées!    ";
	std::cout << RESET << std::endl;
}

//-----------------------------------------------------------------------------
// * Print
//-----------------------------------------------------------------------------
void User::print()
{
	std::cout << YELLOW << "Utilisateur:" << RESET<< std::endl;
	std::cout << "  name:     " << GREEN << name     << RESET << std::endl;
	std::cout << "  birthday: " << GREEN << birthday << RESET << std::endl;
}
