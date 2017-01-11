
#include <iostream>
#include <fstream>

#include "file.h"
#include "colors.cpp"

//-----------------------------------------------------------------------------
// * Does file exists ?
//-----------------------------------------------------------------------------
bool file::exists(const char* fileName) {
  std::ifstream file(fileName);
  bool fileExists = file.good();
  file.close();
  return fileExists;
}

//-----------------------------------------------------------------------------
// * Error: Can't open file
//-----------------------------------------------------------------------------
void file::errorCantOpen(const char* fileName)
{
	std::cerr << std::endl;
	std::cerr << RED << "    ✖ Impossible d'ouvrir le fichier ";
	std::cerr << fileName << RESET << std::endl;
}
