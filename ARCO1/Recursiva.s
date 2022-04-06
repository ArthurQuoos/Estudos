#void main(){
#	int fat = fact(5);
#	printf("%i", fat);

#}


#int fact(int n){
#	if (n < 1) return 1;
#	else return (n * fact(n – 1));
#}

.text

main:

	li $a0, 5   # a0 == n
	li $v0, 1   # fat  
	
	li $t0, 1
	
	jal fact


	#Exercício (Complete o código - printar o resultado e sair)  


fact:
	addi $sp, $sp, -12
	sw $a0, 12($sp)
	sw $s0, 8($sp)
	sw $ra, 4($sp)
	
	beq $a0, $t0, sair   # n == 1?
	slti $s0, $a0, 1       # caso base n < ou == 1
	bne $s0, $zero, sair

	addi $a0, $a0, -1
	
	jal fact

	lw $a0, 12($sp)
	lw $s0, 8($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 12
	
	mul $v0, $v0, $a0
	

sair:

	jr $ra


	






