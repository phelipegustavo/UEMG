.data
	infog: .asciiz "Digite o valor de G: "
	infoh: .asciiz "Digite o valor de H: "
	infoi: .asciiz "Digite o valor de I: "
	infoj: .asciiz "Digite o valor de J: "
	infof: .asciiz "f = (g + h) - (i + j) = "
	
.text
	li $v0,4 	#imprimir na tela
	la $a0,infog 
	syscall
	
	li $v0,5 	#ler valor
	syscall
	
	move $t0,$v0	#t0 -> g
	#--------------------------------
	li $v0,4 	#imprimir na tela
	la $a0,infoh 
	syscall
	
	li $v0,5 	#ler valor
	syscall
	
	move $t1,$v0	#t1 -> h
	#--------------------------------
	li $v0,4 	#imprimir na tela
	la $a0,infoi 
	syscall
	
	li $v0,5 	#ler valor
	syscall
	
	move $t2,$v0	#t2 -> i
	#--------------------------------
	li $v0,4 	#imprimir na tela
	la $a0,infoj 
	syscall
	
	li $v0,5 	#ler valor
	syscall
	
	move $t3,$v0	#t3 -> j
	
	add $t4, $t0, $t1 #(g + h)
	add $t5, $t2, $t3 #(i + j)
	sub $t6, $t4, $t5 #(g + h) - (i + j)
	
	li $v0,4	#imprimir info resultado
	la $a0,infof
	syscall
	
	li $v0,1 	#imprimir valor de f
	move $a0,$t6
	syscall
	
	
	