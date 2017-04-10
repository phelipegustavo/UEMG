package exercicio01;

/**
 *
 * @author phelipe
 */
public class Professor {
    
    private String  nome;
    private String  titulacao;
    private int     idade;

    public Professor() {
    }
    
    public Professor(String nome, String titulacao, int idade) {
        this.nome = nome;
        this.titulacao = titulacao;
        this.idade = idade;
    }
    
    public void alteraTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }
    
    public String retornaProfessor(){
        return "Professor: "
                + "\nNome: " + this.nome
                + "\nTitulação: " + this.titulacao
                + "\nIdade: " + this.idade
                + "\n---------------------";
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTitulacao() {
        return titulacao;
    }

    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    
}