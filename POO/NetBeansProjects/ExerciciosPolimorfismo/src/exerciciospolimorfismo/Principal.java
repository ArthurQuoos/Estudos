
package exerciciospolimorfismo;

import java.util.ArrayList;
import java.util.Iterator;

public class Principal {

    
        public class Embarcados {

    public String getTensao(){
        return "0";
    }
    public String toString(){
        return getTensao();
    }

   }//
    public class ESP extends Embarcados{
    public String getTensao(){
        return "127";
    }
    }//
    public class RaspBerry extends Embarcados {
    public String getTensao(){
        return "220";
    }
    }//
    public class Arduino extends Embarcados{
    public String getTensao(){
        return "110";
    }
    }

    public Principal(){
              ArrayList <Embarcados> lista = new ArrayList<>();
       
       lista.add(new Arduino());
       lista.add(new RaspBerry());
       lista.add(new ESP());
       
       Iterator i = lista.iterator();
       
       while(i.hasNext()){
           System.out.println(i.next());
       }
    }
      public static void main(String[] args){
/*
          ArrayList<Embarcados> lista = new ArrayList<>();
                                               //Arduino obj = new Arduino();
lista.add(new Arduino());  //lista.add(obj);
lista.add(new RaspBerry());
lista.add(new ESP());

Iterator i = lista.iterator();
while( i.hasNext() )
      //System.out.println(i.next().getTensao());
      System.out.println(i.next());
*/    
    new Principal();
    Principal.Arduino arduino = new Principal().new Arduino();

      }

} // fim da classe

