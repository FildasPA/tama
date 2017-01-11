
//=============================================================================
// ▼ State
// ----------------------------------------------------------------------------
//
//=============================================================================

#ifndef __State
#define __State

#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class State
{

	private:
		std::string state;

	public:

		State();
		void setState(std::string New);
		std::string getState();


};

#endif


