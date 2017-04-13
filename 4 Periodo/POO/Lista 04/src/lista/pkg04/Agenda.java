package lista.pkg04;

import java.util.ArrayList;

/**
 *
 * @author phelipe
 */
public class Agenda {

    private ArrayList<Pessoa> cardeneta;
    
    public Agenda(int tamanho) {
        cardeneta = new ArrayList<>(tamanho);
    }
    
    public void incluiPessoa(Pessoa pessoa) {
        cardeneta.add(pessoa);
    }

    public void excluirPessoa(int posicao) {
        try {
            cardeneta.remove(posicao);
        } catch (Exception e) {
            System.out.println("Erro ao excluir pessoa, verifique a posição informada");
        }
    }
    
    public void imprimeAgenda(){
        String strPessoas = "";
        
        for (Pessoa p : cardeneta){
            strPessoas += "\n----------------" + p.retornaPessoa();
        }
        System.out.println("Agenda: " + strPessoas);
    }

    public ArrayList<Pessoa> getCardeneta() {
        return cardeneta;
    }

    public void setCardeneta(ArrayList<Pessoa> cardeneta) {
        this.cardeneta = cardeneta;
    }
    
}
