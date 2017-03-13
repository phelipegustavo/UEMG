
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JOptionPane;


public class Aula01 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		//ENTRADA E SAIDA (CONSOLE)
		/*System.out.print("Informe seu nome: ");
				
		Scanner scanner = new Scanner(System.in);
		
		String texto = scanner.nextLine();
		
		scanner.close();
		
		System.out.println("Hello " + texto);
		*/
		
		//ENTRADA E SAIDA (JOPTION)
		/*
		String texto = JOptionPane.showInputDialog(null, "Ola, Digite seu nome");
		JOptionPane.showMessageDialog(null, "Ola " + texto);
		*/
		
		
		//GRAVAR ARQUIVO
		FileWriter fileWriter;
		try {
			fileWriter = new FileWriter("temp.txt");
			PrintWriter printWriter = new PrintWriter(fileWriter);
			printWriter.println("OLA");
			fileWriter.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		
		//CONVERSAO STRING INTEIRO
		/*
		try{
			int n = Integer.parseInt(JOptionPane.showInputDialog(null,"Informe um numero: "));
			JOptionPane.showInputDialog(null, "O dobro de " + n + " é: " + n*2);
		
		}catch(NumberFormatException e){
			JOptionPane.showMessageDialog(null, "Um NUMERO, ANIMAL!");
		}
		*/
	}

}
