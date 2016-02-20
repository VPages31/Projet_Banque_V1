#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "client.h"
#ifndef BANQUE_H
#define BANQUE_H

extern Date today;

class Banque
{
	private:
		string nomBanque;
		string adresse;
		vector <Client> listeC;
	protected:
		
	
	public:
	/** Forme canonique **/
		// Constructeurs
		Banque(string nom ="NomCommunique", string adresse = "adresse indefinie");
		// Destructeur
		 virtual ~Banque();
		// Operateurs 
		friend istream & operator>>(istream & out, Banque & D);
		friend ostream & operator<<(ostream & in, Banque  & D);
	
	
	/** Fonctions internes a la classe Banque **/
	void Menu();
	void Afficher();
	void ModifierBanque();
	void ModifierBanque(string nom, string adr);
	void Authentification();
	void NouveauClient();
	void SupprimerCompte();
	void ModifierToday();
};

#endif	// BANQUE_H
