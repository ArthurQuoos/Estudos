
package interface3;


public class Construcao implements IEmissaoCarbono {
    private float altura;
    private float emissaoCarbono;

    public Construcao(float emissaoCarbono){
        setEmissaoCarbono(emissaoCarbono );
    }
    
    public float getEmissaoCarbono(){
        return this.emissaoCarbono;
    }
    
     public void setEmissaoCarbono(float emissaoCarbono){
           this.emissaoCarbono = emissaoCarbono;
     }
    
    public String toString(){
        return "\nCONSTRUCAO:"+ getEmissaoCarbono();
    }
}
