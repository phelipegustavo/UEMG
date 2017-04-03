package exercicio.pkg02;

import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Exercicio02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Dicionario dicionario = new Dicionario();
        int op = 1;

        while (op != 0) {
            System.out.println(
                    "*****DICIONÁRIO*****\n"
                    + "1 - Inserir Palavra\n"
                    + "2 - Excluir Palavra\n"
                    + "3 - Incluir Significado\n"
                    + "4 - Alterar quantidade palavra\n"
                    + "5 - Imprimir Dicionario\n"
                    + "0 - SAIR");
            op = scanner.nextInt();

            switch (op) {
                case 1:
                    Palavra palavra = new Palavra();
                    System.out.println("Palavra: ");
                    palavra.setTermo(scanner.next());
                    System.out.println("Significado: ");
                    palavra.incluiSignificado(scanner.next());
                    dicionario.inserePalavra(palavra);
                    break;
                case 2:
                    System.out.println("Informe a posição para excluir: ");
                    dicionario.excluiPalavra(scanner.nextInt());
                    break;
                case 3:
                    System.out.println("Informe a posicao para incluir: ");
                    int pos = scanner.nextInt();
                    System.out.println("Significado: ");
                    dicionario.palavra[pos].incluiSignificado(scanner.next());
                    break;
                case 4:
                    System.out.println("Informe a quantidade: ");
                    dicionario.setQuantPalavra(scanner.nextInt());
                    break;
                case 5:
                    dicionario.imprimeDicionario();
                    break;
                case 0:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção Inválida!");
                    break;
            }
        }

    }

}
