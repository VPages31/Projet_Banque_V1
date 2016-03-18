/**
 * 
 */


/**
 * @author Vincent
 *
 */
public final class Moto extends Vehicule {
	// Constructeur
	public Moto() {
		super();
		setNom("moto");
		setTPS(5);
	}
	// Methodes
	@Override
	void avancer() {
		// Indique l'etat de marche du vehicule
		System.out.println("\nLa " + nom + " demarre\n");
		System.out.println(" |-->elle traverse le carrefour en " + getTPS() + " sec.\n");
	}

	@Override
	void arreter() {
		// Indique l'etat d'arret du vehicule
		System.out.println("\nLa " + nom + " freine et s'arrete\n");
	}
	@Override
	public void action(boolean feuRouge) {
		if(!feuRouge)
			this.avancer();
		else
			this.arreter();	
	}

	
}



