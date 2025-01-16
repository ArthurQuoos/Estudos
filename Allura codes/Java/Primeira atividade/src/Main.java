//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        System.out.println("Aqui comeca o meu imperio de streaming");
        System.out.println("Filme: Top Gun: Maverick");

        int ano = 2022;
        System.out.println("Ano de Lancamento: " + ano);
        boolean incluidoNoPlano = true;
        double notaDoFilme = 8.1;
        float precoDaAssinatura = 15;

        double media = (9.8 + 6.3 + 8.0) / 3;
        //String sinopse = "Filme de aventura com gala dos anos 80";
        String sinopse = """
                Filme Top Gun Maverick 
                Filme de aventura com gala dos anos 80
                Muito bom!
                """;
        System.out.println(sinopse);
        System.out.println(String.format("media da classificacao do filme: %.2f", media));

        int classificacao;
        classificacao = (int) (media / 2); //conversao para int
        System.out.println("estrelas: " + classificacao);
    }
}