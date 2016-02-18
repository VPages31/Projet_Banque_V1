#include "cptPEL.h"

CptPEL::CptPEL(string numCompte, Date d, int dureeBloquage, double versement): Compte (numCompte, d)
{
	#ifdef DEBUG
		cout << "Constructeur CptPEL Default " << (int)(this)<<endl;
	#endif
	this->dureeBloquage = dureeBloquage;
	this->versement = versement;
	this->dateDebloquage = today;
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
	int choix = 0;
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
		cout << "6 - Retour" << endl << endl;
		cin >> choix;
		switch (choix)
		{
			case 1 :
				Consulter();
			break;
	
			case 2 :
			break;
	
			case 3 :
			break;
	
			case 4 :
			break;
	
			case 5 :
			break;
	
			case 6 :
			break;
	
			default :
			break;
		}
	}while (choix != 6);
}
void CptPEL::Emprunter()
{
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
	getchar(); 
}

void CptPEL::Consulter()
{
	CLEAR;
	Ligne();
	cout << endl << "\tMenu PEL" << endl << endl;
	Ligne();
	cout << endl << "Date de Débloquage : " << dateDebloquage << endl;
	Compte::Consulter();
	cout << endl << "appuyer sur entree pour continuer ...";
	Poubelle();
	getchar();
}