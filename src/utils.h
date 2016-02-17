#ifndef UTILS_H
#define UTILS_H

#ifdef UNIX
#define clear() system("clear")
#else
    #ifdef WIN32
    #define clear() system("cls")
    #endif // WIN32
#endif // UNIX

#define LIGNE 41

//fonction pour tracer une ligne pour les menus (il suffit de changer le define pour changer la taille de toutes les lignes)
void Ligne(void);

#endif