
//=============================================================================
// ▼ List
// ----------------------------------------------------------------------------
// Une liste à afficher.
//=============================================================================

#ifndef __List
#define __List

#include <list>
#include <string>

class List {

	private:
		unsigned int fir;
		unsigned int pos;
		unsigned int nDisplayed;

		std::list<std::string> list;


	public:

		// Fonctions primaires
		List();
		List(unsigned int);
		List(unsigned int,unsigned int,unsigned int);

		// Accesseurs
		unsigned int getFirstDisplayedItem(); // ?
		unsigned int getFirst();              // ?
		unsigned int getPosition();           // ?
		std::string getSelectedItem();
		unsigned int getSize();

		// Mutateurs
		void setFirst(unsigned int);
		void setPosition(unsigned int);
		void setNDisplayed(unsigned int);

		// Opérations
		void setList();
		void addItem(std::string);
		void addItem(std::string,unsigned int);
		void removeItem(unsigned int);

		// Affichage
		void display();
		void displayAll(); // Fonction de test
		void displayItem(unsigned int);

};

#endif
