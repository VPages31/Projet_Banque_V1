#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "compte.h"
#include "cptCourant.h"
#include "cptEpargne.h"
#include "cptBloque.h"
#include "cptPEL.h"
#ifndef CLIENT_H
#define CLIENT_H

extern Date today;

class Client
{
	private:
		string nom;
		string prenom;
		string mail;
		int telephone[10];
		string adresse;
		int numClient;
		vector <CptCourant> listeCC;
		vector <CptEpargne> listeLE;
		vector <CptBloque> listeCB;
		vector <CptPEL> listePEL;

	protected:

	public:
	/** Fonctions internes a la classe Client **/
		void Menu();
		void Afficher();
		void AjouterCompte();
		void SupprimerCompte();
		void GererCompte(); //choix du compte a gerer
		void SupprimerClient();
};

#endif	// CLIENT_H
