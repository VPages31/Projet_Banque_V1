/**
 * 
 */
 /*
package com.ldnr.feu;
import com.ldnr.vehicule.Vehicule;
import com.ldnr.vehicule.Moto;
import com.ldnr.vehicule.Voiture;
*/
import java.util.Hashtable;
import java.util.Scanner;


/**
 * @author Benoit
 *
 */
public class Menu {
	//Donnees Membres
	protected int nbLigne = 40;
	protected int temps=100;
	public Hashtable<Integer, Vehicule> bouchon;
	
	public Menu() {
		this.bouchon = new Hashtable<Integer, Vehicule>();
	}
	
	public void call() {
		if (bouchon.size() < 1) {
			initialize(bouchon);
		}
		else {}
		String choix= "z";
		Feu feu1 = new Feu();
		Scanner sc = new Scanner(System.in);
		ligne();
		System.out.println("\n ---------- M E N U ---------- ");
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
						// ici supprimmer les vehicules qui sont passes
						int temps = feu1.dureeArret;
						while (temps > 0) {
							Vehicule enCours = bouchon.get(1); //1 ou 0 ? le premier element
							int tps = enCours.getTPS();
							temps = temps - tps;
							bouchon.remove(1); //1 ou 0 ? le premier element
						}
						bouchon.values(); // affichage des vehicules restant
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
				System.out.println("Merci d'avoir utilise notre programme");
				break;
			default:
				System.out.println("Choix non reconnu");
				break;
			}
		}
		while (choix !="0");
		sc.close();
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
				System.out.println("Erreur: le caractere "+ (i+1) +" n'est pas reconnu");
				break;
			}
		}
		sc.close();
	}
	
	/**
	 * 
	 * @param bouchon : liste des vehicules qui attendent au feu
	 * boucle:
	 * 1: on affiche le prochain vehicule a� passer
	 * 2: on passe le feu au vert
	 * 3: on fait passer le vehicule
	 * 4: on supprimme le vehicule de la liste
	 * 5: on affiche le vehicule suivant
	 * 6: on demande si on veut passer le feu au rouge ou faire passer le vehicule suivant
	 * jusqu'a� liste vide ou quitter
	 */
	public void feuManuel(Hashtable<Integer, Vehicule> bouchon) {
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < bouchon.size(); ++i)
		{
			System.out.println("Vehicule suivant : " + bouchon.get(0) );
			System.out.println("1 - Laisser passer le vehicule suivant \n 2 - Changer la couleur du feu \n 3 - Retour");
			int choix = sc.nextInt();
			switch(choix) 
			{
				case 1:
					Vehicule enCours = bouchon.get(0);
					enCours.action(false); // = feu rouge faux--> donc passageOK		
				break;
				case 2:
					// Changement de feu
					System.out.println("Le case 2");
				break;
				case 3:
					// retour
				break;
			}
		}
		sc.close();
	}
}