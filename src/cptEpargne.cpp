/// VINCENT

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
				cout << " *************\\   COMPTE EPARGNE   /************* " << endl;
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
							cout << "case 0 - Retour" <<endl;
						#endif						
						return;
					break;
					default:
						CLEAR;
						cout << endl<< "Ce choix est incorrect" << endl;
						cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
						Poubelle();
						CLEAR;
				}	
			} while(choix < 1 || choix > 5);
		} // 
	}///

    void CptEpargne::Consulter()
    {	Ligne();
		cout << "Compte Epargne n° " << Compte::numCompte << endl;
		Ligne();
		cout << endl << "Solde: " << Compte::solde << " €" << endl;
		cout << "Taux d'interets :" << interets << " %" << endl;
		Ligne();
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
		Poubelle();
		CLEAR;
    }

    void CptEpargne::Ajouter()
    {	double m;
		do
		{	cout << endl << "Saisir le montant : ";	
			cin >> m;
			if(m<=0)
				cout << endl << "Opération impossible" << endl;
		} while(m<=0);	// Impossible de déposer 0€ ou -30€
		if(Compte::solde + m <= plafond)
		{	Compte::solde += m;
			Compte::Historique(m);
			cout << "Vous ajoutez " << m << "€ au compte n°" << Compte::numCompte << endl << "Nouveau solde : " << Compte::solde << "€"<< endl;
		}
		else
		{	cout << endl << "\t Plafond atteint, operation impossible" << endl;
			cout << "\t Ouvrez un nouveau compte epargne" << endl;
		}
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl << endl;
		Poubelle();
		CLEAR;
    }

    void CptEpargne::Retirer()
	{	double m;
		do  // Controle d'un Montant non-nul (-> Retrait De 10€ Ou -10€ OK)
		{ 	cout << endl << "Saisir le montant : ";
			cin >> m;
			if(m==0)
				cout << endl << "Opération impossible" << endl;
		} while(m == 0);	// Impossible De Retirer 0€	
		
			if(Compte::solde - m >= 0)
			{ 	Compte::solde -= m;
				Compte::Historique((-1)*m);
				cout << "Vous retirez " << m << "€ au compte n°" << Compte::numCompte << endl << "Nouveau solde : " << Compte::solde << endl;
			}
			else
			{ 	cout << endl << "Minimum atteint, operation impossible" << endl;
			}
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl;
		Poubelle();
		CLEAR;
		}

    void CptEpargne::AjouterInterets()
    { 	double res = Compte::solde*(interets/100);
		cout << interets << " % d\'interets appliqués a " << Compte::solde << " €";
		Compte::solde += res;
		cout << endl << "|- - > Benefice de " << res << " €";
		cout << endl << "|- - - -> Nouveau solde : " << Compte::solde << " €";
		if(res!=0) // si le calcul n'est pas fait sur rien, inutil de rajouter une opération sur un solde de 0€ dans l'historique
			Compte::Historique(res);
			
		cout << endl << endl << "Pressez la touche \'Entree\' pour continuer..." << endl;
		Poubelle();
		CLEAR;
    }
    
