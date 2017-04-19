package exercicio02;

/**
 *
 * @author phelipe
 */
public class Midia {
   
    private int codigo;
    private String descricao;
    private int prateleira;

    public Midia(String descricao, int prateleira) {
        this.descricao = descricao;
        this.prateleira = prateleira;
        codigo = 0; 
    }
    
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

    public int getPrateleira() {
        return prateleira;
    }

    public void setPrateleira(int prateleira) {
        this.prateleira = prateleira;
    }
    
    
    
}
