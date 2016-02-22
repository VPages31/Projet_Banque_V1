#include "client.h"

//************* FONCTIONS MEMBRES Client **************
// Constructeur
Client::Client(int num)
{
    #ifdef DEBUG
		cout << "Constructeur client " << (int)(this)<<endl;
	#endif
    nom= "nom";
    prenom= "prenom";
    mail= "mail";
    telephone = "0000000000";
    adresse= "adresse par defaut";
    numClient=num;
}

// Destructeur
Client::~Client()
{
    #ifdef DEBUG
		cout << "Destructeur client " << (int)(this)<<endl;
	#endif
}

void Client::Menu()
{
    char choix='z';
    do
    {
        CLEAR;
        Ligne();
        cout<< " **************\\   COMPTE CLIENT   /************** "<<endl;
        Ligne();
        Afficher();
        Ligne();
        cout<<endl<< " 1: Ouvrir un compte"<<endl;
        cout<<endl<< " 2: Gerer un compte"<<endl;
        cout<<endl<< " 3: Fermer un compte"<<endl;
        cout<<endl<< " 0: Retour"<<endl;
        cin>>choix;
        Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
        #ifdef DEBUG
            cout << "votre choix: "<<choix<<endl;
        #endif
        switch(choix)
        {
        case '1':
            #ifdef DEBUG
                cout << "case 1: Ouvrir compte " <<endl;
            #endif
            AjouterCompte();
            break;
        case '2':
            #ifdef DEBUG
                cout << "case 2: Gerer compte " <<endl;
            #endif
            GererCompte();
            break;
        case '3':
            #ifdef DEBUG
                cout << "case 3: Fermer compte " <<endl;
            #endif
            SupprimerCompte();
            break;
        case '0':
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
        } //fin switch
    } //fin do
    while (choix!='0');
} // fin Menu()


void Client::Afficher()
{
    cout<<nom<<" "<<prenom<<endl<<mail<<endl;
    cout<<telephone;
    cout<<endl<<adresse<<endl<<"numero client: "<<numClient<<endl;
}

void Client::AjouterCompte()
{
    char choix='z';
    int numero=0;
    int taille=0;
    do
    {
	CLEAR;
        Ligne();
        cout<<endl<< " Type de compte a ajouter:"<<endl;
        cout<<endl<< " 1: Compte Courant"<<endl;
        cout<<endl<< " 2: Livret Epargne"<<endl;
        cout<<endl<< " 3: Compte Bloque"<<endl;
        cout<<endl<< " 4: Plan Epargne Logement"<<endl;
        cout<<endl<< " 0: Retour"<<endl;
        cin>>choix;
        Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
        #ifdef DEBUG
            cout << "votre choix: "<<choix<<endl;
        #endif
        switch(choix)
        {
        case '1':
            taille=(signed)listeCC.size();
            #ifdef DEBUG
                cout << "case 1: ajout Compte Courant " <<endl;
            #endif
            if (taille==0) //si aucun, on ajoute en premier element
            {
                CptCourant c;
                listeCC.push_back(c);
            }
            else //si au moins un compte present, on ajoute a la suite
            {
                CptCourant c;// <--------------------- A modifier en incrementant le numero de compte c("taille")
                listeCC.push_back(c);
            }
            cout<< "Compte cree avec succes." << endl << "Vous pouvez maintenant revenir dans le menu client et choisir Gerer Compte pour y acceder"<<endl<<"Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '2':
            taille=(signed)listeLE.size();
            #ifdef DEBUG
                cout << "case 2: ajout Livret Epargne " <<endl;
            #endif
            if (taille==0) //si aucun, on ajoute en premier element
            {
                CptEpargne c;
                listeLE.push_back(c);
            }
            else //si au moins un compte present, on ajoute a la suite
            {
                CptEpargne c;// <--------------------- A modifier en incrementant le numero de compte c("taille")
                listeLE.push_back(c);
            }
            cout<< "Compte cree avec succes." << endl << "Vous pouvez maintenant revenir dans le menu client et choisir Gerer Compte pour y acceder"<<endl<<"Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '3':
            taille=(signed)listeCB.size();
            #ifdef DEBUG
                cout << "case 3: ajout Compte Bloque " <<endl;
            #endif
            if (taille==0) //si aucun, on ajoute en premier element
            {
                CptBloque c;
                listeCB.push_back(c);
            }
            else //si au moins un compte present, on ajoute a la suite
            {
                CptBloque c;// <--------------------- A modifier en incrementant le numero de compte c("taille")
                listeCB.push_back(c);
            }
            cout<< "Compte cree avec succes." << endl << "Vous pouvez maintenant revenir dans le menu client et choisir Gerer Compte pour y acceder"<<endl<<"Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '4':
            taille=(signed)listePEL.size();
            #ifdef DEBUG
                cout << "case 4: ajout Plan Epargne Logement " <<endl;
            #endif
            if (taille==0) //si aucun, on ajoute en premier element
            {
                CptPEL c;
                listePEL.push_back(c);
            }
            else //si au moins un compte present, on ajoute a la suite
            {
                CptPEL c;// <--------------------- A modifier en incrementant le numero de compte c("taille")
                listePEL.push_back(c);
            }
            cout<< "Compte cree avec succes." << endl << "Vous pouvez maintenant revenir dans le menu client et choisir Gerer Compte pour y acceder"<<endl<<"Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '0':
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
        } //fin switch
    } //fin do
    while (choix!='0');
} //fin AjouterCompte()

void Client::SupprimerCompte()
{
    char choix='z';
    int numero=0;
    int taille=0;
    unsigned int i;
    do
    {	CLEAR;
        Ligne();
        cout<<endl<< " Type de compte a supprimer:"<<endl;
        cout<<endl<< " 1: Compte Courant"<<endl;
        cout<<endl<< " 2: Livret Epargne"<<endl;
        cout<<endl<< " 3: Compte Bloque"<<endl;
        cout<<endl<< " 4: Plan Epargne Logement"<<endl;
        cout<<endl<< " 0: Retour"<<endl;
        cin>>choix;
        Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
        #ifdef DEBUG
            cout << "votre choix: "<<choix<<endl;
        #endif
        switch(choix)
        {
        case '1':
            taille=(signed)listeCC.size();
            #ifdef DEBUG
                cout << "case 1: supprimer Compte Courant " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Compte Courant"<<endl;
            else if (taille==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeCC[0] "<<endl;
                #endif
                listeCC.erase (listeCC.begin()+1);
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a supprimer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeCC[numero] "<<endl;
                #endif
                listeCC.erase (listeCC.begin()+numero);
            }
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            CLEAR;
            break;
        case '2':
            taille=(signed)listeLE.size();
            #ifdef DEBUG
                cout << "case 2: supprimer Livret Epargne " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Livret Epargne"<<endl;
            else if (taille==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeLE[0] "<<endl;
                #endif
                listeLE.erase (listeLE.begin()+1);
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a supprimer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeLE[numero] "<<endl;
                #endif
                listeLE.erase (listeLE.begin()+numero);
            }
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            CLEAR;
            break;
        case '3':
            taille=(signed)listeCB.size();
            #ifdef DEBUG
                cout << "case 3: supprimer Compte Bloque " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Compte Bloque"<<endl;
            else if (taille==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeCB[0] "<<endl;
                #endif
                listeCB.erase (listeCB.begin()+1);
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a supprimer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeCB[numero] "<<endl;
                #endif
                listeCB.erase (listeCB.begin()+numero);
            }
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            CLEAR;
            break;
        case '4':
            taille=(signed)listePEL.size();
            #ifdef DEBUG
                cout << "case 4: supprimer Plan Epargne Logement " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Plan Epargne Logement"<<endl;
            else if (taille==1)
            {
                #ifdef DEBUG
                    cout << "suppression listePEL[0] "<<endl;
                #endif
                listePEL.erase (listePEL.begin()+1);
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a supprimer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listePEL[numero] "<<endl;
                #endif
                listePEL.erase (listePEL.begin()+numero);
            }
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            CLEAR;
            break;
        case '0':
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
        } //fin switch
    } //fin do
    while (choix!='0');
} //fin SupprimerCompte()

void Client::GererCompte()
{
    char choix='z';
    int numero=0;
    int taille=0;
    int i;
    do
    {
	CLEAR;
        Ligne();
        cout<<endl<< " Type de compte a gerer:"<<endl;
        cout<<endl<< " 1: Compte Courant"<<endl;
        cout<<endl<< " 2: Livret Epargne"<<endl;
        cout<<endl<< " 3: Compte Bloque"<<endl;
        cout<<endl<< " 4: Plan Epargne Logement"<<endl;
        cout<<endl<< " 0: Retour"<<endl;
        cin>>choix;
        Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
        #ifdef DEBUG
            cout << "votre choix: "<<choix<<endl;
        #endif
        switch(choix)
        {
        case '1':
            taille=(signed)listeCC.size();
            #ifdef DEBUG
                cout << "case 1: vector Comptes Courants " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Compte Courant"<<endl;
            else if (taille>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeCC[numero].Menu();
            }
            else
                listeCC[0].Menu();
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '2':
            taille=(signed)listeLE.size();
            #ifdef DEBUG
                cout << "case 2: vector Livrets Epargne " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Livret Epargne"<<endl;
            else if (taille>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeLE[numero].Menu();
            }
            else
                listeLE[0].Menu();
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '3':
            taille=(signed)listeCB.size();
            #ifdef DEBUG
                cout << "case 3: vector Compte Bloque " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Compte Bloque"<<endl;
            else if (taille>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeCB[numero].Menu();
            }
            else
                listeCB[0].Menu();
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '4':
            taille=(signed)listePEL.size();
            #ifdef DEBUG
                cout << "case 4: vector Plan Epargne Logement " <<endl;
            #endif
            if (taille==0)
                cout<<"Vous n'avez pas de Plan Epargne Logement"<<endl;
            else if (taille>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (i=0; i<taille; i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listePEL[numero].Menu();
            }
            else
                listePEL[0].Menu();
            cout<< "Appuyez sur Entree pour continuer"<<endl;
            Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
            break;
        case '0':
            #ifdef DEBUG
                cout << "case 0 " <<endl;
            #endif
            break;
        } //fin switch
    } //fin do
    while (choix!='0');
} //fin GererCompte

//lorsqu'un client a ferme tous ses comptes, il n'est plus dans la banque et on va renvoyer cette donnee
// a la banque pour qu'elle supprime ce client du vector Client
void Client::SupprimerClient()
{
    //
}
