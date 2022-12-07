import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;

public class mainClass{
        

    public static void main (String [] args)throws Exception,IOException{
        ArrayList <Conta> lista_de_contas = new ArrayList<Conta>();
        Scanner sc = new Scanner (System.in);

        Pessoa pessoa01 = new PessoaFisica("Luana", 001,"vila_maria", 123456789, 16,9,1999, "Feminino");
        Pessoa pessoa02 = new PessoaFisica("Leo", 002,"vila_joao", 123456789, 27,1,1999, "Masculino");
        Pessoa pessoa03 = new PessoaJuridica("Arroz_Cristal",003,"vila_cristal",5555444,"comida");

        
        System.out.println("\n###Listando as Pessoas Fisicas e Juridicas###\n");

        System.out.println(pessoa01.toString() + "\n");
        System.out.println(pessoa02.toString() + "\n");
        System.out.println(pessoa03.toString() + "\n");

        lista_de_contas.add( new ContaPoupanca( pessoa01, 10, 1000.00,1.10));
        lista_de_contas.add( new ContaEspecial(pessoa03, 13, 1200.0,300.0));


        System.out.println("\n###Listando as Contas Especiais e Poupanca###\n");
        for(int i = 0 ; i < lista_de_contas.size() ; i++){
            System.out.println(lista_de_contas.get(i).toString() + "\n");
        }

        //Saque
        System.out.println("\n\nExecutando um Saque\n Antes: " + lista_de_contas.get(0).getSaldo() + "\n");
        lista_de_contas.get(0).sacar();

        //Deposito
        System.out.println("\n\nExecutando um Deposito\n Antes: " + lista_de_contas.get(0).getSaldo() + "\n");
        
        System.out.println("Digite um valor\n");
        lista_de_contas.get(0).depositar(sc.nextInt());
        System.out.println("Depois: " + lista_de_contas.get(0).getSaldo() + "\n");

        //Tranferencia
        System.out.println("\n###Listando as Contas Especiais e Poupanca###\n");
        for(int i = 0 ; i < lista_de_contas.size() ; i++){
            System.out.println(lista_de_contas.get(i).toString() + "\n");
        }
        lista_de_contas.get(0).transferir(lista_de_contas);

        for(int i = 0 ; i < lista_de_contas.size() ; i++){
            System.out.println(lista_de_contas.get(i).toString() + "\n");
        }

    }
}