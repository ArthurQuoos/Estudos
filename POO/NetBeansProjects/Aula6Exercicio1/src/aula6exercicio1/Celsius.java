
package aula6exercicio1;


public class Celsius {

    private float temperatura;
    
    public Celsius(){
        setTemperatura(0);
    }
    
    public void setTemperatura(float temperatura){
        this.temperatura = temperatura;
    }
    
    public float converter(float farenheit){
        return 5.0f / 9.0f * (farenheit - 32);
    }
    
    public String toString(){
        return this.temperatura+"";
    }
    
}//fim da classe
