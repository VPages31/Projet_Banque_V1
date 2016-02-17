#include "date.h"
#include <iostream>

#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
	protected :
		string numCompte;
		double solde;
		double historique[10];
		Date D;
	public :
		Compte(string numCompte);
		~Compte();
		void Consulter(); // Permet de consulter le solde et l'historique du compte
		void Ajouter (double montant); // Ajoute de l'argent au solde
		void Retirer ( double montant ); // Retire de l'argent au solde
		double GetSolde ();
		virtual void Menu() = 0;
};

#endif
