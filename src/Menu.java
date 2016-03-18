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
	protected int nbLigne = 55;
	protected int temps=100;
	protected int nbVehiculesTotal; //nombre total de vehicules dans le programme (passés et en attente)
	protected int enAttente; //nombre de vehicules au feu
	protected Hashtable<Integer, Vehicule> bouchon;
	protected Feu feu;
	protected Scanner sc;
	protected String bouchon_s;
	
	public Menu() {
		try { this.bouchon = new Hashtable<Integer, Vehicule>(); }
			catch (Exception e) { }
		try { this.feu = new Feu(); }
			catch (Exception e) { }
		try { this.sc = new Scanner(System.in); }
			catch (Exception e) { }
		this.nbVehiculesTotal = 0;
		this.enAttente = 0;
	}
	
	public void call() {
		if (this.bouchon.size() < 1) {
			ajouterVehicules();
		}
		else { System.out.println("un bouchon existe"); }
		
		int choix;
		do {
			ligne();
			System.out.println(" ---  _ _   _ _    _ ____    _ _     _    _     _  --- ");
			System.out.println(" --- | | \\_/ | |  | |____|  | | \\   | |  | |   | | --- ");
			System.out.println(" --- | |\\   /| |  | |___    | |\\ \\  | |  | |   | | --- ");
			System.out.println(" --- | | \\_/ | |  | |___|   | | \\ \\ | |  | |   | | --- ");
			System.out.println(" --- | |     | |  | |____   | |  \\ \\| |  | |___| | --- ");
			System.out.println(" --- |_|     |_|  |_|____|  |_|   \\_|_|  \\_______/ --- \n");
			ligne();
			this.AfficherBouchon();
			System.out.println("\n 1 : Simulation automatique (pendant le temps de votre choix)");
			System.out.println(" 2 : Simulation automatique (faire passer tous les vehicules)");
			System.out.println(" 3 : Gestion manuelle du feu");
			System.out.println(" 4 : Ajouter des vehicules au feu");
			System.out.println("\n 0 : Quitter");
			ligne();
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
			case 4:
				ajouterVehicules();
				break;
			case 0:
				System.out.println("Merci d'avoir utilise notre programme");
				break;
			default:
				System.out.println("Choix du menu non reconnu");
				break;
			}
		}
		while (choix != 0);
	}
	
	public void ligne() {
		for (int i = 0; i < this.nbLigne; i++) {
			System.out.print("*");
		}
		System.out.print("\n");
	}
	
	public void ajouterVehicules() {
		System.gc();
		System.out.println(bouchon.keys());
		System.out.println("Merci de remplir la file de voiture\nsous la forme: 11221111212122...\navec: 1 pour moto, 2 pour voiture");
		if (sc.hasNext() && this.nbVehiculesTotal > 0) {
			String poubelle=sc.nextLine();
		}
		bouchon_s = sc.nextLine();
		int taille= bouchon_s.length();
		System.out.println("nb de vehicules a ajouter : " +taille);
		Moto moto = new Moto();
		Voiture voiture = new Voiture();
		int id=this.bouchon.size();
		for (int i=id; i<(id+taille) ; i++) {
			switch (bouchon_s.charAt(i-id)) {
			case '1':
				System.out.println(" ajout d'une moto " +i);
				try { this.bouchon.putIfAbsent(i, moto); }
					catch (Exception e) { System.out.println("impossible de creer le vehicule");}
				this.nbVehiculesTotal++;
				this.enAttente++;
				break;
			case '2':
				System.out.println(" ajout d'une voiture " +i);
				try { this.bouchon.putIfAbsent(i, voiture); }
				catch (Exception e) { System.out.println("impossible de creer le vehicule"); }
				this.nbVehiculesTotal++;
				this.enAttente++;
				break;
			default:
				System.out.println("Erreur: le caractere "+ (i+1) +" n'est pas reconnu");
				break;
			}
		}
		System.out.println("bouchon: "+this.bouchon.size());
		this.AfficherBouchon();
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
					this.enAttente--;
					i++;
				}
				AfficherBouchon(); // affichage des vehicules restant
				temps=temps-feu.dureeAvance;
			}
			else {
				feu.Decompte();
				temps=temps-feu.dureeArret;
			}
		}
		while (temps > 0);
		System.out.println("temps restant: " +temps);
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
				this.enAttente--;
				i++;
			}
			AfficherBouchon(); // affichage des vehicules restant
		}
		while (i<taille);
	}
	
	/**
	 * @boucle :
	 * 1: on affiche le prochain vehicule a passer
	 * 2: on passe le feu au vert
	 * 3: on fait passer le vehicule
	 * 4: on supprimme le vehicule de la liste
	 * 5: on affiche le vehicule suivant
	 * 6: on demande si on veut passer le feu au rouge ou faire passer le vehicule suivant
	 * jusqu'a liste vide ou quitter
	 */
	public void feuManuel() {
		int choix = 9;
		int num=0;	
		Vehicule enCours = bouchon.get(0);
		while((this.enAttente > 0) && choix != 0)
		{
			enCours = bouchon.get(num);
				System.out.println("Vehicule suivant a passer: " + enCours.nom );
				System.out.println(" 1 - Laisser passer le vehicule suivant \n 2 - Changer la couleur du feu \n 0 - Retour");
				choix = sc.nextInt();
				switch(choix) 
				{
				case 1:
					if (feu.arret==false) 
					{
						enCours.action(false); // = feu rouge faux--> donc passageOK
						bouchon.remove(enCours); // le vehicule passe, il est supprimme de la liste
						num++;
						this.enAttente--;
					}
					else
					{
						System.out.println(" !!!!!!! Impossible - Le feu est rouge - !!!!!!!\n");
						ligne();
					}
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

	public void AfficherBouchon() {
		//int taille = this.enAttente;
		int taille = bouchon.size();
		int n = 0;//this.nbVehiculesTotal - this.enAttente;
		if(bouchon.size() > 0)	{
			ligne();
			System.out.println("<Vehicules dans la file: "+taille);
			for (int i=n; i<taille; i++) {
				Vehicule enCours = this.bouchon.get(i);
				System.out.print(" "+ enCours.nom);
			}
			System.out.print(" >\n");
			ligne();
		}
		else
			System.out.println(" <route degagee>");
	}
}