#include "compte.h"

main ()
{
	Compte C("0123456789");
	cout << C.GetSolde() << endl;
	C.Ajouter(10.15);
	cout << C.GetSolde() << endl;
	C.Retirer(25.65);
	cout << C.GetSolde() << endl;
	C.Consulter();
}