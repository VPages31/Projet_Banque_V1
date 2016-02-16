#Compilateur utilisé
Compilo=g++
SRC=$(wildcard *.c)
CFLAGS=-Wall

# Cible principale
ProjetBanque.cestparti: date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o
	$(Compilo) $(CFLAGS) -o $@ date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o

# Dépendances
date.o : date.cpp date.h 
	$(Compilo) $(CFLAGS) -c date.cpp

cptCourant.o : cptCourant.cpp cptCourant.h
	$(Compilo) $(CFLAGS) -c cptCourant.cpp

cptEpargne.o : cptEpargne.cpp cptEpargne.h
	$(Compilo) $(CFLAGS) -c cptEpargne.cpp

cptBloque.o : cptBloque.cpp cptBloque.h
	$(Compilo) $(CFLAGS) -c cptBloque.cpp

cptPEL.o : cptPEL.cpp cptPEL.h
	$(Compilo) $(CFLAGS) -c cptPEL.cpp

compte.o : compte.cpp compte.h cptPEL.o cptBloque.o cptEpargne.o cptCourant.o date.o
	$(Compilo) $(CFLAGS) -c compte.cpp

client.o : client.cpp client.h compte.o
	$(Compilo) $(CFLAGS) -c client.cpp

banque.o: banque.cpp banque.h client.o
	$(Compilo) $(CFLAGS) -c banque.cpp

main.o: main.cpp banque.o
	$(Compilo) $(CFLAGS) -c	main.cpp

# Cibles fictives
MrProper :
	echo "Suppression des *.o"
	rm -rf *.o

ResetAll :
	echo "R.A.Z"
	rm -rf *.o *.cestparti
