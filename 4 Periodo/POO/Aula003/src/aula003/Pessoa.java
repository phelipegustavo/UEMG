package aula003;

/**
 *
 * @author phelipe
 */
public class Pessoa {
    
    private String nome;
    private int anoNascimento;

    public int calcularIdade(int anoAtual){
        return anoAtual - anoNascimento;
    }   
    
    public String retornaPessoa(){
        return "Nome: " + this.nome + ", ano de nascimento: " + this.anoNascimento;
    }
    
    public Pessoa() {
        this.nome = "";
        this.anoNascimento = 0;
    }

    public Pessoa(String nome, int anoNascimento) {
        this.nome = nome;
        this.anoNascimento = anoNascimento;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAnoNascimento() {
        return anoNascimento;
    }

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }
    
}
