.data
	infovar1: .asciiz "Informe o primeiro valor: "
	infovar2: .asciiz "Informe o segundo valor: "
	infotrue: .asciiz "Os valores informados sao iguais"
	infofalse: .asciiz "Os valores informados sao diferentes"

.text
	li $v0,4 		#carrega codigo para imprimir
	la $a0,infovar1		#carrega o endereco de infovar1
	syscall
	
	li $v0,5		#ler valor
	syscall
	move $t0,$v0		#var1 -> $t0
	#-----------------------
	li $v0,4 		#carrega codigo para imprimir
	la $a0,infovar1		#carrega o endereco de infovar2
	syscall
	
	li $v0,5		#ler valor
	syscall
	move $t1,$v0		#var2 -> $t1
	#-----------------------
	
	bne $t0,$t1,diferentes
		li $v0,4
		la $a0,infotrue
		syscall
		j fim
	
	diferentes:
		li $v0,4
		la $a0,infofalse
		syscall
	fim:
		
	
