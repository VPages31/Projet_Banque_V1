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
    cout<<"Solde: "<<Compte::solde<<" avec un taux d'interets de "<<interets<<"%"<<endl;
    cout<<"duree du blocage : "<<blo_duree<<" ans"<<endl<<"date de fin de blocage: ";
    blo_date_debl.AfficherDate();
    AfficherDureeBlocage();
}

void CptBloque::AfficherStatutBlocage() //me souviens plus de ce que cette fonction doit faire...
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
}

CptBloque CptBloque::AjouterInterets()
{
    this->Compte::solde=this->Compte::solde+((this->Compte::solde*this->interets)/100);
    #ifdef DEBUG
		cout<<(int)(this)<< " AjouterInterets: " <<interets<< "% nouveau solde: " <<this->Compte::solde<<endl;
	#endif
    return (*this);
}

//************* FONCTIONS SURCHARGE Compte **************

void CptBloque::Ajouter (double montant) // Ajoute de l'argent au solde
{
    Compte::solde=Compte::solde+montant;
    #ifdef DEBUG
		cout << "Ajouter " << (int)(this)<<endl;
	#endif
}

void CptBloque::Retirer ( double montant ) // Retire de l'argent au solde
{
    #ifdef DEBUG
		cout << "Retirer " << (int)(this)<<endl;
	#endif
    if (blo_duree==0)
        Compte::solde=Compte::solde-montant;
    else
        cout<< "Votre compte est bloque, vous ne pouvez pas retirer "<<endl;
}

double CptBloque::GetSolde ()
{
    return Compte::solde;
}

void CptBloque::Menu()
{

    char choix;
    do
    {
        CLEAR;
        Ligne();
        cout<< " / / / / / / COMPTE BLOQUE \\ \\ \\ \\ \\ \\ "<<endl;
        Ligne();
        AfficherCompte();
        Ligne();
        cout<<endl<< " 1: Ajouter de l'argent"<<endl;
        cout<<endl<< " 2: Retirer de l'argent"<<endl;
        cout<<endl<< " 3: Ajouter les interets"<<endl;
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
            #ifdef DEBUG
                cout << "case 1 " <<endl;
            #endif
            cout<< " Montant a ajouter: ";
            cin>> montant;
            this->Ajouter(montant);
            break;
        case '2':
            #ifdef DEBUG
                cout << "case 2 " <<endl;
            #endif
            cout<< " Montant a retirer: ";
            cin>> montant;
            this->Retirer(montant);
            break;
        case '3':
            #ifdef DEBUG
                cout << "case 3 " <<endl;
            #endif
            this->AjouterInterets();
            break;
        case '0':
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
        } //fin switch
        cout<< "Appuyez sur Entree pour continuer"<<endl;
        Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
    } //fin do
    while (choix!='0');
} // fin Menu()
