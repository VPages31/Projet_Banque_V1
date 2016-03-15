/**
 * 
 */
//package com.ldnr.feu;

/**
 * @author Benoit
 *
 */
public class testAttente {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int temps=100;
		Feu feu1 = new Feu();
		do {
		temps=temps-feu1.Decompte();
		}
		while (temps > 0);
		System.out.println("temps restant: " +temps);
	}

}
