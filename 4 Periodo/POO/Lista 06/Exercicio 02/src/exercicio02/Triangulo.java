package exercicio02;

/**
 *
 * @author phelipe
 */
public class Triangulo extends FiguraGeometrica {

    public Triangulo() {
        super(3);
    }

    @Override
    public double calcularPerimetro() {
        return lados[0]+lados[1]+lados[2];
    }

    @Override
    public double calcularArea() {
        /*Formula de Heron*/
        double p = calcularPerimetro()/2;
        return Math.sqrt(p*(p-getLados()[0])*(p-getLados()[1])*(p-getLados()[2]));
    }

    @Override
    public void imprimirDados() {
        System.out.println("Triangulo:"
                + "\nPerimetro: " + calcularPerimetro()
                + "\nArea: " + calcularArea()
        );
    }
    
}
