public class ContaEspecial extends Conta{
    private double limite;

    public ContaEspecial(Pessoa cliente, int nr_conta, Double saldo, double limite) {
        super(cliente, nr_conta, saldo);
        this.limite = limite;
    }
    
    public double getLimite() {
        return limite;
    }


    public void setLimite(double limite) {
        this.limite = limite;
    }

    protected Boolean tem_saldo(double valor){
        if (valor <= getSaldo() + limite)
        return true;
    else
        return false;
    }

    public Conta abrir_conta(Pessoa cliente, int nr_conta, Double saldo) {
        ContaEspecial nv_conta;
        if (cliente != null){
            nv_conta = new ContaEspecial(cliente, nr_conta, saldo, limite);
            return nv_conta;
        }else {
            System.out.println("Pessoa invalida!\n");
            return null;
        }
    }

    public String toString() {
        return super.toString() + "Limite da Conta: " + limite + "\n";
    }
    
}
