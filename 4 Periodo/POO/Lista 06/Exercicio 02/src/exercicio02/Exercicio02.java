package exercicio02;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Exercicio02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<FiguraGeometrica> figuras = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        int op = menu();
        while (op != 0) {
            switch (op) {
                case 1: {
                    System.out.println("Informe o tipo de figura 1-Quadrado | 2-Circulo | 3-Triangulo: ");
                    int tipo = scanner.nextInt();
                    switch (tipo) {
                        case 1: {
                            System.out.println("Informe o tamanho do lado: ");
                            double lados[] = new double[4];
                            lados[0] = scanner.nextDouble();
                            FiguraGeometrica figuraGeometrica = new Quadrado();
                            for (int i = 0; i < 4; i++) {
                                lados[i] = lados[0];
                            }
                            figuraGeometrica.setLados(lados);
                            figuras.add(figuraGeometrica);
                        }
                        break;
                        case 2: {
                            System.out.println("Informe o valor do raio: ");
                            double lados[] = new double[1];
                            lados[0] = scanner.nextDouble();
                            FiguraGeometrica figuraGeometrica = new Circulo();
                            figuraGeometrica.setLados(lados);
                            figuras.add(figuraGeometrica);
                        }
                        break;
                        case 3: {
                            double lados[] = new double[3];
                            for (int i = 0; i < 3; i++) {
                                System.out.println("Informe o valor do lado " + (i+1));
                                lados[i] = scanner.nextDouble();
                            }
                            FiguraGeometrica figuraGeometrica = new Triangulo();
                            figuraGeometrica.setLados(lados);
                            figuras.add(figuraGeometrica);
                        }
                        break;
                    }
                }
                break;
                case 2: {
                    System.out.println("Informe a posição da figura: ");
                    try {
                        int pos = scanner.nextInt();
                        System.out.println("Perimetro: " + figuras.get(pos).calcularPerimetro());
                    } catch (Exception e) {
                        System.out.println("Posição Invalida!");
                    }
                }
                break;
                case 3: {
                    System.out.println("Informe a posição da figura: ");
                    try {
                        int pos = scanner.nextInt();
                        System.out.println("Area: " + figuras.get(pos).calcularArea());
                    } catch (Exception e) {
                        System.out.println("Posição Invalida!");
                    }
                }
                break;
                case 4: {
                    for (FiguraGeometrica f : figuras) {
                        f.imprimirDados();
                    }
                }
                break;
                case 5: {
                    System.out.println("Informe a posição da figura: ");
                    FiguraGeometrica f = null;
                    try {
                        int pos = scanner.nextInt();
                        f = figuras.get(pos);
                    }catch(Exception e){
                        System.out.println("Posição Inválida!");
                    }
                    String msg = "A figura é ";
                    if (f instanceof Quadrado){
                        System.out.println(msg+"um Quadrado");
                    }else if (f instanceof Circulo){
                        System.out.println(msg+"um Circulo");
                    }else if (f instanceof Triangulo){
                        System.out.println(msg+"um Triangulo");
                    }
                }
                break;
                default:System.out.println("Opção Inválida!");
            }
            op = menu();
        }
    }

    public static int menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("**Figura Geometrica**"
                + "\n1 - Criar Figura Geometrica"
                + "\n2 - Calcular Perimetro"
                + "\n3 - Calcular Area"
                + "\n4 - Imprimir todas as Figuras"
                + "\n5 - Tipo de Figura(Posição)"
                + "\n0 - SAIR");
        return scanner.nextInt();
    }

}
