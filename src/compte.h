#ifndef COMPTE_H
#define COMPTE_H
#include "date.h"
#include <iostream>
#include <deque>

extern Date today;

class Compte
{
	protected :
		string numCompte;
		double solde;
		deque <double> historique;
		Date D;
	public :
		Compte(string numCompte, Date d= today);
		~Compte();
		void Consulter(); // Permet de consulter le solde et l'historique du compte
		void Ajouter (double montant); // Ajoute de l'argent au solde
		void Retirer (double montant); // Retire de l'argent au solde
		double GetSolde ();
		virtual void Menu() = 0;
		void Historique(double s); // ajoute une transaction dans historique
};

#endif
