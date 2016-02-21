/// ROMAIN

#include "cptPEL.h"

CptPEL::CptPEL(string numCompte, Date d, int dureeBloquage, double versement): Compte (numCompte, d)
{
	#ifdef DEBUG
		cout << "Constructeur CptPEL Default " << (int)(this)<<endl;
	#endif
	this->dureeBloquage = dureeBloquage;
	this->versement = versement;
	this->dateDebloquage.an += dureeBloquage;
} 
	


CptPEL::~CptPEL()
{
	#ifdef DEBUG
		cout << "Destructeur CptPEL" << (int)(this)<<endl;
	#endif
}

void CptPEL::Menu()
{
	char choix;
	do
	{
		CLEAR;
		Ligne();
		cout << endl << "\tMenu PEL" << endl << endl;
		Ligne();
		cout << endl << "1 - Consulter" << endl;
		cout << "2 - Modifier le versement" << endl;
		cout << "3 - Ajouter le versement" << endl;
		cout << "4 - Ajouter de l'argent" << endl;
		cout << "5 - Faire l'emprunt" << endl;
		cout << "0 - Retour" << endl << endl;
		cin >> choix;
		switch (choix)
		{
			case '1' :
				Consulter();
				break;
	
			case '2' :
				ModifierVersement();
				break;
	
			case '3' :
				AjouterVersement();
				break;
	
			case '4' :
				Ajouter();
				break;
	
			case '5' :
				Emprunter();
				break;
			case '0' :
			break;
	
			default:
			CLEAR;
				cout << endl<< "Ce choix est incorrect" << endl;
				cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
				Poubelle();
			CLEAR;
		}
	}while (choix != '0');
}
void CptPEL::Emprunter()
{
	double montant = 0;
	Ligne();
	cout << endl << "\tMenu PEL" << endl << endl;
	Ligne();
	if (dateDebloquage < today)
	{
		cout << " Combien voulez vous emprunter a la banque? " << endl;
		cin >> montant;
		Compte::Retirer(montant);
		Compte::Historique((-1)*montant);
	}
	else
	{
		cout << "Le compte est toujours bloqué" << endl;
		cout << " Appuyer sur entree pour continuer ... " << endl;
		Poubelle();
		getchar();	
	}	
}

void CptPEL::ModifierVersement()
{
	do {
	CLEAR;
	Ligne();
	cout << endl << "\tMenu PEL" << endl << endl;
	Ligne();
	cout << endl << "Entrer la nouvelle somme a verser chaque mois"<< endl;
	cin >> versement;
	}while (versement <= 50);
}


void CptPEL::AjouterVersement()
{
	CLEAR;
	Ligne();
	cout << endl << "\tMenu PEL" << endl << endl;
	Ligne();
	Compte::solde += versement;
	cout << endl << "Versement effectué" << endl << endl;
	cout << "appuyer sur entrée pour continuer ...";
	Compte::Historique(versement);
	Poubelle();
	getchar(); 
}

void CptPEL::Consulter()
{
	CLEAR;
	Ligne();
	cout << endl << "\tMenu PEL" << endl << endl;
	Ligne();
	cout << endl << "Date de Débloquage : " << dateDebloquage << endl;
	Poubelle();
	Compte::Consulter();
}

void CptPEL::Ajouter()
{
	double somme = 0;
	do {
		CLEAR;
		Ligne();
		cout << endl << "\tMenu PEL" << endl << endl;
		Ligne();
		cout << endl << "Quelle somme voulez vous ajouter ?" << endl;
		cin >> somme;
		Compte::Ajouter(somme);
	}while (somme < 0);
	Compte::Historique(somme);
}
