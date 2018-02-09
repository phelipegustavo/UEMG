package aula005;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Aula005 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Pessoa pessoa = null;

        int op = Integer.parseInt(JOptionPane.showInputDialog("Digite 1 para Física e 2 para Juridica: "));

        if (op == 1) {
            String nome = JOptionPane.showInputDialog("Nome: ");
            String cpf = JOptionPane.showInputDialog("CPF: ");
            int ano = Integer.parseInt(JOptionPane.showInputDialog("Ano de Nascimento: "));
            String endereco = JOptionPane.showInputDialog("Endereço: ");
            pessoa = new Fisica(nome, cpf, ano, endereco);
            pessoa.impressao();
        } else if(op ==2) {
            String nome = JOptionPane.showInputDialog("Nome: ");
            String cnpj = JOptionPane.showInputDialog("CPF: ");
            int ano = Integer.parseInt(JOptionPane.showInputDialog("Ano de Nascimento: "));
            String endereco = JOptionPane.showInputDialog("Endereço: ");
            pessoa = new Juridica(nome, cnpj, ano, endereco);
            pessoa.impressao();
        }
        
        if (pessoa instanceof Fisica){
            Fisica f = (Fisica) pessoa;
            System.out.println("Idade: " + f.calcularIdade());
        }else if (pessoa instanceof Juridica){
            Juridica j = (Juridica) pessoa;
            System.out.println("Idade: " + j.calcularIdade());
        }
        
    }

}
