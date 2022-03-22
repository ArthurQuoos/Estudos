
package pacotea;

public class ClasseA {
    
	public int primeiro;
	int segundo; //package-private
	private int terceiro;
	protected int quarto;
 	//package-private+
 	// filhos
    
	private int getTerceiro(){
    	return this.terceiro;
	}
    public int getQuarto(){
    	return this.quarto;
	}
}

