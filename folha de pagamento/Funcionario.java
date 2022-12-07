public class Funcionario extends Pessoa {
		

    //Codigo de Identificação do Funcionário
    protected String code;
	protected int TempoNaEmpresa;

    public Funcionario() {

    }
	
	public Funcionario(String nome, String CPF, String endereco, String telefone,
			String email, String code,int TempoNaEmpresa) {

		super(nome, CPF, endereco, telefone, email);		
		this.code = code;
		this.TempoNaEmpresa = TempoNaEmpresa;
	}

	public String toString(){
		return super.toString() + "code: " + code + "\nTempo do Funcionario na Empresa (Em Meses): " + TempoNaEmpresa + "\n"; 
    }
    
    public String getCode() {
        return code;
    }
    public int getTempoNaEmpresa() {
        return TempoNaEmpresa;
    }

    public void setCode(String code) {
        this.code = code;
    }


    public void setTempoNaEmpresa(int TempoNaEmpresa) {
        this.TempoNaEmpresa = TempoNaEmpresa;
    }
    
	public double Previdencia_social(double salario_bruto){
        //INSS
        if (salario_bruto <= 1693.72){
            return 0.08*salario_bruto;

        }else if (salario_bruto > 1693.72 && salario_bruto <= 2822.9 ){
            return 0.09*salario_bruto;
            
        }else if (salario_bruto > 2822.9 && salario_bruto <= 5645.8 ){
            return 0.11*salario_bruto;

        }else if (salario_bruto > 5645.8){
            return 621.04;
        }
        return 0;
	}

}
