.data

	x: .asciiz " "
	y: .asciiz "Olá mundo!!!!\n\n"


.text

strcpy:

	addi $sp, $sp, -20
	sw $s3, 20($sp)
	sw $s5, 16($sp)
	sw $s6, 12($sp)
	sw $s7, 8($sp)
	sw $ra, 4($sp)
	
	li $s3, 0 # $s3 = i
	
   while: 
   	
   	add $s5, $s3, $a0 #$s5 = &x[i]
   	add $s6, $s3, $a1 #$s6 = &y[i]
   	lb $s7, 0($s6)
   	beq $s7, $zero, sair
   	sb $s7, 0($s5)
   	addi $s3, $s3, 1
   	j while
   	
   sair:
   
   	move $v1, $s3
   	lw $s3, 20($sp)
	lw $s5, 16($sp)
	lw $s6, 12($sp)
	lw $s7, 8($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 20
   	jr $ra
   	
 main: 
 	la $a0, x
 	la $a1, y
 	
 	jal strcpy
 	
 	li $v0, 4
 	la $a0, x
 	syscall
 	
 	li $v0, 1
 	move $a0, $v1
 	syscall
 	
 	li $v0, 10
 	syscall
 	
