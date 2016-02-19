#include <iostream>
#include <string>
using namespace std;

#include "compte.h"
#include "cptCourant.h"



main ()
{
	CLEAR;
	
	CptCourant C("222222"); // Test constructeur avec parametres numCompte au minimum
	C.Menu();
	
	CLEAR;
}
