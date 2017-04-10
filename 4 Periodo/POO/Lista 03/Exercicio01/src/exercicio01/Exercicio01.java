package exercicio01;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Exercicio01 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Curso[]     cursos      = new Curso[10];
        Turma[]     turmas      = new Turma[10];
        int         posCursos   = 0;
        int         posTurmas   = 0;   
        int         pos         = 0;
        
        int op = menu();
        while (op != 0){
            
            switch(op){
                
                case 1: /*Inserir Curso*/
                    
                    /*Professor*/
                    Professor   professor   = criarProfessor();
                    
                    /*Modalidade*/
                    Modalidade  modalidade  = criarModalidade();
                    modalidade.setQuantVagas(Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a capacidade de alunos: ")));
                    modalidade.setProfessor(professor);
                    
                    /*Alunos*/
                    Aluno[]     alunos      = criarAluno();
                    
                    /*Turma*/
                    Turma      turma        = new Turma();
                    turma.setAlunos(alunos);
                    turma.setModalidade(modalidade);
                    turmas                  = inserirTurma(turmas, turma, posTurmas);
                    posTurmas++;
                    
                    /*Curso*/
                    String      endereco    = JOptionPane.showInputDialog(null, "Informe o endereço do curso");
                    Curso       curso       = new Curso(endereco, turmas);
                    cursos                  = inserirCurso(cursos, curso, posCursos);
                    posCursos++;

                    break;
                    
                case 2:/*Incluir Aluno*/ 
                    String      modalidadeAi= JOptionPane.showInputDialog(null, "Informe a descrição do curso do aluno: ");
                    for (Curso c : cursos){
                        if (c == null) break;
                        for (Turma t: c.turmas){
                            if (t == null) break;
                            if (t.getModalidade().getDescricao().equals(modalidadeAi)){
                                int     matricula   = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe o codigo de matrícula do aluno: "));
                                String  nomeA       = JOptionPane.showInputDialog(null, "Informe o nome do aluno: ");
                                String  cpf         = JOptionPane.showInputDialog(null, "Informe o CPF do aluno: ");
                                Aluno   aluno = new Aluno(matricula);
                                aluno.setNome(nomeA);
                                aluno.setCpf(cpf);
                                t.insereAluno(aluno);
                            }break;
                        }
                    }
                    break;

                case 3: /*Excluir Aluno*/
                    int         posA        = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a posicao do aluno: "));
                    String      modalidadeA = JOptionPane.showInputDialog(null, "Informe a descrição da modalidade do aluno: ");
                    for (Curso c : cursos){
                        if (c == null) break;
                        for (Turma t : c.turmas){
                            if (t == null) break;
                            if (t.getModalidade().getDescricao().equals(modalidadeA)){
                                t.excluirAluno(posA);
                                break;
                            }
                        }
                    }
                    break;
                    
                case 4: /*Alterar Titulação Professor*/
                    String      modalidadeP = JOptionPane.showInputDialog(null, "Informe a descrição da modalidade do Professor: ");
                    String      nomeP       = JOptionPane.showInputDialog(null, "Informe o nome do Professor: ");

                    for (Curso c : cursos){
                        if (c == null) break;
                        for (Turma t : c.turmas){
                            if (t == null) break;
                            if (t.getModalidade().getDescricao().equals(modalidadeP) && 
                                    t.getModalidade().getProfessor().getNome().equals(nomeP)){
                                String      titulacao      = JOptionPane.showInputDialog(null, "Informe a nova titulação do Professor: ");
                                t.getModalidade().getProfessor().alteraTitulacao(titulacao);
                                break;
                            }
                        }
                    }
                    break;

                case 5: /*Exibir Cursos*/
                    pos                     = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a posicao do curso: "));
                    cursos[0].imprimeCurso();
                    break;

                case 0: JOptionPane.showMessageDialog(null, "SAINDO...");break;

                default: JOptionPane.showMessageDialog(null, "Opção Inválida!");break;
                
            }
            
            op = menu();
        }
    }
    
    public static int menu(){
        String msg = 
                "***Escola***\n"
                + "1 - Inserir Curso\n"
                + "2 - Inserir Aluno\n"
                + "3 - Excluir Aluno\n"
                + "4 - Alterar Titulação do Professor\n"
                + "5 - Exibir Curso\n"
                + "0 - SAIR\n";
        int op = Integer.parseInt(JOptionPane.showInputDialog(null , msg + "Informe a Opção desejada: "));
        return op;
    }
    
    public static Curso[] inserirCurso(Curso[] cursos, Curso curso, int posicao){
        if (posicao < 10 && cursos[posicao] == null){
            cursos[posicao] = curso;
            JOptionPane.showMessageDialog(null, "Curso inserido com sucesso");
        }
        return cursos;
    }
    
    public static Turma[] inserirTurma(Turma[] turmas, Turma turma, int posicao){
        if (posicao < 10 && turmas[posicao] == null){
            turmas[posicao] = turma;
            JOptionPane.showMessageDialog(null, "Curso inserido com sucesso");
        }
        return turmas;
    }
    
    public static Professor criarProfessor(){
        String      nomeP       = JOptionPane.showInputDialog(null, "Informe o nome do professor: ");
        String      titulacao   = JOptionPane.showInputDialog(null, "Informe a titulação do professor: ");
        int         idade       = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a idade do professor: "));
        Professor   professor  = new Professor(nomeP, titulacao, idade);
        return professor;
    }
    
    public static Modalidade criarModalidade(){
        String      descricao   = JOptionPane.showInputDialog(null, "Informe a descrição da Modalidade: ");
        int         hraInicio   = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a hora de Inicio: "));
        int         hraFim      = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a hora de Fim: "));
        Modalidade  modalidade = new Modalidade(descricao, hraInicio, hraFim);
        return modalidade;
    }
    
    public static Aluno[] criarAluno(){
        int         quantAluno  = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantos alunos devem ser inseridos: "));
        Aluno[]     alunos      = new Aluno[25];
        for (int i=0; i<quantAluno; i++){
            int     matricula   = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe o codigo de matrícula do aluno: "));
            String  nomeA       = JOptionPane.showInputDialog(null, "Informe o nome do aluno: ");
            String  cpf         = JOptionPane.showInputDialog(null, "Informe o CPF do aluno: ");
            Aluno  aluno1       = new Aluno(matricula);
            aluno1.alteraNome(nomeA);
            aluno1.alteraCpf(cpf);
            alunos[i]=aluno1;
        }
        return alunos;
    }
}
