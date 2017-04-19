package exercicio02;

import java.util.ArrayList;

/**
 *
 * @author phelipe
 */
public class DVD extends Midia {
    
    private int numeroFaixas;
    private ArrayList<Faixa> faixas;

    public DVD(int codigo, String descricao, int prateleira, int numeroFaixas) {
        super(descricao, prateleira);
        super.setCodigo(codigo);
        this.numeroFaixas = numeroFaixas;
        faixas = new ArrayList<>();
    }
    
    public void adcionarFaixa(Faixa faixa){
        faixas.add(faixa);
    }
    
    public int getNumeroFaixas() {
        return numeroFaixas;
    }

    public void setNumeroFaixas(int numeroFaixas) {
        this.numeroFaixas = numeroFaixas;
    }

    public ArrayList<Faixa> getFaixas() {
        return faixas;
    }

    public void setFaixas(ArrayList<Faixa> faixas) {
        this.faixas = faixas;
    }
    
}
