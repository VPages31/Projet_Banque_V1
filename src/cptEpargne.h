#include <iostream>
#include <string>
#include "compte.h"
using namespace std;
#ifndef CPTEPARGNE_H
#define CPTEPARGNE_H

class CptEpargne : public Compte
{
protected:
    int plafond;
    double interets;

public:
	CptEpargne(string numCompte="123456", int plafond =15999, double inte=10);
	CptEpargne &operator=(const CptEpargne &c);
    void Consulter(); // Permet de consulter le solde et l'historique du compte
    void Ajouter (); // Ajoute de l'argent au solde
    void Retirer (); // Retire de l'argent au solde
    void AjouterInterets();
    void Menu();
    ~CptEpargne();
};
#endif	// CPTEPARGNE_H
