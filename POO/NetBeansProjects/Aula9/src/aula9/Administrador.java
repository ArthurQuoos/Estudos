
package aula9;


public class Administrador extends Faculdade {
     public Administrador(){
    }
    public String toString(){
             //return super.toString() + “ “ + this.getNome();
            //Sobrecarga
           return this.getClass().getCanonicalName() + "  " + this.getNome();
    }
   }
