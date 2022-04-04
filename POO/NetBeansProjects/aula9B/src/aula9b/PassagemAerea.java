
package aula9b;


public class PassagemAerea extends Taxas {

    private String nomeCompanhia;
    private float preco;




    public PassagemAerea(String nomeCompanhia, String nomeComprador, 
                                              String ID, String destino, float preco ){

          super();
         
         //Composicao
         Comprador comprador = new Comprador( nomeComprador, ID );

         setNomeCompanhia(nomeCompanhia);
         setPreco( preco );

   }

   public float getPrecoPassagem(){
           return this.preco + getTaxas();
   }

}
