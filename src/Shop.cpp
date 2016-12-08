#include <vector>
#include <string>

const unsigned int MaxStorage = 10;

Shop::Shop()
{
	FirstID = 0;
	CurrID = 0;
}

void Shop::CreateRandomObject()
{
	int Rand = rand() % 10;
	Object New = ;
/*
	Récupérer Rand'ème ligne dans la liste des objets	
*/

	Storage.push_back(New);
}

void Shop::RandomObjects(int number)
{
	for (int i=0; i<number; i++){
		CreateRandomObject();
	}
}

void Shop::CreateObject(string name, string description, string picture, int nutrition)	// nutrition = 0 => objet, nutrition = 1 => aliment
{



}

void Shop::DisplayStorage()
{





}

void Shop::buy(int id)
{



}


class Shop
{
	vector<object> Storage;
	
public:

	Shop();
	void CreateObject();
	void CreateObject(string name, string description, string picture, int nutrition);
	void DisplayStorage();
	void buy(int id);	


