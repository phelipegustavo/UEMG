/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula005.Sobrecarga;

/**
 *
 * @author pheli
 */
public class OperacoesMatematicas {
    
    public void soma(String x, String y){
        int a = Integer.parseInt(x);
        int b = Integer.parseInt(y);
        int soma = a+b;
        System.out.println("Soma: " + soma);
    }
    
    public void soma(int x, int y){
        int soma = x+y;
        System.out.println("Soma: " + soma);
    }
    
}
