package exercicio.pkg01;

/**
 *
 * @author phelipe
 */
public class Pedido {
    
    private String descricao;
    private String data;
    public ItemPedido[] itens = new ItemPedido[10];
    private int qtdItens;
    
    public Pedido(String descricao, String data) {
        this.descricao = descricao;
        this.data = data;
        this.qtdItens = 0;
    }

    public Pedido() {
    }
   
    public void insereItem(ItemPedido item){
        if (qtdItens < itens.length){
            this.itens[qtdItens] = item;
            qtdItens++;
        } else {
            System.out.println("Impossivel adcionar item, vetor cheio!");
        }
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public ItemPedido[] getItens() {
        return itens;
    }

    public void setItens(ItemPedido[] itens) {
        this.itens = itens;
    }
    
}
