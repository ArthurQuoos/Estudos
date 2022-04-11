
package interface2;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    

    
    public void setData(Data dataNascimento){
          this.dia = dataNascimento.getDia();
          this.mes = dataNascimento.getMes();
          this.ano = dataNascimento.getAno();
    }

    public int getDia(){   return this.dia; }
    public int getMes(){   return this.mes; }
    public int getAno(){   return this.ano; }


}
