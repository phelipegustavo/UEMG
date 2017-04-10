package exercicio01;

/**
 *
 * @author phelipe
 */
public class Aluno {

    private int     matricula;
    private String  nome;
    private String  cpf;

    public Aluno(int matricula) {
        this.matricula = matricula;
    }

    public void alteraNome(String nome) {
        this.nome = nome;
    }

    public void alteraCpf(String cpf) {
        this.cpf = cpf;
    }

    public String retornaAluno() {
        return "Aluno: " + this.nome
                + "\nMatrícula: " + this.matricula
                + "\nCPF: " + this.cpf
                + "\n---------------------";
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

}
