#define DEBUG 1

#include "utils.h"
#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
	protected :
		int jour;
		int mois;
		int an;
	public :
		Date(int j=22, int m=02, int a=2016);
		Date &operator=( const Date & D);
		void ModifierDate();
		void AfficherDate();
		~Date();
};

#endif
