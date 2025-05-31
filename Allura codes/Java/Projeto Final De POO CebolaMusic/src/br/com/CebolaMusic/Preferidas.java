package br.com.CebolaMusic;

public class Preferidas {

    public void inclui(Audio audio){
        if(audio.getClassificacao() > 8){
            System.out.println(audio.getTitulo() + " e " +
                    "considerado sucesso absoluto");
        }else{
            System.out.println(audio.getTitulo() + " e legalzinho");
        }
    }
}
