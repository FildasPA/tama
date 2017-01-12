
#ifndef __User
#define __User

class User {

private:
	std::string name;
	std::string birthday;

public:

	User();

	// Accesseurs
	std::string getName();
	std::string getBirthday();

	// Mutateurs
	void setName(std::string);
	void setBirthday(std::string);
	void setValueFromString(std::string,std::string,bool&);

	// Fichiers
	bool fileExists();
	void readInfos();
	void writeFile();

	void askInfos();
	void print();
};

#endif
