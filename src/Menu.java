/**
 * 
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
	protected Hashtable<Integer, Vehicule> bouchon;
	protected Feu feu;
	protected Scanner sc;
	
	public Menu() {
		this.bouchon = new Hashtable<Integer, Vehicule>();
		this.feu = new Feu();
		this.sc = new Scanner(System.in);
	}
	
	public void call() {
		if (this.bouchon.size() < 1) {
			initialize();
		}
		else { System.out.println("un bouchon existe"); }
		ligne();
		System.out.println("\n ---------- M E N U ---------- ");
		ligne();
		System.out.println("\n 1 : Simulation automatique (pendant le temps de votre choix");
		System.out.println(" 2 : Simulation automatique (faire passer tous les vehicules)");
		System.out.println(" 3 : Gestion manuelle du feu");
		System.out.println("\n 0 : Quitter");
		ligne();
		int choix;
		do {
			choix = sc.nextInt();
			switch (choix) {
			case 1:
				feuAuto();
				break;
			case 2:
				feuAutoVide();
				break;
			case 3:
				feuManuel();
				break;
			case 0:
				System.out.println("Merci d'avoir utilise notre programme");
				break;
			default:
				System.out.println("Choix non reconnu");
				break;
			}
		}
		while (choix != 0);
	}
	
	public void ligne() {
		for (int i = 0; i < this.nbLigne; i++) {
			System.out.print("*");
		}
	}
	
	public void initialize() {
		System.out.println("Merci de remplir la file de voiture\nsous la forme: 11221111212122...\navec: 1 pour moto, 2 pour voiture");
		String bouchon_s = sc.nextLine();
		int taille= bouchon_s.length();
		Moto moto = new Moto();
		Voiture voiture = new Voiture();
		for (int i=0; i<taille ; i++) {
			switch (bouchon_s.charAt(i)) {
			case '1':
				this.bouchon.put(i, moto);
				break;
			case '2':
				this.bouchon.put(i, voiture);
				break;
			default:
				System.out.println("Erreur: le caractere "+ (i+1) +" n'est pas reconnu");
				break;
			}
		}
		this.AfficherBouchon(taille);
		//System.gc();
	}
	
	/**
	 * boucle:
	 * Affiche un compteur pour simuler l'ecoulement du temps
	 * avec alternance des feux
	 * A chaque feu rouge :
	 * On recupere le temps total disponible pour que des vehicules passent
	 * on recupere le temps mis par le premier vehicule pour passer
	 * on soustrait le temps du premier vehicule au temps total
	 * on supprime le premier vehicule
	 * et on recommence jusqu'a avoir un temps total <= 0;
	 * fin boucle: des que le temps entre par l'utilisateur est <=0
	 */
	public void feuAuto() {
		System.out.println("Merci d'entrer le temps de la simulation: ");
		temps = sc.nextInt();
		feu.arret=true;
		Vehicule enCours = bouchon.get(0);
		int i=0; //compteur de vehicule
		do {
			if (feu.arret == false) { 
				int tps_total = feu.dureeArret;
				// ici supprimmer les vehicules qui sont passes
				while (tps_total > 0) {
					enCours = bouchon.get(i);
					int tps = enCours.getTPS();
					tps_total = tps_total - tps;
					enCours.action(false);
					System.out.println(tps_total);
					bouchon.remove(i);
					i++;
				}
				AfficherBouchon(i); // affichage des vehicules restant
				temps=temps-feu.dureeAvance;
			}
			else {
				feu.Decompte();
				temps=temps-feu.dureeArret;
			}
		}
		while (temps > 0);
		System.out.println("temps restant: " +temps);
		//System.gc();
	}
	
	public void feuAutoVide() {
		feu.arret=true;
		Vehicule enCours = bouchon.get(0);
		int taille=bouchon.size();
		int i=0;
		do {
			feu.Decompte();
			int tps_total = feu.dureeArret;
			// ici supprimmer les vehicules qui sont passes
			while (tps_total > 0 && i < taille) {
				enCours = bouchon.get(i);
				int tps = enCours.getTPS();
				tps_total = tps_total - tps;
				enCours.action(false);
				System.out.println(tps_total);
				bouchon.remove(i);
				i++;
			}
			AfficherBouchon(i); // affichage des vehicules restant
		}
		while (i<taille);
	}
	
	/**
	 * boucle:
	 * 1: on affiche le prochain vehicule a�ｿｽ passer
	 * 2: on passe le feu au vert
	 * 3: on fait passer le vehicule
	 * 4: on supprimme le vehicule de la liste
	 * 5: on affiche le vehicule suivant
	 * 6: on demande si on veut passer le feu au rouge ou faire passer le vehicule suivant
	 * jusqu'a�ｿｽ liste vide ou quitter
	 */
	public void feuManuel() {
		int choix = 9;
		while((bouchon.size() > 0) && choix != 0)
		{
			for(int i = 0; i < bouchon.size(); ++i) 
			{
				System.out.println("Vehicule suivant : " + bouchon.get(0) );
				System.out.println("1 - Laisser passer le vehicule suivant \n 2 - Changer la couleur du feu \n 3 - Retour");
				choix = sc.nextInt();
				switch(choix) 
				{
					case 1:
						Vehicule enCours = bouchon.get(0);	// 0 ou 1 that's the question
						enCours.action(false); // = feu rouge faux--> donc passageOK
						bouchon.remove(enCours); // le vehicule passe, il est supprimm顤e la liste
					break;
					case 2:
						feu.Change();	// changement du feu et affichage en consequence inclus
						ligne();
						System.out.println("\n");
					break;
					case 0:
						// retour
					break;
				}
			}
		}
		//System.gc();
	}
	
	public void AfficherBouchon(int n) {
		int taille = this.bouchon.size();
		System.out.println("Vehicules dans la file: ");
		for (int i=n; i<taille; i++) {
			Vehicule enCours = this.bouchon.get(i);
			System.out.print(" "+ enCours.getNom());
		}
		System.out.println(" <route degagee>");
	}
}