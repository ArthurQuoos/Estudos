
package interface3;

public class Bicicleta implements IEmissaoCarbono {
     private String cor;
     private float emissaoCarbono;

     public Bicicleta( float emissaoCarbono ){
          setEmissaoCarbono( emissaoCarbono );
    }

      public float getEmissaoCarbono(){
           return this.emissaoCarbono;
     }
     
           public void setEmissaoCarbono(float emissaoCarbono){
           this.emissaoCarbono = emissaoCarbono;
     }

     public String toString(){
           return "\nBICICLETA: " + getEmissaoCarbono();
     }
}

