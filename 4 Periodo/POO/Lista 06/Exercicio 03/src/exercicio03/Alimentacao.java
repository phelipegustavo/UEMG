package exercicio03;

/**
 *
 * @author phelipe
 */
public class Alimentacao extends Produto {
    
    private String validade;

    public Alimentacao(int codigo, String descricao) {
        super(codigo, descricao);
    }

    public Alimentacao(String validade, int codigo, String descricao, double preco, int quantidade) {
        super(codigo, descricao);
        setPreco(preco);
        setQuantidade(quantidade);
        this.validade = validade;
    }
    
    @Override
    public void imprimeProduto() {
        System.out.println("Alimento: "
                + "\nCodigo: " + getCodigo()
                + "\nDescrição: " + getDescricao()
                + "\nValidade: " + validade
                + "\nPreço: R$ " + getPreco()
                + "\nQuantidade: " + getQuantidade()
        );
    }
    
}
