package exercicio01;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class ContaBancaria {

    private Cliente cliente;
    private int numeroConta;
    private double saldo;

    public ContaBancaria(int numeroConta) {
        cliente = new Cliente();
        this.numeroConta = numeroConta;
        this.saldo = 0;
    }

    public void sacar(double valor) {
        if (valor <= saldo) {
            this.saldo -= valor;
        } else {
            JOptionPane.showMessageDialog(null, ""
                    + "Impossivel Realizar saque, não é possivel realizar saques com valor maior que o saldo"
            );
        }
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }

    public void imprimirConta() {
        JOptionPane.showMessageDialog(null, ""
                + "\nConta nº: " + numeroConta
                + "\nNome: " + cliente.getNome()
                + "\nCPF: " + cliente.getCpf()
                + "\nSaldo: R$" + saldo
        );
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public int getNumeroConta() {
        return numeroConta;
    }

    public void setNumeroConta(int numeroConta) {
        this.numeroConta = numeroConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
}
