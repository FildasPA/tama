#ifndef __Food
#define __Food

#include "Object.h"

//--------------------------------------------
// * Class object
//--------------------------------------------

class Food : public Object
{
	private:
		int nutrition;

	public:

		// Fonctions primaires
		Food(unsigned int);
};

#endif
