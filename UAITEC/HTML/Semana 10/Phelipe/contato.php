<?php
	include("header.php");
	$nome="";
	$email="";
	$assunto="";
	$mensagem="";
?>
		
	<div class="linha">
		<section>
			<div class="coluna col5 sidebar">
				<h3>Localização</h3>
				<img src="img/mapa.jpg" alt="" />
				<ul class="sem-padding sem-marcador">
					<li>Avenida Paraná, 3001</li>
					<li>Bairro Jardim Belvedere</li>
					<li>Divinópolis - MG</li>
				</ul>
				<h3>Contato Direto</h3>
				<ul class="sem-padding sem-marcador">
					<li>Fone: <strong>(37) 9999-9999</strong></li>
					<li>Email: <strong>uaitec@divinopolis.com</strong></li>
					<li>Skype: <strong>uaitec</strong></li>
				</ul>
			</div>
			<div class="coluna col7 contato">
				<h2>Envie sua mensagem</h2>
				<?php
					if(isset($_POST["nome"]))
					{
						$nome=$_POST["nome"];
						$email=$_POST["email"];
						$assunto=$_POST["assunto"];
						$mensagem=$_POST["mensagem"];
						
						if ($nome and $email and $assunto and $mensagem)
						{
							$query="insert into contato values('','$nome','$email','$assunto','$mensagem')";
							$result = $conexao->query($query);
							
							echo "<script>alert('Mensagem enviada com sucesso!')</script>";
							
							
						}
						else
						{
							echo "<script>alert('Atenção, preencha todos os campos !')</script>";
						}
					}	
				?>
				<form action="contato.php" method="post">
					<label for="nome">Seu nome:</label>
					<input type="text" name="nome" id="nome" value="<?php echo $nome; ?>" />
					<label for="email">Seu e-mail:</label>
					<input type="text" name="email" id="email" value="<?php echo $email; ?>"/>
					<label for="Assunto">Assunto:</label>
					<input type="text" name="assunto" id="assunto" value="<?php echo $assunto; ?>"/>
					<label for="mensagem">Mensagem:</label>
					<textarea name="mensagem" id="mensagem"><?php echo $mensagem; ?></textarea>
					<input type="submit" class="botao" name="enviar" value="Enviar Mensagem &raquo;" />
				</form>
			</div>
		</section>
	</div>
	
	<div class="conteudo-extra">
		<div class="linha">
			<div class="coluna col7">
				<section>
					<h2>Método alternativo de contatos</h2>
					<p>Sed laoreet nulla vel orci iaculis convallis. 
					Suspendisse auctor libero in tortor aliquam</p>
					<p>Sed laoreet nulla vel orci iaculis convallis. 
					Suspendisse auctor libero in tortor aliquam</p>
					<p>Sed laoreet nulla vel orci iaculis convallis. 
					Suspendisse auctor libero in tortor aliquam</p>
				</section>
			</div>
			<div class="coluna col5">
				<?php
					include("comp_noticia.php");
				?>
			</div>
		</div>
	</div>
		
<?php
	include("footer.php");
?>				