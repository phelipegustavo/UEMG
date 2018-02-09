.data
	infonum: .asciiz "Informe o numero: "
	infoimpar: .asciiz "O numero e impar "
	infopar: .asciiz "O numero e par "
	
.text 
	#exibe infonum
	li $v0,4		
	la $a0,infonum
	syscall
	#recebe numero
	li $v0,5
	syscall
	move $t0,$v0 		#move o valor recebido para $t0
	
	addi $t1,$zero,2	#$t1 recebe 2
		
	div  $t0,$t1		#divide $t0 por $t1
	mfhi $t2		#Armazena o resto da divisao de $t0 por $t1
	
	beq $t2,$zero,par	#compara $t2 com $zero
		#se $t2 != $zero
		li $v0,4	
		la $a0,infoimpar
		syscall
		j fim
	par:
		#se $t2 == $zero
		li $v0,4
		la $a0,infopar
		syscall
	fim:
