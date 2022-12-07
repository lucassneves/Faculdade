import java.util.ArrayList;
import java.util.Scanner;

public abstract class Conta {
    private Scanner in = new Scanner(System.in);
    private Pessoa cliente;
    private int nr_conta;
    private Double saldo;

    public Conta (Pessoa cliente, int nr_conta, Double saldo) {
        this.cliente = cliente;
        this.nr_conta = nr_conta;
        this.saldo = saldo;
    }

    public Pessoa getCliente() {
        return cliente;
    }
    public int getNr_conta() {
        return nr_conta;
    }

    public Double getSaldo() {
        return saldo;
    }

    public void setCliente(Pessoa cliente) {
        this.cliente = cliente;
    }

    public void setNr_conta(int nr_conta) {
        this.nr_conta = nr_conta;
    }

    public void setSaldo(Double saldo) {
        this.saldo = saldo;
    }
    
    public abstract Conta abrir_conta (Pessoa cliente, int nr_conta, Double saldo);

    
    public void sacar() {
            double valor;
            System.out.println("Digite o Valor que deseja sacar:");
            valor = in.nextDouble();
            if (tem_saldo(valor)){
                debitar(valor);
                System.out.println("Valor Sacado com Sucesso!\nSaldo atual da Conta: " + saldo + "\n");
            } else {
                System.out.println("O valor desejado excede o valor da conta atual: " + saldo + "\n");
            }
    }

    private void debitar(double valor){
        this.saldo -= valor; 
    }

    protected Boolean tem_saldo(double valor){
        if (valor <= saldo)
            return true;
        else
            return false;
    }

    public void depositar(double valor) {
        this.saldo += valor;
        
    }

    public void transferir(ArrayList <Conta> contas) {
        double valor;
        int nr_conta_auxiliar;
        Boolean dinheiro_transferido = false;
        
        System.out.println("Digite o Valor que deseja Transferir:");
        valor = in.nextDouble();

        
        if (tem_saldo(valor)){
            System.out.println("Digite o numero da Conta que recebera a tranferencia:\n");
            nr_conta_auxiliar = in.nextInt();
            

            for(int i = 0;i < contas.size();i++){
                if (contas.get(i).nr_conta == nr_conta_auxiliar && (getNr_conta() != contas.get(i).nr_conta) ){
                    contas.get(i).depositar(valor);
                    debitar(valor);
                    dinheiro_transferido = true;
                    System.out.println("Dinheiro Transferido!\n");
                    
                }
            }
            if (!dinheiro_transferido){
                System.out.println("Conta nao encontrada!\n");
            }

        } else {
            System.out.println("O valor desejado excede o valor da conta atual: " + saldo + "\n");
        }

    }

    public String toString(){
        return cliente.toString() + "Numero da conta: " + nr_conta + "\nSaldo atual da conta: " + saldo + "\n";
    }
}
