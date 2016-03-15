
public final class Moto extends Vehicule {
	
	public Moto() {
		this.setVitesse(0); 
		this.setNom("moto");
	}

	@Override
	void accelerer() {
		// Indique l'etat de marche du véhicule
		System.out.println("La moto accelere energiquement...");
	}

	@Override
	void freiner() {
		// Indique l'etat d'arret du véhicule
		System.out.println("La moto ralenti vivement...");
	}

}



