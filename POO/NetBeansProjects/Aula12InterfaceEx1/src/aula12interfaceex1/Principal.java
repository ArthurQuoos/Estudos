
package aula12interfaceex1;

import java.util.Scanner;


public class Principal {
       
         public static void main(String [ ] args){

         String menu =
                   "\n1) CAIXA ELETRONICO"+
                   "\n2) PIX"+
                   "\nEscolha a opcao ( X-sair ): ";

         Scanner entradaMenu, entradaCaixa, EntradaPIX;
         String entrada;
         CaixaEletronico caixa;
         int numConta, numTerminal;
         String chavePIX;         
         float valor;
         PIX pix;
          do {
              System.out.println( menu );
              entradaMenu = new Scanner( System.in );
              entrada = entradaMenu.next();
              switch ( entrada ) {
                    case "1": 

                      entradaCaixa = new Scanner(System.in);

                      System.out.println("Informe numero da conta: ");
                      numConta = Integer.parseInt(entradaCaixa.next());

                      System.out.println("Informe numero do terminal: ");
                      numTerminal = Integer.parseInt(entradaCaixa.next());

                      caixa = new CaixaEletronico(numConta, numTerminal );
                      
                      System.out.println("Valor a pagar:");
                      valor = Float.parseFloat( entradaCaixa.next() );

                      caixa.pagar( valor );
                    break;

                    case "2":
                      entradaCaixa = new Scanner(System.in);

                      System.out.println("Informe numero da conta: ");
                      numConta = Integer.parseInt(entradaCaixa.next());

                      System.out.println("Informe numero da chave PIX: ");
                      chavePIX = entradaCaixa.next();

                     pix = new PIX( chavePIX, numConta );
                      
                      System.out.println("Valor a pagar:");
                      valor = Float.parseFloat( entradaCaixa.next() );

                      pix.pagar( valor );
                    break;
                    default:
                               System.out.println("\nOpcao invalida");
                    break;

              }//fim switch

         } while ( ! entrada.equals("X") );


       /*   int numConta=123;
          int numTerminal=456;
          CaixaEletronico caixa = new CaixaEletronico(numConta, numTerminal );
          caixa.pagar( 123.45f );

          String chavePIX = “789”;
          numConta = 555;
          PIX pix = new PIX( chavePIX, numConta );
          pix.pagar( 333.44f );
*/

         }//fim main

}//fim classe

