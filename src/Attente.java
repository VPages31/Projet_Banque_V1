/**
 * 
 */
//package com.ldnr.feu;

/**
 * @author Benoit
 *
 */
public class Attente {
	
	//données membres
	public boolean arret;
	//protected static int dureeArret = 0;
	
	//Constructeur
	public Attente() {
		this.arret = true;
	}
	
	//Méthodes
	public void Interupteur() {
		if (this.arret == true) 
		{ this.arret = false; }
		else
		{ this.arret = true; }
	}
}
