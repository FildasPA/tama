//=============================================================================
// ▼ Types
// ----------------------------------------------------------------------------
// Diverses conversions int <=> string
//=============================================================================

#ifndef __Types
#define __Types

#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <sstream>      /* stringstream (int_to_string) */

// int & string functions
namespace types {
	std::string int_to_string(int);
	bool is_digit(std::string);
	void to_upper(std::string,std::string&);
	bool int_is_in_range(int,int,int);
	int stoi(std::string);
	int ctoi(const char []);
}

#endif
