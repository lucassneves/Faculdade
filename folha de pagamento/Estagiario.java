import java.util.Scanner;

//Todo Estagiário trabalha somente 6 horas

public class Estagiario extends Funcionario implements Interface_Pagamento{
	
	private int tempoContratoRestante;
	private boolean jovemAprendiz;
	private final float Peso_da_profissao = 39;
	//Quantidade de Horas Semanais de Trabalho
	private final int cargaHorariaSemanal = 36;


	public Estagiario(){
		
	}
	
	public Estagiario (String nome, String CPF, String endereco,
		String telefone, String email, String codigo,
		 int TempoNaEmpresa, int tempoContratoRestante, boolean jovemAprendiz) {
	
		super(nome, CPF, endereco, telefone, email, codigo, TempoNaEmpresa);
		
		this.tempoContratoRestante = tempoContratoRestante;
		this.jovemAprendiz = jovemAprendiz;
		
	}

	public String toString(){
		return super.toString() + "Tempo de Contrato Restante: " + tempoContratoRestante + "\nParticipação no Jovem Aprendiz: " + jovemAprendiz + "\n";
	}

	public int getTempoContratoRestante() {
		return tempoContratoRestante;
	}
	
	public boolean isJovemAprendiz() {
		return jovemAprendiz;
	}

	public void setTempoContratoRestante(int tempoContratoRestante) {
		this.tempoContratoRestante = tempoContratoRestante;
	}

	public void setJovemAprendiz(boolean jovemAprendiz) {
		this.jovemAprendiz = jovemAprendiz;
	}

	public static Funcionario cria_estagiario(){
		Funcionario novo_estagiario = new Estagiario();

		System.out.println("\nEntre com os dados de Estagiario:");

		novo_estagiario.setNome(Exceptions_of_Empresa.tratamento_para_nomes());

		novo_estagiario.setCPF(Exceptions_of_Empresa.tratamento_para_cpfs());

		novo_estagiario.setEndereco(Exceptions_of_Empresa.tratamento_para_enderecos());

		novo_estagiario.setTelefone(Exceptions_of_Empresa.tratamento_para_telefone());

		novo_estagiario.setEmail(Exceptions_of_Empresa.tratamento_para_emails());

		novo_estagiario.setCode(Exceptions_of_Empresa.tratamento_para_codigos());

		((Estagiario)novo_estagiario).setJovemAprendiz(Exceptions_of_Empresa.tratamento_para_Jovem_aprediz());

		novo_estagiario.setTempoNaEmpresa(0);

		((Estagiario)novo_estagiario).setTempoContratoRestante(Exceptions_of_Empresa.tratamento_para_tempo_invalido());

		return novo_estagiario;
	}
		
	public double calculaBonus(){
		
		if(jovemAprendiz == true && (super.TempoNaEmpresa <= 6)){
		 return (0.05 * Interface_Pagamento.Salario_base);
		}
		else{
			return (0.1 * Interface_Pagamento.Salario_base);
		}
	}
	
	public double calculaSalarioBruto(){
		//Peso da profissão = 39
		return ((Interface_Pagamento.Salario_base * Peso_da_profissao)/cargaHorariaSemanal);
	}
	public double descontoPrevidenciaSocial(){
		return super.Previdencia_social(calculaSalarioBruto());
	}
	public double calculaSalarioliquido(){
		return calculaSalarioBruto() - descontoPrevidenciaSocial() + calculaBonus();
	}

}
