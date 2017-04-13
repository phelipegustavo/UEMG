package lista.pkg04;

/**
 *
 * @author phelipe
 */
public class Contato {

    private String registro;
    private String tipo;
    private String operadora;

    public Contato(String registro, String tipo, String operadora) {
        this.registro = registro;
        this.tipo = tipo;
        this.operadora = operadora;
    }
    
    public String retornaContato() {
        return ""
                + "\nRegistro: " + registro
                + "\nTipo: " + tipo
                + "\nOperadora: " + operadora;
    }

    public String getRegistro() {
        return registro;
    }

    public void setRegistro(String registro) {
        this.registro = registro;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getOperadora() {
        return operadora;
    }

    public void setOperadora(String operadora) {
        this.operadora = operadora;
    }
    
    
}
