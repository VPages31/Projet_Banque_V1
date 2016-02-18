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

bool Date::operator<(const Date & D)
{
	cout << "entrée fonction <" << endl;
	if (this->an < D.an)
	{
		return true;
	}
	else
	{
		if (an == D.an && mois < D.mois)
		{
			return true;
		}
		else
		{
			if (mois == D.mois && jour < D.jour)
			{
				return true;
			}
            else
                return false;
		}
	}
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

ostream & operator<< (ostream & out, Date & D)
{
	cout << D.jour << D.mois << D.an;
	return out;
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
