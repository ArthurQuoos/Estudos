
.data

  printX: .asciiz "O saldo da sua conta é \n\n"

  print1: .asciiz "Entre com seu salario \n"

  print2: .asciiz "Entre com a sua divida\n"
  
.text


printSaldo:
	
	li $v0, 4
	la $a0, printX
	syscall
	
	li $v0, 1
	move $a0, $a3
	syscall 
  
 	 jr $ra

somaSaldo:

  
 add $a3, $a3, $a1 # saldo = saldo + salario
  
 jr $ra

subtraiSaldo:

 sub $a3, $a3, $a2 # saldo = saldo - divida
 
 jr $ra

saldoDisponivel:

 addi $sp, $sp, -4
 sw $ra, 4($sp)

 jal somaSaldo

 jal subtraiSaldo

 lw $ra, 4($sp)
 jr $ra 


main:

	li $a1, 0  #salario
	li $a2, 0  #divida
	li $a3, 0  #saldo

	li $v0, 4      #print da str 1
	la $a0, print1
	syscall

	li $v0, 5      #scanf salario 
	syscall
	move $a1, $v0

	li $v0, 4      #print da str2
	la $a0, print2
	syscall

	li $v0, 5      #scanf divida
	syscall
	move $a2, $v0

	jal saldoDisponivel
	jal printSaldo
	

 
 li $v0, 10   #fim
 syscall
 
 
 
