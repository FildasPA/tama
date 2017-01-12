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

#include "../lib/Button.h"
#include "../lib/colors.cpp"
#include "../lib/types.h"
#include "../lib/file.h"
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
Button* resetButton = new Button("images/b_Oeuf.png");
Button* foodButton = new Button("images/b_Faim.png");
Button* happyButton = new Button("images/b_Calin.png");
Button* healButton = new Button("images/b_Soin.png");
Button* washButton = new Button("images/b_Douche.png");
Button* settingButton = new Button("images/b_Reglage.png");
Button* resumeButton = new Button("images/b_Play.png");
Button* quitButton = new Button("images/b_Quit.png");
Button* shopButton = new Button("images/b_Shop.png");
Button* parkButton = new Button("images/b_Arbre.png");


// Sprites
namespace sprite {
	Sprite background;
	Sprite initial;
	Sprite dead;
	Sprite	dirty;
	Sprite hungry;
	Sprite sad;
	Sprite sick;
}



// Textures
namespace texture {
	Texture background;
	Texture initial;
	Texture dead;
	Texture dirty;
	Texture hungry;
	Texture sad;
	Texture sick;
}

Pet* pet;
User* user;

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
	loadTexture(texture::background,	"images/lac.jpg");
	loadTexture(texture::initial,	"images/petNormal.png");
	loadTexture(texture::dead,		"images/Crane.png");
	loadTexture(texture::dirty,    	"images/Sale.png");
	loadTexture(texture::hungry,	"images/Faim.png");
	loadTexture(texture::sad,		"images/Smiley_Triste.png");
	loadTexture(texture::sick,		"images/Soin.png");

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
	sprite::initial.setTexture(texture::initial);
	sprite::dead.setTexture(texture::dead);
	sprite::dirty.setTexture(texture::dirty);
	sprite::hungry.setTexture(texture::hungry);
	sprite::sad.setTexture(texture::sad);
	sprite::sick.setTexture(texture::sick);
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
	if(pet->isSad())	mainState.setState("Sad");
	if(pet->isHappy())	mainState.setState("Happy");
	if(pet->isDirty())	mainState.setState("Dirty");
	if(pet->isHungry())	mainState.setState("Hungry");
	if(pet->isSick())	mainState.setState("Sick");
	if(pet->isDead())	mainState.setState("Dead");
	else mainState.setState("Pet");
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

sprite::initial.setPosition(400,450);
sprite::hungry.setPosition(500,200);
sprite::sad.setPosition(500,200);
sprite::dirty.setPosition(500,200);
//sprite::happy.setPosition(500,200);
sprite::sick.setPosition(500,200);
sprite::dead.setPosition(500,200);

foodButton->sprite.setPosition(25,50);
happyButton->sprite.setPosition(25,225);
healButton->sprite.setPosition(25,400);
washButton->sprite.setPosition(25,575);

resetButton->sprite.setPosition(50,450);
settingButton->sprite.setPosition(250,450);
resumeButton->sprite.setPosition(454,225);
quitButton->sprite.setPosition(450,450);
shopButton->sprite.setPosition(650,450);
parkButton->sprite.setPosition(850,450);


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
				mainState.setState("Pause");

			}
/*
			if (event.type == Event::TextEntered) {
				if (event.text.unicode < 128)
				std::cout << "tapé: " << static_cast<char>(event.text.unicode) << std::endl;
			}
*/
		}

		window.clear();
		window.draw(sprite::background);

		pet->updateState();

		if(mainState.getState() != "Pause"){
			checkPetStates();
		}

		// mainState est l'état actuel du jeu, mainState.getState();, mainState.setState("coucou");

		if(mainState.getState() == "Pause")
		{
			window.draw(resetButton->sprite);
			window.draw(settingButton->sprite);
			window.draw(quitButton->sprite);
			window.draw(shopButton->sprite);
			window.draw(resumeButton->sprite);
			window.draw(parkButton->sprite);

			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
/*			if (settingButton->isClicked(window) == true)
			{
				mainState.setState("Setting");		// envoie sur setting
			}
			if (parkButton->isClicked(window) == true)
			{
				mainState.setState("Park");		// envoie sur park
			}
*/			if (quitButton->isClicked(window) == true)
			{
				window.close();				// ferme la fenêtre
			}
/*			if (shopButton->isClicked(window) == true)
			{
				mainState.setState("Shop");		// envoie sur le shop
			}
*/			if (resumeButton->isClicked(window) == true)
			{
				mainState.setState("Pet");		// reprend le jeu
			}
		}

		if(mainState.getState() == "Dead")
		{
			window.draw(sprite::initial);
			window.draw(sprite::dead);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
		}

		if(mainState.getState() == "Dirty")
		{
			window.draw(sprite::initial);
			window.draw(sprite::dirty);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
		}

		if(mainState.getState() == "Hungry")
		{
			window.draw(sprite::initial);
			window.draw(sprite::hungry);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
		}

		if(mainState.getState() == "Sad")
		{
			window.draw(sprite::initial);
			window.draw(sprite::sad);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
		}

		if(mainState.getState() == "Sick")
		{
			window.draw(sprite::initial);
			window.draw(sprite::sick);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
		}
/*
		if(mainState.getState() == "Setting")
		{
			resetButton->sprite.setPosition(100,100);
			window.draw(resetButton->sprite);
			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
		}
*/
/*		if(mainState.getState() == "Shop")
		{
			resetButton->sprite.setPosition(100,100);
			window.draw(resetButton->sprite);
			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
		}

		if(mainState.getState() == "Park")
		{
			resetButton->sprite.setPosition(100,100);
			window.draw(resetButton->sprite);
			if (resetButton->isClicked(window) == true)
			{
				cout<<"ça marche bordel"<<endl;		// FONCTION DE JUJU! pour re-générer le pet
			}
		}
*/
		if(mainState.getState() == "Pet")
		{
			window.draw(sprite::initial);
			window.draw(foodButton->sprite);
			window.draw(happyButton->sprite);
			window.draw(washButton->sprite);
			window.draw(healButton->sprite);
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

