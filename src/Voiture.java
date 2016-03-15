
public final class Voiture extends Vehicule {

	private int nbPortes; 
	
	public Voiture(int vitesse) {
		super(vitesse);
		this.nbPortes = 4;
	}

	@Override
	void accelerer() {
		 // Indique l'etat de marche du véhicule
		System.out.println("La voiture accelere progressivement");
		
	}

	@Override
	void freiner() {
		// Indique l'etat d'arret du véhicule
		System.out.println("La voiture s'arrete tranquillement");
	}

}
