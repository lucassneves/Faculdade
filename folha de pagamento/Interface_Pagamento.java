public interface Interface_Pagamento {

	//Salario Base para qualquer funcionário na empresa
	public final static double Salario_base = 2000.00;
	
	//Metodos são implicidamente definidos como publicos e abstratos em Interfaces
	double calculaBonus();
	double calculaSalarioBruto();
	double calculaSalarioliquido();
	double descontoPrevidenciaSocial();

}
