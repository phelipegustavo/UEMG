package exercicio01;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Exercicio01 {

    /**
     * @param args the command line arguments
     */

    public static void main(String[] args) {
        ArrayList<Mensagem> mensagens = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int op = menu();

        while (op != 0) {
            switch (op) {
                case 1: {
                    System.out.println("Informe o conteudo Mensagem: ");
                    String msg = scanner.next();
                    int codigo = mensagens.size()+1;
                    System.out.println("Informe o tipo de mensagem 1-SMS | 2-Alerta: ");
                    int tipo = scanner.nextInt();
                    if (tipo == 1) {
                        Mensagem mensagem = new SMS();
                        mensagem.setConteudo(msg);
                        mensagem.setCodigo(codigo);
                        mensagens.add(mensagem);
                    } else {
                        Mensagem mensagem = new Alerta();
                        mensagem.setConteudo(msg);
                        mensagem.setCodigo(codigo);
                        mensagens.add(mensagem);
                    }
                    
                    System.out.println("Mensagem criada com sucesso!");
                    break;
                }
                case 2: {
                    System.out.println("Informe o codigo da Mensagem: ");
                    int codigo = scanner.nextInt();
                    for (Mensagem m : mensagens) {
                        if (m.getCodigo() == codigo) {
                            m.enviarMensagem();
                            System.out.println("Mensagem enviada com sucesso");
                        }
                    }
                    break;
                }
                case 3: {
                    System.out.println("Informe o codigo da Mensagem: ");
                    int codigo = scanner.nextInt();
                    for (Mensagem m : mensagens) {
                        if (m.getCodigo() == codigo) {
                            m.imprimirMensagem(codigo);
                            break;
                        } 
                    }
                    break;
                }
                case 4: {
                    for (Mensagem m : mensagens) {
                        m.imprimirMensagem(0);
                    }
                }
                break;
                case 5: {
                   System.out.println("Informe o codigo da Mensagem: ");
                    int codigo = scanner.nextInt();
                    for (Mensagem m : mensagens) {
                        if (m.getCodigo() == codigo) {
                            if (m instanceof Alerta){
                                System.out.println("Tipo: Alerta");
                            }
                            else if (m instanceof SMS){
                                System.out.println("Tipo: SMS");
                            }
                            break;
                        }
                    }
                }
                break;
                default: System.out.println("Opção Invalida! "); break;
            }
            op = menu();
        }
    }

    public static int menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("**Mensagem**"
                + "\n1 - Criar Mensagem"
                + "\n2 - Enviar Mensagem"
                + "\n3 - Imprimir Mensagem"
                + "\n4 - Imprimir todas as Mensagens"
                + "\n5 - Tipo da Mensagem(Posição)"
                + "\n0 - SAIR");
        return scanner.nextInt();
    }
}
