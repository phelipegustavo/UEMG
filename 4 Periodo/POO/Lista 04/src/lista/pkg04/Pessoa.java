package lista.pkg04;

import java.util.ArrayList;

/**
 *
 * @author phelipe
 */
public class Pessoa {
    
    private String nome;
    private ArrayList<Contato> contatos;
    private String aniversario;
    
    public Pessoa(){
        contatos = new ArrayList<>();
    }

    public Pessoa(String nome, String aniversario) {
        this.nome = nome;
        this.aniversario = aniversario;
        contatos = new ArrayList<>();
    }
    
    public void insereContato(Contato contato){
        contatos.add(contato);
        System.out.println("Contato adcionado com sucesso!");
    }
    
    public String retornaPessoa(){
        String strContatos = "";
        
        for (Contato c : contatos){
            strContatos += c.retornaContato();
        }

        return ""
                + "\nNome: " + nome
                + "\nAniversario: " + aniversario
                + strContatos;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setContatos(ArrayList<Contato> contatos) {
        this.contatos = contatos;
    }

    public void setAniversario(String aniversario) {
        this.aniversario = aniversario;
    }
    
}
