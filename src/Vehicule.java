
public abstract class Vehicule {
	
	private int vitesse;

	
	public Vehicule() {
		this.vitesse = 0;	// un vehicule par default a l'arret
	}
	
	int getVitesse() {
		return this.vitesse;
	}
	void setVitesse(int v) {
		this.vitesse = v;
	}
	
	abstract void accelerer();
	abstract void freiner();
	
}
