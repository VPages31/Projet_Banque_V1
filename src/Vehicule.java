
public abstract class Vehicule {
	
	private int vitesse;
	private String nom;

	
	public Vehicule() {
		this.vitesse = 0;	// un vehicule par default a l'arret
	}
	
	int getVitesse() {
		return this.vitesse;
	}
	String getNom() {
		return this.nom;
	}
	void setVitesse(int v) {
		this.vitesse = v;
	}
	void setNom(String n) {
		this.nom = n;
	}
	
	abstract void accelerer();
	abstract void freiner();
	
}
