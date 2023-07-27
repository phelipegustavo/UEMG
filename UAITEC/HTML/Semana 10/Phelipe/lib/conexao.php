<?php	
	
	$servidor='127.0.0.1';
	$usuario='root';
	$senha='1234';
	$banco='progweb';
	
	//Mensagens de Erro
	$msg[0] = "Conexão com o banco falhou!";
	$msg[1] = "Não foi possível selecionar o banco de dados!";

	$conexao=mysqli_connect($servidor,$usuario,$senha,$banco)or die($msg[0]);
	/*if($conexao)
		echo "tudo ok";
	else
		echo "Erro " . $mysql->error();
	
	*/
	//mysqli_close($conexao);
	
?>