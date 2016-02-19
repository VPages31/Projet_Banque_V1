#include "cptEpargne.h"

    //Constructeur
    CptEpargne::CptEpargne(string num, int plaf, double inte):Compte(num)
    {   interets=inte;
        plafond=plaf;
        #ifdef DEBUG
            cout << "Constructeur par parametres cptEpargne" << endl;
        #endif // DEBUG
    }
    
    
    //Affectation
	CptEpargne &CptEpargne::operator= (const CptEpargne &c)
	{ 	Compte::numCompte=c.Compte::numCompte;
		Compte::solde=c.Compte::solde;
		Compte::D=c.Compte::D;
		int taille=(signed)c.historique.size();
		if (taille==0)
			historique[0]=c.historique[0];
		else
		{	int i;
			for(i=0; i<taille; i++)
				Compte::historique[i]=c.Compte::historique[i];
		}
		
		interets=c.interets;
		plafond=c.plafond;
		#ifdef DEBUG
			cout << "operator = CptEpargne " << (int)(this)<<endl;
		#endif
		return (*this);
	}
	// Destructeur
    CptEpargne::~CptEpargne()
    { 	
		#ifdef DEBUG
            cout << "Destructeur compte epargne " << (int)(this)<<endl;
        #endif
    }

	void CptEpargne::Menu()
	{
		int choix;
		CLEAR;
		while(choix!=0)
		{	
			do
			  {
				
				cout << endl;
				Ligne();
				cout << " **************\\   COMPTE EPARGNE   /************** " << endl;
				Ligne();
				cout << endl << " 1: Consulter le compte" << endl;
				cout << endl << " 2: Ajouter de l'argent" << endl;
				cout << endl << " 3: Retirer de l'argent" << endl;
				cout << endl << " 4: Ajouter les interets" << endl;
				cout << endl << " 5: Afficher l\'historique" << endl;
				cout << endl << " 0: Retour" << endl;
				cin >> choix;
				Poubelle();
				
				#ifdef DEBUG
					cout << "votre choix: "<< choix << endl;
				#endif
				switch(choix)
				{	case 1:
						#ifdef DEBUG
							cout << "case 1 - Consulter" << endl;
						#endif
						CLEAR;
					Consulter();
					break;
					case 2:
						#ifdef DEBUG
							cout << "case 2 - Ajout" <<endl;
						#endif
						CLEAR;
					Ajouter();
					break;
					case 3:
						#ifdef DEBUG
							cout << "case 3 - Retrait" <<endl;
						#endif
						CLEAR;
					Retirer();
					break;
					case 4:
						#ifdef DEBUG
							cout << "case 4 - Interets" <<endl;
						#endif
						CLEAR;
					AjouterInterets();
					break;
					case 5:
						#ifdef DEBUG
							cout << "case 5 - Historique" <<endl;
						#endif
						CLEAR;
					Compte::Consulter();
					break;
					case 0:
						#ifdef DEBUG
							cout << "case 0 - Sortie" <<endl;
						#endif
						return;
					break;
					default:
						CLEAR;
						cout << endl<< endl << "Ce choix est incorrect" << endl;
						Poubelle();
						CLEAR;
				}	
			} while(choix < 1 || choix > 5);
		}
	}

    void CptEpargne::Consulter()
    {	Ligne();
		cout << "Compte Epargne n° " << Compte::numCompte << endl;
		Ligne();
		cout << "Ouvert le: ";
		D.AfficherDate();
		cout << "Solde: " << Compte::solde << " €" << endl;
		cout << "Taux d'interets :" << interets << " %" << endl;
		Ligne();
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
		Poubelle();
		CLEAR;
    }

    void CptEpargne::Ajouter()
    {	cout << "Saisir le montant : ";
		double m;
		cin >> m;
		
		if(Compte::solde + m <= plafond)
		{	Compte::solde += m;
			Compte::Historique(m);
			cout << "Vous ajoutez " << m << "€ au compte n°" << Compte::numCompte << endl << "Nouveau solde : " << Compte::solde << "€"<< endl;
		}
		else
		{	cout << endl << " Plafond atteint, operation impossible" << endl;
		}
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
		Poubelle();
		CLEAR;
    }

    void CptEpargne::Retirer()
	{	cout << "Saisir le montant : ";
		double m;
		cin >> m;
		
		if(Compte::solde - m >= 0)
		{ 	Compte::solde -= (m);
			Compte::Historique((-1)*m);
			cout << "Vous retirez " << m << "€ au compte n°" << Compte::numCompte << endl << "Nouveau solde : " << Compte::solde << endl;
		}
		else
		{ 	cout << endl << "Minimum atteint, operation impossible" << endl;
		}
	cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
	Poubelle();
	CLEAR;
    }

    void CptEpargne::AjouterInterets()
    { 	double res = Compte::solde*(interets/100);
		Compte::solde += res;
		Compte::Historique(res);
    }
    
