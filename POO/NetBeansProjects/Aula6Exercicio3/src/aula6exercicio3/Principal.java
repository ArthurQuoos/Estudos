// Crie uma Classe que gere um número inteiro aleatório. 
// A seguir, receba um número do usuário e informe se o número recebido é maior, 
// menor ou igual ao número recebido. 



package aula6exercicio3;


public class Principal {
    private int numero;
    
    public  Principal(){
        setNumero();
    }
    
    
    public static void main(String[] args) {

       Principal objeto = new Principal();
       Scanner entrada = new Scanner (System.in );
       int ne = entrada.nextInt();
       
       objeto.verificarNumero(ne);
       
       
    }
    
    public void setNumero(){
        //Math.random();
        //System.out.println(Math.random());
        int n = 1 + (int) (Math.random()*10);//num aleatorio de 1 a 10
        System.out.println(n);
        this.numero = n;
    }
    
    public static int verificaNumero(int n){
        if (numero >= this.numero)
            System.out.println(numero + "eh maior ou igual.");
        else 
        System.out.println(numero + " eh menor");    
        
      }
    
}
