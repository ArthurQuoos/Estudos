.data

.text

main:

  addiu $t0, $zero, 5
  addiu $t1, $zero, 4
  addiu $t4, $zero, 1

 Mult:
  beq $t1, $t4, fim
  addu $t3, $t3, $t0
  subu $t1, $t1, $t4
  j Mult

 fim:
