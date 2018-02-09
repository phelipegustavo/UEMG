.data
	infoqtde: 	.asciiz "Informe a quantidade de numeros a inserir: "
	infovalor: 	.asciiz "Informe um numero inteiro: "
	infopar: 	.asciiz "\nTotal de numeros pares: "
	infoimpar: 	.asciiz "\nTotal de numeros impares: "
.text
	#Exibe infoqtde
	li $v0,4
	la $a0,infoqtde
	syscall
	#recebe qntde
	li $v0,5
	syscall
	move $t0,$v0 			#$t0 armazena quantidade
	#-------------------------------
	add $t7,$zero,$zero		#inicialização contador loop -> $t7
	add $t6,$zero,$zero		#inicialização contador pares  -> $t6
	add $t5,$zero,$zero		#inicialização contador impres -> $t5

	ler_valores:			#label para receber valores
		beq $t7,$t0,imprimir	#compara contador do loop -> $t7 com quantidade informada -> $t0
			addi $t7,$t7,1  #incrementa cotador -> $t7
			#exibe infovalor
			li $v0,4
			la $a0,infovalor
			syscall
			#recebe valor
			li $v0,5
			syscall
			
			move $t1,$v0	#$t1 armazena valores
			j par_impar	#vai para par_impar

	par_impar:			#label para contar numeros pares e impares
		add $t2,$zero,2		#$t2 -> 2
		div $t1,$t2		#divide valor -> $t1 por 2
		mfhi $t3		#move o resto da divisao para $t3
		beq $t3,$zero,par
			#É impar
			addi $t5,$t5,1 	#incrementa contador de impares
			j ler_valores
	
		par:
			#É par
			addi $t6,$t6,1 	#incrementa contador de pares
			j ler_valores
		
	imprimir:
		#imprime quantidade de numeros pares
		li $v0,4
		la $a0,infopar
		syscall
		
		li $v0,1
		move $a0,$t6
		syscall 
		
		#imprime quantidade de numeros impares
		li $v0,4
		la $a0,infoimpar
		syscall
		
		li $v0,1
		move $a0,$t5
		syscall 
		
		
