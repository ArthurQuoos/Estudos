
package exercicio1;

public class Principal {

        public static void main(String [] args){
                Exercicio1 objeto1 = new Exercicio1();
                Exercicio1 objeto2 = new Exercicio1("vermelho");

                //Imprimir
                System.out.println( objeto1 ); //implicita (não informou o método toString )
                System.out.println(objeto2.toString() ); //explicita (informou o método toString) 
               //exercicio.Exercicio1@eed1f14
        }        

}//fim classe Principal

