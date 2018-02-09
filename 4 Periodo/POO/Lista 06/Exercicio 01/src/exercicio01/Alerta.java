package exercicio01;

/**
 *
 * @author phelipe
 */
public class Alerta extends Mensagem {

    @Override
    public void enviarMensagem() {
        setStatus("Mensagem Enviada");
    }

    @Override
    public void imprimirMensagem(int codigo) {
        System.out.println("Mensagem:"
                + " Alerta"
                + "\n Codigo: " + getCodigo()
                + "\n "+ getConteudo()
                + "\n Status: " + getStatus()
        );
    }
    
}
