public class Produtos implements Comparable<Produtos> {
    private String nome;
    private double valor;

    public Produtos(String nome, double valor) {
        this.nome = nome;
        this.valor = valor;
    }

    public String getNome() {
        return nome;
    }

    public double getValor() {
        return valor;
    }

    @Override
    public String toString() {
        return "Produto: {" +
                "nome='" + nome +
                ", valor=" + valor +
                '}';
    }

    @Override
    public int compareTo(Produtos outroProdutos) {
        return Double.valueOf(this.valor).compareTo(Double.valueOf(outroProdutos.valor));
    }
}
