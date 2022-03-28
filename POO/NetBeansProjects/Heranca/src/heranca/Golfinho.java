
package heranca;


public class Golfinho extends Mamifero {
    
    public Golfinho (String nome, int qtdePelos){
            super( nome, qtdePelos);
        }
      public String toString(){
          return getNome() + " " + this.qtdePelos;
      }

}
