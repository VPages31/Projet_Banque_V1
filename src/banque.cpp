#include "banque.h"

Banque(string nom , string adresse );
{
	#ifdef DEBUG
		cout << "Constructeur Banque" << endl;
	#endif
	this->nomBanque = nom;
	this->adresse = adresse;
}

virtual ~Banque();
{
	#ifdef DEBUG
		cout << "Destruteur Banque"
	#endif
}

void Banque::Menu()
{
	int choix;
	do {
		choix = 10;
		CLEAR;
		Ligne();
		cout<< " **************\\     BANQUE      /************** "<<endl;
		Ligne();
		cout << endl << " 1 - Afficher la Banque" << endl;
		cout << " 2 - Modifier la Banque" << endl;
		cout << " 3 - Nouveau Client" << endl;
		cout << " 4 - Acces Client" << endl;
		cout << endl << " 0 - Sortir" << endl;
		cin >>choix;
		switch (choix)
		{
			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 0:
				break;
		}
	}while(choix != 0);

}

void Banque::Afficher()
{
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	cout << endl << "Banque : " << nomBanque << endl;
	cout << "Adresse : " << adresse << endl << endl;
	cout << "Liste client : " << endl
	if (listeC.size() == 0)
		cout << "Aucuns client dans la banque"
	else
	{
		for (int i = 0; i < listeC.size(); i++)
		{
			cout << listeC[i].nom << " " << listeC[i].prenom << " ";
			cout << listeC[i].numClient << endl;
		}
	}


}

void Banque::ModifierBanque()
{
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	cout << "Entrez le nom de la banque" << endl;
	getline(nomBanque);
	cout << "Entrez l'adresse de la banque" << endl;
	getline(adresse);

}

void Banque::Authentification()
{
	int num;
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	if (listeC.size() == 0)
		cout << "Aucuns client dans la banque" << endl
		cout << "Appuyer sur entree pour continuer..." << endl
		getchar();
	else
	{
		cout << " Saisir le numero du client " << endl;
		cin >> num;
		// a terminer
	}
}

void Banque::NouveauClient()
{
	
}

// je ne met pas Banque:: car pourra etre appelé hors de la classe
void SupprimerCompte()
{
	
}
