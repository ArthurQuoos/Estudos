
package javaapplication1;

//import java.util.Scanner;
//import javax.swing.JOptionPane;

       
//import java.util.Scanner;


public class JavaApplication1 {

	     //Metodo de classe
	public static void main(String[] args) {
   	 
        /*  //Simples soma
    	Scanner entrada = new Scanner(System.in);
    	System.out.print("V1: ");
    	int v1 = entrada.nextInt();
   	 
    	System.out.print("V2: ");
    	int v2 = entrada.nextInt();
   	 
    	int total = v1 + v2;
    	System.out.println("Total eh: " + total);
        */
        
   	/*  //Soma e compara < ou >
    	Scanner entrada = new Scanner(System.in);
    	System.out.print("V1: ");
    	int v1 = entrada.nextInt();
   	 
    	System.out.print("V2: ");
    	int v2 = entrada.nextInt();
   	 
    	String result = new String();
    	if ( v1 > v2 )
        	result = "V1 eh maior que V2";
    	else
        	if ( v1 <= v2 )
            	result = "V1 eh menor ou igual a V2";
   	 
    	System.out.println(result);
   	 
    	int total = v1 + v2;
    	System.out.println("Total eh: " + total);
   	*/
        
      
   	/*
    	String valor1 = JOptionPane.showInputDialog("V1: ");
    	float v1 = Float.parseFloat(valor1);
   	 
    	String valor2 = JOptionPane.showInputDialog("V2: ");
    	float v2 = Float.parseFloat(valor2);
   	 
    	float total = v1 + v2;
   	 
    	JOptionPane.showMessageDialog(null, "Total eh: " + total,
            	"Titulo", JOptionPane.INFORMATION_MESSAGE);
	}
        */

                
    	Flor rosa = new Flor();
    	Flor violeta = new Flor("violeta", 10.4f, 5);
   	 
    	System.out.println(rosa.getCor());   	 
    	rosa.setCor("vermelha");
    	System.out.println(rosa.getCor());
   	 
    	System.out.println(violeta.getCor());
    	System.out.println(violeta.getTamanho());
    	System.out.println(violeta.getPetalas());

	}

	
    
}

