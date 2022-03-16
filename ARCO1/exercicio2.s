   # int a = 2;
   #int b = 10;
   # x = 0;
   #if ( a >= 0 && b <= 50 )
   #      x = 1;
   # printf("%i", x);
   
   .data
   
   
   .text
   
   main:
   
   addi $t1 , $zero, 2
   addi $t2, $zero, 10
   addi $t4, $zero, 50
   
   addi $a0, $zero, 0
   
   slti $a3, $t1, 0
    bne $a0, $a3, fim
   slt $a3, $t4, $t2
    bne $a0, $a3, fim
    addi $a0, $zero, 1
    
    fim:
    li $v0, 1
    syscall
    
   
