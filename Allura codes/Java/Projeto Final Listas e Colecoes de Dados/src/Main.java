import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner teclado = new Scanner(System.in);
        double iniciaLimite;
        String iniciaNome;
        double iniciaValor;

        System.out.println("""
        Olá seja bem vindo a sua IA de compras favorita, Compra Facil!
        por favor cadastre seu cartao de credito: """);
        iniciaLimite = teclado.nextDouble();
        Conta cartaoDeCredito = new Conta(iniciaLimite);
        System.out.println("Agora estamos prontos para comecar!");

        int z = 1;
        while(z == 1){
            System.out.println("XXXXXXXXXXXXXXXXXXXXXXXX");
            System.out.println("Limite do cartao: " + cartaoDeCredito.getLimite());
            System.out.println("Fatura do cartao: " + cartaoDeCredito.getFatura());
            System.out.println("XXXXXXXXXXXXXXXXXXXXXXXX");
            System.out.println("""
                    tecle 1 para comprar ou tecle qualquer outro botao para sair""");
            z = teclado.nextInt();
            
            if(z == 1 ) {
                System.out.println("Oque deseja comprar?");
                iniciaNome = teclado.next();
                System.out.println("Quanto deseja pagar nesse produto?");
                iniciaValor = teclado.nextDouble();
                if((cartaoDeCredito.getLimite() >= iniciaValor) && ((iniciaValor + cartaoDeCredito.getFatura()) <= cartaoDeCredito.getLimite())){
                    Produtos compra = new Produtos(iniciaNome, iniciaValor);
                    cartaoDeCredito.lancaCompra(compra);
                    cartaoDeCredito.setFatura(iniciaValor);
                    System.out.println("Compra realizada!");
                }else{
                    System.out.println("o valor do produto e maior do que o limite do seu cartao de credito");
                }
            }else{
                System.out.println("----------Compras Realizadas----------");
                Collections.sort(cartaoDeCredito.getCompras());

                for (Produtos c : cartaoDeCredito.getCompras()) {
                    System.out.println(c.getNome() + " - " + c.getValor());
                }

                System.out.println("Bye bye");
            }
        }
    }
}