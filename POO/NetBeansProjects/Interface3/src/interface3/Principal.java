
package interface3;

import java.util.ArrayList;
import java.util.Iterator;

public class Principal {

       public Principal(){
                 ArrayList<IEmissaoCarbono> lista = new ArrayList<>();

                 Construcao predio = new Construcao( 100.0f );
                 //lista.add( new Construcao( 100.0f )  );
                 lista.add( predio );

                 lista.add( new Carro( 200.0f ) );
                 lista.add( new Bicicleta( 1.0f) );

                 Iterator i = lista.iterator();
                 while ( i.hasNext() )
                        System.out.println( i.next() );

       }


        public static void main( String [ ] args ){
                 
               new Principal();  //instanciação

       }//fim main


}//fim classe

