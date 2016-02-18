#include "client.h"

//************* FONCTIONS MEMBRES Client **************
void Client::Menu()
{
    char choix='z';
    do
    {
        CLEAR;
        Ligne();
        cout<< " / / / / / / COMPTE CLIENT \\ \\ \\ \\ \\ \\ "<<endl;
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
        cout<< "Appuyez sur Entree pour continuer"<<endl;
        Poubelle(); // vide le cache et met en pause avant d'effacer l'ecran
    } //fin do
    while (choix!='0');
} // fin Menu()


void Client::Afficher()
{
    cout<<nom<<" "<<prenom<<endl<<mail<<endl;
    for (int i=0; i<10; i++)
        cout<<telephone[i];
    cout<<endl<<adresse<<endl<<"numero client: "<<numClient<<endl;
}

void Client::AjouterCompte()
{
    char choix='z';
    int numero=0;
    do
    {
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
            #ifdef DEBUG
                cout << "case 1: vector Comptes Courants " <<endl;
            #endif
            if (listeCC.size()==0) //si aucun, on ajoute en premier element
                cout<<"...en developpement..."; // <-------------------------------- A faire
            else //si au moins un compte present, on ajoute a la suite
                cout<<"...en developpement..."; // <-------------------------------- A faire
            break;
        case '2':
            #ifdef DEBUG
                cout << "case 2: vector Livrets Epargne " <<endl;
            #endif
            if (listeLE.size()==0) //si aucun, on ajoute en premier element
                cout<<"...en developpement..."; // <-------------------------------- A faire
            else //si au moins un compte present, on ajoute a la suite
                cout<<"...en developpement..."; // <-------------------------------- A faire
            break;
        case '3':
            #ifdef DEBUG
                cout << "case 3: vector Compte Bloque " <<endl;
            #endif
            if (listeCB.size()==0) //si aucun, on ajoute en premier element
                cout<<"...en developpement..."; // <-------------------------------- A faire
            else //si au moins un compte present, on ajoute a la suite
                cout<<"...en developpement..."; // <-------------------------------- A faire
            break;
        case '4':
            #ifdef DEBUG
                cout << "case 4: vector Plan Epargne Logement " <<endl;
            #endif
            if (listePEL.size()==0) //si aucun, on ajoute en premier element
                cout<<"...en developpement..."; // <-------------------------------- A faire
            else //si au moins un compte present, on ajoute a la suite
                cout<<"...en developpement..."; // <-------------------------------- A faire
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
} //fin AjouterCompte()

void Client::SupprimerCompte()
{
    char choix='z';
    int numero=0;
    do
    {
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
            #ifdef DEBUG
                cout << "case 1: vector Comptes Courants " <<endl;
            #endif
            if (listeCC.size()==0)
                cout<<"Vous n'avez pas de Compte Courant"<<endl;
            else if (listeCC.size()==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeCC[0] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a supprimer: ";
                for (int i=0; i<listeCC.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeCC[numero] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            break;
        case '2':
            #ifdef DEBUG
                cout << "case 2: vector Livrets Epargne " <<endl;
            #endif
            if (listeLE.size()==0)
                cout<<"Vous n'avez pas de Livret Epargne"<<endl;
            else if (listeLE.size()==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeLE[0] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listeLE.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeLE[numero] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            break;
        case '3':
            #ifdef DEBUG
                cout << "case 3: vector Compte Bloque " <<endl;
            #endif
            if (listeCB.size()==0)
                cout<<"Vous n'avez pas de Compte Bloque"<<endl;
            else if (listeCB.size()==1)
            {
                #ifdef DEBUG
                    cout << "suppression listeCB[0] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listeCB.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listeCB[numero] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            break;
        case '4':
            #ifdef DEBUG
                cout << "case 4: vector Plan Epargne Logement " <<endl;
            #endif
            if (listePEL.size()==0)
                cout<<"Vous n'avez pas de Plan Epargne Logement"<<endl;
            else if (listePEL.size()==1)
            {
                #ifdef DEBUG
                    cout << "suppression listePEL[0] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
            else
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listePEL.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                #ifdef DEBUG
                    cout << "suppression listePEL[numero] "<<endl;
                #endif
                cout<<"...en developpement..."; // <-------------------------------- A faire
            }
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
} //fin SupprimerCompte()

void Client::GererCompte()
{
    char choix='z';
    int numero=0;
    do
    {
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
            #ifdef DEBUG
                cout << "case 1: vector Comptes Courants " <<endl;
            #endif
            if (listeCC.size()==0)
                cout<<"Vous n'avez pas de Compte Courant"<<endl;
            else if (listeCC.size()>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listeCC.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeCC[numero].Menu();
            }
            else
                listeCC[0].Menu();
            break;
        case '2':
            #ifdef DEBUG
                cout << "case 2: vector Livrets Epargne " <<endl;
            #endif
            if (listeLE.size()==0)
                cout<<"Vous n'avez pas de Livret Epargne"<<endl;
            else if (listeLE.size()>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listeLE.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeLE[numero].Menu();
            }
            else
                listeLE[0].Menu();
            break;
        case '3':
            #ifdef DEBUG
                cout << "case 3: vector Compte Bloque " <<endl;
            #endif
            if (listeCB.size()==0)
                cout<<"Vous n'avez pas de Compte Bloque"<<endl;
            else if (listeCB.size()>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listeCB.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listeCB[numero].Menu();
            }
            else
                listeCB[0].Menu();
            break;
        case '4':
            #ifdef DEBUG
                cout << "case 4: vector Plan Epargne Logement " <<endl;
            #endif
            if (listePEL.size()==0)
                cout<<"Vous n'avez pas de Plan Epargne Logement"<<endl;
            else if (listePEL.size()>1)
            {
                cout<< " Merci d'indiquer le numero du compte a gerer: ";
                for (int i=0; i<listePEL.size(); i++)
                    cout<<i<< " ";
                cout<<endl;
                cin>>numero;
                listePEL[numero].Menu();
            }
            else
                listePEL[0].Menu();
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
} //fin GererCompte

void Client::SupprimerClient()
{
    //
}
