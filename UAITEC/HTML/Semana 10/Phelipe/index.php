<?php
	include("header.php");
?>
		
	<div class="linha">
		<section>
			<div class="coluna col3 sidebar">
				<h3>Clientes satisfeitos</h3>
				<ul class="sem-marcador sem-padding">
				<?php
				$query = "select * from cliente limit 0,10";
				if ($result = $conexao->query($query)) {
					while ($linha = $result->fetch_row()) {
						?>
						<li><a href="<?php echo $linha[2];?>"><?php echo $linha[1];?></a></li>
						<?php
					}
					$result->close();
				}
				?>	
				</ul>
				<a href="clientes.php" class="botao">ver todos &raquo;</a>
			</div>
			<div class="coluna col9">
				<h2>Último trabalho: <em>Empresa ABC</em></h2>
				<img src="img/thumb-grande.jpg" alt="" />
				<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer lacinia, dolor mollis tempor finibus, 
				neque diam maximus nisi, sit amet finibus dolor orci quis felis. Nunc arcu libero, viverra ut ante et, 
				imperdiet commodo velit. Nulla facilisi. Duis sed est pulvinar, tincidunt arcu sit amet, auctor velit.</p>
				<a href="clientes.php" class="botao">Ver outros trabalhos &raquo;</a>
			</div>
		</section>
	</div>
		
	<div class="conteudo-extra">
		<div class="linha">
			<div class="coluna col7">
				<section>
					<h2>Como conquistar clientes na era digital</h2>
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