package exercicio.pkg02;

/**
 *
 * @author phelipe
 */
public class Palavra {
    
    private String termo;
    private String[] significado;
    private int quantSignificado;
    
    public void alteraTermo(String termo){
        this.termo = termo;
    }
    
    public void incluiSignificado(String significado){
        this.significado[quantSignificado] = significado;
        quantSignificado++;
    }
    
    public void alteraSignificado(String significado, int posicao){
        this.significado[posicao] = significado;
    }

    public Palavra(String termo, int quantSignificado) {
        this.termo = termo;
        this.quantSignificado = quantSignificado;
    }

    public Palavra() {
        this.quantSignificado=0;
        this.significado = new String[10];
    }
    
    public String getTermo() {
        return termo;
    }

    public void setTermo(String termo) {
        this.termo = termo;
    }

    public String[] getSignificado() {
        return significado;
    }

    public void setSignificado(String[] significado) {
        this.significado = significado;
        this.quantSignificado++;
    }

    public int getQuantSignificado() {
        return quantSignificado;
    }

    public void setQuantSignificado(int quantSignificado) {
        this.quantSignificado = quantSignificado;
    }
    
}
