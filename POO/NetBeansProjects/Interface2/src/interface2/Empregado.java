
package interface2;

public abstract class Empregado {

      private Data dataNascimento;

      public Empregado(Data dataNascimento){
               setDataNascimento(dataNascimento);
      }

      public Data getDataNascimento(){
               return this.dataNascimento;
      }
      public void setDataNascimento(Data dataNascimento){
               dataNascimento.setData(dataNascimento);

      }

}

