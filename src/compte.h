#ifndef COMPTE_H
#define COMPTE_H
#include "date.h"
//#include "today.h"
#include <iostream>
#include <vector>

extern Date today;

class Compte
{
	protected :
		string numCompte;
		double solde;
		vector <double> historique;
		//double historique[10];
		Date D;
	public :
		Compte(string numCompte, Date d= today);
		~Compte();
		void Consulter(); // Permet de consulter le solde et l'historique du compte
		void Ajouter (double montant); // Ajoute de l'argent au solde
		void Retirer (double montant); // Retire de l'argent au solde
		double GetSolde ();
		virtual void Menu() = 0;
		void Historique(double s); // ajoute une transaction dans le vector historique
};

#endif
