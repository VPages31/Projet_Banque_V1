#include "date.h"
Date today( 11, 2, 2016);

Date::Date(int j, int m, int a)
{
	this->jour = j;
	this->mois = m;
	this->an = a;
	#ifdef DEBUG
	cout << "Constructeur parametre de Date " << (int)(this) <<endl;
	#endif
}

Date & Date::operator=( const Date & D)
{
    jour=D.jour;
    mois=D.mois;
    an=D.an;
    #ifdef DEBUG
	cout << "operator= de Date " << (int)(this) <<endl;
    #endif
    return *this;
}

Date::~Date()
{
	#ifdef DEBUG
	cout << "Destructeur de Date " << (int)(this) <<endl;
	#endif
}

void Date::ModifierDate()
{
	#ifdef DEBUG
	cout << "Modification de Date " << (int)(this) <<endl;
	#endif
	cin >> jour >> mois >> an;
}

void Date::AfficherDate()
{
	cout << jour << " " << mois << " " << an << endl;
}
