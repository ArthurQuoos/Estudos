

package javaapplication1;


public class Flor {
    
        //Variaveis de instancia (Atributos)
    private String cor;
    private float tamanho;
    private int petalas;
    
    //Construtor padrao
    public Flor(){
        
        setCor("Azul");
        setTamanho(0);
        setPetalas(0);
        
        /*
        this.cor = "Azul";
        this.tamanho = 0;
        this.petalas = 0;
        */
    }
    
    //Construtor personalizado
    public Flor(String cor, float tamanho, int petalas){   	 
        setCor(cor);
        setTamanho(tamanho);
        setPetalas(petalas);
    }

    
    //Metodos acessores
     public String getCor(){
            return this.cor; //this e ponteiro para o proprio objeto
     }
     //Metodos mutadores
	public void setCor(String cor){
    	this.cor = cor;
	}
	public float getTamanho(){
    	return this.tamanho;
	}
	public void setTamanho(float tamanho) {
    	this.tamanho = tamanho;
	}
	public int getPetalas(){
    	return this.petalas;
	}
	public void setPetalas(int petalas) {
    	this.petalas = petalas;
	}
    

     
     
}
