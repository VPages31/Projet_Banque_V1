#include <iostream>
#include <string>
using namespace std;

#include "compte.h"
#include "cptEpargne.h"



main ()
{
	
	CptEpargne E("123456"); // Test constructeur avec parametres numCompte au minimum
	
	E.Menu();
	
	CLEAR;
}
