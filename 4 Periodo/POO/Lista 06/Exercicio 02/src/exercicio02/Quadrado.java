package exercicio02;

/**
 *
 * @author phelipe
 */
public class Quadrado extends FiguraGeometrica {

    public Quadrado() {
        super(4);
    }

    @Override
    public double calcularPerimetro() {
        return getLados()[0]*4;
    }

    @Override
    public double calcularArea() {
        return getLados()[0]*getLados()[0];
    }

    @Override
    public void imprimirDados() {
        System.out.println("Quadrado:"
                + "\nPerimetro: "+calcularPerimetro()
                + "\nArea: "+calcularArea()
        ); 
    }
    
}
