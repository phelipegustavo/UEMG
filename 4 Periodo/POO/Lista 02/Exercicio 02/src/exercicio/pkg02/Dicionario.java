package exercicio.pkg02;

/**
 *
 * @author phelipe
 */
public class Dicionario {

    public Palavra[] palavra;
    private int quantPalavra;

    public void inserePalavra(Palavra palavra) {
        this.palavra[quantPalavra] = palavra;
        quantPalavra++;
    }

    public void excluiPalavra(int posicao) {
        for (int i = posicao; i < quantPalavra; i++) {
            this.palavra[i] = this.palavra[i + 1];
        }
        quantPalavra--;
    }

    public void alteraQuantPalavra(int quantPalavra) {
        this.quantPalavra = quantPalavra;
    }
    
    public void imprimeDicionario(){
        for (int i=0; i<quantPalavra; i++){
            System.out.println("Palavra: " + this.palavra[i].getTermo() + "\nSignificados: ");
            for (int j=0; j<this.palavra[i].getQuantSignificado(); j++){
                System.out.println("\t" + this.palavra[i].getSignificado()[j]);
            }
        }
    }

    public Dicionario() {
        this.quantPalavra=0;
        this.palavra = new Palavra[10];
    }
    

    public Palavra[] getPalavra() {
        return palavra;
    }

    public void setPalavra(Palavra[] palavra) {
        this.palavra = palavra;
    }

    public int getQuantPalavra() {
        return quantPalavra;
    }

    public void setQuantPalavra(int quantPalavra) {
        this.quantPalavra = quantPalavra;
    }
    
    
}
