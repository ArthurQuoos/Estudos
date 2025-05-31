import br.com.CebolaMusic.Musicas;
import br.com.CebolaMusic.Podcasts;
import br.com.CebolaMusic.Preferidas;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        Musicas minhaMusica = new Musicas();
        Podcasts meuPodcast = new Podcasts();

        minhaMusica.setTitulo("After Dark");
        minhaMusica.setAutor("Mr.Kitty");
        minhaMusica.setAlbum("Time");
        minhaMusica.setGenero("Synthpop");
        minhaMusica.setDuracao(419);

        meuPodcast.setTitulo("Flow");
        meuPodcast.setDuracao(1000);
        meuPodcast.setHost("Igor e Monark");
        meuPodcast.setDescricao("Igor e Monark entrevistam diversos convidados e debatem sobre temas variados");

        for (int i = 0; i < 100; i++) {
            minhaMusica.reproduzir();
        }
        for (int i = 0; i < 1000; i++) {
            minhaMusica.curtir();
        }

        for (int i = 0; i < 150; i++) {
            meuPodcast.reproduzir();
        }
        for (int i = 0; i < 60; i++) {
            meuPodcast.curtir();
        }

       for (int i = 0; i < 23; i++) {
           meuPodcast.avaliar(random.nextInt(10));
          // minhaMusica.avaliar(random.nextInt(10));
       }
       System.out.println("A classificacao desse podcast e: " + meuPodcast.getClassificacao());


        Preferidas favoritas = new Preferidas();
        favoritas.inclui(minhaMusica);
        //favoritas.inclui(meuPodcast);

    }
}