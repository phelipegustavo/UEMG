package aula005;

/**
 *
 * @author phelipe
 */
public abstract class Pessoa {
    
    private String nome;
    private String cpfcnpj;
    private int anoNascimento;
    private String endereco;

    public Pessoa(String nome, String cpfcnpj, int anoNascimento, String endereco) {
        this.nome = nome;
        this.cpfcnpj = cpfcnpj;
        this.anoNascimento = anoNascimento;
        this.endereco = endereco;
    }

    public abstract void impressao();
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpfcnpj() {
        return cpfcnpj;
    }

    public void setCpfcnpj(String cpfcnpj) {
        this.cpfcnpj = cpfcnpj;
    }

    public int getAnoNascimento() {
        return anoNascimento;
    }

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
}
