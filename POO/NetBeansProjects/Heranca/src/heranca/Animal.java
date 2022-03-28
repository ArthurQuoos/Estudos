
package heranca;


public class Animal {
          private String nome;

         public Animal(){
                setNome("animal");
         }
         public Animal(String nome){
                setNome(nome);
        }
        public void setNome(String nome){
               this.nome = nome;
        }
        public String getNome(){
                return this.nome;
        }
        

}
