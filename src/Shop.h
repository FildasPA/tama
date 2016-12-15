#ifndef __Shop
#define __Shop

#include <vector>
#include <string>

//--------------------------------------------
// * Class object
//--------------------------------------------

class Shop
{
	vector<Object> Storage;
	int FirstID;
	int CurrID;
	
public:

	Shop();
	void CreateRandomObject();
	void RandomObjects(int number);
	void CreateObject(string name, string description, string picture, int nutrition=0);
	void DisplayStorage();
	void buy(int id);	
};

#endif
