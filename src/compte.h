#include "date.h"
#include <iostream>

using namespace std;

#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
	private :
		double numCompte;
		double solde;
		double historique[10];
		Date D;
	public :
		Compte(double numCompte);
		~Compte();
		void Consulter(); // Permet de consulter le solde et l'historique du compte
		void Ajouter (double montant); // Ajoute de l'argent au solde 
		void Retirer ( double montant ); // Retire de l'argent au solde
		void Menu() = 0;

};

#endif