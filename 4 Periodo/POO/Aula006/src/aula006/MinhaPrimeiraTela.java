package aula006;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalDate;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author phelipe
 */
public class MinhaPrimeiraTela extends JFrame implements ActionListener{
    
    private JTextField textAnoNasc;
    private JButton btnCalcular;
    private JLabel lblAnonasc;
    
    public MinhaPrimeiraTela(){
        super("Calculadora de Idade");
        setSize(300,100);
        setLayout(new GridLayout(2,2));
        textAnoNasc = new JTextField();
        lblAnonasc  = new JLabel("Ano de Nascimento");
        btnCalcular = new JButton("Calcular");
    }
    
    public void configurarJanela(){
        add(lblAnonasc);
        add(textAnoNasc);
        add(btnCalcular);
        btnCalcular.addActionListener(this);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == btnCalcular){
            JOptionPane.showMessageDialog(null,LocalDate.now().getYear()-Integer.parseInt(textAnoNasc.getText()));
        }
        
    }
    
}