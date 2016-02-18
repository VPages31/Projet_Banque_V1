#include "cptEpargne.h"

    //Constructeur
    CptEpargne::CptEpargne(string numCompte, int plaf, double inte):Compte(num)
    {   interets=i;
        plafond=plaf;
        #ifdef DEBUG
            cout << "Constructeur par parametres cptEpargne" << endl;
        #endif // DEBUG
    }
    
    //Affectation
	cptEpargne &cptEpargne::operator= (const cptEpargne &c)
	{ Compte::numCompte=c.Compte::numCompte;
		Compte::solde=c.Compte::solde;
		for (int i=0; i<10; i++)
		{
			Compte::historique[i] = c.Compte::historique[i];
		}
		Compte::D=c.Compte::D;
		interets=c.interets;
		plafond=c.plaf;
		#ifdef DEBUG
			cout << "operator= CptEpargne " << (int)(this)<<endl;
		#endif
		return (*this);
	}

    void CptEpargne::Consulter()
    { cout << endl <<  << endl;
    }

    void CptEpargne::Ajouter (double montant);
    {Ajouter(montant);
    }

    void CptEpargne::Retirer (double montant);
    { Retirer(montant);
    }


	void CptEpargne::Menu()
	{
		//CLEAR;
		Ligne();
		cout<< " / / / / / / COMPTE EPARGNE \\ \\ \\ \\ \\ \\ "<<endl;
		Ligne();
		AfficherCompte();
		Ligne();
		cout<<endl<< " 1: Ajouter de l'argent"<<endl;
		cout<<endl<< " 0: Retour"<<endl;
		char choix;
		cin>>choix;
		Poubelle(); //si jamais l'utilisateur entre plus d'1 caractere, on vide le cache
		#ifdef DEBUG
			cout << "votre choix: "<<choix<<endl;
		#endif
		switch(choix)
		{
		case 1:
			#ifdef DEBUG
				cout << "case 1 " <<endl;
			#endif
			break;
		case 0:
			#ifdef DEBUG
				cout << "case 0 " <<endl;
			#endif
			break;
		}
	}

    CptEpargne::~CptEpargne()
    {
        #ifdef DEBUG
            cout << "Destructeur compte epargne " << (int)(this)<<endl;
        #endif
    }
