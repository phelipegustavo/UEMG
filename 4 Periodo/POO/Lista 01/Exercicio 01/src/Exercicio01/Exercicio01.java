package Exercicio01;


import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author phelipe
 */
public class Exercicio01 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int numero = Integer.parseInt(JOptionPane.showInputDialog("Informe um numero: "));
        
        String msg = (numero % 2 ==0) ? "par":"impar";
        
        JOptionPane.showMessageDialog(null, "O numero informado é " + msg);
    }
    
}
