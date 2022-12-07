import java.util.Scanner;

public class Gerente extends Funcionario implements Interface_Pagamento{
	
	private String senha = null;
	private final float Peso_da_profissao = 72;
	private final int cargaHorariaSemanal = 48;

	public Gerente(){
		
	}

	public Gerente(String nome, String CPF, String endereco, String telefone, String email, String codigo,
	int TempoNaEmpresa, String senha){
		
		super(nome, CPF, endereco, telefone, email, codigo, TempoNaEmpresa);

		this.senha = senha;
	}
	
	public boolean autenticar(String senha){
		if(this.senha == senha)
			return true;
		else
			 return false;
	}
	
	public boolean alterarSenha(String senhaAntiga, String senhaNova){
		if(senha == null){
			senha = senhaNova;
			return true;
		}
		else if(senhaAntiga == senha){
			senha = senhaNova;
			return true;
		}
		else{
			return false;
		}
	}
	
	public String toString () {
		return super.toString() + "senha: " + senha + "\n";
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	public static Funcionario cria_gerente(){
		
		Funcionario novo_gerente = new Gerente();

		novo_gerente.setNome(Exceptions_of_Empresa.tratamento_para_nomes());

		novo_gerente.setCPF(Exceptions_of_Empresa.tratamento_para_cpfs());

		novo_gerente.setEndereco(Exceptions_of_Empresa.tratamento_para_enderecos());

		novo_gerente.setTelefone(Exceptions_of_Empresa.tratamento_para_telefone());

		novo_gerente.setEmail(Exceptions_of_Empresa.tratamento_para_emails());

		novo_gerente.setCode(Exceptions_of_Empresa.tratamento_para_codigos());
	
		((Gerente)novo_gerente).setSenha(Exceptions_of_Empresa.tratamento_para_digitar_senhas());

		novo_gerente.setTempoNaEmpresa(0);

		return novo_gerente;
	}
	
	public double calculaBonus(){
		
		if(super.TempoNaEmpresa >= 12){
		    return (0.35 * Interface_Pagamento.Salario_base);
		}
		else{
			return (0.25 * Interface_Pagamento.Salario_base);
		}
	}
	
	public double calculaSalarioBruto(){
		//Peso da profissão = 57.6
		return ((Interface_Pagamento.Salario_base * Peso_da_profissao)/cargaHorariaSemanal);
	}
	public double descontoPrevidenciaSocial(){
		return super.Previdencia_social(calculaSalarioBruto());
	}
	public double calculaSalarioliquido(){
		return calculaSalarioBruto() - descontoPrevidenciaSocial() + calculaBonus();
	}

}









































