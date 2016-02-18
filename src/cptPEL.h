#include "compte.h"
#include <iostream>
#include <string>
using namespace std;
#include <cstdio>
#include "utils.h"
#ifndef CPTPEL_H
#define CPTPEL_H

extern Date today;

class CptPEL : public Compte
{
	private :
		int dureeBloquage;
		Date dateDebloquage;
		double versement;
	public :
		CptPEL(string numCompte = "12345", Date d = today, int dureeDebloquage = 5, double versement = 50);
		~CptPEL();
		void Menu();
		void Emprunter();
		void ModifierVersement();
		void AjouterVersement();
		void Consulter();
};
#endif	// CPTPEL_H
