package exercicio02;

import java.util.ArrayList;
import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Exercicio02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<Livro> livros = new ArrayList<>();
        ArrayList<DVD> DVDs = new ArrayList<>();

        int op = menu();
        while (op != 0) {

            switch (op) {

                /*Cadastar Livro*/
                case 1: {
                    int codigo = livros.size();
                    String descricao = JOptionPane.showInputDialog("Informe a descrição do livro: ");
                    int prateleira = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero da prateleira: "));
                    int numeroPaginas = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero de páginas: "));

                    Autor autor = new Autor();
                    autor.nome = JOptionPane.showInputDialog("Informe o nome do autor: ");
                    autor.titulacao = JOptionPane.showInputDialog("Informe a titulação do autor: ");

                    Livro livro = new Livro(codigo, descricao, prateleira, numeroPaginas, autor);
                    livros.add(livro);

                    JOptionPane.showMessageDialog(null, "Livro cadastrado com sucesso!"
                            + "\nCódigo: " + livro.getCodigo()
                            + "\nDescrição: " + livro.getDescricao()
                            + "\nAutor: " + livro.getAutor().nome
                            + "\nNumero de Páginas: " + livro.getNumeroPagina()
                            + "\nPrateleira: " + livro.getPrateleira()
                    );
                }
                break;

                /*Cadastrar DVD*/
                case 2: {
                    int codigo = DVDs.size();
                    String descricao = JOptionPane.showInputDialog("Informe a descrição do DVD: ");
                    int prateleira = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero da prateleira: "));
                    int numeroFaixas = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero de faixas: "));
                    DVD dvd = new DVD(codigo, descricao, prateleira, numeroFaixas);

                    for (int i = 0; i < numeroFaixas; i++) {
                        Faixa faixa = new Faixa();
                        faixa.titulo = JOptionPane.showInputDialog("Informe o título da faixa " + i + ": ");
                        faixa.quantMinutos = Integer.parseInt(JOptionPane.showInputDialog("Informe a quantidade de minutos da faixa " + i + ": "));
                        dvd.adcionarFaixa(faixa);
                    }
                    DVDs.add(dvd);

                    JOptionPane.showMessageDialog(null, "DVD cadastrado com sucesso!"
                            + "\nCódigo: " + dvd.getCodigo()
                            + "\nDescrição: " + dvd.getDescricao()
                            + "\nPrateleira: " + dvd.getPrateleira()
                    );
                }
                break;

                /*Imprimir Mídias*/
                case 3: {
                    String strLivros = "Livros:";
                    for (Livro l : livros) {
                        strLivros += "\n---------------"
                                + "\nCódigo: " + l.getCodigo()
                                + "\nDescrição: " + l.getDescricao()
                                + "\nAutor: " + l.getAutor().nome
                                + "\nTitulação Autor: " + l.getAutor().titulacao
                                + "\nNumero de Páginas: " + l.getNumeroPagina()
                                + "\nPrateleira: " + l.getPrateleira();
                    }
                    String strDVDs = "DVDs:";
                    String strFaixas = "Faixas:";
                    for (DVD d : DVDs) {
                        for (Faixa f : d.getFaixas()) {
                            strFaixas += "\n----*----"
                                    + "\nTítulo: " + f.titulo
                                    + "\nMinutos: " + f.quantMinutos;
                        }
                        strDVDs += "\n---------------"
                                + "\nCódigo: " + d.getCodigo()
                                + "\nDescrição: " + d.getDescricao()
                                + "\nNumero de Faixas: " + d.getNumeroFaixas()
                                + "\nPrateleira: " + d.getPrateleira()
                                + "\n" + strFaixas;
                    }

                    JOptionPane.showMessageDialog(null, strLivros);
                    JOptionPane.showMessageDialog(null, strDVDs);

                }
                break;

                /*Excluir Livro*/
                case 4: {
                    String descricao = JOptionPane.showInputDialog("Informe a descrição do Livro: ");
                    for (Livro l : livros) {
                        if (l.getDescricao().equals(descricao)) {
                            livros.remove(l);
                            JOptionPane.showMessageDialog(null, "Livro removido com Sucesso!");
                            break;
                        }
                    }
                    JOptionPane.showMessageDialog(null, "Erro ao excluir, Livro não encontrado!");
                }
                break;

                /*Excluir DVD*/
                case 5: {
                    int codigo = Integer.parseInt(JOptionPane.showInputDialog("Informe o codigo do DVD: "));
                    for (DVD d : DVDs) {
                        if (d.getCodigo() == codigo) {
                            DVDs.remove(d);
                            JOptionPane.showMessageDialog(null, "DVD removido com Sucesso!");
                            break;
                        }
                    }
                    JOptionPane.showMessageDialog(null, "Erro ao excluir, DVD não encontrado!");
                    break;
                }
                default:
                    JOptionPane.showMessageDialog(null, "Opção Inválida!");
                    break;

            }
            op = menu();
        }
    }

    public static int menu() {
        return Integer.parseInt(JOptionPane.showInputDialog("**Mídias**"
                + "\n1 - Cadastar Livro"
                + "\n2 - Cadastrar DVD"
                + "\n3 - Imprimir todas as midias da biblioteca"
                + "\n4 - Excluir um livro"
                + "\n5 - Excluir um DVD"
                + "\n0 - SAIR"
        ));
    }

}
