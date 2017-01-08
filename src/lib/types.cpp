//=============================================================================
//
// ■ Conversions & vérifications
// -- Objet : Quelques fonctions de conversions (et verif) entre int et string.
// -- Par : Julien Boge
// -- Dernière modification : 20.03.16
//
//=============================================================================
// ▼ Liste des fonctions :
// ----------------------------------------------------------------------------
//   * to_upper(string,string&) : met la première string en majuscule dans la
//   seconde chaîne. Utile pour la vérification des commandes.
//   * int_to_string(int) : convertis un entier en string.
//   * int_is_in_range(int,int,int) : indique si l'entier est entre deux
//   autres entiers.
//   * is_digit(string) : indique si le string contient un entier.
//   * stoi(string) : convertis un string en entier.
//
//=============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <sstream>      /* stringstream (int_to_string) */

#include "types.h"

//=============================================================================
// ▼ Int & Strings functions
// ----------------------------------------------------------------------------
// *
//=============================================================================

//------------------------------------------------------------------------------
// * To upper (string,string&)
//------------------------------------------------------------------------------
void types::to_upper(std::string s, std::string& s2) {
  std::locale loc;
  for(unsigned int i = 0 ; i < s.size() ; i++) {
    s2.push_back(toupper(s[i],loc));
  }
}

//------------------------------------------------------------------------------
// * Int to string
//------------------------------------------------------------------------------
std::string types::int_to_string(int n) {
  std::stringstream ss;
  ss << n;
  return ss.str();
}

//------------------------------------------------------------------------------
// * Int is in range ?
//------------------------------------------------------------------------------
bool types::int_is_in_range(int v, int min, int max) {
  return (v >= min && v <= max);
}

//------------------------------------------------------------------------------
// * Is digit? (string)
//------------------------------------------------------------------------------
bool types::is_digit(std::string s) {
  unsigned int d = 0;
  if(s[0] == '-') d = 1;
  for(unsigned int i = d ; i < s.size() ; i++) {
    if(s[i] < '0' || s[i] > '9') return false;
  }
  return true;
}

//-----------------------------------------------------------------------------
// * String to int
//-----------------------------------------------------------------------------
int types::stoi(std::string s) {
  return atoi(s.c_str());
}

//-----------------------------------------------------------------------------
// * Const char to int
//-----------------------------------------------------------------------------
int types::ctoi(const char c[]) {
  return atoi(c);
}

