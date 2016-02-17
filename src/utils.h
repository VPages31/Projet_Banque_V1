#include <iostream>
using namespace std;
#include <cstdlib>

#ifndef UTILS_H
#define UTILS_H

#ifdef __linux__
#define CLEAR system("clear")
#else
    #ifdef _WIN32
    #define CLEAR system("cls")
    #endif // WIN32
#endif // UNIX

#define LIGNE 41

//fonction pour tracer une ligne pour les menus (il suffit de changer le define pour changer la taille de toutes les lignes)
void Ligne(void);

#endif