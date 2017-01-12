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

	sf::Texture texture;

	if (!texture.loadFromFile("images/Background_medium.jpg"))
	{
    		std::cout<<" Erreur chargement de la texture! "<<std::endl;
		return 1;
	}

	sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "Coucou bob!");
	window.setVerticalSyncEnabled(true);


	sf::Sprite sprite(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				texture.loadFromFile("images/Background.jpg");
				window.setSize(texture.getSize());
				sprite.setTexture(texture);


			}

		window.clear();
		window.draw(sprite);
		window.display();
		}
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
