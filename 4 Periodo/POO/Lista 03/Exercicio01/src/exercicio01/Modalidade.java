package exercicio01;

/**
 *
 * @author phelipe
 */
public class Modalidade {
    
    private String      descricao;
    private Professor   professor;
    public  int         quantVagas;
    private int         horarioInicio;
    private int         horarioFim;
    
    public Modalidade(){
        
    }

    public Modalidade(String descricao, int horarioInicio, int horarioFim) {
        this.descricao = descricao;
        this.horarioInicio = horarioInicio;
        this.horarioFim = horarioFim;
    }
    
    public void alteraProfessor(Professor professor){
        this.professor = professor;
    }
    
    public String retornaModalidade(){
        return "Modalidade: "
                + "\nDescrição: " + this.descricao
                + "\n" + this.professor.retornaProfessor()
                + "\nQuantidade de Vagas: " + this.quantVagas
                + "\nHorario Inicio: " + this.horarioInicio
                + "\nHorario Fim: " + this.horarioFim
                + "\n---------------------";
                
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public Professor getProfessor() {
        return professor;
    }

    public void setProfessor(Professor professor) {
        this.professor = professor;
    }

    public int getQuantVagas() {
        return quantVagas;
    }

    public void setQuantVagas(int quantVagas) {
        this.quantVagas = quantVagas;
    }

    public int getHorarioInicio() {
        return horarioInicio;
    }

    public void setHorarioInicio(int horarioInicio) {
        this.horarioInicio = horarioInicio;
    }

    public int getHorarioFim() {
        return horarioFim;
    }

    public void setHorarioFim(int horarioFim) {
        this.horarioFim = horarioFim;
    }
    
}
