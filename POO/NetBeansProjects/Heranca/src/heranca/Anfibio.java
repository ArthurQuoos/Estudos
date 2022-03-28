
package heranca;


public class Anfibio extends Animal { 
            protected int qtdeEscamas;
            
            public Anfibio(String nome, int qtdEscamas){
                        super( nome );
                        setQtdeEscamas( qtdEscamas );
            }
           public void setQtdeEscamas( int qtdeEscamas ){
                     this.qtdeEscamas = qtdeEscamas;
           }
        public int getQtdeEscamas(){
                 return this.qtdeEscamas;
         }
        
        public Anfibio(){
            setNome("animal do anfibio");
        }

}
