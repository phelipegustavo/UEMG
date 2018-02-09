package exercicio03;

/**
 *
 * @author phelipe
 */
public class Livro extends Produto{
    
    private String autor;
    private int numeroPaginas;

    public Livro(int codigo, String descricao) {
        super(codigo, descricao);
    }

    public Livro(String autor, int numeroPaginas, int codigo, String descricao, double preco, int quantidade) {
        super(codigo, descricao);
        setPreco(preco);
        setQuantidade(quantidade);
        this.autor = autor;
        this.numeroPaginas = numeroPaginas;
    }
    
    @Override
    public void imprimeProduto() {
        System.out.println("Livro: "
                + "\nCodigo: " + getCodigo()
                + "\nDescrição: " + getDescricao()
                + "\nAutor: " + autor
                + "\nNumero de Páginas: " + numeroPaginas
                + "\nPreço: R$ " + getPreco()
                + "\nQuantidade: " + getQuantidade()
        );
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getNumeroPaginas() {
        return numeroPaginas;
    }

    public void setNumeroPaginas(int numeroPaginas) {
        this.numeroPaginas = numeroPaginas;
    }

}
