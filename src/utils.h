#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<string>
using namespace std;
#include <cstdlib>

#define DEBUG 1

#ifdef __linux
#define CLEAR system("clear")
#else
    #ifdef WIN32
    #define CLEAR system("cls")
    #endif // WIN32
#endif // UNIX

#define LIGNE 50

//fonction pour tracer une ligne pour les menus (il suffit de changer le define pour changer la taille de toutes les lignes)
void Ligne(void);

void Poubelle();

#endif //UTILS_H
