/**
 * 
 */
//package com.ldnr.vehicule;

/**
 * @author Vincent
 *
 */
public final class Voiture extends Vehicule {
	// Constructeur
	public Voiture() {
		super(); 
		setNom("voiture");
		setTPS(15);
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

}
