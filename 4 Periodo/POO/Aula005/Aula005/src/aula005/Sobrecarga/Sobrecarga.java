
package aula005.Sobrecarga;

import java.util.Scanner;

/**
 *
 * @author pheli
 */
public class Sobrecarga {
    
    public static void main(String[] args) {
        OperacoesMatematicas om = new OperacoesMatematicas();
        Scanner scanner = new Scanner(System.in);
        
        
        int a = 5;
        int b = 5;
        om.soma (a,b);
        
        String v1 = "5";
        String v2 = "5";
        om.soma(v2, v2);
        
    }
    
}
