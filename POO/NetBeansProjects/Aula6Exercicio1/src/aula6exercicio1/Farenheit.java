
package aula6exercicio1;


public class Farenheit {
        private float temperatura;
    
    public Farenheit(){
        setTemperatura(0);
    }
    
    public void setTemperatura(float temperatura){
        this.temperatura = temperatura;
    }
    
    public float converter(float celsius){
        return 9.0f / 5.0f * (celsius + 32);
    } 
    
    public String toString(){
        return this.temperatura+"";
    }
}
