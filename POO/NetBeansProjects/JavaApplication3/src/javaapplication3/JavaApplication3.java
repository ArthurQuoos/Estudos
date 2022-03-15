
package javaapplication3;


public class JavaApplication3 {    
    



     public static void main( String [ ] args ) {
            Transportadora  obj = new Transportadora();
            Veiculo caminhao = new Veiculo("caminhão", 0);
            Veiculo van = new Veiculo("van", 0);
            caminhao.inserir( 10.5f );
            van.inserir ( 20.3f );
            obj.cadastrar( caminhao );
            obj.cadastrar( van );
            System.out.println( caminhao );
            System.out.println( van );
     }
}






