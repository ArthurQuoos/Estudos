
package aula9;


public class Faculdade extends Empregado {
     private String nomeFaculdade;
     public Faculdade(){
    }
    public Faculdade(String nome){
            super(nome);
    }
    public Faculdade(String nome, float salario){
            super(nome, salario);
   }
    protected String getNomeFaculdade(){
                return this.nomeFaculdade;
      }
   }
