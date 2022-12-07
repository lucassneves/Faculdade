import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;

public class Empresa {

    private String name;
    public static Empresa empresa;
    private Scanner sc = new Scanner (System.in);

    /*Lista de Funcionários
        > Existem vários tipos de Funcionários nesta lista
    */
    private ArrayList <Funcionario> contribuintes = null;


    /*Carregar Banco de dados dos Funcionários
        > Chama uma função da classe arquivo que retorna todos os funcionários
        para uma lista na empresa.
    */
    public void carregar_banco_de_dados_dos_funcionarios()throws Exception{
        contribuintes = Arquivo.funcionariosToArray();
        System.out.println("\nSistema carregado com sucesso!");
    }

    /* Add novo funcionario
        > Adiciona um novo funcionário tanto na lista atual de funcionários,
        quanto no arquivo onde armazena todos os funcionários
    */
    public void Add_novo_funcionario()throws Exception,IOException {
        if (contribuintes == null)
            contribuintes = new ArrayList <Funcionario>();

        int num;
        boolean var = true;
        
        do {
            System.out.println("\nEntre com o tipo de Funcionario para adicionar um funcionario\n");
            System.out.println("\n-> Gerente ---- Digite 1\n-> Empregado -- Digite 2\n-> Estagiário - Digite 3\n");
            num = sc.nextInt();
            if (num == 1) {
                contribuintes.add(Gerente.cria_gerente());
                Arquivo.Add_New_Funcionario_inFile(contribuintes.get( contribuintes.size() - 1),"Gerente.txt");
                var = false;
            }else if (num == 2){
                contribuintes.add(Empregado.cria_empregado());
                Arquivo.Add_New_Funcionario_inFile(contribuintes.get( contribuintes.size() - 1),"Empregado.txt");
                var = false;
            }else if (num == 3){
                contribuintes.add(Estagiario.cria_estagiario());
                Arquivo.Add_New_Funcionario_inFile(contribuintes.get( contribuintes.size() - 1),"Estagiario.txt");
                var = false;
            }else{
                System.out.println("Resposta Invalida");
            }
        }while(var);
        
        System.out.println("Funcionário adicionado com Sucesso!");
    }
    
    //Contrutor da classe empresa
    private Empresa(String nome_da_Empresa){    
        this.name = nome_da_Empresa;
    }
    
    //Utilização do padrão de projeto "Singleton"
    // >> Retorna uma instancia, para quem criar a variável empresa
    public static Empresa getinstancia( String nome_da_Empresa){
        if (empresa == null){
            empresa = new Empresa(nome_da_Empresa);
            //Conectar aqui a função carregar banco de dados
        }
        return empresa;
    }

    public void listar_funcionarios(){

        for(int i = 0;i < contribuintes.size();i++)
            System.out.println(contribuintes.get(i).toString());
    }

}
