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
#include <SFML/Graphics.hpp>
#include "../lib/colors.cpp"
#include "../lib/Button.h"

using namespace std;
using namespace sf;

//=============================================================================
// ▼ Variables globales
// ----------------------------------------------------------------------------
//
//=============================================================================

// Window
RenderWindow window;

// Sprites
namespace sprite {
	Sprite background;
	Sprite reset;
}

// Textures
namespace texture {
	Texture background;
	Texture pause;
	Texture resume;
	Texture setting;
	Texture reset;
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
	loadTexture(texture::reset,     "images/reset.png");
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
	sprite::reset.setTexture(texture::reset);
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
	Button resetButton(sprite::reset);
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

//=============================================================================
// ▼ Main
// ----------------------------------------------------------------------------
// Main & structure
//=============================================================================

//-----------------------------------------------------------------------------
// * Initialisation
//-----------------------------------------------------------------------------
void init()
{
	loadTextures();
	setSprites();
	setButton();ww
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
				// 
			}

			if (event.type == Event::TextEntered) {
				if (event.text.unicode < 128)
				std::cout << "tapé: " << static_cast<char>(event.text.unicode) << std::endl;
			}
		}

	window.clear();
	window.draw(sprite::background);
	// window.draw(text);
	// window.draw(shape);
	window.display();
	}
}

//-----------------------------------------------------------------------------
// * Terminate
//-----------------------------------------------------------------------------
void end()
{

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

