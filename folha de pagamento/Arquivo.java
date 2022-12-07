import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileReader;
import java.io.BufferedReader;

public class Arquivo{
	public static ArrayList <Funcionario> funcionariosToArray() throws Exception {
		ArrayList <Funcionario> contribuintes = new ArrayList <Funcionario> ();
		Funcionario auxiliar;
		FileReader reader;
		BufferedReader br;

		reader = new FileReader("Gerente.txt");
		br = new BufferedReader(reader);
		while((auxiliar = getObject_inFIle("Gerente.txt",br, new Gerente()))!= null)
			contribuintes.add(auxiliar);		
		reader.close();
		br.close();

		reader = new FileReader("Empregado.txt");
		br = new BufferedReader(reader);
		while((auxiliar = getObject_inFIle("Empregado.txt",br, new Empregado()))!= null)
			contribuintes.add(auxiliar);
		reader.close();
		br.close();

		reader = new FileReader("Estagiario.txt");
		br = new BufferedReader(reader);
		while((auxiliar = getObject_inFIle("Estagiario.txt",br, new Estagiario()))!= null)
			contribuintes.add(auxiliar);	
		reader.close();
		br.close();
		
		return contribuintes;
	}

	public static Funcionario getObject_inFIle(String caminho, BufferedReader br, Funcionario aux) throws Exception{


		int i;
		String str = "";
		if ((i = br.read()) == -1 ){
			return null;
		} else{
			str =""+ (char)i;
		}

		//leitura do codigo
		while((i = br.read()) != 44)str = str + (char)i;
		aux.setCode(str);
		str = "";

		//leitura do nome
		while((i = br.read()) != 44)str = str + (char)i; 
		aux.setNome(str);
		str = "";

		//leitura do cpf
		while((i = br.read()) != 44)str = str + (char)i; 
		aux.setCPF(str);
		str = "";

		//leitura do endereco
		while((i = br.read()) != 44)str = str + (char)i;
		aux.setEndereco(str);
		str = "";

		//leitura do telefone
		while((i = br.read()) != 44)str = str + (char)i; 
		aux.setTelefone(str);
		str = "";

		//leitura do email
		while((i = br.read()) != 44)str = str + (char)i; 
		aux.setEmail(str);
		str = "";
		//Tempo na Empresa
		
		i = br.read();
		while(i != 44 && i != 10 ){
			str = str + (char)i;
			i = br.read();
		}
		aux.setTempoNaEmpresa(Integer.parseInt(str));
		str = "";

		if (caminho == "Gerente.txt"){
			//leitura da senha
			while((i = br.read()) != 10)str = str + (char)i;  	
			((Gerente)aux).setSenha(str);
			str = "";
			
		} else if (caminho == "Estagiario.txt"){
			//leitura do tempo de contrato restante
			while((i = br.read()) != 44)str = str + (char)i; 
			((Estagiario)aux).setTempoContratoRestante(Integer.parseInt(str));
			str = "";
			//leitura do boolean jovemAprendiz
			while((i = br.read()) != 10)str = str + (char)i; 
			if(str.equals("true"))((Estagiario)aux).setJovemAprendiz(true);
			else ((Estagiario)aux).setJovemAprendiz(false);
			str = "";
		}
		return aux;
	}

	public static void Add_New_Funcionario_inFile(Funcionario novo_funcionario, String caminho) throws IOException {
		int i = 44; //valor da virgula na tabela ascii
		int j = 10; //valor do \n na tabela ascii

		FileWriter reader = new FileWriter(caminho,true);
		PrintWriter in = new PrintWriter(reader);

		Add_Pessoa_and_Funcionario(in, novo_funcionario);
	
		if(novo_funcionario instanceof Gerente){

			//escrita da senha
			in.write(((Gerente)novo_funcionario).getSenha()); 
			in.write((char)j);
			
		} else if(novo_funcionario instanceof Estagiario){
			//escrita do tempo de contrato restante
			in.write(Integer.toString(((Estagiario)novo_funcionario).getTempoContratoRestante())); 
			in.write((char)i);

			//leitura do boolean jovemAprendiz
			if(((Estagiario)novo_funcionario).isJovemAprendiz() == true)
				in.write("true");
			else
				in.write("false");
			in.write((char)j);
			
		}
		
		reader.close();
		in.close();
	}
	
	public static void Add_Pessoa_and_Funcionario(PrintWriter in, Funcionario funcionario) throws IOException {
	
		int i = 44; //valor da virgula em decimal na tabela ascii

		//escrita do codigo
		in.write(funcionario.getCode()); 
		in.write((char)i); 
	
		//escrita do nome
		in.write(funcionario.getNome()); 
		in.write((char)i);
	
		//escrita do cpf
		in.write(funcionario.getCPF()); 
		in.write((char)i);
	
		//escrita do endereco
		in.write(funcionario.getEndereco()); 
		in.write((char)i);
	
		//escrita do telefone
		in.write(funcionario.getTelefone()); 
		in.write((char)i);
	
		//escrita do email
		in.write(funcionario.getEmail()); 
		in.write((char)i);

		in.write(Integer.toString(funcionario.getTempoNaEmpresa()));
		if (funcionario instanceof Empregado)
			in.write((char)10);
		else
			in.write((char)i);
	}
}
