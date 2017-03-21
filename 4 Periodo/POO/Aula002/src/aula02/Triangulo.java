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
public class Triangulo {
    
    public float lado1;
    public float lado2;
    public float lado3;
    public String nome;
    public String cor;

    public Triangulo() {
        this.lado1 = 0;
        this.lado2 = 0;
        this.lado3 = 0;
        this.nome = "";
        this.cor = "";
    }

    public Triangulo(float lado1, float lado2, float lado3, String nome, String cor) {
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
        this.nome = nome;
        this.cor = cor;
    }
    
    public float calcularPerimetro(){
        return this.lado1+this.lado2+this.lado3;
    }
    
    public void imprimir(){
        JOptionPane.showMessageDialog(null,"nome: " + this.nome + ", cor: " + this.cor);
        JOptionPane.showMessageDialog(null,"lado1: " + String.valueOf(this.lado1) + 
                ", lado2: " + String.valueOf(this.lado2) + 
                ", lado3: " + String.valueOf(this.lado3));
    }
}
