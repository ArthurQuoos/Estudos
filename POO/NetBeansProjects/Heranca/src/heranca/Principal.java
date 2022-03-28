
package heranca;


public class Principal {

    public static void main(String[] args) {
        Sapo sapo = new Sapo("Girino", "verde",50);
        System.out.println(sapo);
        
        Sapo perereca = new Sapo();
        System.out.println( perereca );
        
        Leao leao = new Leao( "LeaoTigre", 60 );
        System.out.println( leao );                

    }
    
}
