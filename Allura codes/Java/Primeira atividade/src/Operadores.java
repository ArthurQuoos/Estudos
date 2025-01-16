/*
public class Operadores {
    public static void main(String[] args) {

        int z = 10 + 5; // Atribui o valor 15 à variável a
        int x = 10 - 5; // Atribui o valor 5 à variável b
        int v = 10 * 5; // Atribui o valor 50 à variável c
        int d = 10 / 5; // Atribui o valor 2 à variável d
        int e = 10 % 3; // Atribui o valor 1 à variável e (o resto da divisão de 10 por 3 é 1)

        int a = 10; // Atribui o valor 10 à variável a
        int b = 5; // Atribui o valor 5 à variável b
        int c = 30; // Atribui o valor 30 à variável c

        boolean igual = (b == a); //Nesse caso a variável igual ficará com o valor *false*, pois o valor de b não é igual o valor de a.
        boolean diferente = (b != c); //A variável diferente ficará com o valor *true*, pois o valor de b é diferente do valor de c.
        boolean maior = (b > a); //A variável maior ficará com o valor *false*, pois o valor de b é menor que o valor de a.
        boolean menorIgual = (b <= c); //A variável menorIgual ficará com o valor *true*, pois o valor de b é menor que o valor de c.

        boolean a = true;
        boolean b = false;
        if (a && b) {
            // Este código não será executado, já que a é verdadeiro e b é falso.
        }

        boolean a = true;
        boolean b = false;
        if (a || b) {
            // Este código será executado, já que a é verdadeiro, mesmo que b seja falso.
        }

        boolean a = true;
        if (!a) {
            // Este código não será executado, já que a é verdadeiro.
        }

        int num = 5;
        int resultado = ++num; //num é incrementado para 6 e depois atribuído a resultado
        System.out.println(num); // imprime 6
        System.out.println(resultado); // imprime 6

        int num = 5;
        int resultado = num++; //num é atribuído primeiramente à variável resultado e depois incrementado para 6
        System.out.println(num); // imprime 6
        System.out.println(resultado); // imprime 5

// ===================================================================================

        String saudacao = "Olá, ";
        String nome = "Alura";
        String mensagem = saudacao + nome + "!"; // concatenacao de strings

        String senha = "12345";
        if (senha.equals("12345")) {
        System.out.println("Acesso autorizado!");
        } else {
        System.out.println("Senha incorreta."); // comparacao de strings || equalsIgnoreCase()
        }

        String nome = "Maria";
        int idade = 30;
        double valor = 55.9999;
        System.out.println(String.format("Meu nome é %s, eu tenho %d anos e hoje gastei %.2f reais", nome, idade, valor));

    }
}

/*
Aqui estão algumas das principais convenções de código do Java:

Nomes de classes devem começar com letra maiúscula e usar a convenção PascalCase (também conhecida como Upper CamelCase).

Exemplo: MinhaClasse.
Nomes de métodos devem começar com letra minúscula e usar a convenção camelCase.

Exemplo: meuMetodo().
Nomes de constantes devem ser totalmente em letras maiúsculas, separadas por underline.

Exemplo: MINHA_CONSTANTE.
Nomes de variáveis devem começar com letra minúscula e usar a convenção camelCase.

Exemplo: minhaVariavel.
Todas as linhas de código devem ter no máximo 80 caracteres de largura para facilitar a leitura.

Recomenda-se usar espaços em branco para separar operadores, palavras-chave e elementos de controle de fluxo.

Exemplo: if (condicao) {.
Use comentários para documentar seu código, explicando o que ele faz e por que ele faz isso. Comentários devem ser claros e concisos.

 */
