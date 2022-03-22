
package aula6exercicio2;

public class Numero {
    private int n1;
    private int n2;
    private int n3;
    
    public Numero(int n1, int n2, int n3){
        
        setNumero(n1,n2,n3);
        
    }
    
    public void setNumero(int n1, int n2, int n3){
        this.n1 = n1;
        this.n2 = n2;
        this.n3 = n3;
    }
    
    public int retornaMenor(){
        
        //return Math.min(n1, Mathmin(n2,n3));
        int menor1 = Math.min(n1, n2);
        int menor2 = Math.min(menor1, n3);
        
        return menor2;
        
    }
}
