#include "utils.h"
#include <iostream>
using namespace std;
#include <cstdio>

main()
{
	CLEAR;
	Ligne();
	cout << endl << "vous etes dans le menu test" << endl << endl;
	Ligne();
	cout << endl << "1 - lalala\n2 - lololo\n3 - lelele\n\n";
	cout << "Appuyer sur entrée pour quitter" << endl;
	getchar();
}