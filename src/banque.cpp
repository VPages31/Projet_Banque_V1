#include "banque.h"

Banque::Banque(string nom , string adresse )
{
	#ifdef DEBUG
		cout << "Constructeur Banque" << endl;
	#endif
	this->nomBanque = nom;
	this->adresse = adresse;
}

Banque::~Banque()
{
	#ifdef DEBUG
		cout << "Destruteur Banque" << endl;
	#endif
}

void Banque::Menu()
{
	char choix;
	do {
		CLEAR;
		Ligne();
		cout<< " **************\\     BANQUE      /************** "<<endl;
		Ligne();
		cout << endl << " 1 - Afficher la Banque" << endl;
		cout << " 2 - Modifier la Banque" << endl;
		cout << " 3 - Nouveau Client" << endl;
		cout << " 4 - Acces Client" << endl;
		cout << " 5 - Modifier date du jour" << endl;
		cout << " 0 - Quitter" << endl;
		cin >>choix;
		switch (choix)
		{
			case '1':
				Afficher();
				break;

			case '2':
				ModifierBanque();
				break;

			case '3':
				NouveauClient();
				break;

			case '4':
				Authentification();
				break;

			case '5':
				ModifierToday();
				break;

			case '0':
				break;
		}
	}while(choix != '0');

}

void Banque::Afficher()
{
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	cout << endl << "Banque : " << nomBanque << endl;
	cout << "Adresse : " << adresse << endl << endl;
	cout << "Liste client : " << endl;
	if (listeC.size() == 0)
		cout << "Aucun client dans la banque" << endl;
	else
	{
		for (int i = 0; i < listeC.size(); i++)
		{
			cout << listeC[i].nom << " " << listeC[i].prenom << " ";
			cout << listeC[i].numClient << endl;
		}
	}
	cout << endl << endl << " Appuyer sur entree pour continuer ... " << endl;
	Poubelle();
	getchar();


}

void Banque::ModifierBanque()
{
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	Poubelle();
	cout << "Entrez le nom de la banque" << endl;
	getline(cin, nomBanque);
	cout << "Entrez l'adresse de la banque" << endl;
	getline(cin, adresse);

}

void Banque::ModifierBanque(string nom, string adr)
{ 	nomBanque=nom;
	adresse=adr;
}


void Banque::Authentification()
{
	int num;
	int i = 0;
	CLEAR;
	Ligne();
	cout<< " **************\\     BANQUE      /************** "<<endl;
	Ligne();
	if (listeC.size() == 0)
	{
		cout << "Aucun client dans la banque" << endl;
		cout << "Appuyer sur entree pour continuer..." << endl;
		Poubelle();
		getchar();
	}
	else
	{
		bool identique = false; // sert a vérifier si le numero de compte choisis existe true = numero existant
		do{
			i = 0;
			cout << " Entrez le numero de client (0 pour quitter)" << endl;
			cin >> num;
			if (num == 0)
				return;
			else
			{	
				do{
					if (listeC[i].numClient == num)
					{
						identique = true;
					}
					i ++;
				}while(i < (int)listeC.size() && identique == false);
			}
		}while (identique == false);
		cout << " Client trouvé " << endl;
		listeC[i-1].Menu();

	}
}

void Banque::NouveauClient()
{
	int num = 0;
	int i = 0;
	bool identique = true; // sert a vérifier si le numero de compte choisis n'est pas deja pris true = numero deja existant
	CLEAR;
	Ligne();
	cout<< " **************\\ NOUVEAU CLIENT /************** "<<endl;
	Ligne();
	do{
		identique == true;
		cout << " Entrez le nouveau numero de client (0 pour quitter)" << endl;
		cin >> num;
		if (num == 0)
		{
			return;
		}
		if (listeC.size()==0)
		{
			identique = false;
		}
		else
		{			
			do{
				if (listeC[i].numClient != num)
				{
					identique = false;
				}
				i ++;
			}while(i < listeC.size() && identique == true);
		}
		cout << endl << "Numero de compte deja existant !" << endl;
	}while (identique == true);
	Client c (num);
	listeC.push_back (c);
	CLEAR;
	Ligne();
	cout<< " **************\\ NOUVEAU CLIENT /************** "<<endl;
	Ligne();
	cout << endl << " Entrez le nom client" << endl;
	cin >> listeC[listeC.size()-1].nom;
	cout << endl << " Entrez le prenom du client " << endl;
	cin >> listeC[listeC.size()-1].prenom;
	Poubelle();
	cout << endl << " Entrez le mail du client" << endl;
	getline(cin, listeC[listeC.size()-1].mail);
	cout << endl << "  Entrez son adresse " << endl;
	getline(cin, listeC[listeC.size()-1].adresse);
	cout << endl << " Entrez le numero de telephone" << endl;
	getline(cin, listeC[listeC.size()-1].telephone);
}

void Banque::ModifierToday()
{
	CLEAR;
	Ligne();
	cout<< " ************\\ Changement Date du jour /************ "<<endl;
	Ligne();
	cout << endl << "Nous sommes le :  " << today;
	today.ModifierDate();
	cout << endl << " La nouvelle date est : " << today << endl << endl;
	cout << "Appuyer sur entrée pour continuer ... " << endl;
	Poubelle();
	getchar();
}
