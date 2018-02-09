package exercicio01;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class ContaEspecial extends ContaBancaria {

    private double limite;

    public ContaEspecial(int numeroConta) {
        super(numeroConta);
        limite = 0;
    }

    @Override
    public void sacar(double valor) {
        if (valor <= limite + getSaldo()) {
            super.setSaldo(getSaldo() - valor);
            JOptionPane.showMessageDialog(null, ""
                    + "Saque de R$ " + valor + " Realizado com sucesso"
            );
        } else {
            JOptionPane.showMessageDialog(null, ""
                    + "Impossivel Realizar saque, valor maior que o limite"
            );
        }
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }
}
