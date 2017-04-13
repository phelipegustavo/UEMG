package lista.pkg04;

import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Lista04 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Agenda agenda = new Agenda(0);

        int op = menu(scanner);
        while (op != 0) {
            switch (op) {
                case 1:
                    System.out.println("Informe o tamanho da agenda");
                    agenda = new Agenda(scanner.nextInt());
                    break;
                case 2:
                    System.out.println("Informe o nome: ");
                    String nome = scanner.next();
                    System.out.println("Informe o Aniversário: ");
                    String aniversario = scanner.next();
                    Pessoa pessoa = new Pessoa(nome, aniversario);
                    System.out.println("Informe o registro do Contato: ");
                    String registro = scanner.next();
                    System.out.println("Informe o tipo: ");
                    String tipo = scanner.next();
                    System.out.println("Informe a operadora: ");
                    String operadora = scanner.next();
                    Contato contato = new Contato(registro, tipo, operadora);
                    pessoa.insereContato(contato);
                    agenda.incluiPessoa(pessoa);
                    break;
                case 3:
                    System.out.println("Informe a posicao: ");
                    int posicao = scanner.nextInt();
                    agenda.excluirPessoa(posicao);
                    break;
                case 4:
                    agenda.imprimeAgenda();
                    break;
            }
            op = menu(scanner);
        }

    }

    private static int menu(Scanner scanner) {
        System.out.println("**AGENDA**"
                + "\n 1 - Cadastrar nova Agenda"
                + "\n 2 - Incluir Pessoa"
                + "\n 3 - Excluir Pessoa"
                + "\n 4 - Imprimir Agenda"
                + "\n 0 - SAIR"
        );
        return scanner.nextInt();

    }

}
