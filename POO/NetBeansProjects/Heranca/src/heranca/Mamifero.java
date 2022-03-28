
package heranca;


public class Mamifero extends Animal {
          protected int qtdePelos;

          public Mamifero(String nome, int qtdePelos){
                   super( nome );
                   setPelos( qtdePelos );
          }

         public void setPelos(int qtdePelos){
                 this.qtdePelos = qtdePelos;
         }
}//fim classe

