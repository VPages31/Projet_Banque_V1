#include "cptBloque.h"
//************* FONCTIONS MEMBRES CptBloque **************
//Constructeur
CptBloque::CptBloque(string num, Date d, int t, double inter): Compte(num, d)
{
    blo_duree=t;
    interets=inter;
    #ifdef DEBUG
		cout << "Constructeur CptBloque parametres " << (int)(this)<<endl;
	#endif
}

//Affectation
CptBloque &CptBloque::operator= (const CptBloque &c)
{
    Compte::numCompte=c.Compte::numCompte;
    Compte::solde=c.Compte::solde;
    for (int i=0; i<10; i++)
        Compte::historique[i]=c.Compte::historique[i];
    Compte::D=c.Compte::D;
    blo_duree=c.blo_duree;
    interets=c.interets;
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
    cout<<"Solde: "<<Compte::solde<<" avec un taux d'interets de "<<interets<<endl;
    cout<<"duree du blocage : "<<blo_duree<<" ans"<<endl<<"date de fin de blocage: ";
    blo_date_debl.AfficherDate();
    AfficherDureeBlocage();
}

void CptBloque::AfficherStatutBlocage()
{
    cout<< "Votre compte est bloque jusqu'au ";
    blo_date_debl.AfficherDate();
}

void CptBloque::AfficherDureeBlocage()
{
    int tps=0;
    tps=(blo_date_debl.an)-(today.an);
    cout<<"Compte bloque pendant encore "<<tps<<" ans"<<endl;
}

void CptBloque::CalculerDateDeblocage()
{
    this->blo_date_debl.jour=(this->D.jour);
    this->blo_date_debl.mois=(this->D.mois);
    this->blo_date_debl.an=(this->D.an)+(this->blo_duree);
    #ifdef DEBUG
		cout << "Calcul date de deblocage " << (int)(this)<<endl;
	#endif
	//return (this->blo_date_debl);
}

CptBloque CptBloque::AjouterInterets()
{
    //
    return (*this);
}

CptBloque CptBloque::Retirer()
{
    //
    return (*this);
}

void CptBloque::Menu()
{
    //CLEAR;
    Ligne();
    cout<< " / / / / / / COMPTE BLOQUE \\ \\ \\ \\ \\ \\ "<<endl;
    Ligne();
    AfficherCompte();
    Ligne();
    cout<<endl<< " 1: Ajouter de l'argent"<<endl;
    cout<<endl<< " 2: Retirer de l'argent"<<endl;
    cout<<endl<< " 0: Retour"<<endl;
    char choix;
    cin>>choix;
    Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
    #ifdef DEBUG
        cout << "votre choix: "<<choix<<endl;
    #endif
    switch(choix)
    {
    case 1:
        #ifdef DEBUG
            cout << "case 1 " <<endl;
        #endif
        break;
    case 2:
        #ifdef DEBUG
            cout << "case 2 " <<endl;
        #endif
        break;
    case 0:
        #ifdef DEBUG
            cout << "case 0 " <<endl;
        #endif
        break;
    }
}

//************* FONCTIONS SURCHARGE Compte **************

//************* main de test unitaire *******************
int main()
{
    cout<<"***************"<<endl;
    cout<<"date du jour: ";
    today.AfficherDate();
    cout<<"***************"<<endl;
    CptBloque C1;
    CptBloque C2;
    cout<<"***************"<<endl;
    C1.AfficherCompte();
    cout<<"***************"<<endl;
    C2.AfficherCompte();
    cout<<"***************"<<endl;
    C2=C1;
    cout<<"***************"<<endl;
    C2.AfficherCompte();
    cout<<"***************"<<endl;
    C1.CalculerDateDeblocage();
    C1.AfficherCompte();
    cout<<"***************"<<endl;
    C2.CalculerDateDeblocage();
    C2.AfficherCompte();
    cout<<"***************"<<endl;
    cout<<"Merci d'entrer la nouvelle date du jour: ";
    today.ModifierDate();
    cout<<"***************"<<endl;
    cout<<"date du jour: ";
    today.AfficherDate();
    cout<<"***************"<<endl;
    C1.Menu();
    return 0;
}
