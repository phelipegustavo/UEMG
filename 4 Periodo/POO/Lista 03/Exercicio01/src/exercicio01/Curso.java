package exercicio01;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Curso {

    private String endereco;
    public Turma[] turmas;

    public Curso(String endereco, Turma[] turmas) {
        this.endereco = endereco;
        this.turmas = turmas;
    }

    public void insereTurma(Turma turma) {
        for (int i = 0; i < turmas.length; i++) {
            if (turmas[i] != null) {
                turmas[i] = turma;
                JOptionPane.showMessageDialog(null, "Turma inserida com sucesso");
                break;
            }
        }
        JOptionPane.showMessageDialog(null, "Impossível inserir turma");
    }

    public void excluiTurma(int posicao) {
        if (turmas[posicao] != null) {
            turmas[posicao] = null;
          
            //add (for) item->item->null--item
            System.out.println("Turma Excluida com sucesso");
        } else {
            System.out.println("Impossível excluir turma");
            System.out.println("Turma excluida com sucesso");
        } else {
            System.out.println("Impossível excluida turma");
        }
    }
    
    public void imprimeCurso(){
        JOptionPane.showMessageDialog(null, "Endereço: " + this.endereco);
        for (Turma turma : turmas){
            if (turma != null)
                turma.imprimeTurma();
        }
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public Turma[] getTurmas() {
        return turmas;
    }

    public void setTurmas(Turma[] turmas) {
        this.turmas = turmas;
    }
    
}
