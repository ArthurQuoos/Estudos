import java.util.Scanner;

public class Convercao {
    public static void main (String[] args){
        Scanner teclado = new Scanner(System.in);

        System.out.println("Conversor de Celsius para Farenheit!");
        System.out.println("Insira uma temperatura em celsius para converter!: ");
        double temperatura = teclado.nextFloat();

        temperatura = (temperatura * 1.8) + 32;
        System.out.println(String.format("Esta temperatura em Farenheit e: %.2f", temperatura));
        System.out.println(String.format("A temperatura em int: %d",(int) temperatura));


    }

}

/*
//Outras atividades:
//Crie um programa que realize a média de duas notas decimais e exiba o resultado.

public class Media{
    public static void main(String[] args) {
        double nota1 = 8.9;
        double nota2 = 7.5;
        double media = (nota1 + nota2) / 2;

        System.out.println("Média: " + media);
    }
}
//Declare uma variável do tipo double e uma variável do tipo int. Faça o casting da variável double para int e imprima o resultado.

public class Casting{
    public static void main(String[] args) {
        double numeroDouble = 15.7;
        int numeroInteiro = (int) numeroDouble;
        System.out.println("Casting de double para int: " + numeroInteiro);
    }
}
//Declare uma variável do tipo char (letra) e uma variável do tipo String (palavra). Atribua valores a essas variáveis e concatene-as em uma mensagem.

public class Palavras{
    public static void main(String[] args) {
        char letra = 'A';
        String palavra = "MARELO";

        String mensagem = "A letra é " + letra + " e a palavra é " + palavra;

        System.out.println(mensagem);
    }
}
//Declare uma variável do tipo double precoProduto e uma variável do tipo int (quantidade).
//Calcule o valor total multiplicando o preço do produto pela quantidade e apresente o resultado em uma mensagem.

public class Produto{
    public static void main(String[] args) {
        double precoProduto = 29.99;
        int quantidade = 3;

        double total = precoProduto * quantidade;

        String mensagem = "O valor total da compra é R$" + total;

        System.out.println(mensagem);
    }
}
//Declare uma variável do tipo double valorEmDolares. Atribua um valor em dólares a essa variável.
//Considere que o valor de 1 dólar é equivalente a 4.94 reais. Realize a conversão do valor em dólares para reais e imprima o resultado formatado.

public class ConversaoDolaresReais {
    public static void main(String[] args) {
        double valorEmDolares = 100.50;
        double taxaDeConversao = 4.94;

        double valorEmReais = valorEmDolares * taxaDeConversao;

        System.out.println("O valor em reais é: " + valorEmReais);
    }
}
//Declare uma variável do tipo double precoOriginal. Atribua um valor em reais a essa variável,
//representando o preço original de um produto. Em seguida, declare uma variável do tipo double percentualDesconto
//e atribua um valor percentual de desconto ao produto (por exemplo, 10 para 10%). Calcule o valor do desconto em reais,
//aplique-o ao preço original e imprima o novo preço com desconto.

public class CalculoDesconto {
    public static void main(String[] args) {
        double precoOriginal = 150.0;

        double percentualDesconto = 10.0;
        double valorDesconto = (percentualDesconto / 100.0) * precoOriginal;
        double novoPreco = precoOriginal - valorDesconto;

        System.out.println("Preço original: R$" + precoOriginal);
        System.out.println("Desconto: R$" + valorDesconto);
        System.out.println("Novo preço com desconto: R$" + novoPreco);
    }
}
 */