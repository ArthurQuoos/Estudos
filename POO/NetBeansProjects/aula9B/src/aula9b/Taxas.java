
package aula9b;


public class Taxas {
    private float taxa;
    private String tipo;
    
    public Taxas () {
           setTaxas(0);
   }
   public void setTaxas(float taxa){
           this.taxa = taxa;
   }

   public void setTaxas(String tipo, float taxa){
           this.tipo = tipo;
           this.taxa = taxa;
   }


    public float getTaxas(){
             return this.taxa;
   }


}

