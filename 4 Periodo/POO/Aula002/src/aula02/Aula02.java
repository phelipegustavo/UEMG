/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula02;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Aula02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Triangulo triangulo = new Triangulo();
        triangulo.nome  = JOptionPane.showInputDialog("Nome: ");
        triangulo.cor   = JOptionPane.showInputDialog("Cor: ");
        triangulo.lado1 = Float.parseFloat(JOptionPane.showInputDialog("Valor lado 1: "));
        triangulo.lado2 = Float.parseFloat(JOptionPane.showInputDialog("Valor lado 2: "));
        triangulo.lado3 = Float.parseFloat(JOptionPane.showInputDialog("Valor lado 3: "));
        
        triangulo.imprimir();
        JOptionPane.showMessageDialog(null, "Perimetro: " + String.valueOf(triangulo.calcularPerimetro()));
        
        Triangulo tri = new Triangulo(2.5f, 5.0f, 4.6f, "Triangulo2", "Preto");
        tri.imprimir();
    }
    
}
