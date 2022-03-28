
package heranca;


public class Sapo extends Anfibio {
    private String cor;
    
    public Sapo(){
        super(); //chamada explicita do construtor da superclasse
        setCor("amarelo");
    }
    
    
        public Sapo(String nome, String cor,int qtdeEscamas){
             super(nome, qtdeEscamas);
             setCor(cor);
        }
        public void setCor(String cor){
              this.cor = cor;
        }

        public String toString(){
            return getNome() + " " + this.cor + " " + getQtdeEscamas();
        }
}


