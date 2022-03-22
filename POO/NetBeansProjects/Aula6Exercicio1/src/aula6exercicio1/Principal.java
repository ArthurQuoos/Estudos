/* 
Compartilhar o seu link com: luciorocha @ professores.utfpr.edu.br

Crie uma Classe que realize a conversão de temperatura de graus Celsius para graus Fahrenheit, e vice-versa, de acordo com as seguintes fórmulas:

celsius = 5.0 / 9.0 * (fahrenheit - 32 )

fahrenheit = 9.0 / 5.0 * celsius + 32
*/

//Classes: Celsius, Farenheit
//atributos: Temperatura
//Verbos: Converter
package aula6exercicio1;


public class Principal {


    public static void main(String[] args) {
        Celsius celsius = new Celsius();
        
        celsius.setTemperatura(100.0f);
        System.out.println(celsius);
        
        System.out.println(celsius.converter(100.0f)+" Celsius");
    
        Farenheit farenheit = new Farenheit();
        farenheit.setTemperatura(100.0f);
        System.out.println("farenheit: "+ farenheit);
        System.out.println(farenheit.converter(100.0f)+" Farenheit");
    
    }
    
}
