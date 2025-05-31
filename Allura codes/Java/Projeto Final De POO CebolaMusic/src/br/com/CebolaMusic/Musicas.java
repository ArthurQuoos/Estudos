package br.com.CebolaMusic;

public class Musicas extends Audio {
    private String album;
    private String genero;
    private String autor;

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getAlbum() {
        return album;
    }

    public void setAlbum(String album) {
        this.album = album;
    }

    @Override
    public double getClassificacao(){
        if(this.getTotalCurtidas() > 500){
            return 10.0;
        }else{
            return 8.0;
        }
    }
}
