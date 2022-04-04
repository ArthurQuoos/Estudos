
package aula9;

public class Terceirizado extends Empregado {
      private String nomeEmpresa;
     public Terceirizado(){
    }
    protected String getNomeEmpresa(){
            return this.nomeEmpresa;
    }
    public String toString(){
          return super.toString() + " " + this.getNomeEmpresa();
    }
   }
