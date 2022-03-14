
.data


.text

main:

  addi $t0, $zero, 10
  addi $t1, $zero, 15
  add $t0, $t0, $t1
  
  li $v0, 1
  add $a0,$zero, $t0
  syscall 
  
  li $v0, 10
  syscall
