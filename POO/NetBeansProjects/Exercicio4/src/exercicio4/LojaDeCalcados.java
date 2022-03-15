
package exercicio4;

import java.util.ArrayList;

public class LojaDeCalcados {
    ArrayList estoque;
    
    public LojaDeCalcados(){
            estoque = new ArrayList();
    }
    public void cadastrar (Calcados calcado){
        this.estoque.add( calcado );
    }
    
    public void vendido (Calcados calcado){
      this.estoque.remove( calcado );
  }
}
