//=============================================================================
//
// ■ Main
// -- Objet :
// -- Par : Julien Boge
// -- Dernière modification :
//
//=============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>

//=============================================================================
// ▼ Prototypes de fonctions
//=============================================================================


//=============================================================================
// ▼ Variables globales
//=============================================================================


//-----------------------------------------------------------------------------
// * Main
//-----------------------------------------------------------------------------
int main(/*int argc, char const *argv[]*/)
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Coucou bob!");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
	return 0;
}
