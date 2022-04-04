
package aula9b;


public class Principal {

    public static void main(String [ ] args ){

            PassagemAerea comprador = 
                  new PassagemAerea("Empresa Azul", "Nome do Comprador","Id123", "Destino", 100.0f);   	
             System.out.println(comprador.setTaxas("Cafe incluso", 300.0f));
            System.out.println(comprador.getPrecoPassagem());
           

   }//fim main
}