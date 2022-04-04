
package aula9;

 public class Principal {
    public static void main(String [ ] args ){
        Professor professor = new Professor("Professor 1");
         System.out.println(professor);
        Professor professor_fisica = new Professor("Professor 2", 300.0f);
        System.out.println(professor_fisica);
   }

}
