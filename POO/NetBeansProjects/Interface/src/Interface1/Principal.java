
package Interface1;


public class Principal {


    public static void main(String[] args) {
        CoelhoPardo coelhoPardo = new CoelhoPardo();
        coelhoPardo.imprimir();
        coelhoPardo.imprimirTipo();
    
        Sapo sapo = new Sapo();
        sapo.imprimirTipo();
        sapo.imprimir();
        
        Peixe peixe = new Peixe();
        peixe.imprimir();
        peixe.imprimirCor();
    }
    
}
