#include "utils.h"

void Ligne(void)
{
    int i;
    for (i=0; i<LIGNE; i++)
        cout<<"*"; //si vous preferez des * a la place des - pour faire de jolies lignes c'est ici !
    cout<<endl;
}

void Poubelle()
{
    string temp;
    getline(cin, temp);
}
