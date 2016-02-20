#Compilateur utilisé
Compilo=g++
SRC=$(wildcard *.c)
CFLAGS=-Wall

# Cible principale
ProjetBanque.cestparti: utils.o date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o
	$(Compilo) $(CFLAGS) -o $@ utils.o date.o cptCourant.o cptEpargne.o cptBloque.o cptPEL.o compte.o client.o banque.o main.o


# Test unitiaires
test_banque: utils.o date.o compte.o cptBloque.o cptCourant.o cptEpargne.o cptPEL.o client.o banque.o test_banque.o
	$(Compilo) -o test_banque.cestparti $^

test_client: utils.o date.o cptBloque.o cptCourant.o cptEpargne.o cptPEL.o compte.o client.o test_client.o
	$(Compilo) -o test_client.cestparti $^
	
test_cptCourant: utils.o date.o cptCourant.o compte.o test_cptCourant.o
	$(Compilo) -o test_cptCourant.cestparti $^

test_cptEpargne: utils.o date.o cptEpargne.o compte.o test_cptEpargne.o
	$(Compilo) -o test_cptEpargne.cestparti $^
	
test_cptBloque: utils.o date.o cptBloque.o compte.o test_cptBloque.o
	$(Compilo) -o test_cptBloque.cestparti $^
	
test_cptPEL: utils.o date.o cptPEL.o compte.o test_cptPEL.o
	$(Compilo) -o test_cptPEL.cestparti $^

test_compte: utils.o date.o compte.o test_compte.o
	$(Compilo) -o test_compte.cestparti $^

test_date: utils.o date.o test_date.o
	$(Compilo) -o test_date.cestparti $^

test_utils: utils.o test_utils.o
	$(Compilo) -o test_utils.cestparti $^
	
# Dépendances des tests unitaires
test_banque.o: test_banque.cpp utils.o date.o cptBloque.o cptCourant.o cptEpargne.o cptPEL.o compte.o client.o banque.o
	$(Compilo) -c $<
	
test_client.o: test_client.cpp utils.o date.o cptBloque.o cptCourant.o cptEpargne.o cptPEL.o compte.o client.o
	$(Compilo) -c $<
	
test_compte.o: test_compte.cpp utils.o date.o compte.o
	$(Compilo) -c $<
	
test_cptCourant.o: test_cptCourant.cpp utils.o date.o cptCourant.o compte.o 
	$(Compilo) -c $<

test_cptEpargne.o: test_cptEpargne.cpp utils.o date.o cptEpargne.o compte.o
	$(Compilo) -c $<

test_cptBloque.o: test_cptBloque.cpp utils.o date.o cptBloque.o compte.o 
	$(Compilo) -c $<	

test_cptPEL.o: test_cptPEL.cpp utils.o date.o cptPEL.o compte.o 
	$(Compilo) -c $<

test_date.o: test_date.cpp utils.o date.o
	$(Compilo) -c $<
	
test_utils.o: test_utils.cpp utils.o
	$(Compilo) -c $<
	
# Dépendances
utils.o: utils.cpp utils.h
	$(Compilo) $(CFLAGS) -c utils.cpp

date.o: date.cpp date.h utils.o
	$(Compilo) $(CFLAGS) -c date.cpp

cptCourant.o: cptCourant.cpp cptCourant.h compte.o
	$(Compilo) $(CFLAGS) -c cptCourant.cpp

cptEpargne.o: cptEpargne.cpp cptEpargne.h compte.o
	$(Compilo) $(CFLAGS) -c cptEpargne.cpp

cptBloque.o: cptBloque.cpp cptBloque.h compte.o
	$(Compilo) $(CFLAGS) -c cptBloque.cpp

cptPEL.o: cptPEL.cpp cptPEL.h compte.o
	$(Compilo) $(CFLAGS) -c cptPEL.cpp

compte.o: compte.cpp compte.h date.o utils.o
	$(Compilo) $(CFLAGS) -c compte.cpp

client.o: client.cpp client.h compte.o
	$(Compilo) $(CFLAGS) -c client.cpp

banque.o: banque.cpp banque.h client.o
	$(Compilo) $(CFLAGS) -c banque.cpp

main.o: main.cpp banque.o
	$(Compilo) $(CFLAGS) -c	main.cpp

# Cibles fictives
MrProper:
	echo "Suppression des *.o"
	rm -rf *.o

ResetAll:
	echo "R.A.Z"
	rm -rf *.o *.cestparti
