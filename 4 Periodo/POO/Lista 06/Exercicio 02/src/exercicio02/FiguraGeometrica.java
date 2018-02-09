package exercicio02;

/**
 *
 * @author phelipe
 */
public abstract class FiguraGeometrica implements InterfaceFigura {

    public double lados[];

    public FiguraGeometrica(int quantidadeLados) {
        this.lados = new double[quantidadeLados];
    }

    public double[] getLados() {
        return lados;
    }

    public void setLados(double[] lados) {
        this.lados = lados;
    }
}
