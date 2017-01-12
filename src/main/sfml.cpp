//=============================================================================
//
// ■ Main
// -- Objet :
// -- Par :
// -- Dernière modification :
//
//=============================================================================


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "../lib/colors.cpp"
#include "../lib/types.h"
#include "../lib/file.h"
#include "../lib/Button.h"
#include "../lib/State.h"

#include "../conf/files_names.h"

#include "../entities/User.h"
#include "../entities/Pet.h"


using namespace std;
using namespace sf;

//=============================================================================
// ▼ Variables globales
// ----------------------------------------------------------------------------
//
//=============================================================================

// Window
RenderWindow window;
State mainState;

// Button
Button* resetButton = new Button("images/reset.png");

// Sprites
namespace sprite {
	Sprite background;
}

// Textures
namespace texture {
	Texture background;
	Texture pause;
	Texture resume;
	Texture setting;
}

Pet* pet = new Pet();
User* user = new User();

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
// ▼ Window
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Create window
//-----------------------------------------------------------------------------
void createWindow()
{
	window.create(VideoMode(1024, 760),"Bobby va bientôt emmenager ici!");
	window.setVerticalSyncEnabled(true);
}

//=============================================================================
// ▼ Textures
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Load texture
//-----------------------------------------------------------------------------
bool loadTexture(Texture& texture, const char *fileName)
{
	if(!texture.loadFromFile(fileName)) {
		std::cerr << "Erreur chargement de la texture " << fileName << std::endl;
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// * Chargement des textures
//-----------------------------------------------------------------------------
void loadTextures()
{
	loadTexture(texture::background,"images/lac.jpg");
	loadTexture(texture::pause,     "images/Background_medium.jpg");
}


//=============================================================================
// ▼ Sprites
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Create background
//-----------------------------------------------------------------------------
void setSprites()
{
	sprite::background.setTexture(texture::background);
}

//=============================================================================
// ▼ Button
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Create button
//-----------------------------------------------------------------------------
void setButton()
{
	//Button* resetButton = new Button("images/reset.png");
}


//=============================================================================
// ▼ Update sprites
// ----------------------------------------------------------------------------
//
//=============================================================================

//-----------------------------------------------------------------------------
// * Update background sprite
//-----------------------------------------------------------------------------
void updateBackground(Texture& texture)
{
	sprite::background.setTexture(texture);
}


//-----------------------------------------------------------------------------
// * Check pet states
//-----------------------------------------------------------------------------
void checkPetStates()
{
	if(pet->isDead())   mainState.setState("Dead");
	if(pet->isHungry()) mainState.setState("Hungry");
	if(pet->isDirty())  mainState.setState("Dirty");
	if(pet->isSad())    mainState.setState("Sad");
	if(pet->isHappy())  mainState.setState("Happy");
}

//=============================================================================
// ▼ Main
// ----------------------------------------------------------------------------
// Main & structure
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
// * Initialisation
//-----------------------------------------------------------------------------
void init()
{
	system("clear");
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

	loadTextures();
	setSprites();
	//setButton();
	createWindow();
}

//-----------------------------------------------------------------------------
// * Update
//-----------------------------------------------------------------------------
void update()
{
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
		// Fermeture de la fenêtre
			if(event.type == Event::Closed) {
				window.close();
				return;
			}

			if((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) {
				std::cout << "Pause!" << std::endl;
				mainState.setState("Menu");

			}

			if (event.type == Event::TextEntered) {
				if (event.text.unicode < 128)
				std::cout << "tapé: " << static_cast<char>(event.text.unicode) << std::endl;
			}
		}

		window.clear();
		window.draw(sprite::background);

		checkPetStates();

		// mainState est l'état actuel du jeu, mainState.getState();, mainState.setState("coucou");

		if(mainState.getState() == "Menu")
		{
			resetButton->sprite.setPosition(100,100);
			window.draw(resetButton->sprite);
			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
		}

		if(mainState.getState() == "Menu")
		{
			resetButton->sprite.setPosition(100,100);
			window.draw(resetButton->sprite);
			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
		}

		window.display();
	}
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
int main()
{
	init();
	update();
	end();

	return 0;
}
                // window.draw(pause);
/*
                if (!texture.loadFromFile("images/Resume.jpg"))
                {
                        std::cout<<" Erreur chargement de la texture! "<<std::endl;
                    return 1;
                }
                menuResume.setTexture(texture);

                if (!texture.loadFromFile("images/Setting.jpg"))
                {
                        std::cout<<" Erreur chargement de la texture! "<<std::endl;
                    return 1;
                }
                menuSetting.setTexture(texture);
*/
                //menuReset.setPosition(100,100);
                // window.draw(menuReset);  // voir si pas de conflit avec window.clear plus bas
            // }
        // }
        // window.clear();
        // window.draw(backGround);
/*
        if(State == "Menu1")
        {
            if (!texture.loadFromFile("images/Menu1.jpg"))
            {
                    std::cout<<" Erreur chargement de la texture! "<<std::endl;
                return 1;
            }
            sprite.setTexture(texture);

            window.draw(sprite);
            window.display();
        }

        if(State == "Menu2")
        {
            if (!texture.loadFromFile("images/Menu2.jpg"))
            {
                    std::cout<<" Erreur chargement de la texture! "<<std::endl;
                return 1;
            }
            sprite.setTexture(texture);

            window.draw(sprite);
            window.display();
        }

        if(State == "Menu3")
        {
            if (!texture.loadFromFile("iamges/Menu3.jpg"))
            {
                    std::cout<<" Erreur chargement de la texture! "<<std::endl;
                return 1;
            }
            sprite.setTexture(texture);

            window.draw(sprite);
            window.display();
        }
*/
    // }
    // return 0;
// }

