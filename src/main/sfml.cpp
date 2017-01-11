//=============================================================================
//
// ■ Main
// -- Objet :
// -- Par : Julien Boge
// -- Dernière modification :
//
//=============================================================================


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "../lib/button.h"

using namespace std;

//=============================================================================
// ▼ Constantes
//=============================================================================
namespace files {
	std::string save_directory = "save";
	std::string user_infos = save_directory + "/user.dat";
}

// Colors
#define RESET       "\033[0m"              // Reset
#define BLACK       "\033[30m"             // Black
#define RED         "\033[31m"             // Red
#define GREEN       "\033[32m"             // Green
#define YELLOW      "\033[33m"             // Yellow
#define BLUE        "\033[34m"             // Blue
#define MAGENTA     "\033[35m"             // Magenta
#define CYAN        "\033[36m"             // Cyan
#define WHITE       "\033[37m"             // White
#define BOLDBLACK   "\033[1m\033[30m"      // Bold Black
#define BOLDRED     "\033[1m\033[31m"      // Bold Red
#define BOLDGREEN   "\033[1m\033[32m"      // Bold Green
#define BOLDYELLOW  "\033[1m\033[33m"      // Bold Yellow
#define BOLDBLUE    "\033[1m\033[34m"      // Bold Blue
#define BOLDMAGENTA "\033[1m\033[35m"      // Bold Magenta
#define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan
#define BOLDWHITE   "\033[1m\033[37m"      // Bold White

/*
//=============================================================================
// ▼ Prototypes de fonctions
//=============================================================================
void start();
void post_start();
void update();
void pre_terminate();
void terminate();

void get_user_infos();

*/
//=============================================================================
// ▼ Main
// ----------------------------------------------------------------------------
// Main & structure
//=============================================================================

//-----------------------------------------------------------------------------
// * Main
//-----------------------------------------------------------------------------
int main()
{
	// start();
	// post_start();
	// update();
	// pre_terminate();
	// terminate();

	sf::Texture textureBackground;
	sf::Texture texturePause;
	sf::Texture textureResume;
	sf::Texture textureSetting;
	sf::Texture textureReset;


	if (!textureBackground.loadFromFile("images/lac.jpg"))
	{
    		std::cout<<" Erreur chargement de la texture! "<<std::endl;
		return 1;
	}

	if (!texturePause.loadFromFile("images/Background_medium.jpg"))
				{
    					std::cout<<" Erreur chargement de la texture! "<<std::endl;
					return 1;
				}
/*
	if (!textureResume.loadFromFile("images/lac.jpg"))
	{
    		std::cout<<" Erreur chargement de la texture! "<<std::endl;
		return 1;
	}

	if (!textureSetting.loadFromFile("images/lac.jpg"))
	{
    		std::cout<<" Erreur chargement de la texture! "<<std::endl;
		return 1;
	}
*/
	if (!textureReset.loadFromFile("images/reset.png"))
	{
    		std::cout<<" Erreur chargement de la texture! "<<std::endl;
		return 1;
	}


	sf::RenderWindow window(sf::VideoMode(1024, 760), "Nom de la fenêtre");
	window.setVerticalSyncEnabled(true);

	string State = "";

	sf::Sprite backGround(textureBackground);
	sf::Sprite pause(texturePause);
	//sf::Sprite menuResume(textureResume);
	//sf::Sprite menuSetting(textureSetting);
	sf::Sprite menuReset(textureReset);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{

				cout<<"Hello"<<endl;
				window.draw(pause);
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
				window.draw(menuReset);	// voir si pas de conflit avec window.clear plus bas
			}
		}
		window.clear();
		window.draw(backGround);
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
	}
	return 0;
}
/*
//-----------------------------------------------------------------------------
// * Start
//-----------------------------------------------------------------------------
void start()
{
	get_user_infos();
	// get_pet_infos();
}

//-----------------------------------------------------------------------------
// * Post-start
//-----------------------------------------------------------------------------
void post_start()
{

}

//-----------------------------------------------------------------------------
// * Update
//-----------------------------------------------------------------------------
void update()
{

}

//-----------------------------------------------------------------------------
// * Pre-terminate
//-----------------------------------------------------------------------------
void pre_terminate()
{

}

//-----------------------------------------------------------------------------
// * Terminate
//-----------------------------------------------------------------------------
void terminate()
{

}


//=============================================================================
// ▼ Category
// ----------------------------------------------------------------------------
// Description
//=============================================================================


//-----------------------------------------------------------------------------
// * Get user informations
// If can't find user file, create a new one.
//-----------------------------------------------------------------------------
void get_user_infos()
{
	std::ofstream file;
	file.open(files::user_infos.c_str()));
	if(file.is_open()) {
		file << pid;
	} else {
		std::cerr << "Erreur: impossible d'ouvrir le fichier ";
		std::cerr << files::user_infos.c_str() << std::endl;
	}
	file.close();
}


//-----------------------------------------------------------------------------
// * Write a string into a file
//-----------------------------------------------------------------------------
string read(const char* file_name,const char* text)
{
	std::string line;

	std::ifstream file;
	file.open(file_name));

	if(file.is_open()) {
		getline(file,line);
		std::istringstream iss(line);
	} else {
		std::cerr << "Erreur: impossible d'ouvrir le fichier ";
		std::cerr << file_name << std::endl;
	}

	file.close();

	return line;
}
*/
