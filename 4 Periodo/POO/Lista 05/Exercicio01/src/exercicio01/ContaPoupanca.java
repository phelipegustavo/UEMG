package exercicio01;

/**
 *
 * @author phelipe
 */
public class ContaPoupanca extends ContaBancaria {
    
    int taxaRendimento;
    
    public ContaPoupanca(int numeroConta){
        super(numeroConta);
        taxaRendimento = 0;
    }
    
    public void calculaNovoSaldo(){
        this.setSaldo(getSaldo() * ( 1 + ((double)taxaRendimento / 100)));
    }

    public int getTaxaRendimento() {
        return taxaRendimento;
    }

    public void setTaxaRendimento(int taxaRendimento) {
        this.taxaRendimento = taxaRendimento;
    }
}
