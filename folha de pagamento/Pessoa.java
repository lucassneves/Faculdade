public class Pessoa {

	protected String nome;
	protected String CPF;
	protected String endereco;
	protected String telefone;
	protected String email;

    public Pessoa (){
        
    }
	
	public Pessoa(String nome, String CPF, String endereco, String telefone, String email) {
		this.nome = nome;
		this.CPF = CPF;
		this.endereco = endereco;
		this.telefone = telefone;
		this.email = email;
	}

	public String toString(){
		return "Nome: " + nome + "\nCPF: " + CPF + "\nEndereço: " + endereco + "\nTelefone: " + telefone + "\nEmail: " + email+"\n";
	}


    public String getNome() {
        return nome;
    }

    public String getCPF() {
        return CPF;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getEmail() {
        return email;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }

        
}

