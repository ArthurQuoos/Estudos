import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String cep;
        Scanner teclado = new Scanner(System.in);
        ConsultaCep consultaCep = new ConsultaCep();

        System.out.println("Bem vindo! Insira um cep valido para pesquisar: ");
        cep = teclado.nextLine();

        try{
            Endereco novoEndereco = consultaCep.buscaEndereco(cep);
            System.out.println(novoEndereco);
            Registrador registrador = new Registrador();
            registrador.salvaJson(novoEndereco);
        }catch (IOException |RuntimeException e){
            System.out.println(e.getMessage());
            System.out.println("Finalizando a aplicacao");
        }
    }
}
