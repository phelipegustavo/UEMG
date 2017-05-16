package exercicio03;

/**
 *
 * @author phelipe
 */
public class PecaCarro extends Produto{
    
    private String tipoCarro;
    private String marca;

    public PecaCarro(int codigo, String descricao) {
        super(codigo, descricao);
    }

    public PecaCarro(String tipoCarro, String marca, int codigo, String descricao, double preco, int quantidade) {
        super(codigo, descricao);
        setPreco(preco);
        setQuantidade(quantidade);
        this.tipoCarro = tipoCarro;
        this.marca = marca;
    }
    
    @Override
    public void imprimeProduto() {
        System.out.println("Peça de Carro: "
                + "\nCodigo: " + getCodigo()
                + "\nDescrição: " + getDescricao()
                + "\nTipo de carro: " + tipoCarro
                + "\nMarca: " + marca
                + "\nPreço: R$ " + getPreco()
                + "\nQuantidade: " + getQuantidade()
        );
    }

    public String getTipoCarro() {
        return tipoCarro;
    }

    public void setTipoCarro(String tipoCarro) {
        this.tipoCarro = tipoCarro;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }
       
}
