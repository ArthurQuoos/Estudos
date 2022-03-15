
package javaapplication3;


public class Veiculo {
        private String tipo;
        private float carga;
        private float frete;
        private float capacidade;
        
        public Veiculo(String tipo, float carga){
               setTipo(tipo);
               inserir(carga);
        }

        public String getTipo(){
               return this.tipo;
        }
        public void setTipo(String tipo){
               this.tipo = tipo;
        }

         public float getCarga(){
               return this.carga;
          }
         public void setCarga(float carga){
                this.carga = carga;
         }
         public float getFrete(){
               return this.frete;
         }
         public void setFrete(float frete){
               this.frete = frete;
         }
         public float getCapacidade(){
                return this.capacidade;
         }
         public void setCapacidade(float capacidade){
                this.capacidade = capacidade;
         }

        public void inserir(float carga){
               this.carga = carga;
        }
          //Sobrecarga de metodo
         public String toString(){

                return "Tipo: " + getTipo() +
                            "\nCarga: " + getCarga() +
                            "\nFrete: " + getFrete() +
                            "\nCapacidade: " + getCapacidade();
          }        



}//fim classe Veiculo


