#include <iostream>
#include <string>
using namespace std;
#ifndef CPTEPARGNE_H
#define CPTEPARGNE_H

class CptEpargne : public Compte
{
private:
    int plafond;
    double interets;

public:
	CptEpargne(string numCompte="123456",int plafond =15999, double interets=10);
	CptEpargne &operator=(const CptEpargne &c);
    void Consulter(); // Permet de consulter le solde et l'historique du compte
    void Ajouter (double montant); // Ajoute de l'argent au solde
    void Retirer (double montant); // Retire de l'argent au solde
    void Menu();
    ~CptEpargne();
};
#endif	// CPTEPARGNE_H
