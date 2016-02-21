#include <iostream>
#include <string>
using namespace std;
#include "banque.h"


int main(int argc, char *argv[])
{
	Banque B;
	string a, b;
	
	CLEAR;
		cout << "Nom de la banque : " << endl;
		getline(cin, b);
		cout << "Adresse : " << endl;
		getline(cin, a);
	
	B.ModifierBanque(b,a);
		
	CLEAR;
		B.Menu();
	CLEAR;
	
	return 0;
}
