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
		//CLEAR;
		Ligne();
		cout<< " / / / / / / COMPTE EPARGNE \\ \\ \\ \\ \\ \\ "<<endl;
		Ligne();
		//ConsulterCompte();
		Ligne();
		cout << endl << " 1: Ajouter de l'argent" << endl;
		cout << endl << " 2: Retirer de l'argent" << endl;
		cout << endl << " 3: Ajouter les interets" << endl;
		cout << endl << " 0: Retour" << endl;
		int choix;
		cin >> choix;

		#ifdef DEBUG
		cout << "votre choix: "<< choix << endl;
		#endif
		switch(choix)
		{	case 1:
				#ifdef DEBUG
				cout << "case 1 " <<endl;
				#endif
			Ajouter();
		break;
			case 2:
				#ifdef DEBUG
				cout << "case 1 " <<endl;
				#endif
			Retirer();
		break;
			case 3:
				#ifdef DEBUG
				cout << "case 1 " <<endl;
				#endif
			AjouterInterets();
		break;
			case 0:
				#ifdef DEBUG
				cout << "case 0 " <<endl;
				#endif
				// 
			break;
		default:
			cout << endl << "Ce choix est incorrect" << endl;
		}
	}

    void CptEpargne::Consulter()
    {  	cout << "Compte Epargne n° " << Compte::numCompte << " ouvert le: ";
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
    
    
