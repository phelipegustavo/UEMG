package exercicio.pkg01;

/**
 *
 * @author phelipe
 */
public class ItemPedido {
    
    private String produto;
    private int quant;
    private float valorTotal;

    public ItemPedido() {
        
    }

    public String retornaItemPedido(){
        return "Nome Pedido: " + produto + ", quantidade: " + quant + ", valor total: " + valorTotal;
    }
    
    public ItemPedido(String produto, int quant, float valorTotal) {
        this.produto = produto;
        this.quant = quant;
        this.valorTotal = valorTotal;
    }

    public String getProduto() {
        return produto;
    }

    public void setProduto(String produto) {
        this.produto = produto;
    }

    public int getQuant() {
        return quant;
    }

    public void setQuant(int quant) {
        this.quant = quant;
    }

    public float getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(float valorTotal) {
        this.valorTotal = valorTotal;
    }
    
}
