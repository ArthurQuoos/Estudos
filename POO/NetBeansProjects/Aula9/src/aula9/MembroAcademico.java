
package aula9;

public class MembroAcademico {
    private String nome;
    public MembroAcademico(){
            setNome(" ");
    }
    public MembroAcademico(String nome){
           setNome(nome);
    }
    public void setNome(String nome){
           this.nome = nome;
   }
   public String getNome(){
              return this.nome;
   }
    public String toString(){
             return this.getClass().getCanonicalName();
    }
} 


