
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
public class Exercicio05 {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int tamanho=Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a quantidade de numeros a inserir"));
        
        int numeros[] = new int[tamanho];
        
        for(int i=0; i<tamanho; i++){
            numeros[i] = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe um numero inteiro"));
        }
        
        JOptionPane.showMessageDialog(null,"Soma dos numeros positivos: " + somarPositivos(numeros));
        JOptionPane.showMessageDialog(null,"Total de numeros negativos: " + contarNegativos(numeros));
        JOptionPane.showMessageDialog(null,"Media dos numeros positivos: " + mediaPositivos(numeros));
        JOptionPane.showMessageDialog(null,"Media dos numeros negativos: " + mediaNegativos(numeros));
        JOptionPane.showMessageDialog(null,"Diferença entre numeros positivos e negativos: " + diferencaPosNeg(numeros));

    }
    
    public static int somarPositivos(int[] vetor){
        int soma=0;
        for (int i=0; i<vetor.length; i++){
            if (vetor[i]>0){
                soma+=vetor[i];
            }
        }
        return soma;
    }
    
    public static  int contarNegativos(int[] vetor){
        int negativos=0;
        for (int i=0; i<vetor.length; i++){
            if (vetor[i]<0){
                negativos++;
            }
        }
        return negativos; 
    }
    
    public static float mediaPositivos(int[] vetor){
        int soma=0;
        int total=0;
        for (int i=0; i<vetor.length; i++){
            if (vetor[i]>0){
                soma+=vetor[i];
                total++;
            }
        }
        return (float)soma/total; 
    }
    
    public static float mediaNegativos(int[] vetor){
        int soma=0;
        int total=0;
        for (int i=0; i<vetor.length; i++){
            if (vetor[i]<0){
                soma+=vetor[i];
                total++;
            }
        }
        return (float)soma/total; 
    }
    
    public static int diferencaPosNeg(int[] vetor){
        int soma=0;
        for (int i=0; i<vetor.length; i++){
            if (vetor[i]<0){
                soma+=vetor[i];
            }
        }
        return somarPositivos(vetor)+soma; 
    }
}
