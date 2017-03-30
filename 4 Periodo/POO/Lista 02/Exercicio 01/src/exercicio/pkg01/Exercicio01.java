package exercicio.pkg01;

import java.util.Scanner;

/**
 *
 * @author phelipe
 */
public class Exercicio01 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Pedido pedido = new Pedido();

        System.out.print("Informe a descrição do pedido:");
        pedido.setDescricao(scanner.nextLine());
        System.out.print("Informe a data do Pedido: ");
        pedido.setData(scanner.next());
        
        
        
        ItemPedido itemPedido = new ItemPedido();

        System.out.print("Informe o produto: ");
        itemPedido.setProduto(scanner.next());
        System.out.print("Informe a quantidade de itens: ");
        itemPedido.setQuant(scanner.nextInt());
        System.out.print("Informe o valor Total do item: ");
        itemPedido.setValorTotal(scanner.nextFloat());

        pedido.insereItem(itemPedido);

        itemPedido.retornaItemPedido();

        System.out.println(
                "\nDescricao pedido: " + pedido.getDescricao()
                + ". Data do pedido: " + pedido.getData()
                + "\nItens Pedido:");
        
        int i=0;
        while (pedido.itens[i] != null){
            System.out.println(
                "\tProduto: " + pedido.getItens()[i].getProduto()
                + ", quantidade: " + pedido.getItens()[i].getQuant()
                + ", valor total: " + pedido.getItens()[i].getValorTotal());
                i++;
        }
               
    }

}
