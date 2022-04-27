


.data

    str1: .asciiz "abcde"
    str2: .asciiz "Digite um char\n"
    str3: .asciiz "\na busca retornou " 
    str4: .asciiz "nao encontrou..."
.text

main:
 
     
    li $v0, 4
    la $a0, str2
    syscall

    li $v0, 12
    syscall

	la $a0, str1

    	jal buscachar
    
    move $a0, $v0
    
    li $v0, 4
    la $a0, str3
    syscall

    li $v0, 11 #print a0
    syscall

    li $v0, 10 #exit
    syscall



buscachar:
	#addi $sp, $sp, -4
	#sw $ra, 4($sp)
	
while:
	lb $v1, 0($a0)
	beq $v1, $zero, sair1
	beq $v1, $v0, sair2
	addi $a0, $a0, 1
	
	j while
	
sair1:
	
	li $v0, 4
	la $a0, str4
	syscall
	
	li $v0, 10
	syscall
	

sair2:
    
    jr $ra
    
    
