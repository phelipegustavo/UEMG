package exercicio01;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Turma {

    private Modalidade modalidade;
    public Aluno[] alunos;

    public Turma() {
        alunos = new Aluno[25];
    }

    public void alteraModalidade(Modalidade modalidade) {
        this.modalidade = modalidade;
    }

    public void insereAluno(Aluno aluno) {
        for (int i = 0; i < alunos.length; i++) {
            if (alunos[i] == null) {
                alunos[i] = aluno;
                JOptionPane.showMessageDialog(null, "Aluno inserido com sucesso");
                return;
            }
        }
        JOptionPane.showMessageDialog(null, "Impossível inserir aluno");
    }

    public void excluirAluno(int posicao) {
        if (alunos[posicao] != null) {
            alunos[posicao] = null;
            JOptionPane.showMessageDialog(null, "Aluno removido com sucesso");
        } else {
            JOptionPane.showMessageDialog(null, "Posicao inválida ou aluno inexistente");
        }
    }

    public void imprimeTurma() {
        String strAlunos = "\n---------------------";
        for (Aluno aluno : alunos) {
            if (aluno != null)
                strAlunos += "\n" + aluno.retornaAluno();
        }
        JOptionPane.showMessageDialog(null, this.modalidade.retornaModalidade() + "\nAlunos" + strAlunos);
    }

    public Modalidade getModalidade() {
        return modalidade;
    }

    public void setModalidade(Modalidade modalidade) {
        this.modalidade = modalidade;
    }

    public Aluno[] getAlunos() {
        return alunos;
    }

    public void setAlunos(Aluno[] alunos) {
        this.alunos = alunos;
    }
    
}
