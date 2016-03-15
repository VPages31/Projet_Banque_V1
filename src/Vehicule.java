/**
 * 
 */
//package com.ldnr.vehicule;

/**
 * @author Vincent
 *
 */
public abstract class Vehicule {
	
	private String nom;
	private int tempsPassageSec;

	// Constructeurs \\
	public Vehicule() {	
	}
	 // Methodes \\
	//   membres  
	String getNom() {
		return this.nom;
	}
	void setNom(String n) {
		this.nom = n;
	}
	int getTPS() {
		return this.tempsPassageSec;
	}
	void setTPS(int tps) {
		this.tempsPassageSec = tps;
	}
	// abstraites 
	abstract void avancer();
	abstract void arreter();
	
}
