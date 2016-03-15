/**
 * 
 */
//package com.ldnr.feu;

/**
 * @author Benoit
 *
 */
public class Feu extends Attente {

	// Données membres
	int dureeAvance;
	int dureeArret; 
	String couleur;
	
	//Constructeur
	public Feu() {
		super();
		dureeAvance = 30;
		dureeArret = dureeAvance +10;
		couleur = "rouge";
	}
	
	//Methodes
	public void MajCouleur() {
		if (super.arret == true) {
			this.couleur = "rouge";
		}
		else {
			this.couleur = "vert";
		}
	}
	
	public void Afficher() {
		System.out.println("Le feu est " + this.couleur);
	}
	
	public void Change() {
		super.Interupteur();
		this.MajCouleur();
		this.Afficher();
	}
	
	public int Decompte() {
		int duree;
		//on initialise la durée du décompte
		if (super.arret == true) 
		{ duree= this.dureeArret; }
		else 
		{ duree= this.dureeAvance; }
		//décompte
		for (int i = 0; i < duree; i++) 
		{ System.out.println(i+1); }
		this.Change();
		return duree;
	}
}
