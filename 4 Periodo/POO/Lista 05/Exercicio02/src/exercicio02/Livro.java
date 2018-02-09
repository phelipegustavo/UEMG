package exercicio02;

/**
 *
 * @author phelipe
 */
public class Livro extends Midia {

    private int numeroPagina;
    private Autor autor;

    public Livro(int codigo, String descricao, int prateleira, int numeroPagina, Autor autor) {
        super(descricao, prateleira);
        super.setCodigo(codigo);
        this.numeroPagina = numeroPagina;
        this.autor = autor;
    }

    public int getNumeroPagina() {
        return numeroPagina;
    }

    public void setNumeroPagina(int numeroPagina) {
        this.numeroPagina = numeroPagina;
    }

    public Autor getAutor() {
        return autor;
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

}
