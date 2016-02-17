#include "compte.h"
//#include "today.h"
#include <iostream>
#include <string>
using namespace std;
#ifndef CPTBLOQUE_H
#define CPTBLOQUE_H

class CptBloque : public Compte
{
private:
    int blo_duree;
    double interets;
    Date blo_date_debl;

protected:
    Date CalculerDateDeblocage();

public:
    CptBloque(string num="000001", int d=0, double inter=1.5);
    CptBloque &operator= (const CptBloque &c);
    ~CptBloque();
    CptBloque AjouterInterets();
    void AfficherCompte();
    void AfficherStatutBlocage();
    void AfficherDureeBlocage();
    void Menu();
};
#endif	// CPTBLOQUE_H
