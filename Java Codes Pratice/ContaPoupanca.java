public class ContaPoupanca extends Conta {
    private double tx_correcao;

    public ContaPoupanca(Pessoa cliente, int nr_conta, Double saldo, double tx_correcao) {
        super(cliente, nr_conta, saldo);
        this.tx_correcao = tx_correcao;
    }


    public double getTx_correcao() {
        return tx_correcao;
    }

    public void setTx_correcao(double tx_correcao) {
        this.tx_correcao = tx_correcao;
    }

    public void atualiza_saldo_rendimento(){
        double novo_valor = tx_correcao*getSaldo();
        setSaldo(novo_valor);
    }

    public Conta abrir_conta(Pessoa cliente, int nr_conta, Double saldo) {
        ContaPoupanca nv_conta;
        if (cliente != null){
            nv_conta = new ContaPoupanca(cliente, nr_conta, saldo, tx_correcao);
            return nv_conta;
        }else {
            System.out.println("Pessoa invalida!\n");
            return null;
        }
    }


    public String toString() {
        return super.toString() + "Taxa de Correcao da Conta: " + tx_correcao + "\n";
    }
    
}
