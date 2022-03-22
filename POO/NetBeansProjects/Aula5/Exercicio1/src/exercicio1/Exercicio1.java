
package exercicio1;


public class Exercicio1 {
     //Fora dos métodos (como variaveis globais)
     private String cor;    //variavel de instancia

     public Exercicio1(){        //Construtor
           
          //super();  //Explicitamente informando que esta classe herda
                             // da classe java.lang.Object

           setCor("azul");

     }//fim construtor

    public Exercicio1(String cor){ //Construtor (sobrecarga)
         setCor(cor);
    }

     public void setCor( String cor ) {
           this.cor = cor;
     }

     public String toString(){  //sobrecarga
            return this.cor;
     }

}//fim classe Exercicio1

