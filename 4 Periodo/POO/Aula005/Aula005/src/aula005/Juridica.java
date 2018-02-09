package aula005;

import java.time.LocalDateTime;

/**
 *
 * @author phelipe
 */
public class Juridica extends Pessoa implements InterfaceExemplo{

    public Juridica(String nome, String cpfcnpj, int anoNascimento, String endereco) {
        super(nome, cpfcnpj, anoNascimento, endereco);
    }

    @Override
    public void impressao() {
        System.out.println("Pessoa Juridica: \n"
                +"\nNome: " + getNome()
                +"\nCNPJ: " + getCpfcnpj()
                +"\nAnoNascimento: " + getAnoNascimento()
                +"\nEndereco: " + getEndereco());
    }

    @Override
    public float calcularIdade() {
        return LocalDateTime.now().getYear()-getAnoNascimento();
    }
    
}
