/**
 * 
 */


/**
 * @author Vincent
 *
 */
public abstract class Vehicule {
	
	protected String nom;
	protected int tempsPassageSec;
	
	// Constructeurs \\
	public Vehicule() {	
	}
	 // Methodes \\
	//   membres  
	public String getNom() {
		return this.nom;
	}
	public void setNom(String n) {
		this.nom = n;
	}
	public int getTPS() {
		return this.tempsPassageSec;
	}
	public void setTPS(int tps) {
		this.tempsPassageSec = tps;
	}
	
	// abstraites
	abstract void avancer();
	abstract void arreter();
	public abstract void action(boolean feuRouge);	
}
