/// KARIMA

#include "cptCourant.h"


//fonction membre
// constructeur
CptCourant::CptCourant(string num ,int d): Compte(num)
{
    agios=d;
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
/*
void CptCourant::Ajouter (double montant) // Ajoute de l'argent au solde
{
    Compte::solde=Compte::solde+montant;
    cout<< " Votre montant vient d'etre ajoute\n"<<endl;
    Poubelle();
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
        cout<< " Votre montant vient d'etre retire \n"<<endl;
          Poubelle();

}
*/
void CptCourant::RetirerAgio()
    {
        if(Compte::solde <= 0)
			 {
               double res_agios = Compte::solde*(agios/100);
		       Compte::solde -= (-res_agios);
			Compte::Historique(res_agios);
		       cout<< " Votre agios vient d'etre retirer \n"<<endl;
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

    char choix;
    do
    {
        CLEAR;
        Ligne();
        cout<< " **************\\ COMPTE COURANT /*************** "<<endl;
        Ligne();
        AfficherCompte();
        Ligne();
        cout<<endl<< " 1: Ajouter de l'argent"<<endl;
        cout<<endl<< " 2: Retirer de l'argent"<<endl;
        cout<<endl<< " 3: Retirer Agios "<<endl;
        cout<<endl<< " 4: Consulter l'historique"<<endl;
        cout<<endl<< " 0: Retour"<<endl;
        cin>>choix;
        Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
        #ifdef DEBUG
            cout << "votre choix: "<<choix<<endl;
        #endif
        double montant=0.0;
        switch(choix)
        {
        case '1':
            CLEAR;
            #ifdef DEBUG
                cout << "case 1 " <<endl;
            #endif            
            cout<< " Montant a ajouter: ";
            cin>> montant;
            this->Ajouter(montant);
            break;
        case '2':
			CLEAR;
            #ifdef DEBUG
                cout << "case 2 " <<endl;
            #endif
            cout<< " Montant a retirer: ";
            cin>> montant;
            this->Retirer(montant);
            break;
        case '3':
			CLEAR;
            #ifdef DEBUG
                cout << "case 3 " <<endl;
            #endif
            this->RetirerAgio();
            break;
            case '4':
            CLEAR;
            #ifdef DEBUG
                cout << "case 4 " <<endl;
            #endif
            this->Consulter();
            break;
        case '0':
			CLEAR;
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
		default:
			CLEAR;
				cout << endl<< "Ce choix est incorrect" << endl;
				cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
				Poubelle();
			CLEAR;
        } //fin switch
    } //fin do
    while (choix!='0');
} // fin Menu()
