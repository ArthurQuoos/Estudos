// Crie uma Classe que leia 3 (três) números e retorne o menor número. 
// Dica: utilize o método static Math.min

// Nome: Numero
// Atributo: numeros
// Verbo: retornarMenor

package aula6exercicio2;


public class Principal {


    public static void main(String[] args) {
        
       Numero numero;
       numero = new Numero(3, 1, 2);
       
       System.out.println(numero.retornaMenor());
        
    }
    
}
