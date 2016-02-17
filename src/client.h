#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "compte.h"
#ifndef CLIENT_H
#define CLIENT_H

class Client
{
	private:
		string nom;
		string prenom;
		string mail;
		int telephone[];
		string adresse;
		int numClient;
		vector CptCourant;
		vector CptEpargne;
		vector CptLogement;
		vector CptBloque;

	protected:

	public:
	/** Fonctions internes a la classe Client **/
		void Menu();
		void Afficher();
		void AjouterCompte();
		void SupprimerCompte();
		void SupprimerClient();
};

#endif	// CLIENT_H
