package br.com.Netflix.calculo;

import br.com.Netflix.modelo.Titulo;

public class CalculadoraDeTempo {
    private int tempoTotal;

    public int getTempoTotal(){
        return tempoTotal;
    }

//    public void inclui(Filme f){
//        tempoTotal += f.getDuracaoEmMinutos();
//    }
//    public void inclui(Serie f){
//        tempoTotal += f.getDuracaoEmMinutos();
//    }
    public void inclui(Titulo titulo){
    this.tempoTotal += titulo.getDuracaoEmMinutos();
    }
}
