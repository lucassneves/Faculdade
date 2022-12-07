import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class mainClass {

    public static void main (String [] args) throws Exception,IOException,Exceptions_of_Empresa {

        Empresa empresa = Empresa.getinstancia("Wave Tec");
        empresa.carregar_banco_de_dados_dos_funcionarios();
        //empresa.listar_funcionarios();
        empresa.Add_novo_funcionario();
        empresa.listar_funcionarios();
        

        
    }
}

