
package aula9;

public class Empregado extends MembroAcademico {

    private float salario;
     public Empregado(){
            setSalario(0);
    }
    public Empregado(String nome){
            super(nome);
             setSalario(0);
    }
    public Empregado(String nome, float salario){
           super(nome);
           setSalario( salario );
   }
    //Metodo acessor
    public float getSalario(){
          return this.salario;
    }
    //Metodo mutador
    public void setSalario(float salario){
          this.salario = salario;
   }
}

