<section>
	<h3>Últimas Notícias</h3>
	<ul class="sem-marcador sem-padding noticias">
		<?php
		$query = "select 
			noticia.*, 
			date_format(data,'%d/%m/%Y') as data_format 
			from noticia limit 0,3";
		if ($result = $conexao->query($query)) {
			while ($linha = $result->fetch_row()) {
				?>
				<li>
					<img src="<?php echo $linha[4];?>" alt="" />
					<h4><?php echo $linha[2];?></h4>
					<?php echo $linha[5];?>
					<?php echo substr($linha[3],0,50);?>...
					<a href="noticia.php?id_noticia=<?php echo $linha[0]; ?>">Leia mais &raquo;</a>
				</li>
				<?php
			}
			$result->close();
		}
		?>
	</ul>
</section>