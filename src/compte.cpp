#include "compte.h"
#include <iomanip>


Compte::Compte(string numCompte, Date d)
{
	#ifdef DEBUG
		cout << "Constructeur compte parametre " << (int)(this)<<endl;
	#endif
	this->numCompte = numCompte;
	solde = 0;
	D = d;
}

Compte::~Compte()
{
	#ifdef DEBUG
		cout << "Destructeur compte " << (int)(this)<<endl;
	#endif
}

void Compte::Ajouter (double montant) // Ajoute de l'argent au solde 
{
	solde=solde+montant;
	#ifdef DEBUG
		cout << "Ajouter au Solde " << (int)(this)<<endl;
	#endif
	this->Historique(montant);
}

void Compte::Consulter() // Permet de consulter le solde et l'historique du compte
{ 	CLEAR;
	int i = 0;
	int taille=(signed)historique.size();
	cout << endl << "Solde actuel : \t"  << setprecision(2) << solde << " €" << endl;
	cout << endl << "Historique :" << endl << endl;
	if (taille==0)
		cout << "Aucune operation effectuee"<<endl;
    else if (taille==1)
    { 	cout << (i+1) << " ->\t";
        if(historique[0] > 0)
			cout << "+" << setprecision(2) << historique[0] << " €" << endl; // Valeur Positive
		else
			cout << setprecision(2) << historique[0] << " €" << endl; // Valeur Negative Ou Zero 
	}
    else
    {
        for ( i = 0 ; i < 10 ; i ++)		// On Affiche Juste Les 10 Dernieres opérations
        { 	cout << (i+1) << " ->\t";
			if(historique[i] > 0)
				cout << "+" << setprecision(2) << historique[i] << " €" << endl; 
			else
				cout << setprecision(2)  << historique[i] << " €" << endl;
        }
    }
	cout << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
	Poubelle();
	CLEAR;
}

void Compte::Retirer ( double montant ) 
{
	solde = solde - montant;
	#ifdef DEBUG
		cout << "Retirer au Solde" << endl;
	#endif
	Historique((-1)*montant);
}

double Compte::GetSolde ()
{
	return (solde);
}

void Compte::Historique(double s) // ajoute une transaction dans historique
{
    #ifdef DEBUG
		cout << "Ajouter a l'historique " << (int)(this)<<endl;
	#endif
    historique.push_front( (signed) s);		// deque
}
