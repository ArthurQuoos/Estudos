
package aula12interfaceex1;


public final class Conta {
    private int numero;
    private int numConta;

    public Conta(int numConta){
           setNumConta(numConta);
    }


    public void setNumConta(int numConta){
           this.numero = numConta;
    }
    public int getNumConta(){
           return this.numConta;
     }

}//fim classe

