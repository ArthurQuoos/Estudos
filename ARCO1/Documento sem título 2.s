   # int a = 3;, 
   # int b = 4;
   # int m = 10;
   # m = a;
   # if ( b < m )
   #     m = b;
   
   # printf("%i", m);
    
    .data 
    
    .text
    
    main:
    
    addi $t1, $zero, 3    #
    addi $t2, $zero, 5    #
    addi $t4, $zero, 10   #
    
    add $t4, $zero, $t1   #
    
    slt $t1,$t2,$t4       #
    beq $t1,$t4,fim       #
    
    
    add $t4, $zero, $t2   #
   
   fim:
   
   li $v0, 1               #
   add $a0, $zero, $t4     #
   syscall                 #
   
    
    
