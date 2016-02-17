#include "date.h"

Date::Date(int j, int m, int a)
{
	this->jour = j;
	this->mois = m;
	this->an = a;
	#ifdef DEBUG
	cout << "Constructeur de Date " << (int)(this)<<endl;
	#endif
}

Date::~Date()
{
	#ifdef DEBUG
	cout << "Destructeur de Date " << (int)(this)<<endl;
	#endif
}

void Date::ModifierDate()
{
	#ifdef DEBUG
	cout << "Modification de Date " << (int)(this)<<endl;
	#endif
	cin >> jour >> mois >> an;
}

void Date::AfficherDate()
{
	cout << jour << " " << mois << " " << an << endl;
}
