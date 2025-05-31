import java.util.ArrayList;
import java.util.List;

public class Conta {
    private double limite;
    private double fatura;
    private List<Produtos> compras;

    public void lancaCompra(Produtos compras) {
            this.compras.add(compras);
        }

    public Conta(double limite) {
        this.limite = limite;
        this.fatura = fatura = 0;
        this.compras = new ArrayList<>();
    }

    public double getLimite() {
        return limite;
    }


    public double getFatura() {
        return fatura;
    }

    public void setFatura(double fatura) {
        this.fatura += fatura;
    }

    public List<Produtos> getCompras() {
        return compras;
    }
}
