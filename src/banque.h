#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "client.h"
#ifndef BANQUE_H
#define BANQUE_H

class Banque
{
	private:
		string nomBanque;
		string adresse;
		vector Client;
	protected:
		
	
	public:
	/** Forme canonique **/
		// Constructeurs
		Banque();
		// pas utile mais bon...    Banque(const Banque & ACopier);
		Banque(string nom ="nom_defaut_", string adresse = "adresse_defaut_");
		// Destructeur
		 virtual ~Banque();
		// Operateurs 
		/// Je ne sais pas si c'est utile... a définir
		friend istream & operator>>(istream & out, Banque & D);
		friend ostream & operator<<(ostream & in, Banque  & D);
	
	
	/** Fonctions internes a la classe Banque **/
	void Menu();
	void Afficher();
	void ModifierBanque();
	void Authentification();
	void NouveauClient();
	void SupprimerCompte();
};

#endif	// BANQUE_H
