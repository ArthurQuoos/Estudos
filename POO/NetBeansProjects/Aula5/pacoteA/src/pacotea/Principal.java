/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pacotea;

public class Principal {

    public static void main(String [] main){
           ClasseA objA = new ClasseA();

           System.out.println(objA.primeiro);  //public
           System.out.println(objA.segundo);  //package-private
           System.out.println(objA.quarto);     //protect: package-private + filhos

   }

}
