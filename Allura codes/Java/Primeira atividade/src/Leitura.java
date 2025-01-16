import java.util.Scanner;

public class Leitura {
    public static void main(String[] args) {
        Scanner leitura = new Scanner(System.in);

        System.out.println("Digite seu filme favortio");
        String filme = leitura.nextLine();

        System.out.println("Qual o ano de lancamento?");
        int ano = leitura.nextInt();
        System.out.println("Diga sua avaliacao para o filme de 0 a 10: ");
        double nota = leitura.nextDouble();

        System.out.println(filme);
        System.out.println(ano);
        System.out.println(nota);

    }
}
