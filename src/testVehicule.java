/**
 * 
 */
//package com.ldnr.feu;

/**
 * @author Vincent
 *
 */
public class testVehicules {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
	Moto M = new Moto();
	Voiture V = new Voiture();
	
	System.out.println("\n  !!! Le feu passe au rouge !!!\n");
	V.arreter();
	M.arreter();
	System.out.println("\n  !!! Le feu passe au vert !!!\n");	
	V.avancer();
	M.avancer();
	}

}