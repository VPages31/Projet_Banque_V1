#include <iostream>
#include <string>
using namespace std;
#include "date.h"
#include "cptBloque.h"
#include "cptCourant.h"
#include "cptEpargne.h"
#include "cptPEL.h"
#ifndef COMPTE_H
#define COMPTE_H

class Compte
{

int numCompte[11];
double solde;
double historique[10];
//Date

/** Fonctions internes a la classe Compte **/
void Consulter();
void Ajouter();
void Retirer();
void Menu();

};

#endif	// COMPTE_H
