/**
 * 
 */
//package com.ldnr.mains;

/**
 * @author Vincent
 *
 */
public class MainFeuxTricolores {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Feu feu1 = new Feu();
		Moto m = new Moto();
		Voiture v = new Voiture();
		int temps=100;
		
		do {
			temps=temps-feu1.Decompte();
			m.action(feu1.arret);
			v.action(feu1.arret);
		} while (temps > 0);
		
		System.out.println("temps restant: " +temps);
		
	}
}


 