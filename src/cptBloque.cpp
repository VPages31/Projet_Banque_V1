#include "cptBloque.h"

//************* FONCTIONS MEMBRES CptBloque **************
//Constructeur
CptBloque::CptBloque(string num, int d): Compte(num)
{
    blo_duree=d;
    #ifdef DEBUG
		cout << "Constructeur CptBloque parametres " << (int)(this)<<endl;
	#endif
}

//Affectation
CptBloque &CptBloque::operator= (const CptBloque &c)
{
    //Compte::numCompte=c.Compte::numCompte;
    //Compte::solde=c.Compte::solde;
    //for (int i=0; i<10; i++)
        //Compte::historique[i]=c.Compte::historique[i];
    //Compte::D=c.Compte::D;
    blo_duree=c.blo_duree;
    blo_date_debl=c.blo_date_debl;
    #ifdef DEBUG
		cout << "operator= CptBloque " << (int)(this)<<endl;
	#endif
	return (*this);
}

//Destructeur
CptBloque::~CptBloque()
{
    #ifdef DEBUG
		cout << "Destructeur CptBloque " << (int)(this)<<endl;
	#endif
}

void CptBloque::AfficherCompte()
{
    cout<<"Compte numero : "<<Compte::numCompte<<" ouvert le: ";
    D.AfficherDate();
    cout<<endl<<"Solde: "<<Compte::solde<<endl;
    cout<<"duree du blocage : "<<blo_duree<<endl<<"date de fin de blocage: ";
    blo_date_debl.AfficherDate();
}

void CptBloque::AfficherStatutBlocage()
{
    cout<< "Votre compte est bloque jusqu'au ";
    blo_date_debl.AfficherDate();
}

void CptBloque::AfficherDureeBlocage()
{
    //
}

Date CptBloque::CalculerDateDeblocage()
{
    //
}

//************* FONCTIONS SURCHARGE Compte **************

//************* main de test unitaire *******************
int main()
{
    CptBloque C1("05101520", 9); //numero de compte, bloque pendant 9 ans
    CptBloque C2;
    C1.AfficherCompte();
    C2.AfficherCompte();
    C2=C1;
    C2.AfficherCompte();
    return 0;
}
