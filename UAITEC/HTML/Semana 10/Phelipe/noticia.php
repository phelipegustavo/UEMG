<?php
	include("header.php");
?>
		
	<div class="linha">
		<section>
		<div class="coluna col12">
			<?php
			$id_noticia=$_GET["id_noticia"];
			$query = "select 
			noticia.*, 
			date_format(data,'%d/%m/%Y') as data_format 
			from noticia
			where id_noticia='$id_noticia'";
			
			$result = $conexao->query($query);
			$linha = $result->fetch_row();
			?>			
			<h2>Notícia</h2>
			<h3><?php echo $linha[5];?> - <?php echo $linha[2];?></h3>
			<p>
				<?php echo nl2br($linha[3]);?>
				
			</p>
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