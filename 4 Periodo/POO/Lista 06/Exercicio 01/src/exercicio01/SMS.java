package exercicio01;

/**
 *
 * @author phelipe
 */
public class SMS extends Mensagem {

    @Override
    public void enviarMensagem() {
        setStatus("Mensagem Enviada");
    }

    @Override
    public void imprimirMensagem(int codigo) {
        System.out.println("Mensagem:"
                + " SMS"
                + "\n Codigo: " + getCodigo()
                + "\n "+ getConteudo()
                + "\n Status: " + getStatus()
        );
    }
    
}
