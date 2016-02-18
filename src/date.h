#define DEBUG 1

#include "utils.h"
#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
	protected :
	    //
	public :
		int jour;
		int mois;
		int an;
		Date(int j=22, int m=2, int a=2016);
		Date &operator=( const Date & D);
		friend ostream & operator<< (ostream & out, Date & D);
		bool operator<(const Date & D);
		void ModifierDate();
		void AfficherDate();
		~Date();
};

#endif
