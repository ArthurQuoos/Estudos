
package interface2;

public final class Balconista extends Empregado
                                implements IEmpregado{

     public Balconista(Data dataNascimento){
             super ( dataNascimento );
     }

     public String toString(){
            return this.nome;
     }


}

