import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    String nomeCliente = "Arthurzin";
    String tipo = "Corrente";
    double saldo = 10.00;
    int op = 0;
        Scanner teclado = new Scanner(System.in);
        System.out.println(String.format("Ola %s!  Eu sou seu atendente virtual do \"Seu Banco\"", nomeCliente));

        while(op != 4) {
            System.out.println("""
                Oque voce deseja fazer agora?
                1 - Consultar Saldos
                2 - Fazer Deposito
                3 - Sacar Valor
                4 - Sair
                """);
            op = teclado.nextInt();

            switch (op) {
                case 1:
                    System.out.println(String.format("Seu Saldo atual e de: R$%.2f", saldo));
                    // consultar saldo
                    break;
                case 2:
                    System.out.println("Qual o valor a ser depositado?");
                    double deposito = teclado.nextDouble();
                    if(deposito > 0){
                        saldo += deposito;
                        System.out.println(String.format("Seu Saldo atualizado e de: R$%.2f", saldo));
                    }else{
                        System.out.println("Valor invalido");
                    }
                    //Deposito
                    break;
                case 3:
                    System.out.println(("Por Favor informe o valor a ser retirado:"));
                    double saque = teclado.nextDouble();
                    if (saque < saldo && saque > 0) {
                        saldo = saldo - saque;
                        System.out.println(String.format("Seu Saldo atualizado e de: R$%.2f", saldo));
                    } else {
                        System.out.println(("Valor invalido"));
                    }
                    // Sacar valor
                    break;
                case 4:
                    System.out.println(("Tchau Tchau"));
                    break;
                default:
                    System.out.println("Valor invalido por favor, tente novamente");
                    break;
            }
        }
    }
}