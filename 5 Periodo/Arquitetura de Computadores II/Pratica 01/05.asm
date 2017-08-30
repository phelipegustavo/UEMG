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
	move $a1,$t0
	move $a2,$t1

	#Texto resultado
	li $v0,4
	la $a0,inforesult
	syscall
	
	#multiplica
	jal multiplicacao

	#Valor variavel
	li $v0,1
	move $a0,$v1
	syscall
	
	li $v0,10
	syscall

	.globl multiplicacao
	multiplicacao:
		mul $v1,$a1,$a2
		jr $ra
