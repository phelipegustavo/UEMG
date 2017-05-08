package aula005;

import java.time.LocalDateTime;

/**
 *
 * @author phelipe
 */
public class Fisica extends Pessoa implements InterfaceExemplo{
    
    public Fisica(String nome, String cpfcnpj, int anoNascimento, String endereco) {
        super(nome, cpfcnpj, anoNascimento, endereco);
    }

    @Override
    public void impressao() {
        System.out.println("Pessoa Física: \n"
                +"\nNome: " + getNome()
                +"\nCPF: " + getCpfcnpj()
                +"\nAnoNascimento: " + getAnoNascimento()
                +"\nEndereco: " + getEndereco());
    }

    @Override
    public float calcularIdade() {
        return LocalDateTime.now().getYear()-getAnoNascimento();
    }
    
    
    
}
