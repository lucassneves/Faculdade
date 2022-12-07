import java.util.Scanner;

public class Empregado extends Funcionario implements Interface_Pagamento{
	
	private final float Peso_da_profissao = 48;
	private final int cargaHorariaSemanal = 48;

	public Empregado(){
		
	}

	public Empregado (String nome, String CPF, String endereco,
		String telefone, String email, String codigo, int TempoNaEmpresa) {
	
		super(nome, CPF, endereco, telefone, email, codigo, TempoNaEmpresa);
		
	}

	public String toString () {
		return super.toString();

	}

	public static Funcionario cria_empregado() {

		Funcionario novo_empregado = new Empregado();

		System.out.println("\nEntre com os dados de Empregado:\n");
		
		novo_empregado.setNome(Exceptions_of_Empresa.tratamento_para_nomes());

		novo_empregado.setCPF(Exceptions_of_Empresa.tratamento_para_cpfs());

		novo_empregado.setEndereco(Exceptions_of_Empresa.tratamento_para_enderecos());

		novo_empregado.setTelefone(Exceptions_of_Empresa.tratamento_para_telefone());

		novo_empregado.setEmail(Exceptions_of_Empresa.tratamento_para_emails());

		novo_empregado.setCode(Exceptions_of_Empresa.tratamento_para_codigos());
		
		novo_empregado.setTempoNaEmpresa(0);

		return novo_empregado;
	}

	public double calculaBonus(){
		if(super.TempoNaEmpresa >= 12){
		    return (0.2 * Interface_Pagamento.Salario_base);
		}
		else{
			return (0.1 * Interface_Pagamento.Salario_base);
		}
	}
	
	public double calculaSalarioBruto(){
		//Peso da profissão = 48
		return ((Interface_Pagamento.Salario_base * Peso_da_profissao)/cargaHorariaSemanal);
	}
	public double descontoPrevidenciaSocial(){
		return super.Previdencia_social(calculaSalarioBruto());
	}
	public double calculaSalarioliquido(){
		return calculaSalarioBruto() - descontoPrevidenciaSocial() + calculaBonus();
	}



}
