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
		Banque(string nom ="Caisse LDNR", string adresse = "12 Rue des Banques");
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
	void ModifierToday();
};

#endif	// BANQUE_H
