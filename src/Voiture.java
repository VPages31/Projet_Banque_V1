
public final class Voiture extends Vehicule {
	
	public Voiture() {
		this.setVitesse(0); 
		this.setNom("voiture");
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
