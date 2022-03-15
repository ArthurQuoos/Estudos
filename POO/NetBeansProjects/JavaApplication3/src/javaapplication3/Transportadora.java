
package javaapplication3;

import java.util.ArrayList;


public class Transportadora {
             //Veiculo [ ] veiculos = new Veiculo[5];
         ArrayList  listaVeiculos;

         public Transportadora(){
                   listaVeiculos = new ArrayList();
         }

         public void cadastrar( Veiculo veiculo ) {
                  this.listaVeiculos.add( veiculo );                
         }



}
