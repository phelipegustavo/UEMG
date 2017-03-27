package aula003;

import java.time.LocalDateTime;
import java.util.Scanner;

/**
 *
 * @author phelipe
 */

/*
    Objeto: Especificação
    Classe: Generalização
        -Atributos
        -Métodos
            -Construtor (Inicialização)
    Visibilidade - Simbolos
        +: public
        -: private
        #: protected
    Métodos:
        -geters: Acesso
        -seters: Modificação
    
*/

public class Aula003 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Pessoa p = new Pessoa();
        Scanner scanner = new Scanner(System.in);
        int yearNow = LocalDateTime.now().getYear(); 
        
        System.out.print("Digite o nome: ");
        p.setNome(scanner.next());
        System.out.print("Digite o ano de nascimento:");
        p.setAnoNascimento(scanner.nextInt());
        
        System.out.println(p.retornaPessoa());
        System.out.println("Idade: " + p.calcularIdade(yearNow));

    }
    
}
