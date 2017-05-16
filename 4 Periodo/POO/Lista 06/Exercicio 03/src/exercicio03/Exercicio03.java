package exercicio03;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Exercicio03 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<Livro> livros = new ArrayList<>();
        ArrayList<PecaCarro> pecasCarros = new ArrayList<>();
        ArrayList<Alimentacao> alimentos = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int op = menu();
        while (op != 0) {
            switch (op) {
                case 1: {
                    System.out.println("Informe o tipo do produto 1-Livro | 2-Peça de Carro | 3-Alimentação: ");
                    int tipo = scanner.nextInt();
                    System.out.println("Descrição: ");
                    String descricao = scanner.next();
                    System.out.println("Preço: R$ ");
                    double preco = scanner.nextDouble();
                    System.out.println("Quantidade: ");
                    int quantidade = scanner.nextInt();
                    switch (tipo) {
                        case 1: {
                            System.out.println("Autor: ");
                            String autor = scanner.next();
                            System.out.println("Numero de páginas: ");
                            int nPaginas = scanner.nextInt();
                            Livro livro = new Livro(autor, nPaginas, livros.size() + 1, descricao, preco, quantidade);
                            livros.add(livro);
                        }
                        break;
                        case 2: {
                            System.out.println("Tipo de peça: ");
                            String tipoCarro = scanner.next();
                            System.out.println("Marca: ");
                            String marca = scanner.next();
                            PecaCarro pecaCarro = new PecaCarro(tipoCarro, marca, pecasCarros.size() + 1, descricao, preco, quantidade);
                            pecasCarros.add(pecaCarro);
                        }
                        break;
                        case 3: {
                            System.out.println("Validade: ");
                            String validade = scanner.next();
                            Alimentacao alimentacao = new Alimentacao(validade, alimentos.size() + 1, descricao, preco, quantidade);
                            alimentos.add(alimentacao);
                        }
                        break;
                        default:
                            System.out.println("Opção Invalida!");
                    }
                }
                break;
                case 2: {
                    System.out.println("Informe o tipo do produto 1-Livro | 2-Peça de Carro | 3-Alimentação: ");
                    int tipo = scanner.nextInt();
                    System.out.println("Informe a posição: ");
                    int pos = scanner.nextInt();
                    System.out.println("Informe o acrescimo do estoque: ");
                    int acrescimo = scanner.nextInt();
                    switch (tipo) {
                        case 1: {
                            try {
                                livros.get(pos).mudaEstoque(acrescimo);
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        case 2: {
                            try {
                                pecasCarros.get(pos).mudaEstoque(acrescimo);
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        case 3: {
                            try {
                                alimentos.get(pos).mudaEstoque(acrescimo);
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        default:
                            System.out.println("Opção Invalida!");
                    }
                }
                break;
                case 3: {
                    System.out.println("Informe o tipo do produto 1-Livro | 2-Peça de Carro | 3-Alimentação: ");
                    int tipo = scanner.nextInt();
                    System.out.println("Informe a posição: ");
                    int pos = scanner.nextInt();
                    switch (tipo) {
                        case 1: {
                            try {
                                System.out.println("Valor em estoque: R$ " + (livros.get(pos).getQuantidade() * livros.get(pos).getPreco()));
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        case 2: {
                            try {
                                System.out.println("Valor em estoque: R$ " + (pecasCarros.get(pos).getQuantidade() * pecasCarros.get(pos).getPreco()));
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        case 3: {
                            try {
                                System.out.println("Valor em estoque: R$ " + (alimentos.get(pos).getQuantidade() * alimentos.get(pos).getPreco()));
                            } catch (Exception e) {
                                System.out.println("Posição Invalida!");
                            }
                        }
                        break;
                        default:
                            System.out.println("Opção Invalida!");
                    }
                }
                break;
                case 4: {
                    System.out.println("Informe o tipo do produto 1-Livro | 2-Peça de Carro | 3-Alimentação: ");
                    int tipo = scanner.nextInt();
                    switch (tipo) {
                        case 1: {
                            for (Livro l : livros) {
                                l.imprimeProduto();
                            }
                        }
                        break;
                        case 2: {
                            for (PecaCarro p : pecasCarros) {
                                p.imprimeProduto();
                            }
                        }
                        break;
                        case 3: {
                            for (Alimentacao a : alimentos) {
                                a.imprimeProduto();
                            }
                        }
                        break;
                        default:
                            System.out.println("Opção Invalida!");
                    }
                }
                break;
                case 5: {
                    System.out.println("------Livros------");
                    for (Livro l : livros){
                        l.imprimeProduto();
                    }
                    System.out.println("\n------Peças de Carros------");
                    for (PecaCarro p : pecasCarros){
                        p.imprimeProduto();
                    }
                    System.out.println("\n------Alimentação------");
                    for (Alimentacao a : alimentos){
                        a.imprimeProduto();
                    }
                }
                break;
                default: System.out.println("Opção Invalida!");

            }
            op = menu();
        }
    }

    public static int menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("**Produtos**"
                + "\n1 - Criar um produto"
                + "\n2 - Mudar estoque"
                + "\n3 - Calcular valor total em estoque"
                + "\n4 - Imprimir todos produtos de um tipo"
                + "\n5 - Imprimir todos os produtos cadastrados"
                + "\n0 - SAIR");
        return scanner.nextInt();
    }

}
