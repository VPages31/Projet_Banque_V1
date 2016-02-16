#include <iostream>
#include <string>
using namespace std;
#include "client.h"
#ifndef BANQUE_H
#define BANQUE_H

class Banque
{
	private:
		string nomBanque;
		int telephone[10];
		string adresse;
	
	protected:
		
	
	public:
	
	/** Fonctions internes a la classe Banque*/
	void Afficher();
	void ModifierBanque();
	void Authentification();
	void NouveauClient();
	void SupprimerCompte();
	void Menu();

};

#endif	// BANQUE_H
