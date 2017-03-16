/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio.pkg04;

import javax.swing.JOptionPane;

/**
 *
 * @author phelipe
 */
public class Exercicio04 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[] numeros = new int[5];

        for (int i = 0; i < 5; i++) {
            numeros[i] = (Integer.parseInt(JOptionPane.showInputDialog(null, "Informe um numero inteiro: ")));
        }
        
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if(numeros[i]>numeros[j]){
                    int aux = numeros[i];
                    numeros[i]=numeros[j];
                    numeros[j]=aux;
                }
            }
        }
        String msg="Numeros inseridos em ordem decrescente: ";
        
        for (int i=0; i<5; i++){
            msg += " " + String.valueOf(numeros[i]);
        }
            
        JOptionPane.showMessageDialog(null, msg);
        
        
    }

}
