package exercicio03;

/**
 *
 * @author phelipe
 */
public abstract class Produto {
    
    private int codigo;
    private String descricao;
    private double preco;
    private int quantidade;

    public Produto(int codigo, String descricao) {
        this.codigo = codigo;
        this.descricao = descricao;
    }
    
    public void mudaEstoque(int acrescimo){
        this.quantidade+=acrescimo;
    }
    
    public abstract void imprimeProduto();

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }
}
