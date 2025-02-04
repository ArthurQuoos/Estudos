package br.com.CebolaMusic;

public class Audio {
    private String titulo;
    private int duracao;
    private int totalCurtidas;
    private int totalVisualizacoes;
    private int totalAvaliacoes;
    private double classificacao;

    public void curtir(){
        this.totalCurtidas++;
        //System.out.println("S2 + 1");
    }

    public void reproduzir(){
        totalVisualizacoes++;
    }

    public void avaliar(int nota){
        //System.out.println("Nota dada: "+ nota);
        totalAvaliacoes++;
        classificacao += nota;
    }

    public int getTotalAvaliacoes() {
        return totalAvaliacoes;
    }

    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getDuracao() {
        return duracao;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public int getTotalCurtidas() {
        return totalCurtidas;
    }

    public int getTotalVisualizacoes() {
        return totalVisualizacoes;
    }

    public double getClassificacao() {
            classificacao = classificacao / totalAvaliacoes;
        System.out.println(String.format("A classificao e: %.2f" ,classificacao));
        return classificacao;
    }
//    public double getClassificacao(){
//        return classificacao;
//    }


}
