#include "compte.h"
#include <iostream>
#include <string>
using namespace std;
#ifndef CPTBLOQUE_H
#define CPTBLOQUE_H

extern Date today;

class CptBloque : public Compte
{
private:
    int blo_duree;
    double interets;
    Date blo_date_debl;

public:
    CptBloque(string num="000001", Date d=today, int t=10, double inter=1.5);
    CptBloque &operator= (const CptBloque &c);
    ~CptBloque();
    void CalculerDateDeblocage();
    CptBloque AjouterInterets();
    void AfficherCompte();
    void AfficherStatutBlocage();
    void CalculerDureeBlocage();
    void AfficherDureeBlocage();
    //void Ajouter (double montant); // Ajoute de l'argent au solde
    void Retirer ( double montant ); // Retire de l'argent au solde
    double GetSolde ();
    void Menu();
};
#endif	// CPTBLOQUE_H
