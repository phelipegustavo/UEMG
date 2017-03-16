
import java.time.LocalDate;
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pheli
 */
public class Exercicio03 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int anoNascimento = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe o ano de nascimento"));
        
        String msg = "Categoria do nadador: ";

        int idade = LocalDate.now().getYear() - anoNascimento;
        
        if (idade >= 5 && idade <= 7)
            msg += " Infantil A";
        else if (idade >= 8 && idade <= 11)
            msg += " Infantil B";
        else if (idade >= 11 && idade <= 13)
            msg += " Juvenil A";
        else if (idade >= 14 && idade <= 17)
            msg += " Juvenil B";
        else if (idade >= 18)
            msg += " Senior";
        else
            msg += " Não Categorizada";
                
        msg += ", " + "idade " + String.valueOf(idade);

        JOptionPane.showMessageDialog(null, msg);

    }
        
}
    

