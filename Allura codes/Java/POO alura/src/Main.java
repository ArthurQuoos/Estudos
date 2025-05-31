//import br.com.Netflix.modelo.Titulo;
import br.com.Netflix.calculo.FiltroRecomendacao;
import br.com.Netflix.modelo.Episodio;
import br.com.Netflix.modelo.Filme;
import br.com.Netflix.modelo.Serie;
import br.com.Netflix.calculo.CalculadoraDeTempo;


public class Main {
    public static void main(String[] args) {
        Filme meuFilme = new Filme();
        meuFilme.setNome("O poderoso Chefao");
        meuFilme.setDuracaoEmMinutos(180);
        meuFilme.setAnoDeLancamento(1970);
        meuFilme.setIncluidoNoPlano(true);
        System.out.println("Duracao do filme: " + meuFilme.getDuracaoEmMinutos());

        meuFilme.exibeFichaTecnica();
        meuFilme.avalia(8);
        meuFilme.avalia(5);
        meuFilme.avalia(10);

        //System.out.println(meuFilme.somaDasAvaliacoes); nao e mais publico
        //System.out.println(meuFilme.totalDeAvaliacao); precisar usar o get para ter acesso
        System.out.println("Media de avaliacao do filme: "+ meuFilme.pegaMedia());
        System.out.println("Total de avaliações: " + meuFilme.getTotalDeAvaliacoes());

        Serie lost = new Serie();
        lost.setNome("Lost");
        lost.setAnoDeLancamento(2000);
        lost.exibeFichaTecnica();
        lost.setTemporadas(10);
        lost.setEpisodiosPorTemporada(10);
        lost.setMinutosPorEpisodio(50);
        System.out.println("Duracao para maratonar: " + lost.getDuracaoEmMinutos());

        Filme outroFilme = new Filme();
        outroFilme.setNome("O poderoso Chefao");
        outroFilme.setDuracaoEmMinutos(200);
        outroFilme.setAnoDeLancamento(1970);
        outroFilme.setIncluidoNoPlano(true);

        CalculadoraDeTempo calculadora = new CalculadoraDeTempo();
        calculadora.inclui(meuFilme);
        calculadora.inclui(outroFilme);
        calculadora.inclui(lost);
        System.out.println(calculadora.getTempoTotal());

        FiltroRecomendacao filtro = new FiltroRecomendacao();
        filtro.filtra(meuFilme);

        Episodio episodio = new Episodio();
        episodio.setNumero(1);
        episodio.setSerie(lost);
        episodio.setTotalVisualizacoes(300);
        filtro.filtra(episodio);
    }
}