package exercicio02;

/**
 *
 * @author phelipe
 */
public class Circulo extends FiguraGeometrica {

    public Circulo() {
        /*Lados[0] = raio*/
        super(1);
    }

    @Override
    public double calcularPerimetro() {
        return 2 * Math.PI * lados[0];
    }

    @Override
    public double calcularArea() {
        return 2 * Math.PI * lados[0] * lados[0];
    }

    @Override
    public void imprimirDados() {
        System.out.println("Circulo:"
                + "\nPerimetro: " + calcularPerimetro()
                + "\nArea: " + calcularArea()
        );

    }

}
