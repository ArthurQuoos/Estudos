
package heranca;


public class Ra extends Anfibio {
        public Ra(String nome, String cor,int qtdeEscamas){
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
