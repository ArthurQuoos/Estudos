
package interface2;

import java.util.ArrayList;
import java.util.Iterator;

public class Principal {

    public static void main(String [ ] args){

              //Empregado [ ] lista = new Empregado[5];  //Vetor fixo com 5 posicoes.
              //ArrayList <Empregado>  lista = new ArrayList<Empregado>();
             ArrayList <Empregado>  lista = new ArrayList<>();

             Data dataChefe = new Data(1,1,2001);
             Chefe joao = new Chefe(dataChefe);

             Data dataBalconista = new Data(2,2,2002);
             Balconista maria = new Balconista(dataBalconista);
             
             lista.add( joao );
             lista.add( maria );

             Iterator i = lista.iterator();  //Adquire um iterator sobre os objetos
             while ( i.hasNext() ) //Tem mais objetos?
                    System.out.println( i.next() );  //Acessa o objeto atual e acessa o proximo objeto
    }
}

