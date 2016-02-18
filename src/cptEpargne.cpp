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
		for (int i=0; i<10; i++)
			Compte::historique[i] = c.Compte::historique[i];
		
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
				cout << " / / / / / / COMPTE EPARGNE \\ \\ \\ \\ \\ \\ " << endl;
				Ligne();
				cout << endl << " 1: Consulter le compte" << endl;
				cout << endl << " 2: Ajouter de l'argent" << endl;
				cout << endl << " 3: Retirer de l'argent" << endl;
				cout << endl << " 4: Ajouter les interets" << endl;
				cout << endl << " 5: Afficher l\'historique" << endl;
				cout << endl << " 0: Retour" << endl;
				cin >> choix;
				
				#ifdef DEBUG
					cout << "votre choix: "<< choix << endl;
				#endif
				switch(choix)
				{	case 1:
						#ifdef DEBUG
						cout << "case 1 - Consulter" << endl;
						#endif
					Consulter();
					break;
					case 2:
						#ifdef DEBUG
						cout << "case 2 - Ajout" <<endl;
						#endif
					Ajouter();
					break;
					case 3:
						#ifdef DEBUG
						cout << "case 3 - Retrait" <<endl;
						#endif
					Retirer();
					break;
					case 4:
						#ifdef DEBUG
						cout << "case 4 - Interets" <<endl;
						#endif
					AjouterInterets();
					break;
					case 5:
						#ifdef DEBUG
						cout << "case 4 - Interets" <<endl;
						#endif
					Compte::Consulter();
					break;
					case 0:
						#ifdef DEBUG
						cout << "case 0 - Sortie" <<endl;
						#endif
						CLEAR;
						return;
					break;
					default:
						cout << endl << "Ce choix est incorrect" << endl;
				}
			} while(choix < 1 || choix > 5);
		}
	}

    void CptEpargne::Consulter()
    {  	cout << endl << "Compte Epargne n° " << Compte::numCompte << " ouvert le: ";
		D.AfficherDate();
		cout << "Solde: " << Compte::solde << " avec un taux d'interets de " << interets << "%" << endl;
    }

    void CptEpargne::Ajouter()
    { 	cout << "Saisir le montant : ";
		double m;
		cin >> m;
		
		if(Compte::solde + m <= plafond)
			Compte::solde = Compte::solde + m;
		else
			cout << endl << "plafond atteint, operation impossible" << endl;
		
    }

    void CptEpargne::Retirer()
    {  	cout << "Saisir le montant : ";
		double m;
		cin >> m;
		
		if(Compte::solde - m >= 0)
			Compte::solde -= m;
		else
			cout << endl << "plus de fonds restants, operation impossible" << endl;
    }

    void CptEpargne::AjouterInterets()
    { 	double res = Compte::solde*(interets/100);
		Compte::solde += res;
    }
    

