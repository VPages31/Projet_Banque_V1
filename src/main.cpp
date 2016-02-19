#include <iostream>
#include <string>
using namespace std;
#include "banque.h"
#include "client.h"
#include "compte.h"

int main()
{
    CptCourant C1;
    CptCourant C2;
    cout<<"***************"<<endl;
    C1.AfficherCompte();
    cout<<"***************"<<endl;
    C2.AfficherCompte();
    cout<<"***************"<<endl;
    C2=C1;
    cout<<"***************"<<endl;
    C2.AfficherCompte();

    C1.Menu();
    // ----------- to do: ------------
    // -- ajout des interets
    // -- depot d'argent
    // -- retrait d'argent

    return 0;
}
