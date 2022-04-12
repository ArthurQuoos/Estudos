
package aula12interfaceex1;


public final class CaixaEletronico extends SistemaPagamento 
                                                           implements IPagamento {
         private int numTerminal;

         public CaixaEletronico( int numConta, int numTerminal ){
                    super( numConta );
                    setNumTerminal ( numTerminal );
         }

         public void setNumTerminal(int numTerminal){
              this.numTerminal = numTerminal;
         }
         public int getNumTerminal(){
              return this.numTerminal;
         }

         public String getTipo(){  //Metodo abstrato que foi implementado.
                return "CAIXA ELETRÔNICO";
         }

         public void pagar(float valor){
              System.out.println(valor+(valor*0.02f ) );
         }
}//fim classe

