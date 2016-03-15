/**
 * 
 */
//package com.ldnr.vehicule;

/**
 * @author Vincent
 *
 */
public class testVehicule {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
	
	boolean feuRouge;	
	Moto M = new Moto();
	Voiture V = new Voiture();
	
	System.out.println("  !!! Le feu passe au rouge !!!\n");
	feuRouge = true;
	V.action(feuRouge);
	M.action(feuRouge);
	
	System.out.println("\n  !!! Le feu passe au vert !!!\n");	
	feuRouge = false;
	V.action(feuRouge);
	M.action(feuRouge);

	}
}