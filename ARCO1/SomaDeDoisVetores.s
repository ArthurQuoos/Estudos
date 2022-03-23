# Faça um programa, em assembly do mips, para somar dois vetores (V1 e V2) onde:
#
#        v1 = {10,20,30,40,50,60}
#
#        v2 = {0,10,-15, 16, 20, 30}
#
# O programa deverá percorrer os dois vetores somando cada elemento e colocando os mesmos no #   vetor resultante.
#
# A saída desejada é apresentada a seguir:
#
#   A soma dos vetores v0 e v1 é:
#
#   10, 30, 15, 56, 70, 90
#   
#   int vetorA = { 1 , 2, 3, ,4, 5, 6}
#   int vetorB = ( 2 ,3 ,4 ,5 , 6, 7}
#   int vetorC = (0 , 0 , 0 , 0 , 0 ,0}
#   
#   for( int i = 0 ; i < 6; i++){
#   vetorC[i] = vetorA[i] + vetorB[i];
#   }
#   
#   for( int i = 0 ; i < 6; i++){
#   printf("%d",vetorC[i]);
#   }
#   
#   return 0;
   
   
.data
	
  str: .asciiz "\n"
  vetorA: .word 10, 20, 30, 40, 50, 60
  vetorB: .word 0, 10, -15, 16, 20, 30
  #vetorC: .word 0, 0, 0, 0, 0, 0
  
  
.text

  main:   


la $t0, vetorA

la $t1, vetorB
li $a3, 0  #i = 0
li $t6, 0
li $t7, 6

while: 
	add $s0, $t0, $a3
	lw $t3, 0($s0)
	add $s1, $t1, $a3
	lw $t4, 0($s1)
	add $t5, $t3, $t4
	addi $a3, $a3, 4
	addi $t6, $t6, 1
	j imprimir
	

imprimir:	
	li $v0, 1
	move $a0, $t5
	syscall
	
	li $v0, 4
	la $a0, str
	syscall
	
	beq $t6, $t7, fim
	j while
	
fim:
	li $v0, 10
	syscall





















