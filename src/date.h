#define DEBUG 1

#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
	private :
		int jour;
		int mois;
		int an;
	public :
		Date(int j=22, int m=02, int a=2016);
		void ModifierDate();
		void AfficherDate();
		~Date();
};
#endif

