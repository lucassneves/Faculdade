import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Calendario {
    private int Dia;
    private int Mes;
    private int Ano;

    public Calendario (int Dia, int Mes, int Ano){
        this.setAno(Ano);
        this.setDia(Dia);
        this.setMes(Mes);
    }

    public int getDia() {
        return Dia;
    }
    public int getMes() {
        return Mes;
    }

    public int getAno() {
        return Ano;
    }
    
    public void setDia(int Dia) {
        this.Dia = Dia;
    }

    public void setMes(int Mes) {
        this.Mes = Mes;
    }

    public void setAno(int Ano) {
        this.Ano = Ano;
    }

    public int Calcula_idade(){
        LocalDate nascimento = LocalDate.of(this.Ano, this.Mes, this.Dia);
        LocalDate hoje = LocalDate.now();
        return (int) ChronoUnit.YEARS.between(nascimento,hoje);
    }

    public String toString() {
        return "Dia: " + Dia + ", Mes: " + Mes + ", Ano: " + Ano + "\nIdade: " + Calcula_idade() + "\n";
    }

}
