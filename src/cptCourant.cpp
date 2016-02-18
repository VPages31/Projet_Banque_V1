#include "cptCourant.h"


//fonction membre
// constructeur
CptCourant::CptCourant(string num, int A): Compte(num)
{
    agios=A;
    #ifdef DEBUG
		cout << "Constructeur cptCourant parametres " << (int)(this)<<endl;
	#endif
}
//affectation
CptCourant &CptCourant::operator= (const CptCourant &c)
{
    Compte::numCompte=c.Compte::numCompte;
    Compte::solde=c.Compte::solde;
    for (int i=0; i<10; i++)
        Compte::historique[i]=c.Compte::historique[i];
    Compte::D=c.Compte::D;
    agios=c.agios;
    #ifdef DEBUG
		cout << "operator= CptCourant " << (int)(this)<<endl;
	#endif
	return (*this);
}
//Destructeur
CptCourant::~CptCourant()
{
    #ifdef DEBUG
		cout << "Destructeur CptCourant " << (int)(this)<<endl;
	#endif
}
void CptCourant::AfficherCompte()
{
     cout<<"Compte Courant numero : "<<Compte::numCompte<<" ouvert le: ";
    D.AfficherDate();
    cout<<"Solde: "<<Compte::solde<<endl;


}
void CptCourant::Ajouter (double montant) // Ajoute de l'argent au solde
{
    Compte::solde=Compte::solde+montant;
    #ifdef DEBUG
		cout << "Ajouter dans le compte courant  " << (int)(this)<<endl;
	#endif
}


void CptCourant::Retirer ( double montant ) // Retire de l'argent au solde de compte courant
{
    #ifdef DEBUG
		cout << "Retirer argent compte courant" << (int)(this)<<endl;
	#endif

        Compte::solde=Compte::solde-montant;

}
 double CptCourant::RetirerAgio()
    {

        if(Compte::solde < 0)
			 {
               double res_agios = Compte::solde*(agios/100);
		       Compte::solde -= res_agios;
			 }
		else
			cout << endl << "Vous avez encore de l'argent,pas d'agios à retirer" << endl;

    }
double CptCourant::GetSolde ()
{
    return Compte::solde;
}
void CptCourant::Menu()
{
    //CLEAR;
    Ligne();
    cout<< " **************\   COMPTE COURANT   /************** "<<endl;
    Ligne();
    AfficherCompte();
    Ligne();
    cout<<endl<< " 1: Ajouter de l'argent"<<endl;
    cout<<endl<< " 2: Retirer de l'argent"<<endl;
    cout<<endl<< " 3: Retirer agios"<<endl;
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
    case 3:
        #ifdef DEBUG
            cout << "case 3 " <<endl;
        #endif
        break;
    case 0:
        #ifdef DEBUG
            cout << "case 0 " <<endl;
        #endif
        break;
    }
}
