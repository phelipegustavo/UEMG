.data
	infovar1: .asciiz "Informe o primeiro valor: "
	infovar2: .asciiz "Informe o segundo valor: "
	inforesult: .asciiz "O valor da multiplicacao e: "
.text
	#carrega valor 1
	li $v0,4		
	la $a0,infovar1
	syscall

	li $v0,5
	syscall
	move $t0,$v0
	#--------------------
	#carrega valor 2
	li $v0,4		
	la $a0,infovar2
	syscall

	li $v0,5
	syscall
	move $t1,$v0
	#-------------------
	mult $t0,$t1		# Multiplica valores, resultado em lo
	mflo $t2		# Move valor de lo para $t2
	#-------------------
	#imprimir resultado
	li $v0,4
	la $a0,inforesult
	syscall
	
	li $v0,1
	move $a0,$t2
	syscall
	
	
	
	
	