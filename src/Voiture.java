/**
 * 
 */


/**
 * @author Vincent
 *
 */
public final class Voiture extends Vehicule {
	// Donnees membres
	
	// Constructeur
	public Voiture() {
		super(); 
		this.setNom("voiture");
		this.setTPS(15);
	}
	// Methodes
	@Override
	void avancer() {
		System.out.println("\nLa " + getNom() + " demarre\n");
		System.out.println(" |--> elle traverse le carrefour en " + getTPS() + " sec.\n");
	}

	@Override
	void arreter() {
		System.out.println("\nLa " + getNom() + " freine et s'arrete\n");
	}
	
	@Override
	public void action(boolean feuRouge) {
		if(!feuRouge)
			this.avancer();
		else
			this.arreter();
	}
	
	
}
