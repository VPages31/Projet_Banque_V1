/**
 * 
 */
//package com.ldnr.vehicule;

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
		// Indique l'etat de marche du véhicule
		System.out.println("Le véhicule (" + getNom() + ") demarre");
		System.out.println(" |--> il traverse le carrefour en " + getTPS() + " sec.");
	}

	@Override
	void arreter() {
		// Indique l'etat d'arret du véhicule
		System.out.println("Le vehicule (" + getNom() + ") freine et s'arrete");
	}
	@Override
	void action(boolean feuRouge) {
		if(!feuRouge)
			this.avancer();
		else
			this.arreter();	
	}

	
}



