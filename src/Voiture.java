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
		System.out.println("Le vehicule (" + getNom() + ") demarre");
		System.out.println(" |--> il traverse le carrefour en " + getTPS() + " sec.");
	}

	@Override
	void arreter() {
		System.out.println("Le vehicule (" + getNom() + ") freine et s'arrete");
	}
	
	@Override
	public void action(boolean feuRouge) {
		if(!feuRouge)
			this.avancer();
		else
			this.arreter();
	}
	
	
}
