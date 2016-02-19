#include "compte.h"
#include <iostream>
#include <string>
using namespace std;
#ifndef CPTCOURANT_H
#define CPTCOURANT_H

class CptCourant:public Compte
{
private:

protected:
    double agios;

public:
    CptCourant(string num="000001", int d=0);
    CptCourant &operator= (const CptCourant &c);
    ~CptCourant();
    void AfficherCompte();
    void  RetirerAgio();
    void Ajouter (double montant); // Ajoute de l'argent au solde de compte courant
    void Retirer ( double montant ); // Retire de l'argent au solde de compte courant
    double GetSolde ();
    void Menu();
};
#endif	//CPTCOURANT_H





