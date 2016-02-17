#Compilateur utilisé
Compilo=g++
SRC=$(wildcard *.c)
CFLAGS=-Wall

# Cible principale
ProjetBanque.cestparti: date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o
	$(Compilo) $(CFLAGS) -o $@ date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o


# Test unitiaires
test_cptEpargne : test_cptEpargne.o compte.o cptEpargne.o date.o
	$(Compilo) -o test_cptEpargne.cestparti $^

testcompte : testcompte.o compte.o date.o
	$(Compilo) -o testcompte.cestparti $^

test_date : test_date.o date.o
	$(Compilo) -o test_date.cestparti $^

# Dépendances des tests unitaires
testcompte.o : testcompte.cpp compte.o date.o
	$(Compilo) -c $<
	
test_cptEpargne.o: test_cptEpargne.cpp compte.o cptEpargne.o date.o
	$(Compilo) -c $<

test_date.o : test_date.cpp date.o
	$(Compilo) -c $<

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
