package exercicio01;

import java.util.ArrayList;
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
        ArrayList<Cliente> clientes = new ArrayList<>();
        ArrayList<ContaPoupanca> contasP = new ArrayList<>();
        ArrayList<ContaEspecial> contasE = new ArrayList<>();

        int op = menuPrincipal();
        while (op != 0) {
            switch (op) {

                /*Cadastrar Clientes*/
                case 1: {
                    Cliente cliente = new Cliente();

                    int tipo = Integer.parseInt(JOptionPane.showInputDialog("Informe o tipo de conta:\n1 - Poupança\n2 - Especial"));
                    cliente.setNome(JOptionPane.showInputDialog("Informe o nome do cliente: "));
                    cliente.setCpf(JOptionPane.showInputDialog("Informe o CPF do cliente: "));
                    int numeroConta = clientes.size();

                    if (tipo == 1) {
                        ContaPoupanca contaPoupanca = new ContaPoupanca(numeroConta);
                        contaPoupanca.setTaxaRendimento(Integer.parseInt(JOptionPane.showInputDialog("Informe a taxa de rendimento: ")));
                        contaPoupanca.setCliente(cliente);
                        contasP.add(contaPoupanca);
                        clientes.add(contaPoupanca.getCliente());
                        JOptionPane.showMessageDialog(null, "Conta cadastrada com Sucesso:");
                        contaPoupanca.imprimirConta();
                    } else if (tipo == 2) {
                        ContaEspecial contaEspecial = new ContaEspecial(numeroConta);
                        contaEspecial.setLimite(Double.parseDouble(JOptionPane.showInputDialog("Informe o limite: ")));
                        contaEspecial.setCliente(cliente);
                        contasE.add(contaEspecial);
                        clientes.add(contaEspecial.getCliente());
                        JOptionPane.showMessageDialog(null, "Conta cadastrada com Sucesso:");
                        contaEspecial.imprimirConta();
                    }
                }
                break;

                /*Imprimir Clientes*/
                case 2: {
                    String strClientes = "";
                    for (Cliente c : clientes) {
                        strClientes += "\n---------------"
                                + "\nNome: " + c.getNome()
                                + "\nCPF: " + c.getCpf();
                    }
                    JOptionPane.showMessageDialog(null, "Clientes: " + strClientes);
                }
                break;

                /*Acessar Conta*/
                case 3: {
                    int tipo = Integer.parseInt(JOptionPane.showInputDialog("Informe o tipo de conta: \n1 - Poupança\n 2 - Especial"));
                    int numeroConta = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero da conta: "));

                    if (tipo == 1) {
                        ContaPoupanca contaPoupanca = new ContaPoupanca(numeroConta);
                        for (ContaPoupanca cp : contasP) {
                            if (cp.getNumeroConta() == numeroConta) {
                                contaPoupanca = cp;
                                break;
                            }
                        }
                        int opc = menuConta(numeroConta, "4 - Calcular novo saldo");
                        while (opc != 0) {
                            switch (opc) {
                                case 1: {
                                    double valor = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor para saque: "));
                                    contaPoupanca.sacar(valor);
                                }
                                break;
                                case 2: {
                                    double valor = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor para depositar: "));
                                    contaPoupanca.depositar(valor);
                                }
                                break;
                                case 3: {
                                    contasP.forEach((cp) -> {
                                        cp.imprimirConta();
                                    });
                                }
                                break;
                                case 4: {
                                    contaPoupanca.calculaNovoSaldo();
                                }
                                break;
                                default:
                                    JOptionPane.showMessageDialog(null, "Opção Inválida!");
                            }
                            opc = menuConta(numeroConta, "4 - Calcular novo saldo");
                        }
                    } else if (tipo == 2) {
                        ContaEspecial contaEspecial = new ContaEspecial(numeroConta);
                        for (ContaEspecial ce : contasE) {
                            if (ce.getNumeroConta() == numeroConta) {
                                contaEspecial = ce;
                                break;
                            }
                        }
                        int opc = menuConta(numeroConta, "");
                        while (opc != 0) {
                            switch (opc) {
                                case 1: {
                                    double valor = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor para saque: "));
                                    contaEspecial.sacar(valor);
                                }
                                break;
                                case 2: {
                                    double valor = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor para depositar: "));
                                    contaEspecial.depositar(valor);
                                }
                                break;
                                case 3: {
                                    contasE.forEach((ce) -> {
                                        ce.imprimirConta();
                                    });
                                }
                                break;
                                default:
                                    JOptionPane.showMessageDialog(null, "Opção Inválida!");
                            }
                            opc = menuConta(numeroConta, "");
                        }
                    }
                }
                break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção Inválida!");
            }
            op = menuPrincipal();
        }
    }

    public static int menuPrincipal() {
        return Integer.parseInt(JOptionPane.showInputDialog("**Banco**"
                + "\n1 - Cadastrar cliente"
                + "\n2 - Imprimir todos clientes"
                + "\n3 - Acessar Conta"
                + "\n0 - SAIR"
        ));
    }

    public static int menuConta(int numeroConta, String outrasOpcoes) {
        return Integer.parseInt(JOptionPane.showInputDialog("Conta nº " + numeroConta
                + "\n1 - Sacar"
                + "\n2 - Depositar"
                + "\n3 - Imprimir todas"
                + "\n" + outrasOpcoes
                + "\n0 - Voltar"
        ));
    }
}
