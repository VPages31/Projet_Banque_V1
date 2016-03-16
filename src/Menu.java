/**
 * 
 */
package com.ldnr.feu;

import java.util.Hashtable;
import java.util.Scanner;

import com.ldnr.vehicule.Vehicule;
import com.ldnr.vehicule.Moto;
import com.ldnr.vehicule.Voiture;

/**
 * @author Benoit
 *
 */
public class Menu {
	//Données Membres
	protected int nbLigne = 40;
	protected int temps=100;
	
	public Menu() {
		Hashtable<Integer, Vehicule> bouchon = 
				new Hashtable<Integer, Vehicule>();
		if (bouchon.size() < 1) {
			initialize(bouchon);
		}
		else {
			String choix= "z";
			Feu feu1 = new Feu();
			Scanner sc = new Scanner(System.in);
			ligne();
			System.out.println(" ---------- M E N U ---------- ");
			ligne();
			System.out.println(" 1 : Simulation automatique");
			System.out.println(" 2 : Gestion manuelle du feu");
			System.out.println(" 3 : ");
			System.out.println("\n 0 : ");
			ligne();
			do {
				choix = sc.nextLine();
				switch (choix) {
				case "1":
					System.out.println("Merci d'entrer le temps de la simulation: ");
					temps = sc.nextInt();
					do {
						temps=temps-feu1.Decompte();
						if (feu1.arret == true) { 
							// ici supprimmer les véhicules qui sont passés
							//
							bouchon.values(); // affichage des véhicules restant
						}
					}
					while (temps > 0);
					System.out.println("temps restant: " +temps);
					break;
				case "2":
					feuManuel(bouchon);
					break;
				case "3":
					// au cas ou on veut ajouter qqchose
					break;
				case "0":
					System.out.println("Merci d'avoir utilisé notre programme");
					break;
				default:
					System.out.println("Choix non reconnu");
					break;
				}
			}
			while (choix !="0");
			sc.close();
		}
	}
	
	public void ligne() {
		for (int i = 0; i < this.nbLigne; i++) {
			System.out.print("*");
		}
	}
	
	public void initialize(Hashtable<Integer, Vehicule> bouchon) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Merci de remplir la file de voiture\nsous la forme: 11221111212122...\navec: 1 pour moto, 2 pour voiture");
		String bouchon_s = sc.nextLine();
		int taille= bouchon_s.length();
		Moto moto = new Moto();
		Voiture voiture = new Voiture();
		for (int i=0; i<taille ; i++) {
			switch (bouchon_s.charAt(i)) {
			case '1':
				bouchon.put(i, moto);
				break;
			case '2':
				bouchon.put(i, voiture);
				break;
			default:
				System.out.println("Erreur: le caractère "+ (i+1) +" n'est pas reconnu");
				break;
			}
		}
		sc.close();
	}
	
	public void feuManuel(Hashtable<Integer, Vehicule> bouchon) {
		//
	}
}
