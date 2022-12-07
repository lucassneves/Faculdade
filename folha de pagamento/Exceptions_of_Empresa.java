import java.util.Scanner;

public class Exceptions_of_Empresa extends RuntimeException{
    private static String srt;
    private static Scanner sc = new Scanner(System.in);
    private static boolean var;

    private static final String senha_incorreta = "Erro, Senha digitada incorreta";
    private static final String nome_invalido = "Nome Invalido, Quantidade de letras insulficientes!";
    private static final String cpf_invalido = "CPF Invalido, Digite somente numeros!";
    private static final String endereco_invalido = "Endereço Invalido, não digite virgulas";
    private static final String telefone_invalido = "Quantidade de numeros insulficientes";
    private static final String email_invalido = "Email Invalido";
    private static final String codigo_invalido = "Codigo de Funcionário Inválido!";
    private static final String senha_invalida = "Senha Invalida, Digite mais caracteres!";
    private static final String string_invalida = "Resposta Invalida";
    private static final String tempo_invalido = "Tempo Inválido";

    public Exceptions_of_Empresa(String a) {
        super(a);
    }

    public static boolean tratamento_para_validar_senha(String senha_atual){
        int num_chances = 3;
        
        System.out.println("\nDigite a sua senha para adquirir o acesso!");
        System.out.println("Você tem 3 Tentativas");
        var = true;

        do {
            srt = sc.nextLine();
            if (srt == senha_atual){
                var = false;
                break;
            }
            num_chances--;
            throw new Exceptions_of_Empresa(senha_incorreta);
        } while (var && num_chances != 0);

        System.out.println("Suas chances acabaram, o programa será Encerrado!");
        System.exit(1);

        return true;
    }

    public static String tratamento_para_nomes(){
        System.out.println("\nEntre com os dados do Funcionário:\nDigite o Nome Completo: ");
        var = true;
		do{
			System.out.println(">> Digite Pelo ou menos 4 letras");
			srt = sc.nextLine();
			if (srt.length() < 4)
				throw new Exceptions_of_Empresa(nome_invalido);
			else
				var = false;
		} while(var);

        return srt;
    }

    public static String tratamento_para_cpfs(){

        System.out.println("\nDigite o CPF:");
			var = true;
			System.out.println(">> Digite 11 numeros, sem espaço ou traço");
			srt = sc.nextLine();

			if (srt.length() != 11)
                throw new Exceptions_of_Empresa(cpf_invalido);
                
        return srt;
    }

    public static String tratamento_para_enderecos(){
        var = true;

        System.out.println("\nDigite o endereço:");
		do{
			System.out.println(">> !NÃO DIGITE VIRUGULAS!");
			srt = sc.nextLine();
			if (srt.indexOf(44) == -1)
				var = false;
			else{
				throw new Exceptions_of_Empresa(endereco_invalido);
			}
        }while(var);

        return srt;
    }
    public static String tratamento_para_telefone(){
        var = true;
        do{    
            System.out.println("\nDigite o Telefone:");
            srt = sc.nextLine();
            if (srt.length() < 8)
                throw new Exceptions_of_Empresa(telefone_invalido);
            else    
                var = false;
        } while(var);

        return srt;
    }
    public static String tratamento_para_emails(){
        var = true;

        do{  
            System.out.println("\nDigite o Email:");
            srt = sc.nextLine();
            if (srt.indexOf("@") == -1)
                throw new Exceptions_of_Empresa(email_invalido);
            else    
                var = false;

        } while(var);

        return srt;
    }

    public static String tratamento_para_codigos(){
        var = true;

        do{ 
            System.out.println("\nInforme o Codigo do Funcionário:");
            System.out.println(">> Somente 4 Digitos:");

            srt = sc.nextLine();
             if (srt.length() < 4)
                throw new Exceptions_of_Empresa(codigo_invalido);
            else {
                try {
					Integer.parseInt(srt);
					var = false;
				} catch (NumberFormatException e) {
					System.out.println("Digitou letras né!");
				}
            }
        } while(var);

        return srt;
    }
    public static String tratamento_para_digitar_senhas(){
        var = true;

        do{ 
            System.out.println("\nInforme a senha padrão do Gerente:");
            System.out.println(">> Pelo ou menos 8 caracteres:");

            srt = sc.nextLine();
             if (srt.length() < 8)
                throw new Exceptions_of_Empresa(senha_invalida);
            else {
                var = false;
            }
        } while(var);

        return srt;
    }

    public static boolean tratamento_para_Jovem_aprediz(){
        var = true;
        System.out.println("\nInforme se o Estagiário é ou não participante do programa Jovem Aprendiz:\n");
        
        
        do{
            System.out.println("!Utilize'SIM' ou 'NAO'!");
            srt = sc.nextLine();
            if(srt.equals("SIM") || srt.equals("NAO"))
                var = false;
            else
                throw new Exceptions_of_Empresa(string_invalida);

        } while(var);

        return srt.equals("SIM");
    }
    public static int tratamento_para_tempo_invalido(){
        int num;
        var = true;

        System.out.println("\nInforme o tempo de contrato do Estagiário:\n");
        System.out.println("!Em Meses!");
        do {
            num = sc.nextInt();
            if(num <= 0)
                throw new Exceptions_of_Empresa(tempo_invalido);
            else
                var = false;
        } while(var);

        return ((int)num);
    }
}