
package exerciciopolimorfismo2;

import java.util.ArrayList;
import java.util.Iterator;

public class Principal {

    public interface IFonte{
        public abstract String getTensao();
    }
    
//------------------------------------------------   
public class ESP implements IFonte {

        public String getTensao(){
                return "1";
        }
}
//------------------------------------------------
public class RaspBerry implements IFonte {

        public String getTensao(){
                return "2";
        }
}
//------------------------------------------------
public class Arduino implements IFonte {

        public String getTensao(){
                return "3";
        }
}

        
    
    public static void main(String[] args) {
              ArrayList<IFonte> lista = new ArrayList<IFonte>();

             lista.add(new ESP()); //ERRO
             lista.add(new RaspBerry());
             lista.add(new Arduino());
             
             Iterator i = lista.iterator();

             while(i.hasNext()){
                    System.out.println(i.next());
              }

    }
    
}
