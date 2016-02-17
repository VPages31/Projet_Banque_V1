#include "compte.h"

Compte::Compte(double numCompte)
{
	int i = 0;
	#ifdef DEBUG
		cout << "Constructeur compte parametre" << endl;
	#endif
	this->numCompte = numCompte;
	solde = 0;
	for ( i = 0 ; i < 10 ; i ++)
	{
		historique[i] = 0;
	}
}

Compte::~Compte()
{
	#ifdef DEBUG
		cout << "Destructeur compte" << endl;
	#endif
}

void Ajouter (double montant) // Ajoute de l'argent au solde (prends en parametre le montant a retirer ou le demande dans la fonction?
{
	solde=solde+montant;
	#ifdef DEBUG
		cout << "Ajouter au Solde" << endl;
	#endif
}

void Consulter() // Permet de consulter le solde et l'historique du compte
{
	int i = 0;
	cout << "Solde : \t" << solde << endl << endl;
	cout << "Historique :" << endl;
	for ( i = 0 ; i < 10 ; i ++)
	{
		cout << << historique[i];
	}
}

void Retirer ( double montant ) // Retire de l'argent au solde (meme probleme que ajouter
{
	solde = solde - montant;
	#ifdef DEBUG
		cout << "Retirer au Solde" << endl;
	#endif
}
