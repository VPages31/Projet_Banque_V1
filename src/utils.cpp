#ifdef UNIX
#define clear() system("clear")
#else
    #ifdef WIN32
    #define clear() system("cls")
    #endif // WIN32
#endif // UNIX

#define LIGNE 41

//fonction pour tracer une ligne pour les menus (il suffit de changer le define pour changer la taille de toutes les lignes)
void Ligne(void)
{
    int i;
    for (i=0; i<LIGNE; i++)
        printf("-"); //si vous preferez des * a la place des - pour faire de jolies lignes c'est ici !
    printf("\n");
}
